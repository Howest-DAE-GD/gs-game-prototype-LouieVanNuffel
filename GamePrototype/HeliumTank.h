#pragma once
#include <vector>
class HeliumTank
{
public:
	HeliumTank(const Point2f& position);

	void PickUp();
	void Draw() const;

	const std::vector<Point2f>& GetVertices() const;

private:
	bool m_HasBeenPickedUp;
	Point2f m_Position;
	std::vector<Point2f> m_Vertices;
	Rectf m_Rect;
};

