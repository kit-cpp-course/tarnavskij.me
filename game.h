#pragma once

#include<ctime>
#include"renderSystem.h"
#include"gameObject.h"


///constants
const int gameObjectsCountMax = 512;


///class game

class Game
{
public:


	Game();//Конструктор

	void difficulLevel();//Выбор сложности
	void setup();
	void initialize();//Начальные параметры консоли.
	bool frame();//Кадры
	void shutdown();//Выключение
	char m_levelNumber = 0;

private:
	void render();
	void update(float dt);

	GameObject* createObject(GameObjectType type, float x, float y, char symbol, ConsoleColor color, ConsoleColor bgColor, bool ts);
    void destroyObject(GameObject* object);

private:


	bool m_isGameActive;
	clock_t m_clockLastFrame;

	int m_fps = 0;
	int m_framesCounter = 0;
	float  m_framesTimeCounter = 0.0;
	int m_score = 0;

	RenderSystem m_renderSystem;

	GameObject* m_object[gameObjectsCountMax];

	float m_shipFireCooldounTime;
	float m_alienAmplitudeTime;
};

