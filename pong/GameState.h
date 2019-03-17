#pragma once
class Game;
class GameState
{
protected:
	std::vector<TextEntity> m_objects;
	sf::Font m_font;
	bool m_done;
public:
	GameState();
	virtual void Enter(Game* const g) = 0;
	virtual void Update(Game* const g) = 0;
	void HandleEvents(sf::Event& event, sf::RenderWindow& window);
	std::vector<TextEntity> Render();
};

class LoadResourcesState : public GameState
{
public:
	LoadResourcesState();
	void Enter(Game* const g);
	void Update(Game* const g);
};


class MainMenuState : public GameState
{
	TextEntity m_text;
public:
	MainMenuState();
	void Enter(Game* const g);
	void Update(Game* const g);
};
