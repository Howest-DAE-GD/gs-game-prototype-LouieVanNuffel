#include "pch.h"
#include "Camera.h"

Camera::Camera(float screenWidth, float screenHeight)
	:m_ScreenWidth{ screenWidth }, m_ScreenHeight{ screenHeight }, m_Position{}
{
}

void Camera::Aim(float levelW, float levelH, const Point2f& trackCenter)
{
	m_Position = Point2f{ trackCenter.x * 2.f - m_ScreenWidth / 2.f, trackCenter.y * 2.f - m_ScreenHeight / 2.f };

	// Handle Camera Bounds
	levelW *= 2.f;
	levelH *= 2.f;
	if (m_Position.x < 0) m_Position.x = 0;
	else if (m_Position.x > levelW - m_ScreenWidth) m_Position.x = levelW - m_ScreenWidth;
	if (m_Position.y < 0) m_Position.y = 0;
	else if (m_Position.y > levelH - m_ScreenHeight) m_Position.y = levelH - m_ScreenHeight;

	glPushMatrix();
	glTranslatef(-m_Position.x, -m_Position.y, 0.f);
	glScalef(2.f, 2.f, 1.f);
}

void Camera::Reset()
{
	glPopMatrix();
}

Point2f Camera::WorldToCameraSpace(const Point2f& position) const
{
	return Point2f{ position.x - m_Position.x, position.y - m_Position.y };
}