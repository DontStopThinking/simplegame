#pragma once
#include "SFML/Graphics.hpp"

class Game
{
public:
	Game();
	~Game();

	bool Running() const;

	void PollEvents();
	void Update();
	void Render();

private:
	sf::RenderWindow* m_Window;
	sf::Event m_Event;
	sf::VideoMode m_VideoMode;

	void InitVariables();
	void InitWindow();
};
