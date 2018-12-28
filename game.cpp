#include"game.h"
#include"Alien.h"
#include"ship.h"
#include"Shoot.h"
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include"level.h"
#include"imput.h"
#include "draw.h"


////class Game

Game::Game()
{
	m_isGameActive = true;
	m_clockLastFrame = 0;





	for (int i = 0; i < gameObjectsCountMax; i++)
		m_object[i] = 0;

	m_shipFireCooldounTime = 0.0;
	m_alienAmplitudeTime = 0.0;

}


void Game::difficulLevel()
{
	printf("Set difficul level 1:Easy 2:Normal 3:Hardcore\n");
	scanf("%c", m_levelNumber);
	m_renderSystem.clear();
}

void Game::setup()
{
	srand(time(0));
	m_renderSystem.initialize();
}

void Game::initialize()
{
	m_shipFireCooldounTime = 0.0;
	m_alienAmplitudeTime = 0.0;


	//load level

	for (int r = 0; r < levelRows; r++)
	{
		for (int c = 0; c < levelColumns; c++)
		{

			unsigned char cellCymbol;

			switch (m_levelNumber)
			{
			case 1:
			{
				cellCymbol = levelDataEasy[r][c];
				break;
			}
			case 2:
			{
				cellCymbol = levelDataNormal[r][c];
				break;
			}
			case 3:
			{
				cellCymbol = levelDataHard[r][c];
				break;
			}


			}
			switch (cellCymbol)
			{
				//create ship
			case cellSymbol_Ship:
			{
				draw(ship.getSymbol(), ship.getColor(), ship.getBackgroundColor());
				break;
			}

			//create alien
			case cellSymbol_Alien:
			{
			 
				draw(alien.getSymbol(), alien.getColor(), alien.getBackgroundColor());
				break;

			}
			//create fatAlien
			case cellSymbol_FatAlien:
			{
				draw(falien.getSymbol(), falien.getColor(), falien.getBackgroundColor());
				
				break;

			}

			case cellSymbol_DebuffAlien:
			{
				draw(dalien.getSymbol(), dalien.getColor(), dalien.getBackgroundColor());
				
				break;

			}

			}
		}

	}

}

bool Game::frame()
{

	clock_t clockNow = clock();
	clock_t deltaClock = clockNow - m_clockLastFrame;
	float deltaTime = float(deltaClock) / CLOCKS_PER_SEC;
	m_clockLastFrame = clockNow;




	//cчетчик ФПС
	m_framesCounter++;
	m_framesTimeCounter += deltaTime;
	if (m_framesTimeCounter >= 1.0)
	{
		m_framesTimeCounter -= 1.0;
		m_fps = m_framesCounter;
		m_framesCounter = 0;

	}

	render();
	update(deltaTime);


	return m_isGameActive;
}

void Game::shutdown()
{
	for (int i = 0; i < gameObjectsCountMax; i++)
	{
		if (m_object[i] != 0)
		{
			delete m_object[i];
			m_object[i] = 0;
		}
	}
}

void Game::render()
{
	//start frame
	m_renderSystem.clear();

	//deaw all game object

	int objectCount = 0;

	for (int i = 0; i < gameObjectsCountMax; i++)
	{
		if (m_object[i] != 0)
		{
			m_object[i]->render(&m_renderSystem);
			objectCount++;
		}
	}



	char buff[64];

	sprintf_s(buff, "Objs: %d  FPS: %d    SCORE: %d", objectCount, m_fps, m_score);
	m_renderSystem.drawText(0, 0, buff, ConsoleColor_Gray, ConsoleColor_Black);


	m_renderSystem.flush();
}



void Game::destroyObject(GameObject* object)
{
	for (int i = 0; i < gameObjectsCountMax; i++)
	{
		if (m_object[i] == object)
		{
			delete m_object[i];
			m_object[i] = 0;
			return;
		}
	}
}

void Game::update(float dt)
{


	bool haveAlifeAliens = false;


	for (int i = 0; i < gameObjectsCountMax; i++)
	{
		GameObject* object = m_object[i];
		if (object != 0)
		{
			object->update(dt);

			switch (object->getletter())
			{


			case 's':
			{

				if (object->getX() < 0)
					object->setX(0);
				if (object->getX() > screenColumns - 1)
					object->setX(screenColumns - 1);

				if (isKeyDown(VK_LEFT))
					object->setXSpeed(-shipSpeed);
				else
				{
					if (isKeyDown(VK_RIGHT))
						object->setXSpeed(shipSpeed);
					else
						object->setXSpeed(0.0);
				}

				if (isKeyDown(VK_UP))
				{
					if (m_shipFireCooldounTime <= 0.0)
					{
						m_shipFireCooldounTime = ship.FireCooldown;

						creationC(float x, float y);
							false);
						bullet->setYSpeed(-bulletSpeed);
						if ((object->getTripleShoot()))
						{
							creationC(float x, float y);
							bullet->setYSpeed(-bulletSpeed);


						}


					}

				}

			}


			case 'c':
			{
				if (object->getY() < 0)
				{
					destroyObject(object);
				}
				else
				{
					for (int e = 0; e < gameObjectsCountMax; e++)
					{
						GameObject* anotherObject = m_object[e];

						if (anotherObject != 0)
						{
							if (anotherObject->getType() == GameObjectType_Alien)
							{
								if (anotherObject->intersects(object))
								{

									destroyObject(object);
									if (anotherObject->getHealth() - 1 <= 0)
									{
										destroyObject(anotherObject);



										m_score++;

									}
									break;
								}
							}
							if (anotherObject->getchar() == GameObjectType_FatAlien)
							{
								if (anotherObject->intersects(object))
								{
									anotherObject->setHealth(anotherObject->getHealth() - 1);
									destroyObject(object);
									if (anotherObject->getHealth() <= 0)
									{
										if (rand() % 10 + 1<5)
										{
											creationBonus(float x, float y)
										}
										destroyObject(anotherObject);





										m_score += 3;


									}
									break;
								}
							}
						}
					}
				}
				break;
			}




	if (!haveAlifeAliens)
	{


		m_isGameActive = false;
	}


}