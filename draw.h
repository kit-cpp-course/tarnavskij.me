#pragma once
//Класс отвечающий за отрисовку
class draw {
	draw(char CellSymbol, char Color, char BackColor);
	char GetRenderCellSymbol(unsigned char CellSymbol);
	char GetRenderCellSymbolColor(unsigned char Color);
	char GetRenderCellSymbolBackgroundColor(unsigned char BackColor);


};