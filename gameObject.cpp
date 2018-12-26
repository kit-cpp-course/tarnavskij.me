#include "gameObject.h"

///class gameObject

GameObject::GameObject()
{
	m_type = GameObjectType_None;
	m_x      = 0.0;
	m_y      = 0.0;
	m_xSpeed = 0.0;
	m_ySpeed = 0.0;
	m_symbol = '?';
	m_health = 0;
	m_ts = false;
	m_color = ConsoleColor_White;
	m_backgroundColor = ConsoleColor_Black;
}

void GameObject::render(RenderSystem* rs)
{
	int row = int(m_y);
	int column = int(m_x);
	rs->drawChar(row, column, m_symbol, m_color, m_backgroundColor);
}

void GameObject::update(float dt)
{
	m_y += m_ySpeed * dt;
	m_x += m_xSpeed * dt;
}

bool GameObject::intersects(GameObject* object)
{
	if (int(m_x) == int(object->m_x)
		&& int(m_y) == int(object->m_y))
		return true;
	return false;
}