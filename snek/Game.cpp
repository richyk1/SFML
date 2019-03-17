#include "Common.h"
#include "Entity.h"
#include "EventHandler.h"
#include "Game.h"

int main()
{
	Game myGame;
	myGame.Run();
}

Game::Game() : m_eventHandler(window, m_player), m_player(WIDTH, HEIGHT)
{
	window.create(sf::VideoMode(WIDTH, HEIGHT), "My window");
	window.setFramerateLimit(30);

	m_food = Food(WIDTH, HEIGHT);
	m_food.NewFood();	
}


void Game::Run()
{
	while (window.isOpen())
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
	window.clear();
	// Render all players
	for (const auto& part : m_player.GetParts())
	{
		window.draw(part);
	}
	window.draw(m_food.GetRectangle());

	window.display();
}