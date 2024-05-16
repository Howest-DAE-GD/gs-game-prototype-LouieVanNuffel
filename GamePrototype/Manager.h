#pragma once
#include <vector>
#include "Obstacle.h"
#include "HeliumTank.h"
class Manager
{
public:
	Manager();

	void Draw() const;

	const std::vector<std::vector<Point2f>>& GetHeliumTankVertices() const;
	const std::vector<std::vector<Point2f>>& GetObstacleVertices();

private:
	std::vector<std::vector<Point2f>> m_HeliumTankVertices;
	std::vector<std::vector<Point2f>> m_ObstacleVertices;

	std::vector<Obstacle*> m_Obstacles;
	std::vector<HeliumTank*> m_HeliumTanks;

};

