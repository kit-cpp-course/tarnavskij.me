#pragma once
#include "GameObject.h"

//Класс отвечающий за персонажа игрока

class Ship : virtual public GameObject
{
	Ship();
	char getLetter() { return m_letter; }

	void setX(float x) { m_x = x; }
	float getX() { return m_x; }

	void setY(float y) { m_y = y; }
	float getY() { return m_y; }

	void setXSpeed(float x) { m_xSpeed = x; }
	float getXSpeed() { return m_xSpeed; }

	void setYSpeed(float y) { m_ySpeed = y; }
	float getYSpeed() { return m_ySpeed; }


	char getSymbol() { return m_symbol; }

	ConsoleColor getColor() { return m_color; }


	ConsoleColor getBackgroundColor() { return m_backgroundColor; }

private:



	float m_x = 0.0;
	float m_y = 0.0;
	float m_xSpeed = 0.0;
	float m_ySpeed = 0.0;

	const char m_letter = 's';
	const char m_symbol = 202;

	const ConsoleColor m_color = ConsoleColor_DarkGray;
	const ConsoleColor m_backgroundColor = ConsoleColor_White;
};