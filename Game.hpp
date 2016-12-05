#ifndef GAME
#define GAME

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Game {
private:
	enum GameState {
		Uninit, Playing, Exiting
	};
	
	static GameState m_GameState;
	
	static sf::RenderWindow m_Window;

	static sf::ContextSettings m_Settings;

	static sf::Clock m_Clock;

	static sf::Time m_Time;

	static void LoadWindow();

	static void Loop();

	static void ProcessInputs();

	static void Update(float dTime);

	static void Render();

	static bool isExiting();

public:
	static void Start();
};

#endif // GAME
