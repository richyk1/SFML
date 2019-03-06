#include "Common.h"
#include "Entity.h"
#include "EventHandler.h"

EventHandler::EventHandler(sf::RenderWindow& window, Player& player) : m_window(window), m_player(player), m_conditionDirection(m_player)
{

}

void EventHandler::HandleEvents()
{
	while (m_window.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::EventType::Closed:
			m_window.close();
			break;
		case sf::Event::EventType::KeyPressed:
			m_conditionDirection.Switch(m_event.key.code);
			break;
		default:
			break;
		}
	}
}

void CaseUp::Do(Player& player)
{
	if (player.Up()) std::cout << "User pressed up." << std::endl;
}

void CaseDown::Do(Player& player)
{
	if (player.Down()) std::cout << "User pressed down." << std::endl;
}

void CaseLeft::Do(Player& player)
{
	if (player.Left()) std::cout << "User pressed left." << std::endl;
}

void CaseRight::Do(Player& player)
{
	if (player.Right()) std::cout << "User pressed right." << std::endl;
}

sf::Keyboard::Key CaseUp::Direction()
{
	return sf::Keyboard::Up;
}

sf::Keyboard::Key CaseDown::Direction()
{
	return sf::Keyboard::Down;
}

sf::Keyboard::Key CaseLeft::Direction()
{
	return sf::Keyboard::Left;
}

sf::Keyboard::Key CaseRight::Direction()
{
	return sf::Keyboard::Right;
}

ConditionDirection::ConditionDirection(Player& player) : m_player(player)
{
	up = new CaseUp();
	down = new CaseDown();
	left = new CaseLeft();
	right = new CaseRight();
	Cases = { up, down, left, right };
}

void ConditionDirection::Switch(sf::Keyboard::Key& key)
{
	m_match = std::find_if(
		Cases.begin(), Cases.end(),
		[&key](ICase * x) {return x->Direction() == key; });
	
	ICase* myCase = *m_match;
	IAction* myAction = dynamic_cast<IAction*>(myCase);
	myAction->Do(m_player);
}