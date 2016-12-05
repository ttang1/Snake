#include "Game.hpp"

Game::GameState Game::m_GameState;

sf::RenderWindow Game::m_Window;

sf::ContextSettings Game::m_Settings;

sf::Clock Game::m_Clock;

sf::Time Game::m_Time;

void Game::LoadWindow() 
{
	m_Settings.antialiasingLevel = 8;
	if (m_GameState != Uninit) {
		return;
	}
	m_Window.create(sf::VideoMode(1080, 720), "SNAKE", sf::Style::Default, m_Settings);
}

void Game::Loop() 
{
	ProcessInputs();
	Update(m_Time.asSeconds());
	Render();
}

void Game::ProcessInputs() 
{
	sf::Event curEvent;
	while (m_Window.pollEvent(curEvent)) {
		switch (curEvent.type) {
			case sf::Event::Closed:
				m_GameState = Game::Exiting;
				break;
			case sf::Event::KeyPressed:
				switch (curEvent.key.code) {
					case (sf::Keyboard::Escape):
						m_GameState = Game::Exiting;
						break;


					default:
						break;
				}
			default:
				break;
		}
	}// end pollEvent
}

void Game::Update(float dTime) 
{
	// update(dTime);
}

void Game::Render() 
{
	m_Window.clear();

//		m_Window.draw();

	m_Window.display();
}

bool Game::isExiting() 
{
	return m_GameState == Game::Exiting;
}

void Game::Start() 
{
	LoadWindow();
	m_GameState = Game::Playing;
	while (!isExiting()) {
		m_Time = m_Clock.restart();
		Loop();
	}
	m_Window.close();
}
