#pragma once

#include<Windows.h>
#include"consoleColor.h"

/////constants

const int screenRows = 25;//размеры консоли.
const int screenColumns = 80;




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

	void initialize();//Дескриптор консоли, начальные значения буфера
	void clear();//Очистка рабочего буфера
	void drawChar(int r, int c, char symbol, ConsoleColor symbolColor, ConsoleColor backgroundColor);//отрисовка символов вплоть до 0-го
	void drawText(int r, int c, const char* text, ConsoleColor symbolColor, ConsoleColor backgroundColor);//запись строки символов , начиная с ячейки на строке r и столбце c и дальше вправо.
	void flush();//отрисовка изменивщихся объектов


private:
	void setConsoleCursor(int r, int c);
	void setConsoleColor(ConsoleColor symbolColor, ConsoleColor backgroundColor);

private:
	HANDLE m_consoleHandle;
	ConsoleSymbolData m_backBuffer[screenRows][screenColumns];//рабочий буфер
	ConsoleSymbolData m_screenBuffer[screenRows][screenColumns];//полная копия ячеек в консоли
};
