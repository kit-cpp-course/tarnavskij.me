#include "gameObject.h"

///class gameObject

GameObject::GameObject()
{
	
}

void GameObject::render(RenderSystem* rs)
{
	int row = int(m_y);
	int column = int(m_x);
	rs->drawChar(row, column)
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