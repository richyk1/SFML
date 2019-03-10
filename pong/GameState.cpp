#include "Common.h"
#include "Entity.h"
#include "Game.h"
#include "GameState.h"

GameState::GameState()
{
	m_done = false;
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

MainMenuState::MainMenuState() {}

void MainMenuState::Enter(Game* const g)
{
	std::cout << "Entered MainMenuState" << std::endl;

	m_font.loadFromFile("arial.ttf");
	m_text.Load(m_font, "Start", sf::Color::Blue, sf::Vector2f(0, 120.f));
	m_text.HorizontalCenter(g->Width);
	m_objects.emplace_back(m_text);

	m_text.Load(m_font, "Exit", sf::Color::Red, sf::Vector2f(0, 240.f));
	m_text.HorizontalCenter(g->Width);
	m_objects.emplace_back(m_text);

}

void MainMenuState::Update(Game* const g)
{
	std::cout << "Bop!" << std::endl;
}