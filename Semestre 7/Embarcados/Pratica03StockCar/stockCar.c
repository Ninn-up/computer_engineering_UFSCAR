#include <reg51.h>

#define GlcdDataBus P3

sbit RS  = P2^0;
sbit RW  = P2^1;
sbit EN  = P2^2;
sbit PSB = P2^3;
sbit RST = P2^5;
sbit p0_2 = P0^2;
sbit p0_4 = P0^4;
sbit p0_5 = P0^5;
sbit p0_6 = P0^6;

// Símbolos dos elementos do jogo
unsigned char code car_player[24]={
0x03,0x80,0x02,0x80, 0x33,0x98,0x3F,0xF8, 0x33,0x98,0x03,0x80,
0x03,0x80,0x33,0x98, 0x3F,0xF8,0x33,0x98, 0x03,0x80,0x00,0x00
};

unsigned char code car_enemy[24]={
0x03,0x80,0x0B,0xA0, 0x0F,0xE0,0x0B,0xA0, 0x03,0x80,0x03,0x80,
0x03,0x80,0x0B,0xA0, 0x0F,0xE0,0x0B,0xA0, 0x03,0x80,0x00,0x00
};

unsigned char code spr_crash[32]={
0x00,0x00,0x00,0x00, 0x00,0x00,0x05,0x00, 0x0A,0x80,0x00,0x40,
0x28,0x00,0x40,0x10, 0x20,0x00,0x14,0x10, 0x09,0x40,0x02,0x80,
0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00
};

unsigned char code ambulancia[32]={
0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00, 0x1F,0xE0,0x1B,0xE0,
0x11,0xA0,0x1B,0xF8, 0x1F,0xF8,0x1F,0xF8, 0x04,0x40,0x00,0x00,
0x00,0x00,0x00,0x00, 0x00,0x00,0x00,0x00
};

// Endereçamento direto
char data          road_vec[16];  // código da pista
unsigned char data road_head  = 0; // índice da posição da pista
char data          road_delta = 0;  // gera curvas

unsigned char data player_x   = 50;
unsigned char data enemy_x    = 50;
signed char data   enemy_y    = -16;
unsigned char data km_tick    = 0;

unsigned char track_width = 54;
unsigned int  km          = 0;
unsigned char ac          = 0;
unsigned char lives       = 10;  // max de vidas
bit           crashed     = 0;
bit           night_mode  = 0;
unsigned char night_km    = 0;

#define HEADLIGHT_REACH 30
#define HEADLIGHT_HALF  10

// Retorna segmento da pista do momento
char road_get(unsigned char l)
{
    unsigned char idx = l >> 2;
    unsigned char real_idx, next_idx;
    char a;
    signed char d;
    
    if(idx >= 15) return road_vec[(road_head + 15) & 15];
    
    real_idx = (road_head + idx) & 15;
    next_idx = (road_head + idx + 1) & 15;
    
    a = road_vec[real_idx];
    d = road_vec[next_idx] - a;
    d = (d * (char)(l & 3)) >> 2;
    
    return a + d;
}

void delay_ms(unsigned int count)
{
    unsigned int i, j;
    for(i = 0; i < count; i++)
        for(j = 0; j < 112; j++);
}

void delay_us()
{
    unsigned char i = 12;
    while(i--);
}

void glcd_cmd(unsigned char c)
{
    RS = 0; RW = 0; GlcdDataBus = c;
    EN = 1; delay_us(); EN = 0;
}

void glcd_dat(unsigned char d)
{
    RS = 1; RW = 0; GlcdDataBus = d;
    EN = 1; delay_us(); EN = 0;
}

void glcd_init()
{
    PSB = 1; RST = 0; delay_ms(10);
    RST = 1; delay_ms(50);
    glcd_cmd(0x30); delay_ms(5);
    glcd_cmd(0x0C); glcd_cmd(0x01); delay_ms(15);
    glcd_cmd(0x36);
    p0_4 = 1; p0_5 = 1; p0_6 = 1;
}

