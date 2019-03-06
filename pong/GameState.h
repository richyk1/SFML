#pragma once
class Game;

class GameState
{
public:
	virtual void Enter(Game* const g) = 0;
	std::stack<sf::Drawable> Render();
	virtual void Update(Game* const g) = 0;
	virtual void Exit() = 0;
};

class LoadResourcesState : public GameState
{
	bool m_done = true;
public:
	void Enter(Game* const g);
	void Update(Game* const g);
	void Exit();
};


class MainMenuState : public GameState
{
	sf::Font m_font;
	sf::Text m_text;
	std::stack<sf::Drawable> m_objects;
	bool m_done = true;
public:
	void Enter(Game* const g);
	void Update(Game* const g);
	void Exit();
};
