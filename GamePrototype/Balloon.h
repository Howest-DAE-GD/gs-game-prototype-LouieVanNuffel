#pragma once
#include "Vector2f.h"
#include <vector>

class Manager;
class Balloon final
{
public:
	Balloon(const Point2f& position, const Color4f& color, Manager& manager, float startInflation, float radius, float screenWidth, float screenHeight);
	~Balloon();

	void Update(float elapsedSec, const Uint8* pStates, std::vector<std::vector<Point2f>> mapVertices);
	void DrawBalloon() const;
	void DrawHeliumMeter() const;

	Point2f GetPosition() const;

	void Inflate(float amount);
	void Deflate(float amount);
	void Die();

private:
	Point2f m_Position;
	Color4f m_Color;
	Manager& m_Manager;

	float m_ScreenWidth;
	float m_ScreenHeight;

	float m_Gravity;
	float m_Speed;
	Vector2f m_Velocity;

	float m_Radius;
	float m_Inflation;
	float m_HeliumTank;

};

