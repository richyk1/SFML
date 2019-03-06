#pragma once
class Game;

class GameState
{
public:
	virtual void Enter(Game* const g) = 0;
	virtual void Update(Game* const g, sf::Time delta) = 0;
	virtual void Exit() = 0;
};

class LoadResourcesState : public GameState
{
	bool m_done = true;
public:
	void Enter(Game* const g);
	void Update(Game* const g, sf::Time delta);
	void Exit();
};


class MainMenuState : public GameState
{
	bool m_done = true;
public:
	void Enter(Game* const g);
	void Update(Game* const g, sf::Time delta);
	void Exit();
};
