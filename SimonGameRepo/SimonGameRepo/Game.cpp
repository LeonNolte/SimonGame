/// <summary>
/// Leon Nolte
/// 21 Jan 2022
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 500U, 32U }, "Simon Virtual Pro Gaming Edition" },
	m_greenButtonRect{ sf::Vector2f{200.0f, 200.0f} },
	m_redButtonRect{ sf::Vector2f{200.0f, 200.0f } },
	m_yellowButtonRect{ sf::Vector2f{200.0f, 200.0f} },
	m_blueButtonRect{ sf::Vector2f{200.0f, 200.0f} },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font
	setupButtons(); // create buttons
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 30.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (sf::Event::MouseButtonReleased == newEvent.type) // user releases mouse button
		{
			processMouseReleases(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

void Game::processMouseReleases(sf::Event t_event)
{
	if (sf::Mouse::Left == t_event.key.code)
	{
		std::cout << "Left mouse released";
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	switch (m_gameMode)
	{
	case GameModes::None:
		std::cout << "No game mode"; // for testing
		break;
	case GameModes::Menu:
		std::cout << "In menu"; // for testing
		break;
	case GameModes::InGame:
		std::cout << "In game"; // for testing
		break;
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);

	// text objects
	m_window.draw(m_title);
	m_window.draw(m_greenInstruction);
	m_window.draw(m_redInstruction);
	m_window.draw(m_yellowInstruction);
	m_window.draw(m_blueInstruction);

	// buttons
	m_window.draw(m_redButtonRect);
	m_window.draw(m_greenButtonRect);
	m_window.draw(m_yellowButtonRect);
	m_window.draw(m_blueButtonRect);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "Error: Could not load Arial font.";
	}

	// title
	m_title.setFont(m_ArialBlackfont);
	m_title.setString("SIMON");
	m_title.setStyle(sf::Text::Bold);
	m_title.setFillColor(sf::Color::White);
	m_title.setCharacterSize(75U);
	m_title.setPosition(30.0f, 20.0f);

	// menu
	m_greenInstruction.setFont(m_ArialBlackfont);
	m_greenInstruction.setString("Press green for \nan easy game");
	m_greenInstruction.setFillColor(GREEN);
	m_greenInstruction.setCharacterSize(25U);
	m_greenInstruction.setPosition(30.0f, 120.0f);

	m_redInstruction.setFont(m_ArialBlackfont);
	m_redInstruction.setString("Press red for \na medium game");
	m_redInstruction.setFillColor(RED);
	m_redInstruction.setCharacterSize(25U);
	m_redInstruction.setPosition(30.0f, 200.0f);

	m_yellowInstruction.setFont(m_ArialBlackfont);
	m_yellowInstruction.setString("Press yellow for \na hard game");
	m_yellowInstruction.setFillColor(YELLOW);
	m_yellowInstruction.setCharacterSize(25U);
	m_yellowInstruction.setPosition(30.0f, 280.0f);

	m_blueInstruction.setFont(m_ArialBlackfont);
	m_blueInstruction.setString("Press blue for \nexiting the game");
	m_blueInstruction.setFillColor(BLUE);
	m_blueInstruction.setCharacterSize(25U);
	m_blueInstruction.setPosition(30.0f, 360.0f);
}

/// <summary>
/// loads the buttons
/// </summary>
void Game::setupButtons()
{
	m_greenButtonRect.setFillColor(GREEN);
	m_greenButtonRect.setPosition(sf::Vector2f(350.0f, 30.0f));
	m_redButtonRect.setFillColor(RED);
	m_redButtonRect.setPosition(sf::Vector2f(570.0f, 30.0f));
	m_yellowButtonRect.setFillColor(YELLOW);
	m_yellowButtonRect.setPosition(sf::Vector2f(350.0f, 250.0f));
	m_blueButtonRect.setFillColor(BLUE);
	m_blueButtonRect.setPosition(sf::Vector2f(570.0f, 250.0f));
}
