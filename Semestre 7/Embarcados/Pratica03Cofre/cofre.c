void LCD_init(void)
{
	delay(20);
	LCD_Command(0x02);
	LCD_Command(0x28);
	LCD_Command(0x0C);
	LCD_Command(0x06);
	LCD_Command(0x01);
	LCD_Command((0x80);
}
	
void LCD_Command