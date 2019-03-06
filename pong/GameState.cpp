#include "Common.h"
#include "Game.h"
#include "GameState.h"

void LoadResourcesState::Enter(Game* const g)
{
	std::cout << "Entered LoadResourcesState" << std::endl;
}

void LoadResourcesState::Update(Game* const g, sf::Time delta)
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
}

void MainMenuState::Update(Game* const g, sf::Time delta)
{
	Exit();
	std::cout << delta.asMilliseconds << std::endl;
}

void MainMenuState::Exit()
{
	
}