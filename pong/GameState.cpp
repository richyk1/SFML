#include "Common.h"
#include "Game.h"
#include "GameState.h"

std::stack<sf::Drawable> Render()
{
	return m_objects;
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

void MainMenuState::Enter(Game* const g)
{
	std::cout << "Entered MainMenuState" << std::endl;
	m_font.loadFromFile("arial.ttf");
	m_text.setFont(m_font);
	m_text.setString("Hello World!");
	m_text.setFillColor(sf::Color::Red);
	m_objects.push(m_text);
}


void MainMenuState::Update(Game* const g)
{
	Exit();
	std::cout << "Bop!" << std::endl;
}

void MainMenuState::Exit()
{
	
}