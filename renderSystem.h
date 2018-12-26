#pragma once

#include<Windows.h>
#include"consoleColor.h"

/////constants

const int screenRows = 25;//������� �������.
const int screenColumns = 80;


///struct

struct ConsoleSymbolData
{
	char symbol;
	ConsoleColor symbolColor;
	ConsoleColor backgroundColor;
};

class RenderSystem
{
public:
	RenderSystem();
	
	void initialize();//���������� �������, ��������� �������� ������
	void clear();//������� �������� ������
	void drawChar(int r, int c, char symbol, ConsoleColor symbolColor, ConsoleColor backgroundColor);//��������� �������� ������ �� 0-��
	void drawText(int r, int c, const char* text, ConsoleColor symbolColor, ConsoleColor backgroundColor);//������ ������ �������� , ������� � ������ �� ������ r � ������� c � ������ ������.
	void flush();//��������� ������������ ��������


private:
	void setConsoleCursor(int r, int c);
	void setConsoleColor(ConsoleColor symbolColor, ConsoleColor backgroundColor);

private:
	HANDLE m_consoleHandle;
	ConsoleSymbolData m_backBuffer[screenRows][screenColumns];//������� �����
	ConsoleSymbolData m_screenBuffer[screenRows][screenColumns];//������ ����� ����� � �������
};

