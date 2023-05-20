#include "game.h"

#include <iostream>

Game::Game()
	: m_Window{nullptr}
	, m_Event{}
	, m_VideoMode{}
    , m_Enemy{}
{
    InitWindow();
    InitEnemies();
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

    // print mouse position relative to window
    std::cout << "Mouse pos: ("
        << sf::Mouse::getPosition(*m_Window).x
        << ", "
        << sf::Mouse::getPosition(*m_Window).y
        << ")\n";
}

void Game::Render()
{
    m_Window->clear(sf::Color::Red);    // clear old frame

    // Draw game objects here
    m_Window->draw(m_Enemy);

    m_Window->display();
}

void Game::InitEnemies()
{
    m_Enemy.setPosition(sf::Vector2f(10.0f, 10.0f));
    m_Enemy.setSize(sf::Vector2f(100.0f, 100.0f));
    m_Enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    m_Enemy.setFillColor(sf::Color::Cyan);
    m_Enemy.setOutlineColor(sf::Color::Green);
    m_Enemy.setOutlineThickness(1.0f);
}

void Game::InitWindow()
{
	m_VideoMode.width = 800;
	m_VideoMode.height = 600;

	m_Window = new sf::RenderWindow{
		m_VideoMode,
		"My first game",
		sf::Style::Titlebar | sf::Style::Close };

    m_Window->setFramerateLimit(60);
}
