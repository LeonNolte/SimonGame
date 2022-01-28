/// <summary>
/// Simon virtual gaming experience based on the Pete Studios ocncept
/// 
/// Leon Nolte
/// C00263935
/// 21 January 2022
/// Est. time: 10 hours
/// Session 1: 10:05 - 10:55 (21 Jan 22)
/// Session 2: 09:20 - 10:55 (28 Jan 22)
/// -----------------------------------------------
/// Known bugs: none
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include "Game.h"

/// <summary>
/// main enrtry point
/// </summary>
/// <returns>success or failure</returns>
int main()
{
	Game game;
	game.run();

	return 1; // success
}