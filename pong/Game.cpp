#include "Common.h"
#include <thread>
#include "Entity.h"
#include "GameState.h"
#include "Game.h"


int main()
{
	Game().Run();

	return 0;
}

Game::Game() : Width(1280), Height(720)
{
	m_window.create(sf::VideoMode(Width, Height), "yung pong");
}

void Game::Run()
{
	TPS = 1000 / 1;
	m_processedTime = m_clock.getElapsedTime().asMilliseconds();

	// Set gamestate to load resources
	ChangeState(new LoadResourcesState());
	while (m_window.isOpen())
	{
		HandleInput();
		while ((m_processedTime + TPS) < m_clock.getElapsedTime().asMilliseconds())
		{
			Update();
			m_processedTime += TPS;
		}
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
	m_window.clear();
	m_objects = m_gameStates.top()->Render();
	for (auto& object : m_objects)
	{
		m_window.draw(object);
	}

	m_window.display();
}

void Game::HandleInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
			if (event.key.code == sf::Keyboard::Z)
				m_window.close();
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}
