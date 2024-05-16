#pragma once
class Camera
{
public:
	Camera(float screenWidth, float screenHeight);
	void Aim(float levelW, float levelH, const Point2f& trackCenter);
	void Reset();

	Point2f WorldToCameraSpace(const Point2f& position) const;

private:
	const float m_ScreenWidth;
	const float m_ScreenHeight;
	Point2f m_Position;
};