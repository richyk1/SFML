#pragma once
class Game;
class GameState
{
protected:
	std::stack<TextEntity> m_objects;
public:
	virtual void Enter(Game* const g) = 0;
	virtual void Update(Game* const g) = 0;
	virtual void Exit() = 0;
	std::stack<TextEntity> Render();
};

class LoadResourcesState : public GameState
{
	bool m_done = true;
public:
	LoadResourcesState();
	void Enter(Game* const g);
	void Update(Game* const g);
	void Exit();
};


class MainMenuState : public GameState
{
	sf::Font m_font;
	sf::Text m_text;

	TextEntity m_object;
	bool m_done = true;
public:
	MainMenuState();
	void Enter(Game* const g);
	void Update(Game* const g);
	void Exit();
};
