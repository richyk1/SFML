#include "Common.h"
#include "Entity.h"
#include "Game.h"
#include "GameState.h"

std::stack<TextEntity> GameState::Render()
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

	Exit();
	if (m_done)
	{
		g->ChangeState(new MainMenuState());
	}
}

void LoadResourcesState::Exit()
{

}

MainMenuState::MainMenuState() : m_object(m_text) {}

void MainMenuState::Enter(Game* const g)
{
	std::cout << "Entered MainMenuState" << std::endl;
	m_font.loadFromFile("arial.ttf");
	m_text.setFont(m_font);
	m_text.setString("Hello World!");
	m_text.setFillColor(sf::Color::Red);
	m_text.setPosition(sf::Vector2f(20.f, 20.f));

	m_object = TextEntity(m_text);
	m_objects.push(m_object);
}

void MainMenuState::Update(Game* const g)
{
	Exit();
	std::cout << "Bop!" << std::endl;
}

void MainMenuState::Exit()
{
	
}