#pragma once
class Map
{
public:
	Map(float screenWidth, float screenHeight, float speed);
	~Map();

	void Update(float elapsedSec);
	void Draw() const;

private:
	Point2f m_Position;
	float m_Speed;

	float m_ScreenWidth;
	float m_ScreenHeight;

};

