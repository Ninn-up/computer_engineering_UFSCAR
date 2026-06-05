#include <reg52.h>
#include <intrins.h>
#include <stdlib.h>
#include <string.h>

#define GlcdDataBus P3
sbit RS  = P2^0; 
sbit RW  = P2^1; 
sbit EN  = P2^2; 
sbit PSB = P2^3; 
sbit RST = P2^5;

// Pinos dos Botões
sbit P00 = P0^0;
sbit P01 = P0^1;
sbit P02 = P0^2;
sbit P03 = P0^3;
sbit P04 = P0^4;
sbit P05 = P0^5;
sbit P06 = P0^6;

// Caracteres
#define CHAR_EMPTY ' '
#define CHAR_DINO 'D'
#define CHAR_CACTUS 'C'
#define CHAR_BIRD 'B'

// Sprites 8x8 em ROM
unsigned char code sprite_dino[8]   = {0x07, 0x05, 0x07, 0x16, 0x1F, 0x0E, 0x0A, 0x0A};
unsigned char code sprite_cactus[8] = {0x04, 0x05, 0x15, 0x15, 0x1F, 0x04, 0x04, 0x04};
unsigned char code sprite_bird[8]   = {0x00, 0x24, 0x3C, 0x1E, 0x0E, 0x04, 0x00, 0x00};

// Fonte Numérica para desenhar a pontuação na tela gráfica
unsigned char code sprite_nums[10][8] = {
    {0x00, 0x1C, 0x22, 0x26, 0x2A, 0x32, 0x22, 0x1C}, // 0
    {0x00, 0x08, 0x18, 0x08, 0x08, 0x08, 0x08, 0x1C}, // 1
    {0x00, 0x1C, 0x22, 0x02, 0x0C, 0x10, 0x20, 0x3E}, // 2
    {0x00, 0x1C, 0x22, 0x02, 0x0C, 0x02, 0x22, 0x1C}, // 3
    {0x00, 0x04, 0x0C, 0x14, 0x24, 0x3E, 0x04, 0x04}, // 4
    {0x00, 0x3E, 0x20, 0x3C, 0x02, 0x02, 0x22, 0x1C}, // 5
    {0x00, 0x1C, 0x22, 0x20, 0x3C, 0x22, 0x22, 0x1C}, // 6
    {0x00, 0x3E, 0x02, 0x04, 0x08, 0x10, 0x10, 0x10}, // 7
    {0x00, 0x1C, 0x22, 0x22, 0x1C, 0x22, 0x22, 0x1C}, // 8
    {0x00, 0x1C, 0x22, 0x22, 0x1E, 0x02, 0x22, 0x1C}  // 9
};

char topLine[16];
char bottomLine[16];

void DelayMs(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 112; j++);
}

void GLCD_Command(unsigned char cmd) {
    RS = 0; RW = 0;
    GlcdDataBus = cmd;
    EN = 1; DelayMs(1); EN = 0;
    DelayMs(1);
}

void GLCD_Data(unsigned char dat) {
    RS = 1; RW = 0;
    GlcdDataBus = dat;
    EN = 1; DelayMs(1); EN = 0;
    DelayMs(1);
}

void GLCD_ClearGDRAM() {
    unsigned char x, y;
    for(y = 0; y < 64; y++) {
        if(y < 32) {
            GLCD_Command(0x80 | y);
            GLCD_Command(0x80);
        } else {
            GLCD_Command(0x80 | (y - 32));
            GLCD_Command(0x88);
        }
        for(x = 0; x < 16; x++) {
            GLCD_Data(0x00);
        }
    }
}

void GLCD_Init() {
    PSB = 1;
    RST = 0; DelayMs(10); RST = 1; DelayMs(50);
    
    GLCD_Command(0x30); DelayMs(1);
    GLCD_Command(0x0C); DelayMs(1);
    GLCD_Command(0x01); DelayMs(10);
    
    GLCD_Command(0x34); DelayMs(1);
    GLCD_ClearGDRAM();
    GLCD_Command(0x36); DelayMs(1);
}

void GLCD_RenderRow(unsigned char pixel_y, char *line_data) {
    unsigned char i, w;
    unsigned char l_char, r_char, l_byte, r_byte;
    
    for(i = 0; i < 8; i++) {
        unsigned char curr_y = pixel_y + i;
        unsigned char base_y = curr_y;
        unsigned char start_x = 0;
        
        if(curr_y >= 32) {
            base_y = curr_y - 32;
            start_x = 8;
        }
        
        GLCD_Command(0x80 | base_y);
        GLCD_Command(0x80 | start_x);
        
        for(w = 0; w < 8; w++) {
            l_char = line_data[w*2];
            r_char = line_data[w*2 + 1];
            
            if(l_char == CHAR_DINO) l_byte = sprite_dino[i];
            else if(l_char == CHAR_CACTUS) l_byte = sprite_cactus[i];
            else if(l_char == CHAR_BIRD) l_byte = sprite_bird[i];
            else if(l_char >= '0' && l_char <= '9') l_byte = sprite_nums[l_char - '0'][i];
            else l_byte = 0x00;
            
            if(r_char == CHAR_DINO) r_byte = sprite_dino[i];
            else if(r_char == CHAR_CACTUS) r_byte = sprite_cactus[i];
            else if(r_char == CHAR_BIRD) r_byte = sprite_bird[i];
            else if(r_char >= '0' && r_char <= '9') r_byte = sprite_nums[r_char - '0'][i];
            else r_byte = 0x00;
            
            GLCD_Data(l_byte);
            GLCD_Data(r_byte);
        }
    }
}

