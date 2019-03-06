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
	float m_processedTime;
	float TPS;
public:
	Game();
	void Run();
	void ChangeState(GameState* newState);
	void Update();
	void Render();
};

