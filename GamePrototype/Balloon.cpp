#include "pch.h"
#include "Balloon.h"
#include "utils.h"
using namespace utils;

Balloon::Balloon(const Point2f& position, const Color4f& color, float startInflation, float radius, float screenWidth, float screenHeight)
	:m_Position{ position }, m_Color{ color }, m_Inflation{ startInflation }, m_Radius{ radius }, m_HeliumTank{ 500.f }, m_Gravity{ -185.f },
	m_ScreenWidth{ screenWidth }, m_ScreenHeight{ screenHeight }
{
}

Balloon::~Balloon()
{
}

void Balloon::Update(float elapsedSec, const Uint8* pStates)
{
	// Helium Tank Limit
	if (m_HeliumTank >= 500.f) m_HeliumTank = 500.f;

	// Keep in bounds
	if (m_Position.y + m_Radius * (m_Inflation / 100.f) >= m_ScreenHeight && m_Velocity.y >= 0)
	{
		m_Position.y = m_ScreenHeight - m_Radius * (m_Inflation / 100.f);
	}
	else if (m_Position.y - m_Radius * (m_Inflation / 100.f) <= 0)
	{
		m_Position.y = m_Radius * (m_Inflation / 100.f);
		Die();
	}
	
	// Input
	if (pStates[SDL_SCANCODE_UP] && m_Inflation < 100.f && m_HeliumTank > 0.f)
	{
		Inflate(40.f * elapsedSec);
	}
	else if (pStates[SDL_SCANCODE_DOWN] && m_Inflation > 10.f)
	{
		Deflate(40.f * elapsedSec);
	}

	if (pStates[SDL_SCANCODE_SPACE])
	{
		m_HeliumTank += 10.f;
	}

	// Physics
	m_Velocity.y = (m_Gravity / 100.f) * (100.f - m_Inflation - 50.f);
	m_Position += m_Velocity * elapsedSec;
	if (m_Inflation > 10.f) m_Inflation -= 20.f * elapsedSec;
}

void Balloon::Draw() const
{
	// Draw balloon
	SetColor(m_Color);
	FillEllipse(m_Position.x, m_Position.y, m_Radius * (m_Inflation / 100.f) * 0.8f, m_Radius * (m_Inflation / 100.f));

	// Draw helium tank bar
	SetColor(Color4f{ 0.f, 1.f, 0.f, 1.f });
	DrawRect(20.f, 20.f, 50.f, 150.f, 5.f);
	FillRect(20.f, 20.f, 50.f, 150.f * (m_HeliumTank / 500.f));
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
}
