

#include"game.h"
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include"level.h"
#include"imput.h"


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
				createObject(GameObjectType_Ship,
					(c + 0.5),
					r,
					GetRenderCellSymbol(cellCymbol),
					GetRenderCellSymbolColor(cellCymbol),
					GetRenderCellSymbolBackgroundColor(cellCymbol),
					true
					);
				break;
			}

			//create alien
			case cellSymbol_Alien:
			{
				GameObject* alien = createObject(GameObjectType_Alien,
					(c + 0.5),
					r,
					GetRenderCellSymbol(cellCymbol),
					GetRenderCellSymbolColor(cellCymbol),
					GetRenderCellSymbolBackgroundColor(cellCymbol),
					false
					);
				alien->setXSpeed(alienAmplitude*cos(m_alienAmplitudeTime));
				alien->setYSpeed(alienSpeed);
				alien->setHealth(alienHealth);
				break;

			}
			//create fatAlien
			case cellSymbol_FatAlien:
			{
				GameObject* fatAlien = createObject(GameObjectType_FatAlien,
					(c + 0.5),
					r,
					GetRenderCellSymbol(cellCymbol),
					GetRenderCellSymbolColor(cellCymbol),
					GetRenderCellSymbolBackgroundColor(cellCymbol),
					false
					);
				fatAlien->setXSpeed(alienAmplitude*cos(m_alienAmplitudeTime));
				fatAlien->setYSpeed(fatAlienSpeed);
				fatAlien->setHealth(fatAlienHealth);
				break;

			}

			case cellSymbol_DebuffAlien:
			{
				GameObject* DebuffAlien = createObject(GameObjectType_FatAlien,
					(c + 0.5),
					r,
					GetRenderCellSymbol(cellCymbol),
					GetRenderCellSymbolColor(cellCymbol),
					GetRenderCellSymbolBackgroundColor(cellCymbol),
					false
				);
				DebuffAlien->setXSpeed(alienAmplitude*cos(m_alienAmplitudeTime));
				DebuffAlien->setYSpeed(fatAlienSpeed);
				DebuffAlien->setHealth(fatAlienHealth);
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
	
	

	
	//c÷åò÷èê ÔÏÑ
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
	
    sprintf_s(buff, "Objs: %d  FPS: %d    SCORE: %d", objectCount,m_fps,m_score);
	m_renderSystem.drawText(0, 0, buff, ConsoleColor_Gray, ConsoleColor_Black);

	
	m_renderSystem.flush();
}

GameObject* Game::createObject (GameObjectType type, float x, float y, char symbol, ConsoleColor color, ConsoleColor bgColor, bool ts)
{
   

	for (int i = 0; i < gameObjectsCountMax; i++)
	{
		if (m_object[i] == 0)
		{
			GameObject* object = new GameObject();
			object->setType (type);
			object->setX ( x);
			object->setY ( y);
			object->setSymbol (symbol);
			object->setColor ( color);
			object->setBackgroundColor ( bgColor);
			

			m_object[i] = object;

			return object;
		}
	}

return 0;
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

			switch (object->getType() )
			{
			  
				
			  case GameObjectType_Ship:
			    {
                     
					if (object->getX() < 0)
						object->setX(0);
					if (object->getX() > screenColumns - 1)
						object->setX(screenColumns-1);
					
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
							m_shipFireCooldounTime = shipFireCooldown;

							GameObject* bullet = createObject(GameObjectType_Bullet,
								                              object->getX(),
								                              object->getY()-1,
								                              GetRenderCellSymbol(cellSymbol_Bullet),
								                              GetRenderCellSymbolColor(cellSymbol_Bullet),
								                              GetRenderCellSymbolBackgroundColor(cellSymbol_Bullet),
															  false);
							bullet->setYSpeed(-bulletSpeed);
							if ((object->getTripleShoot()))
							{
								GameObject* bullet = createObject(GameObjectType_Bullet,
									object->getX()-1,
									object->getY() - 1,
									GetRenderCellSymbol(cellSymbol_Bullet),
									GetRenderCellSymbolColor(cellSymbol_Bullet),
									GetRenderCellSymbolBackgroundColor(cellSymbol_Bullet),
									false);
								bullet->setYSpeed(-bulletSpeed);


							}


						}

					}
					
			    }
  

			  case GameObjectType_Bullet:
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
									  if (anotherObject->getHealth()-1 <= 0)
									  {
										  destroyObject(anotherObject);

										
										
										  m_score++;
										  									  
									  }
									  break;
								  }
							  }
							  if (anotherObject->getType() == GameObjectType_FatAlien)
							  {
								  if (anotherObject->intersects(object))
								  {
									  anotherObject->setHealth(anotherObject->getHealth() - 1);
									  destroyObject(object);
									  if (anotherObject->getHealth() <= 0)
									  {
										  if(rand() % 10 + 1<5)
										  {
											  GameObject* TripleShoot = createObject(GameObjectType_TripleShoot,
												  anotherObject->getX(),
												  anotherObject->getY(),
												  GetRenderCellSymbol(cellSymbol_TripleShoot),
												  GetRenderCellSymbolColor(cellSymbol_TripleShoot),
												  GetRenderCellSymbolBackgroundColor(cellSymbol_TripleShoot),
												  false);
											  TripleShoot->setYSpeed(+tripleShootSpeed);
										  }
										  destroyObject(anotherObject);

										 



										  m_score+=3;


									  }
									  break;
								  }
							  }
						  }
					  }
				  }
				  break;
			  }
			  
			  case GameObjectType_TripleShoot:
			  {
				  if (object->getY() < 0)
				  {
					  destroyObject(object);
				  }
				  
				  {
					  for (int e = 0; e < 32; e++)
					  {
						  GameObject* anotherObject = m_object[e];

						  if (object->getType() == GameObjectType_Ship)
						  {
							  anotherObject->setTripleShoot(true);

						  }
					  }
				  }
			  }
				
			  case GameObjectType_Alien:
			    {
				  haveAlifeAliens = true;
				  if (object->getY() >= screenRows)
					  m_isGameActive = false;
				  else
					object->setXSpeed(alienAmplitude * cos(m_alienAmplitudeTime));
                  break;
			    }
				
			  case GameObjectType_FatAlien:
			  {
				  haveAlifeAliens = true;
				  if (object->getY() >= screenRows)
					  m_isGameActive = false;
				  else
					  object->setXSpeed(alienAmplitude * cos(m_alienAmplitudeTime));
				  break;
			  }
				
			}
		}
	}

	if (m_shipFireCooldounTime > 0.0)
		m_shipFireCooldounTime -= dt;

	
	m_alienAmplitudeTime += dt;

	


	if (!haveAlifeAliens)
	{
		
			
	   m_isGameActive = false;
	}


}

