#include "pch.h"
#include "Obstacle.h"
#include "utils.h"
using namespace utils;

Obstacle::Obstacle(const Point2f& position)
	:m_Position{ position }, m_Vertices{}, m_Rect{}, m_Rotation{ float(rand() % 6) }, m_RotationSpeed{ 0.5f }
{
	m_Rect = Rectf{ m_Position.x, m_Position.y, 50.f, 50.f };

	Point2f leftBottom{ m_Position };
	Point2f leftTop{ m_Position.x, m_Position.y + m_Rect.height };
	Point2f rightTop{ m_Position.x + m_Rect.width, m_Position.y + m_Rect.height };
	Point2f rightBottom{ m_Position.x + m_Rect.width, m_Position.y };


	m_Vertices = std::vector<Point2f>{ leftBottom, leftTop, rightTop, rightBottom };
}

void Obstacle::Update(float elapsedSec)
{
	m_Rotation += m_RotationSpeed * elapsedSec;
	UpdateVertices();
}

void Obstacle::Draw() const
{
	SetColor(Color4f{ 0.f, 0.f, 0.f, 1.f });
	FillPolygon(m_Vertices);
}

const std::vector<Point2f>& Obstacle::GetVertices() const
{
	return m_Vertices;
}

void Obstacle::UpdateVertices()
{
	Point2f middle{ m_Position.x + m_Rect.width / 2.f, m_Position.y + m_Rect.height / 2.f };
	m_Vertices[0] = Point2f{middle.x + (m_Rect.width / 2.f) * cosf(m_Rotation),
							middle.y + (m_Rect.height / 2.f) * sinf(m_Rotation) };
	m_Vertices[1] = Point2f{ middle.x + (m_Rect.width / 2.f) * cosf(m_Rotation + g_Pi/2.f),
							middle.y + (m_Rect.height / 2.f) * sinf(m_Rotation + g_Pi/2.f) };
	m_Vertices[2] = Point2f{ middle.x + (m_Rect.width / 2.f) * cosf(m_Rotation + g_Pi),
							middle.y + (m_Rect.height / 2.f) * sinf(m_Rotation + g_Pi) };
	m_Vertices[3] = Point2f{ middle.x + (m_Rect.width / 2.f) * cosf(m_Rotation + g_Pi * 3.f / 2.f),
							middle.y + (m_Rect.height / 2.f) * sinf(m_Rotation + g_Pi * 3.f / 2.f) };
}
