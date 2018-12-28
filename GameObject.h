#pragma once

#include "renderSystem.h"
#include"ConsoleColor.h"



//класс абстрактный игровых объектов


	class GameObject
	{
	public:
		void render(RenderSystem* rs);
		void GameObject::render(RenderSystem* rs);
		void GameObject::update(float dt);
		bool GameObject::intersects(GameObject* object);
		

		virtual float x() const = 0;//Функции , которые имеют все игровые объекты
		virtual float y() const = 0;
		virtual float xSpeed() const = 0;
		virtual float ySpeed() const = 0;

		virtual  char symbol() const = 0;

		virtual ConsoleColor color()const =0;
		virtual ConsoleColor backgroundColor() const = 0;
	};




