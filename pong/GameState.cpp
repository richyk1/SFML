#include <iostream>
#include <stack>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Game.h"
#include "GameState.h"

GameState::GameState()
{
	m_done = false;
}

void GameState::HandleEvents(sf::Event& event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Z)
			window.close();
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::MouseButtonPressed)
	{
		for (auto& object : m_objects)
		{
			if (object.GetBorder().contains(event.mouseButton.x, event.mouseButton.y))
				if (object.GetString() == "Exit") window.close();
		}
	}
	if (event.type == sf::Event::MouseMoved)
		for (auto& object : m_objects)
		{
			if (object.GetBorder().contains(event.mouseMove.x, event.mouseMove.y))
				object.SetBorderColor(sf::Color(255, 255, 255, 50));
			else object.SetBorderColor(sf::Color::Transparent);
		}
}

std::vector<TextEntity> GameState::Render()
{
	return m_objects;
}

LoadResourcesState::LoadResourcesState()
{
}

void LoadResourcesState::Enter(Game* const g)
{
	std::cout << "Entered LoadResourcesState" << std::endl;
}

void LoadResourcesState::Update(Game* const g)
{
	m_done = true;
	if (m_done)
	{
		g->ChangeState(new MainMenuState());
	}
}

MainMenuState::MainMenuState()
{

}

void MainMenuState::Enter(Game* const g)
{
	std::cout << "Entered MainMenuState" << std::endl;

	m_font.loadFromFile("arial.ttf");
	m_text.Load(m_font, "Start", sf::Color::Blue, sf::Vector2f(0, 120.f));
	m_text.HorizontalCenter(g->Width);
	m_text.CreateBorder();
	m_objects.emplace_back(m_text);

	m_text.Load(m_font, "Exit", sf::Color::Red, sf::Vector2f(0, 240.f));
	m_text.HorizontalCenter(g->Width);
	m_text.CreateBorder();
	m_objects.emplace_back(m_text);

}

void MainMenuState::Update(Game* const g)
{
	//std::cout << "Tick!" << std::endl;
}