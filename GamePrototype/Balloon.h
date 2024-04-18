#pragma once
#include "Vector2f.h"

class Balloon final
{
public:
	Balloon(const Point2f& position, const Color4f& color, float startInflation, float radius, float screenWidth, float screenHeight);
	~Balloon();

	void Update(float elapsedSec, const Uint8* pStates);
	void Draw() const;

	void Inflate(float amount);
	void Deflate(float amount);
	void Die();

private:
	Point2f m_Position;
	Color4f m_Color;

	float m_ScreenWidth;
	float m_ScreenHeight;

	float m_Gravity;
	Vector2f m_Velocity;

	float m_Radius;
	float m_Inflation;
	float m_HeliumTank;

};

