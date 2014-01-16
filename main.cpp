//
//  main.m
//  SDL2_Pong
//
//  Created by Jake on 12/01/14.
//  Copyright (c) 2014 Draderus. All rights reserved.
//

#include <iostream>

#include "game.h"

int main(int argc, char* argv[])
{
	Game game;
	
	game.Init("Pong",800,600,32,false);
	
	while(game.Running())
	{
		game.HandleEvents(&game);
		game.Update();
		game.Draw();
	}
	
	// cleanup the engine
	game.Clean();
	
	return 0;
}

