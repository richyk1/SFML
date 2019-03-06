#pragma once
class GameState;

class StateManager
{
	virtual void ChangeState(GameState* newState) = 0;
	virtual void Update() = 0;
};

class Game : public StateManager
{
private:
	sf::RenderWindow m_window;
	std::stack<GameState*> m_gameStates;
	sf::Clock m_clock;
	sf::Time m_prevTime;
	sf::Time m_currentTime;
	sf::Time m_delta;
public:
	Game();
	void Run();
	void ChangeState(GameState* newState);
	void Update();
	void Render();
};