void glcd_clear()
{
    unsigned char i, j;
    glcd_cmd(0x36);
    for(i = 0; i < 64; i++)
    {
        glcd_cmd(0x80 | (i < 32 ? i : i - 32));
        glcd_cmd(i < 32 ? 0x80 : 0x88);
        for(j = 0; j < 16; j++) glcd_dat(0x00);
    }
}

void put_num3(unsigned int v)
{
    unsigned char c;
    c = 0; while(v >= 100) { v -= 100; c++; } glcd_dat(c + '0');
    c = 0; while(v >= 10)  { v -= 10;  c++; } glcd_dat(c + '0');
    glcd_dat((unsigned char)v + '0');
}

void put_text()
{
    glcd_cmd(0x30); glcd_cmd(0x8D);
    glcd_dat('K'); glcd_dat('M'); glcd_dat(':');
    put_num3(km);
    glcd_cmd(0x9D);
    glcd_dat('A'); glcd_dat('C'); glcd_dat(':');
    glcd_dat(ac / 10 + '0');
    glcd_dat(ac % 10 + '0');
    glcd_cmd(0x36);
}

void glcd_goto(unsigned char linha, unsigned char col)
{
    glcd_cmd(0x80 | (linha & 0x1F)); 
    glcd_cmd((linha < 32 ? 0x80 : 0x88) + col);
}

// Desenha os elementos do jogo
void draw_sprite(unsigned char x, signed char y,
                 unsigned char code *s, unsigned char h,
                 unsigned char yl, unsigned char yh,
                 unsigned char xl, unsigned char xr)
{
    unsigned char i, col, desl, linha;
    unsigned int pixels, pe, pd;

    if(x > 112 || x + 13 < xl || x > xr) return;

    col  = x >> 4; // x / 16
    desl = x & 15; // x % 16

    for(i = 0; i < h; i++)
    {
        if(y + (signed char)i < 0) continue;
        linha = (unsigned char)(y + i);
        if(linha > 63 || linha < yl || linha > yh) continue;

        pixels = ((unsigned int)s[i<<1] << 8) | s[(i<<1)+1];
        
        // Otimização de pipeline: previne shifts dinâmicos longos
        if (desl >= 8) {
            pe = (pixels >> 8) >> (desl - 8);
        } else {
            pe = pixels >> desl;
        }
        
        pd = desl ? (pixels << (16 - desl)) : 0;

        if(pe) { glcd_goto(linha, col); glcd_dat(pe>>8); glcd_dat(pe); }
        if(pd && col < 7) { glcd_goto(linha, col+1); glcd_dat(pd>>8); glcd_dat(pd); }
    }
}

// Altera a posição da pista
void update_track()
{
    unsigned char real_idx1;
    
    road_head = (road_head - 1) & 15;
    real_idx1 = (road_head + 1) & 15;

    if((km_tick & 0x0F) == 0) { if(road_delta <  4) road_delta++; }
    if((km_tick & 0x0F) == 8) { if(road_delta > -4) road_delta--; }
    if((km_tick & 0x1F) == 16)
    {
        if(road_delta > 0) road_delta--;
        else if(road_delta < 0) road_delta++;
    }
    
    if     (road_delta >=  3) road_vec[road_head] = road_vec[real_idx1] + 2;
    else if(road_delta >=  1) road_vec[road_head] = road_vec[real_idx1] + 1;
    else if(road_delta <= -3) road_vec[road_head] = road_vec[real_idx1] - 2;
    else if(road_delta <= -1) road_vec[road_head] = road_vec[real_idx1] - 1;
    else                      road_vec[road_head] = road_vec[real_idx1];
    
    if(road_vec[road_head] < -5) { road_vec[road_head] = -5; road_delta =  1; }
    if(road_vec[road_head] >  8) { road_vec[road_head] =  8; road_delta = -1; }
}

void draw_track(unsigned char yl, unsigned char xl, unsigned char xr)
{
    unsigned char i, left, right;
    unsigned int word;
    for(i = 0; i < 64; i += 2)
    {
        if(i < yl) continue;
        left  = 14 + road_get(i);
        right = left + track_width;
        if(left >= xl && left <= xr)
        {
            word = 0x8000 >> (left & 15);
            glcd_goto(i, left >> 4); glcd_dat(word>>8); glcd_dat(word);
        }
        if(right >= xl && right <= xr)
        {
            word = 0x8000 >> (right & 15);
            glcd_goto(i, right >> 4); glcd_dat(word>>8); glcd_dat(word);
        }
    }
}

