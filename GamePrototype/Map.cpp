#include "pch.h"
#include "Map.h"

Map::Map(float screenWidth, float screenHeight, float speed)
	:m_Position{ Point2f{0.f, 0.f} }, m_ScreenWidth{ screenWidth }, m_ScreenHeight{ screenHeight }, m_Speed{ speed }
{
}

Map::~Map()
{
}

void Map::Update(float elapsedSec)
{
	m_Position.x -= m_Speed * elapsedSec;
}

void Map::Draw() const
{
}
