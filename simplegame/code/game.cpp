#include "game.h"

Game::Game()
	: m_Window{nullptr}
	, m_Event{}
	, m_VideoMode{}
{
    InitWindow();
}

Game::~Game()
{
	delete m_Window;
}

bool Game::Running() const
{
	return m_Window->isOpen();
}

void Game::PollEvents()
{
    // Event polling
    while (m_Window->pollEvent(m_Event))
    {
        switch (m_Event.type)
        {
        case sf::Event::Closed:
            m_Window->close();
            break;

        case sf::Event::KeyPressed:
            if (m_Event.key.code == sf::Keyboard::Escape)
            {
                m_Window->close();
            }
            break;
        }
    }
}

void Game::Update()
{
    PollEvents();
}

void Game::Render()
{
    m_Window->clear(sf::Color::Red);    // clear old frame

    // Draw game objects here

    m_Window->display();
}

void Game::InitVariables()
{
}

void Game::InitWindow()
{
	m_VideoMode.width = 800;
	m_VideoMode.height = 600;

	m_Window = new sf::RenderWindow{
		m_VideoMode,
		"My first game",
		sf::Style::Titlebar | sf::Style::Close };
}
