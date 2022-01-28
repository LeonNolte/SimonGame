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

enum class GameModes
{
	None,
	Menu,
	InGame
};

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
	void processMouseReleases(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupButtons();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_title; // title text object

	// menu instruction text objects
	sf::Text m_greenInstruction; // instructions for easy game
	sf::Text m_redInstruction; // instructions for medium game
	sf::Text m_yellowInstruction; // instructions for hard game
	sf::Text m_blueInstruction; // instructions for exiting

	GameModes m_gameMode = GameModes::Menu;

	bool m_exitGame; // control exiting game

	const sf::Color RED = sf::Color::Color(180, 0, 0, 255); // Red used for button
	const sf::Color BLUE = sf::Color::Color(0, 0, 180, 255); // Blue used for button
	const sf::Color GREEN = sf::Color::Color(0, 180, 0, 255); // green used for button
	const sf::Color YELLOW = sf::Color::Color(180, 180, 0, 255); // yellow used for button

	sf::RectangleShape m_redButtonRect; // red button rectangle
	sf::RectangleShape m_blueButtonRect; // blue button rectangle
	sf::RectangleShape m_greenButtonRect; // green button rectangle
	sf::RectangleShape m_yellowButtonRect; // yellow button rectangle

};

#endif // !GAME_HPP

