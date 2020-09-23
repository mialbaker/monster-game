//// main.cpp

/////////////////////////////////////////////////////////////////////////////
//// main()
/////////////////////////////////////////////////////////////////////////////

//#include "Game.h"
//
//int main()
//{
//	// Create a game
//	// Use this instead to create a mini-game:   Game g(3, 5, 2);
//	Game g(10, 12, 40);
//
//	// Play the game
//	g.play();
//}

#include "Arena.h"
#include "Player.h"
#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

int main()
{
	Arena a(1, 4);
	a.addPlayer(1, 2);
	a.player()->dropPoisonVial();
	a.player()->dropPoisonVial();
	a.player()->move(EAST);
	a.player()->dropPoisonVial();
	a.player()->move(EAST);
	a.addVampire(1, 1);
	while (a.vampireCount() > 0)
		a.moveVampires();
	a.player()->move(WEST);
	a.player()->dropPoisonVial();
	a.history().display();
	cout << "====" << endl;
}






