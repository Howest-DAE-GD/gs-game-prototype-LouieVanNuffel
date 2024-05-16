#include "pch.h"
#include "Game.h"

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_Map = new Map();
	m_Camera = new Camera(GetViewPort().width, GetViewPort().height);
	m_Balloon = new Balloon(Point2f{ GetViewPort().width * 1.f / 5.f, GetViewPort().height * 4.f / 5.f }, Color4f{ 1.f, 0.f, 0.f, 1.f }, 50.f, 75.f, GetViewPort().width, GetViewPort().height);
	m_Manager = new Manager();
}

void Game::Cleanup( )
{
	delete m_Map;
	m_Map = nullptr;
	delete m_Camera;
	m_Camera = nullptr;
	delete m_Balloon;
	m_Balloon = nullptr;
	delete m_Manager;
	m_Manager = nullptr;
}

void Game::Update( float elapsedSec )
{
	const Uint8* pStates{ SDL_GetKeyboardState(nullptr) };
	m_Balloon->Update(elapsedSec, pStates, m_Map->GetMapVertices(), m_Manager->GetObstacleVertices(), m_Manager->GetHeliumTankVertices());
}

void Game::Draw( ) const
{
	ClearBackground( );
	m_Camera->Aim(m_Map->GetWidth(), m_Map->GetHeight(), m_Balloon->GetPosition());
	m_Map->Draw();
	m_Manager->Draw();
	m_Balloon->DrawBalloon();
	m_Camera->Reset();
	m_Balloon->DrawHeliumMeter();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
