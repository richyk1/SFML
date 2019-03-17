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
	sf::RenderWindow window;
	sf::Clock m_clock;
	sf::Event event;
	std::stack<GameState*> m_gameStates;
	std::vector<TextEntity> m_objects;
	float m_processedTime;
	float TPS;
public:
	const int Width, Height;
	Game();
	void Run();
	void ChangeState(GameState* newState);
	void Update();
	void Render();
	void HandleEvents();
};

