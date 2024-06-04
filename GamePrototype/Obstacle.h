#pragma once
#include <vector>
class Obstacle
{
public:
	Obstacle(const Point2f& position);

	void Update(float elapsedSec);

	void Draw() const;

	const std::vector<Point2f>& GetVertices() const;

private:
	void UpdateVertices();
	Point2f m_Position;
	std::vector<Point2f> m_Vertices;
	Rectf m_Rect;

	float m_Rotation;
	float m_RotationSpeed;

};

