#pragma once
#pragma once
#include "Alien.h"
//Cоздание наслденика класса Alien
class dAlien : public Alien
{
	dAlien();




private:



	float m_x = 0.0;
	float m_y = 0.0;
	float m_xSpeed = 0.0;
	float m_ySpeed = 0.0;


	int m_health = 5;

	const char m_symbol = 2;
	const char m_letter = 'd';

	const ConsoleColor m_color = ConsoleColor_Yellow;
	const ConsoleColor m_backgroundColor = ConsoleColor_Black;
};