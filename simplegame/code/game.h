#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

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
	// Game objects
	sf::RectangleShape m_Enemy;

	sf::RenderWindow* m_Window;
	sf::Event m_Event;
	sf::VideoMode m_VideoMode;

	void InitEnemies();

	void InitWindow();
};
