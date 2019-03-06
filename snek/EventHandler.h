#pragma once
class IAction
{
public:
	virtual void Do(Player& player) = 0;
};

class ICase
{
public:
	virtual sf::Keyboard::Key Direction() = 0;
};

class CaseUp : public IAction, public ICase
{
public:
	void Do(Player& player);
	sf::Keyboard::Key Direction();
};

class CaseRight : public IAction, public ICase
{
public:
	void Do(Player& player);
	sf::Keyboard::Key Direction();
};

class CaseDown : public IAction, public ICase
{
public:
	void Do(Player& player);
	sf::Keyboard::Key Direction();
};

class CaseLeft : public IAction, public ICase
{
public:
	void Do(Player& player);
	sf::Keyboard::Key Direction();
};

class SwitchCase
{
protected:
	std::vector<ICase*> Cases;
	ICase* up;
	ICase* down;
	ICase* left;
	ICase* right;
};

class ConditionDirection : public SwitchCase
{
private:
	 std::vector<ICase*>::iterator m_match;
	 Player& m_player;
public:
	ConditionDirection(Player& player);
	void Switch(sf::Keyboard::Key& key);
};

class EventHandler
{
private:
	sf::Event m_event;
	sf::RenderWindow& m_window;
	Player& m_player;
	ConditionDirection m_conditionDirection;
public:
	EventHandler(sf::RenderWindow& window, Player& player);
	void HandleEvents();
};