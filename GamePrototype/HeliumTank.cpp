#include "pch.h"
#include "HeliumTank.h"
#include "utils.h"
using namespace utils;

HeliumTank::HeliumTank(const Point2f& position)
	:m_Position{ position }, m_Vertices{}, m_Rect{}, m_HasBeenPickedUp{}
{
	m_Rect = Rectf{ m_Position.x, m_Position.y, 50.f, 50.f };

	Point2f leftBottom{ m_Position };
	Point2f leftTop{ m_Position.x, m_Position.y + m_Rect.height };
	Point2f rightTop{ m_Position.x + m_Rect.width, m_Position.y + m_Rect.height };
	Point2f rightBottom{ m_Position.x + m_Rect.width, m_Position.y };


	m_Vertices = std::vector<Point2f>{ leftBottom, leftTop, rightTop, rightBottom };
}

void HeliumTank::PickUp()
{
	m_HasBeenPickedUp = true;
}

void HeliumTank::Draw() const
{
	if (!m_HasBeenPickedUp)
	{
		SetColor(Color4f{ 0.f, 1.f, 0.f, 1.f });
		FillRect(m_Rect);
	}
}

const std::vector<Point2f>& HeliumTank::GetVertices() const
{
	return m_Vertices;
}
