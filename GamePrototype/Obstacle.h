#pragma once
#include <vector>
class Obstacle
{
public:
	Obstacle(const Point2f& position);

	void Draw() const;

	const std::vector<Point2f>& GetVertices() const;

private:
	Point2f m_Position;
	std::vector<Point2f> m_Vertices;
	Rectf m_Rect;

};

