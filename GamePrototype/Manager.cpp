#include "pch.h"
#include "Manager.h"
#include "Texture.h"
#include "utils.h"
using namespace utils;

Manager::Manager()
	:m_HeliumTankVertices{}, m_ObstacleVertices{}, m_Obstacles{}, m_HeliumTanks{}, m_Timer{}, m_IsAlive{ true },
	m_EndRect{ 1450.f, 0.f, 140.f , 105.f }
{
	Point2f bottomLeft{ m_EndRect.left, m_EndRect.bottom };
	Point2f topLeft{ m_EndRect.left, m_EndRect.bottom + m_EndRect.height };
	Point2f topRight{ m_EndRect.left + m_EndRect.width, m_EndRect.bottom + m_EndRect.height };
	Point2f bottomRight{ m_EndRect.left + m_EndRect.width, m_EndRect.bottom };
	m_EndRectVertices = std::vector<Point2f>{ bottomLeft, topLeft, topRight, bottomRight };
	Reset();
}

Manager::~Manager()
{
	for (int index{}; index < m_HeliumTanks.size(); ++index)
	{
		delete m_HeliumTanks[index];
		m_HeliumTanks[index] = nullptr;
	}
	m_HeliumTanks.clear();

	for (int index{}; index < m_Obstacles.size(); ++index)
	{
		delete m_Obstacles[index];
		m_Obstacles[index] = nullptr;
	}
	m_Obstacles.clear();

	m_HeliumTankVertices.clear();
	m_ObstacleVertices.clear();
}

void Manager::Update(float elapsedSec)
{
	if (m_IsAlive)
	{
		m_Timer += elapsedSec;
		for (int index{}; index < m_Obstacles.size(); ++index)
		{
			m_Obstacles[index]->Update(elapsedSec);
		}
		UpdateVertices();
	}
}

void Manager::Draw() const
{
	for (int index{}; index < m_Obstacles.size(); ++index)
	{
		m_Obstacles[index]->Draw();
	}

	for (int index{}; index < m_HeliumTanks.size(); ++index)
	{
		m_HeliumTanks[index]->Draw();
	}
}

const std::vector<std::vector<Point2f>>& Manager::GetHeliumTankVertices() const
{
	return m_HeliumTankVertices;
}

const std::vector<std::vector<Point2f>>& Manager::GetObstacleVertices() const
{
	return m_ObstacleVertices;
}

const std::vector<Point2f>& Manager::GetEndRectVertices() const
{
	return m_EndRectVertices;
}

void Manager::PickUpHeliumTank(int index)
{
	m_HeliumTanks[index]->PickUp();
	m_HeliumTankVertices[index] = std::vector<Point2f>{};
}

void Manager::Reset()
{
	m_IsAlive = true;
	m_Timer = 0.f;
	for (int index{}; index < m_HeliumTanks.size(); ++index)
	{
		delete m_HeliumTanks[index];
		m_HeliumTanks[index] = nullptr;
	}
	m_HeliumTanks.clear();

	for (int index{}; index < m_Obstacles.size(); ++index)
	{
		delete m_Obstacles[index];
		m_Obstacles[index] = nullptr;
	}
	m_Obstacles.clear();

	m_HeliumTankVertices.clear();
	m_ObstacleVertices.clear();

	m_Obstacles.push_back(new Obstacle(Point2f{ 58, 51 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 151, 181 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 157, 316 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 320, 290 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 450, 320 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 114, 520 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 340, 614 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 580, 157 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 740, 290 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 760, 60 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 890, 260 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 680, 550 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 530, 705 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 890, 615 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 930, 478 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1027, 461 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1056, 627 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1164, 725 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1340, 660 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1401, 588 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1368, 460 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1254, 340 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1415, 295 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1205, 117 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1079, 144 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1082, 39 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1374, 29 }));

	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 93, 386 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 217, 523 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 277, 64 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 649, 231 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 530, 521 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 841, 525 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 1182, 202 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 1467, 535 }));

	for (int index{}; index < m_HeliumTanks.size(); ++index)
	{
		m_HeliumTankVertices.push_back(m_HeliumTanks[index]->GetVertices());
	}

	for (int index{}; index < m_Obstacles.size(); ++index)
	{
		m_ObstacleVertices.push_back(m_Obstacles[index]->GetVertices());
	}
}

void Manager::DrawTimer()
{
	int minutes{ int(m_Timer / 60.f) };
	float seconds{ m_Timer - 60.f * minutes };
	std::string timerText{ std::to_string(minutes) + ":" + std::to_string(seconds)};
	m_Text = new Texture(timerText, "Font.otf", 50.f, Color4f{ 1.f, 1.f, 1.f, 1.f });
	if (m_IsAlive) m_Text->Draw(Point2f{ 20.f, 430.f });
	else m_Text->Draw(Point2f{ 275.f, 225.f });
	delete m_Text;
	m_Text = nullptr;
}

void Manager::End()
{
	m_IsAlive = false;
}

void Manager::UpdateVertices()
{
	for (int index{}; index < m_Obstacles.size(); ++index)
	{
		m_ObstacleVertices[index] = m_Obstacles[index]->GetVertices();
	}
}
