#pragma once

#include "renderSystem.h"

enum GameObjectType //перечисление всех игровых объектов
{
	GameObjectType_None,
	GameObjectType_Ship,
	GameObjectType_Bullet,
	GameObjectType_Alien,
	GameObjectType_FatAlien,
	GameObjectType_DebuffAlien,
	GameObjectType_TripleShoot,


};

//класс игровых объектов

class GameObject
{
public:
	GameObject();
	void render(RenderSystem* rs);
	void update(float dt);//Управление нашим кораблем

	bool intersects(GameObject* object);

	void setType(GameObjectType type) { m_type = type; } 
	GameObjectType getType() { return m_type; }

	void setX(float x) { m_x = x; }
	float getX() { return m_x; }

	void setY(float y) { m_y = y; }
	float getY() { return m_y; }

	void setXSpeed(float x) { m_xSpeed = x; }
	float getXSpeed() { return m_xSpeed; }

	void setYSpeed(float y) { m_ySpeed = y; }
	float getYSpeed() { return m_ySpeed; }

	void setHealth(int h) { m_health = h; }
	int getHealth() { return m_health; }

	void setSymbol(char symbol) { m_symbol = symbol; }
	char getSymbol() { return m_symbol; }

	void setTripleShoot(bool ts) { m_ts = ts; }
	bool getTripleShoot() { return m_ts; }


	void setColor(ConsoleColor color) { m_color = color; }
	ConsoleColor getColor() { return m_color; }

	void setBackgroundColor(ConsoleColor color) { m_backgroundColor = color; }
	ConsoleColor getBackgroundColor() { return m_backgroundColor; }



   private:

	   GameObjectType m_type;

	   float m_x;
	   float m_y;
	   float m_xSpeed;
	   float m_ySpeed;

	   bool m_ts;
	   int m_health;

	   char m_symbol;

	   ConsoleColor m_color;
	   ConsoleColor m_backgroundColor;
};

