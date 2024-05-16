#include "pch.h"
#include "Balloon.h"
#include <iostream>
#include "utils.h"
using namespace utils;

Balloon::Balloon(const Point2f& position, const Color4f& color, float startInflation, float radius, float screenWidth, float screenHeight)
	:m_Position{ position }, m_Color{ color }, m_Inflation{ startInflation }, m_Radius{ radius }, m_HeliumTank{ 500.f }, m_Gravity{ -300.f }, m_Speed{ 125.f },
	m_ScreenWidth{ screenWidth }, m_ScreenHeight{ screenHeight }
{
}

Balloon::~Balloon()
{
}

void Balloon::Update(float elapsedSec, const Uint8* pStates,std::vector<std::vector<Point2f>> mapVertices, std::vector<std::vector<Point2f>> obstacleVertices, std::vector<std::vector<Point2f>> heliumVertices)
{
	// Collision
	HitInfo hitInfo{};
	// With environment
	for (int index{}; index < mapVertices.size(); ++index)
	{
		for (int angle{}; angle < 360; angle += 10)
		{
			if (Raycast(mapVertices[index], Point2f{m_Position.x, m_Position.y}, Point2f{m_Position.x + float(cos(angle)) * m_Radius * (m_Inflation / 100.f) * 0.8f, m_Position.y + float(sin(angle)) * m_Radius * (m_Inflation / 100.f)}, hitInfo))
			{
				Die();
			}
		}
	}
	// With Obstacles
	for (int index{}; index < obstacleVertices.size(); ++index)
	{
		for (int angle{}; angle < 360; angle += 10)
		{
			if (Raycast(obstacleVertices[index], Point2f{ m_Position.x, m_Position.y }, Point2f{ m_Position.x + float(cos(angle)) * m_Radius * (m_Inflation / 100.f) * 0.8f, m_Position.y + float(sin(angle)) * m_Radius * (m_Inflation / 100.f) }, hitInfo))
			{
				Die();
			}
		}
	}
	// With helium tanks
	for (int index{}; index < heliumVertices.size(); ++index)
	{
		for (int angle{}; angle < 360; angle += 10)
		{
			if (Raycast(heliumVertices[index], Point2f{m_Position.x, m_Position.y}, Point2f{m_Position.x + float(cos(angle)) * m_Radius * (m_Inflation / 100.f) * 0.8f, m_Position.y + float(sin(angle)) * m_Radius * (m_Inflation / 100.f)}, hitInfo))
			{
				m_HeliumTank += 100.f;
			}
		}
	}

	// Helium Tank Limit
	if (m_HeliumTank >= 500.f) m_HeliumTank = 500.f;
	
	// Input
	if (pStates[SDL_SCANCODE_UP] && m_Inflation < 100.f && m_HeliumTank > 0.f)
	{
		Inflate(40.f * elapsedSec);
	}
	else if (pStates[SDL_SCANCODE_DOWN] && m_Inflation > 10.f)
	{
		Deflate(40.f * elapsedSec);
	}

	if (pStates[SDL_SCANCODE_RIGHT])
	{
		m_Velocity.x += m_Speed * 2 * elapsedSec;
		if (m_Velocity.x > m_Speed) m_Velocity.x = m_Speed;
	}
	else if (pStates[SDL_SCANCODE_LEFT])
	{
		m_Velocity.x -= m_Speed * 2 * elapsedSec;
		if (m_Velocity.x < -m_Speed) m_Velocity.x = -m_Speed;
	}
	else
	{
		if (m_Velocity.x > 0) m_Velocity.x -= m_Speed * elapsedSec;
		if (m_Velocity.x < 0) m_Velocity.x += m_Speed * elapsedSec;
	}
	
	if ((pStates[SDL_SCANCODE_RIGHT] && pStates[SDL_SCANCODE_LEFT]))
	{
		m_Velocity.x = 0;
	}

	if (pStates[SDL_SCANCODE_SPACE])
	{
		m_HeliumTank += 10.f;
	}

	// Physics
	if (m_Inflation > 10.f) m_Velocity.y = (m_Gravity / 100.f) * (100.f - m_Inflation - 50.f);
	else m_Velocity.y += m_Gravity * elapsedSec;
	m_Position += m_Velocity * elapsedSec;
	if (m_Inflation > 10.f) m_Inflation -= 20.f * elapsedSec;
}

void Balloon::DrawBalloon() const
{
	SetColor(m_Color);
	FillEllipse(m_Position.x, m_Position.y, m_Radius * (m_Inflation / 100.f) * 0.8f, m_Radius * (m_Inflation / 100.f));
}

void Balloon::DrawHeliumMeter() const
{
	if (m_HeliumTank > 250.f) SetColor(Color4f{ 0.f, 1.f, 0.f, 1.f });
	else if (m_HeliumTank > 100.f) SetColor(Color4f{ 1.f, 1.f, 0.f, 1.f });
	else SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });

	DrawRect(20.f, 20.f, 50.f, 150.f, 5.f);
	FillRect(20.f, 20.f, 50.f, 150.f * (m_HeliumTank / 500.f));
}

Point2f Balloon::GetPosition() const
{
	return m_Position;
}

void Balloon::Inflate(float amount)
{
	m_Inflation += amount;
	m_HeliumTank -= amount;
}

void Balloon::Deflate(float amount)
{
	m_Inflation -= amount;
}

void Balloon::Die()
{
	m_Position = Point2f{ 150.f, 300.f };
	m_HeliumTank = 500.f;
	m_Inflation = 50.f;
	m_Velocity.x = 0.f;
}
