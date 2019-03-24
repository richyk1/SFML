#include <iostream>
#include <stack>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Button.h"
#include "GameState.h"
#include "Game.h"


int main()
{
	Game().Run();

	return 0;
}

Game::Game() : Width(1280), Height(720)
{

	window.create(sf::VideoMode(Width, Height), "yung pong");
}

void Game::Run()
{
	TPS = 1000 / 60;
	m_processedTime = m_clock.getElapsedTime().asMilliseconds();

	// Set gamestate to load resources 
	ChangeState(new LoadResourcesState());
	
	while (window.isOpen())
	{
		// Handle events
		while (window.pollEvent(event))
		{
			HandleEvents();
		}

		// Update the game
		while ((m_processedTime + TPS) < m_clock.getElapsedTime().asMilliseconds())
		{
			Update();
			m_processedTime += TPS;
		}

		// Render the game
		Render();
	}
}

void Game::ChangeState(GameState* newState)
{
	if (m_gameStates.size() > 0)
	{
		if(m_gameStates.top() != newState)
			m_gameStates.pop();
	}
	m_gameStates.push(newState);
	if (m_gameStates.top() == newState)
	{
		m_gameStates.top()->Enter(this);
	}
}

void Game::Update()
{
	m_gameStates.top()->Update(this);
}

void Game::Render()
{
	window.clear();
	mObjects = m_gameStates.top()->Render();
	mEntities = mObjects.first;
	mButtons = mObjects.second;
	for (auto& button : mButtons)
	{
		window.draw(*button);
	}
	for (auto& entity : mEntities)
	{
		window.draw(*entity);
	}


	window.display();
}

void Game::HandleEvents()
{
	m_gameStates.top()->HandleEvents(this, event, window);
}
