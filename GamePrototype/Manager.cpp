#include "pch.h"
#include "Manager.h"
#include "Texture.h"

Manager::Manager()
	:m_HeliumTankVertices{}, m_ObstacleVertices{}, m_Obstacles{}, m_HeliumTanks{}, m_Timer{}, m_IsAlive{ true }
{
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

const std::vector<std::vector<Point2f>>& Manager::GetObstacleVertices()
{
	return m_ObstacleVertices;
}

void Manager::PickUpHeliumTank(int index)
{
	m_HeliumTanks[index]->PickUp();
	m_HeliumTankVertices[index] = std::vector<Point2f>{};
}

void Manager::Reset()
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

	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 565, 271 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 860, 850 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 436, 1470 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 2600, 1336 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 1650, 930 }));
	m_HeliumTanks.push_back(new HeliumTank(Point2f{ 2238, 430 }));

	m_Obstacles.push_back(new Obstacle(Point2f{ 765, 371 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 660, 950 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 436, 1670 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 2800, 1436 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 1750, 930 }));
	m_Obstacles.push_back(new Obstacle(Point2f{ 2438, 430 }));

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
