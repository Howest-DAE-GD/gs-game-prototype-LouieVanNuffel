#pragma once
#include <vector>
#include "Obstacle.h"
#include "HeliumTank.h"
class Texture;
class Manager
{
public:
	Manager();
	~Manager();

	void Update(float elapsedSec);
	void Draw() const;

	const std::vector<std::vector<Point2f>>& GetHeliumTankVertices() const;
	const std::vector<std::vector<Point2f>>& GetObstacleVertices() const;
	const std::vector<Point2f>& GetEndRectVertices() const;
	void PickUpHeliumTank(int index);
	void Reset();
	void DrawTimer();
	void End();

private:
	void UpdateVertices();
	std::vector<std::vector<Point2f>> m_HeliumTankVertices;
	std::vector<std::vector<Point2f>> m_ObstacleVertices;

	std::vector<Obstacle*> m_Obstacles;
	std::vector<HeliumTank*> m_HeliumTanks;

	Rectf m_EndRect;
	std::vector<Point2f> m_EndRectVertices;

	Texture* m_Text;
	float m_Timer;

	bool m_IsAlive;

};

