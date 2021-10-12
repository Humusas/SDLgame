#include "GameObject.h"

GameObject::GameObject()
{
    m_angle = 0.0f;
}

const Vector2D& GameObject::GetPosition() const
{
    return m_position;
}

const Vector2D& GameObject::GetSize() const
{
    return m_size;
}

const std::string GameObject::GetTag() const
{
    return m_tag;
}

float GameObject::GetAngle() const
{
    return m_angle;
}

void GameObject::SetTag(const std::string& tag)
{
    m_tag = tag;
}

void GameObject::SetAngle(float angle)
{
    m_angle = angle;
}

void GameObject::SetPosition(int x, int y)
{
    m_position = { x, y };
}

void GameObject::SetPosition(const Vector2D& position)
{
    m_position = position;
}

void GameObject::SetSize(int width, int height)
{
    m_size = { width, height };
}

void GameObject::SetSize(const Vector2D& size)
{
    m_size = size;
}