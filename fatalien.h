#pragma once
#include "Alien.h"
//Создание наслденика класса Alien
class fAlien : public Alien
{
	fAlien();




private:



	float m_x = 0.0;
	float m_y = 0.0;
	float m_xSpeed = 0.0;
	float m_ySpeed = 0.0;


	int m_health = 3;

	const char m_symbol = 2;
	const char m_letter = 'f';

	const ConsoleColor m_color = ConsoleColor_Red;
	const ConsoleColor m_backgroundColor = ConsoleColor_Black;
};