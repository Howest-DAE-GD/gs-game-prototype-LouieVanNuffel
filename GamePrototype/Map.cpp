#include "pch.h"
#include "Map.h"
#include "Texture.h"
#include "SVGParser.h"

Map::Map()
{
	m_Texture = new Texture("Map.png");
	SVGParser::GetVerticesFromSvgFile("Map.svg", m_MapVertices);
}

Map::~Map()
{
	delete m_Texture;
	m_Texture = nullptr;
}

void Map::Update(float elapsedSec)
{
}

void Map::Draw() const
{
	m_Texture->Draw();
}

float Map::GetWidth() const
{
	return m_Texture->GetWidth();
}

float Map::GetHeight() const
{
	return m_Texture->GetHeight();
}
std::vector<std::vector<Point2f>> Map::GetMapVertices() const
{
	return m_MapVertices;
}
