#pragma once
#include <vector>

class Texture;
class Map
{
public:
	Map();
	~Map();

	void Update(float elapsedSec);
	void Draw() const;

	float GetWidth() const;
	float GetHeight() const;

	std::vector<std::vector<Point2f>> GetMapVertices() const;

private:
	Texture* m_Texture;
	std::vector<std::vector<Point2f>> m_MapVertices;
};

