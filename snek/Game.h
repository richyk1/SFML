#pragma once
class Game
{
	float lastTime;
	float currentTime;
	float fps;
	static const int WIDTH = 800;
	static const int HEIGHT = 600;
	sf::RenderWindow m_window;
	sf::Clock m_clock;
	Player m_player;
	Food m_food;
	sf::RectangleShape m_foodShape;
	EventHandler m_eventHandler;
public:
	Game();
	void Update();
	void Render();
	void Run();
};
