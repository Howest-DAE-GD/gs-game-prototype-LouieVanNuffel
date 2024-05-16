#include "pch.h"
#include "Manager.h"

Manager::Manager()
	:m_HeliumTankVertices{}, m_ObstacleVertices{}, m_Obstacles{}, m_HeliumTanks{}
{
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
