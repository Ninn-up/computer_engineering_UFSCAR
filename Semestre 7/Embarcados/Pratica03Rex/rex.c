#include<reg51.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
	
sbit P00 = P0^0;
sbit P01 = P0^1;
sbit P02 = P0^2;
sbit P03 = P0^3;
sbit P04 = P0^4;
sbit P05 = P0^5;
sbit P06 = P0^6;

const char idata DINO_CHAR_DATA[8] = {
	0x00,
	0x03,
	0x07,
	0x0e,
	0x0f,
	0xfe,
	0x0e,
	0x0a
};

const char idata CLOUD_CHAR_DATA[8] = {
	0x00,
	0x06,
	0x09,
	0x11,
	0x0e,
	0x00,
	0x00,
	0x00
};


const char idata CACTUS_CHAR_DATA[8] = {
	0x00,
	0x04,
	0x15,
	0xff,
	0x0e,
	0x04,
	0x04,
	0x04
};



#define CHAR_DINO '\x01'
#define CHAR_CLOUD '\x02'
#define CHAR_CACTUS '\x03'
#define CHAR_EMPTY ' '

char idata charMap[5] = {
	0x00,
	0x05,
	0x06,
	0x07,
	0xff
};


sfr LCD_Port=0x90; // Porta P1 como porta de dados
sbit rs=P1^3;
//sbit rw=P1^1;
sbit en=P1^2;

//sbit Jump = P1^4;

char clouds[17] = "";
char cactuses[17] = "";


int y = 0;


void delay(unsigned int count) // Garante delay de approx. 1ms
{
	int i, j;
	for(i=0;i<count;i++)
		for(j=0;j<112;j++);
	
}

void invertChar(char* out, const char* charData)
{
	int i = 0;
	for(i = 0; i < 8; i++)
		out[i] = 0xff ^ charData[i];
}

void LCD_Command(char cmnd) // LCD16x2 command function
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
	rs=0;
	//rw=0;
	en=1;
	delay(1);
	en=0;
	delay(2);
	
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);
	en=1;
	delay(1);
	en=0;
	delay(5);

}

void LCD_Char(char char_data) // LCD data write function
{
	LCD_Port = (LCD_Port & 0x0F) | (char_data & 0xF0);
	rs=1;
	//rw=0;
	en=1;
	delay(1);
	en=0;
	delay(2);
	
	LCD_Port = (LCD_Port & 0x0F) | (char_data << 4);
	en=1;
	delay(1);
	en=0;
	delay(5);
	
}

