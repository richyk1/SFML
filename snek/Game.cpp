#include "Common.h"
#include "Entity.h"
#include "EventHandler.h"
#include "Game.h"

int main()
{
	Game myGame;
	myGame.Run();
}

Game::Game() : m_eventHandler(m_window, m_player), m_player(WIDTH, HEIGHT)
{
	m_window.create(sf::VideoMode(WIDTH, HEIGHT), "My window");
	m_window.setFramerateLimit(30);

	m_food = Food(WIDTH, HEIGHT);
	m_food.NewFood();	
}


void Game::Run()
{
	while (m_window.isOpen())
	{
		Update();
		Render();
	}
}

void Game::Update()
{
	m_eventHandler.HandleEvents();
	m_player.Move();
	if (m_player.GetRectangle().getGlobalBounds().intersects(m_food.GetRectangle().getGlobalBounds()))
	{
		std::cout << "Got food" << std::endl;
		m_food.NewFood();
		m_player.Grow();
	}
}

void Game::Render()
{
	m_window.clear();
	// Render all players
	for (const auto& part : m_player.GetParts())
	{
		m_window.draw(part);
	}
	m_window.draw(m_food.GetRectangle());

	m_window.display();
}