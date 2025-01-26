#include "stdafx.h"
#include "MyGame.h"

#pragma warning (disable:4244)

CMyGame::CMyGame(void) : 
	m_ground(512, 0, 2000, 200, CColor::Black(), 0),
	m_marble(X_SLING, Y_SLING, 30, 30, CColor::Red(), CColor::Black(), 0),
	m_background("back.jpg")
{
}

CMyGame::~CMyGame(void)
{
}

/////////////////////////////////////////////////////
// Per-Frame Callback Funtions (must be implemented!)

void CMyGame::OnUpdate()
{
	m_ground.Update(GetTime());
	for (CSprite *p : m_house)
		p->Update(GetTime());
	m_marble.Update(GetTime());
}

void CMyGame::OnDraw(CGraphics* g)
{
	g->Blit(CVector(0, 0), m_background);
	for (CSprite *p : m_house)
		p->Draw(g);
	m_marble.Draw(g);
}

/////////////////////////////////////////////////////
// Game Life Cycle

// one time initialisation
void CMyGame::OnInitialize()
{
}

// called at the start of a new game - display menu here
void CMyGame::OnDisplayMenu()
{
	StartGame();	// this allows to start the game immediately
}

// called when Game Mode entered
void CMyGame::OnStartGame()
{
	for (CSprite *p : m_house)
		delete p;
	m_house.clear();
	
	CSprite *p;
	p = new CSpriteRect(775, 175, 20, 150, CColor::Black(128), CColor::Black(), GetTime());
	m_house.push_back(p);
	p = new CSpriteRect(925, 175, 20, 150, CColor::Black(128), CColor::Black(), GetTime());
	m_house.push_back(p);
	p = new CSpriteRect(850, 260, 154, 20, CColor::Black(128), CColor::Black(), GetTime());
	m_house.push_back(p);
	p = new CSpriteRect(810, 320, 20, 100, CColor::Black(128), CColor::Black(), GetTime());
	m_house.push_back(p);
	p = new CSpriteRect(890, 320, 20, 100, CColor::Black(128), CColor::Black(), GetTime());
	m_house.push_back(p);
	p = new CSpriteRect(850, 380, 100, 20, CColor::Black(128), CColor::Black(), GetTime());
	m_house.push_back(p);
	p = new CSpriteRect(850, 415, 50, 50, CColor::Black(128), CColor::Black(), GetTime());
	m_house.push_back(p);
	p = new CSpriteOval(850, 300, 40, 40, CColor::Green(), CColor::Black(), GetTime());
	m_house.push_back(p);
}

// called when Game is Over
void CMyGame::OnGameOver()
{
}

// one time termination code
void CMyGame::OnTerminate()
{
}

/////////////////////////////////////////////////////
// Keyboard Event Handlers

void CMyGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_F4 && (mod & (KMOD_LALT | KMOD_RALT)))
		StopGame();
	if (sym == SDLK_SPACE)
		PauseGame();
	if (sym == SDLK_F2)
		NewGame();
}

void CMyGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{
}


/////////////////////////////////////////////////////
// Mouse Events Handlers

void CMyGame::OnMouseMove(Uint16 x,Uint16 y,Sint16 relx,Sint16 rely,bool bLeft,bool bRight,bool bMiddle)
{
}

void CMyGame::OnLButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnLButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnRButtonUp(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonDown(Uint16 x,Uint16 y)
{
}

void CMyGame::OnMButtonUp(Uint16 x,Uint16 y)
{
}