bit is_left_pressed()
{
    p0_2 = 0;
    if(!p0_6) { p0_2 = 1; return 1; }
    p0_2 = 1; return 0;
}

bit is_right_pressed()
{
    p0_2 = 0;
    if(!p0_4) { p0_2 = 1; return 1; }
    p0_2 = 1; return 0;
}

void main()
{
    signed char amb_x;
    unsigned char left, right, i;
    unsigned char yl, xl, xr;

    player_x = 50; enemy_x = 50; enemy_y = -16;
    crashed = 0; road_delta = 0; night_km = 0; road_head = 0;
    for(i = 0; i < 16; i++) road_vec[i] = 0;

    glcd_init();

    while(1)
    {
        if(night_mode)
        {
            yl = 45 - HEADLIGHT_REACH;
            xl = player_x + 6 - HEADLIGHT_HALF;
            xr = player_x + 6 + HEADLIGHT_HALF;
        }
        else
        {
            yl = 0; xl = 0; xr = 127;
        }

        if(!crashed)
        {
            glcd_clear(); 
            update_track();

            if(is_left_pressed()  && player_x > 0)   player_x -= 3;
            if(is_right_pressed() && player_x < 112)  player_x += 3;

            if(enemy_y < 64) enemy_y += 3;

            km_tick++;
            if(km_tick >= 18)
            {
                km_tick = 0;
                km++;
                night_km++;
                if(night_km >= 20)
                {
                    night_km = 0;
                    night_mode = !night_mode;
                }
            }

            if(enemy_y >= 64)
            {
                enemy_y = -16;
                left    = 14 + road_vec[road_head];
                enemy_x = left + 8 + (km_tick < 18 ? km_tick : 0);
            }

            left  = 14 + road_get(45);
            right = left + track_width;
            if(player_x + 4 < left || player_x + 10 > right) crashed = 1;
            
            if(enemy_y + 11 > 44 && enemy_y < 56)
                if(player_x + 11 > enemy_x + 2 && player_x + 2 < enemy_x + 11)
                    crashed = 1;

            put_text();
            draw_track(yl, xl, xr);
            draw_sprite(enemy_x, enemy_y, car_enemy, 12, yl, 44, xl, xr);
            draw_sprite(player_x, 45, car_player, 12, 0, 63, 0, 127);
        }
        else
        {
            ac++;
            if(lives) lives--;

            if(lives == 0)
            {
                glcd_clear();
                glcd_cmd(0x30); glcd_cmd(0x88);
                glcd_dat('G'); glcd_dat('A'); glcd_dat('M'); glcd_dat('E'); glcd_dat(' ');
                glcd_dat('O'); glcd_dat('V'); glcd_dat('E'); glcd_dat('R');
                glcd_cmd(0x99);
                glcd_dat('K'); glcd_dat('M'); glcd_dat(':');
                put_num3(km);
                glcd_cmd(0x36);
                while(1);
            }

            amb_x = -16;
            while(amb_x < (signed char)player_x)
            {
                glcd_clear(); put_text();
                draw_track(0, 0, 127);
                draw_sprite(player_x, 45, spr_crash,  16, 0, 63, 0, 127);
                draw_sprite((unsigned char)amb_x, 37, ambulancia, 16, 0, 63, 0, 127);
                delay_ms(35);
                amb_x += 4;
            }
            glcd_clear(); put_text();
            draw_track(0, 0, 127);
            draw_sprite(player_x, 45, spr_crash,  16, 0, 63, 0, 127);
            draw_sprite(player_x, 37, ambulancia, 16, 0, 63, 0, 127);
            delay_ms(1200);

            player_x = 50; enemy_x = 50; enemy_y = -16;
            crashed = 0; road_delta = 0; road_head = 0;
            for(i = 0; i < 16; i++) road_vec[i] = 0;
        }
        
        // atraso
        delay_ms(18);
    }
}