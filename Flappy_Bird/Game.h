#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<Windows.h>
#include "TextureManager.h"
using namespace std;


class Game
{
public:

	SDL_Window* window;	//window pointer variable
	SDL_Renderer* render;	//render pointer variable
	SDL_Texture* player;	//Texture variable of the Player(bird)
	SDL_Texture* bg;

	SDL_Rect srcplayer, desplayer;
	SDL_Event event1,pEvent;


	bool gamestate;


	bool init();
	bool getgamestate();
	void Event();
	bool init_renderer();
	void update_dimensions();
	~Game();

};



Game play;



bool Game::getgamestate()
{
	return gamestate;
}

bool Game::init()
{

	window = NULL;
	render = NULL;


	srcplayer.h = 427;
	srcplayer.w = 435;
	srcplayer.x = 0;
	srcplayer.y = 0;


	//Destination Dimensions


	desplayer.h = 100;

	desplayer.w = 100;

	desplayer.x = 100;

	desplayer.y = 1;

	



	gamestate = false;

	bool success = true;

	SDL_Init(SDL_INIT_EVERYTHING);

	


	
	window = SDL_CreateWindow(" Flappy Bird ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 480, SDL_WINDOW_RESIZABLE);
	if (!(window))
	{
		cout << "Error Creating renderer , Error is : \n", SDL_GetError();
		success = false;
	}
	else
	{
		gamestate = true;
	}

	return success;
}


void Game::Event()
{
	SDL_PollEvent(&event1);

	if (event1.type == SDL_QUIT)
	{
		gamestate = false;

		cout << "\n\nWindow Closed\n\n";
	}
	
}

bool Game::init_renderer()
{
	bool success = true;
	render = SDL_CreateRenderer(window, -1, 0);

	if (render)
	{
		gamestate = true;
		cout << "Successfully Created Window";


		player = TextureManager::Texture("Assets/bird.png", render);
		bg = TextureManager::Texture("Assets/BG.png", render);


		//SDL_QueryTexture(player, NULL, NULL, &desplayer.w, &desplayer.h);



		for (; desplayer.y <= 400;)
		{
			SDL_Delay(10);
			

			desplayer.y = desplayer.y + 1;


			

			SDL_RenderClear(render);
			SDL_RenderCopy(render, bg, NULL, NULL);


			SDL_PollEvent(&pEvent);

			if (desplayer.y > 0)
			{

				if (pEvent.type == SDL_KEYDOWN)
				{

					if (pEvent.key.keysym.sym == SDLK_SPACE)
					{

						desplayer.y = desplayer.y - 25;
						cout << "UP arrow" << endl;
					}

					cout << "Key pressed" << endl;


				}
			}


			SDL_RenderCopy(render, player, &srcplayer, &desplayer);
			SDL_RenderPresent(render);

			SDL_Delay(1000/60);


		}
		







	}

	else
	{
		success = false;
	}
	
	
	

	return success;
}

void Game::update_dimensions()
{
	//Source Dimensions

	

	
	//cout << desplayer.y << endl;

	
	


}


Game:: ~Game()
{

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}
