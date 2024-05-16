#include "pch.h"
#include "Obstacle.h"
#include "utils.h"
using namespace utils;

Obstacle::Obstacle(const Point2f& position)
	:m_Position{ position }, m_Vertices{}, m_Rect{}
{
	m_Rect = Rectf{ m_Position.x, m_Position.y, 100.f, 100.f };

	Point2f leftBottom{ m_Position };
	Point2f leftTop{ m_Position.x, m_Position.y + m_Rect.height };
	Point2f rightTop{ m_Position.x + m_Rect.width, m_Position.y + m_Rect.height };
	Point2f rightBottom{ m_Position.x + m_Rect.width, m_Position.y };


	m_Vertices = std::vector<Point2f>{ leftBottom, leftTop, rightTop, rightBottom };
}

void Obstacle::Draw() const
{
	SetColor(Color4f{ 0.f, 0.f, 0.f, 1.f });
	FillRect(m_Rect);
}

const std::vector<Point2f>& Obstacle::GetVertices() const
{
	return m_Vertices;
}
