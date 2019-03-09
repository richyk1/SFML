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
	sf::Clock m_clock;
	std::stack<GameState*> m_gameStates;
	std::stack<TextEntity> m_objects;
	float m_processedTime;
	float TPS;
public:
	Game();
	void Run();
	void ChangeState(GameState* newState);
	void Update();
	void Render();
};

