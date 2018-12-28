#pragma once
#include "GameObject.h"

class Alien : virtual public GameObject //Класс отвечает за создание противников.
{
	Alien();
	char getLetter() { return m_letter; }

	void setX(float x) { m_x = x; }
	float getX() { return m_x; }

	void setY(float y) { m_y = y; }
	float getY() { return m_y; }

	void setHealth(int h) { m_health = h; }
	int getHealth() { return m_health; }

	void setXSpeed(float x) { m_xSpeed = x; }
	float getXSpeed() { return m_xSpeed; }

	void setYSpeed(float y) { m_ySpeed = y; }
	float getYSpeed() { return m_ySpeed; }


	char getSymbol() { return m_symbol; }

	ConsoleColor getColor() { return m_color; }


	ConsoleColor getBackgroundColor() { return m_backgroundColor; }



private:



	float m_x=0.0;//координаты
	float m_y=0.0;
	float m_xSpeed=0.0;//Скорость передвижения по координатам
	float m_ySpeed=0.0;


	int m_health=1;//Здоровье 

	const char m_symbol=2;//символ в консольной графике

	const ConsoleColor m_color=ConsoleColor_Green;//его цвет
	const ConsoleColor m_backgroundColor=ConsoleColor_Black;//цвет заднего фона
};





