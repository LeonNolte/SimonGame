/// <summary>
/// Leon Nolte
/// 21 Jan 2022
/// </summary>

#ifndef GAME_HPP
#define GAME_HPP

/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupButtons();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message

	bool m_exitGame; // control exiting game

	const sf::Color RED = sf::Color::Color(180, 0, 0, 255);
	const sf::Color BLUE = sf::Color::Color(0, 0, 180, 255);
	const sf::Color GREEN = sf::Color::Color(0, 180, 0, 255);
	const sf::Color YELLOW = sf::Color::Color(180, 180, 0, 255);

	sf::RectangleShape m_redButtonRect;

};

#endif // !GAME_HPP