void LCD_String(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy(char row, char pos, char *str)
{
	if (row == 0)
		LCD_Command((pos & 0x0F) | 0x80);
	else if (row == 1)
		LCD_Command((pos & 0x07) | 0xC0);
	
	LCD_String(str);
}



void LCD_Init(void) // Initialize Function
{
	delay(20);
	LCD_Command(0x02); // Return to home
	LCD_Command(0x28); // Display mode
	LCD_Command(0x0C); // Display on/off
	LCD_Command(0x06); // Cursor auto-increments after each character
	LCD_Command(0x01); // Clear display
	LCD_Command(0x80); // Set SSRAM address

}

void LCD_send_char(char* customChar, char pos)
{
	int i = 0;
	
	LCD_Command(0x40 + (pos << 3));
	
	for(i = 0; i < 8; i++)
		LCD_Char(customChar[i]);
}


void shiftLeft(char* str, int len, char lastChar)
{
	int i;
	for(i = 0; i < (len - 1); i++)
	{
		str[i] = str[i+1];
	}

	str[len - 1] = lastChar;
}



char topLine[17] = {' '};
char bottomLine[17] = {' '};

void custom_itoa(int score, char* buf) {
    //buf[0] = (score / 1000) % 10 + '0';
    buf[0] = (score / 100)  % 10 + '0';
    buf[1] = (score / 10)   % 10 + '0';
    buf[2] = (score)        % 10 + '0';
    //buf[4] = '\0';
}

void render(char* top, char* bottom, const int y, const char* clouds, const char* cactuses, int score, int reversed)
{
	int i = 0;
	char scoreChr[4] = "";
	unsigned char score_len = 0;
	memcpy(top, clouds, 16);
	memcpy(bottom, cactuses, 16);

	if(y == 1)
		top[1] = CHAR_DINO;
	else
		bottom[1] = CHAR_DINO;
	
	if(reversed){
		for(i = 0; i < 16; i++)
		{
			top[i] = charMap[top[i]];
			bottom[i] = charMap[bottom[i]];
		}
	}
	
	custom_itoa(score, scoreChr);
	memcpy(top + 13, scoreChr, 4);
}

char genEnemy(void) 
{
	bool chance_vazio = rand() > (3 * RAND_MAX / 4);
	
	if (!chance_vazio) 
	{
		if (rand() > (RAND_MAX / 2))
		{
			return CHAR_CLOUD;
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

void main()
{
	char idata tmpCustomChar[8];
	char tempEnemy = ' ';
	int clock = 0;
	int score;
	bool alive = 1;
	int jump = 0;
	int jumpClock = 0;
	int i = 0;
	/*
	char customChar[] = {
		0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00
	};*/
	
	
	LCD_Init();
	
	for (i = 0; i < 17; i++) 
	{
		//tempEnemy = genEnemy();
		shiftLeft(clouds, 17, CHAR_EMPTY);
		shiftLeft(cactuses, 17, CHAR_EMPTY);
	}
	
	//LCD_send_char(customChar, '\x00');
	LCD_send_char(DINO_CHAR_DATA, CHAR_DINO);
	LCD_send_char(CLOUD_CHAR_DATA, CHAR_CLOUD);
	LCD_send_char(CACTUS_CHAR_DATA, CHAR_CACTUS);
	//LCD_send_char(EMPTY_CHAR_DATA, CHAR_EMPTY);
	
	invertChar(tmpCustomChar, DINO_CHAR_DATA);
	LCD_send_char(tmpCustomChar, CHAR_DINO + 4);
	invertChar(tmpCustomChar, CLOUD_CHAR_DATA);
	LCD_send_char(tmpCustomChar, CHAR_CLOUD + 4);
	invertChar(tmpCustomChar, CACTUS_CHAR_DATA);
	LCD_send_char(tmpCustomChar, CHAR_CACTUS + 4);
	
	
	LCD_Command(0x80);
	
	
	listenButtons();
	
	score = 0;
	clock = 0;
		
	do{
		jump = !P04 || !P05 || !P06;
		if(jump && (jumpClock == 0))
		{
			jumpClock = 3;
		}
		
		if(clock >= 20)
		{
			if(jumpClock) {jumpClock -= 1;};
			clock = 0;
			tempEnemy = genEnemy();
		  shiftLeft(clouds, 17, tempEnemy == CHAR_CLOUD ? CHAR_CLOUD : CHAR_EMPTY);
		  shiftLeft(cactuses, 17, tempEnemy == CHAR_CACTUS ? CHAR_CACTUS : CHAR_EMPTY);
			score++;
		}
		clock+=score + 15;
		//score++;
		
		
		if(jumpClock == 0)
		{
			if(cactuses[1] != CHAR_EMPTY)
			{
				alive = 0;
			}
		}
		
		render(topLine, bottomLine, jumpClock > 0, clouds, cactuses, score, score & 0x20);
		
		
		//LCD_Command(0x08);
		//LCD_Command(0x80);
		LCD_String_xy(0, 0, topLine);
		LCD_String_xy(1, 0, bottomLine);
		//LCD_Command(0x0C);
		//LCD_Command(0x80);
		
	}while(alive || jump);
	
	LCD_String_xy(0, 0, "Voce perdeu!");
	LCD_String_xy(1, 0, "Tente novamente!");
	
	while(!jump){
		jump = !P04 || !P05 || !P06;}

	
	delay(30);
	
}