void shiftLeft(char* str, int len, char lastChar) {
    int i;
    for(i = 0; i < (len - 1); i++) {
        str[i] = str[i+1];
    }
    str[len - 1] = lastChar;
}

void custom_itoa(int score, char* buf) {
    if(score < 0) score = 0;
    buf[0] = (score / 100) % 10 + '0';
    buf[1] = (score / 10)  % 10 + '0';
    buf[2] = (score)       % 10 + '0';
}

// define quantos inimigos vão aparecer
char genEnemy(void) {
    int chance = rand();
    if (chance > (RAND_MAX / 2)) {
        if (rand() > ((RAND_MAX / 4) * 3)) {
            return CHAR_BIRD;
        }
        return CHAR_CACTUS;
    }
    return CHAR_EMPTY;
}

void listenButtons(){
    P03 = 0;
    P02 = 0;
    P01 = 0;
    P00 = 0;
}

void main() {   
    int clock = 0;
    int speed = 5; 
    int score = 0; 
    int current_delay = 40;
    int obstacle_cooldown = 0; 
    
    bit alive = 1;
    bit is_jumping = 0;
    char tempEnemy = CHAR_EMPTY;
    char backup_top, backup_bot;
    char backup_s1, backup_s2, backup_s3; 
    bit btn_pressed;
    char scoreStr[3];
    
    GLCD_Init();
    listenButtons();
    
    memset(topLine, CHAR_EMPTY, 16);
    memset(bottomLine, CHAR_EMPTY, 16);
    
    while(1) {
        btn_pressed = !P04 || !P05 || !P06;
        
        // se morrer, a tela é congelada
        if(!alive) {
            if(btn_pressed) {
                alive = 1;
                clock = 0;
                score = 0; 
                obstacle_cooldown = 0; // Zera o cooldown ao recomeçar
                memset(topLine, CHAR_EMPTY, 16);
                memset(bottomLine, CHAR_EMPTY, 16);
                DelayMs(200);
            }
            continue;
        }
        
        // pulo
        is_jumping = btn_pressed;
        
				// pontuação (decrescimo)
        if (is_jumping) {
            score--; 
            if (score <= 0) {
                score = 0;
                alive = 0; 
            }
        } else {
            if (score < 999) score++; 
        }

        // aceleração
        current_delay = 40 - ((score / 50) * 4);
        if (current_delay < 15) current_delay = 15; 

        // deslocamento
        if(clock >= 20) {
            clock = 0;
            shiftLeft(topLine, 16, CHAR_EMPTY);
            shiftLeft(bottomLine, 16, CHAR_EMPTY);
            
            // evita muitos obstáculos por segundo
            if (obstacle_cooldown > 0) {
                obstacle_cooldown--;
            } else {
                tempEnemy = genEnemy();
                
                if(tempEnemy == CHAR_BIRD) {
                    topLine[15] = CHAR_BIRD;
                    obstacle_cooldown = 4; // espera 4 espaços após um pássaro
                }
                else if(tempEnemy == CHAR_CACTUS) {
                    bottomLine[15] = CHAR_CACTUS;
                    obstacle_cooldown = 3; // espera 3 espaços após um cacto
                }
            }
        }
        clock += speed; 
        
        // colisao
        if(!is_jumping && bottomLine[1] == CHAR_CACTUS) alive = 0;
        if(is_jumping && topLine[1] == CHAR_BIRD) alive = 0;
        
        // renderização
        backup_top = topLine[1];
        backup_bot = bottomLine[1];
        backup_s1  = topLine[12];
        backup_s2  = topLine[13];
        backup_s3  = topLine[14];
        
        if(is_jumping) topLine[1] = CHAR_DINO;
        else bottomLine[1] = CHAR_DINO;
        
        custom_itoa(score, scoreStr);
        memcpy(topLine + 12, scoreStr, 3);
        
        GLCD_RenderRow(20, topLine);
        GLCD_RenderRow(48, bottomLine);
        
        topLine[1] = backup_top;
        bottomLine[1] = backup_bot;
        topLine[12] = backup_s1;
        topLine[13] = backup_s2;
        topLine[14] = backup_s3;
        
        DelayMs(current_delay); 
    }
}