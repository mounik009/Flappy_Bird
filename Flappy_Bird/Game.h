#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<Windows.h>
#include "TextureManager.h"

using namespace std;


class Game
{
public:

	const int SCREEN_HEIGHT = 1920;
	const int SCREEN_WIDTH = 1080;

	int score, highscore;
	bool playstate;
	bool menustate;
	double bird_rotate;

	

	SDL_Window* window;	//window pointer variable
	SDL_Renderer* render;	
	

	//Texture for MainMenu
	SDL_Texture* mainmenu;
	SDL_Texture* play;
	SDL_Texture* esc;
	SDL_Texture* hi_score;





	//Texture variable of the Player(bird)
	SDL_Texture* player1;
	SDL_Texture* player2;	
	
	//Pipe Texture

	SDL_Texture* pipe1a;
	SDL_Texture* pipe1b;
	
	SDL_Texture* bg;

	//ground
	SDL_Texture* levelloop1;
	SDL_Texture* levelloop2;

	//clouds
	SDL_Texture* cloud1;
	SDL_Texture* cloud2;
	SDL_Texture* cloud3;

	//menu birds
	SDL_Texture* tempbird1;
	//SDL_Texture* tempbird2;
	

	//Coords for Bird

	SDL_Rect srcplayer, desplayer;

	//Coords for Ground

	SDL_Rect srcground, desground1,desground2;

	//Coords for Pipe
	SDL_Rect srcpipe, despipe1a,despipe1b;
	SDL_Rect despipe2a;
	SDL_Rect despipe2b;
	SDL_Rect despipe3a, despipe3b;
	SDL_Rect despipe4a, despipe4b;
	SDL_Rect despipe5a, despipe5b;
	//COords for Menu Birds
	SDL_Rect srcbird,t_bird1, t_bird2,t_bird3;

	//Coords for Clouds
	SDL_Rect srccloud1,srccloud2,srccloud3, descloud1, descloud2, descloud3;
	SDL_Rect menupipe1, menupipe2,menupipe3,menupipe4;

	SDL_Event event1,pEvent,mainevent;

	//Coors for main menu




	bool gamestate;


	bool init();
	bool getgamestate();
	void Event();
	bool init_game();
	bool init_render();
	bool Menu();
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

	bird_rotate = 0;
	score = 0;
	//Dimensions for Ground
	srcground.h = 218;
	srcground.w = 3000;
	srcground.x = 0;
	srcground.y = 0;

	desground1.h = 200;
	desground1.w = 1920;
	desground1.x = 0;
	desground1.y = 880;

	//Dimensions for Ground loop2

	desground2.h = 200;
	desground2.w = 1920;
	desground2.x = desground1.x + 1920;
	desground2.y = desground1.y;

	//Source Dimensions for Bird

	srcplayer.h = 363;
	srcplayer.w = 410;
	srcplayer.x = 0;
	srcplayer.y = 0;


	//Destination Dimensions for Bird


	desplayer.h = 140;
	desplayer.w = 140;
	desplayer.x = 450;
	desplayer.y = 1;

	//Source Dimensions for Clouds
	srccloud1.h = 248;
	srccloud1.w = 427;
	srccloud1.x = 0;
	srccloud1.y = 0;

	//Source Dimensions for Cloud 2
	srccloud2.h = 267;
	srccloud2.w = 545;
	srccloud2.x = 0;
	srccloud2.y = 0;

	//Source Dimensions for Cloud 3
	srccloud3.h = 140;
	srccloud3.w = 258;
	srccloud3.x = 0;
	srccloud3.y = 0;

	//Destination Dimensions for Cloud 1
	descloud1.h = 200;
	descloud1.w = 400;
	descloud1.x = 100;
	descloud1.y = 100;

	//Destination Dimensions for Cloud 2
	descloud2.h = 200;
	descloud2.w = 400;
	descloud2.x = 1400;
	descloud2.y = 150;

	//Destination Dimensions for Cloud 3
	descloud3.h = 150;
	descloud3.w = 300;
	descloud3.x = 700;
	descloud3.y = 90;
	
	//Destination for Menu pipes
	menupipe1.h = 600;
	menupipe1.w = 140;
	menupipe1.x = 400;
	menupipe1.y = SCREEN_WIDTH-250;

	menupipe2.h = 600;
	menupipe2.w = 140;
	menupipe2.x = 400;
	menupipe2.y = -2;

	menupipe3.h = 600;
	menupipe3.w = 140;
	menupipe3.x = 1500;
	menupipe3.y = SCREEN_WIDTH-600;

	menupipe4.h = 600;
	menupipe4.w = 140;
	menupipe4.x = 1500;
	menupipe4.y = -300;

	//Source for Menu Birds

	srcbird.h = 248;
	srcbird.w = 321;
	srcbird.x = 0;
	srcbird.y = 0;

	//Source for Menu Birds
	t_bird1.h = 190;
	t_bird1.w = 210;
	t_bird1.x = 250;
	t_bird1.y = 270;

	t_bird2.h = 100;
	t_bird2.w = 110;
	t_bird2.x = 1700;
	t_bird2.y = 170;

	t_bird3.h = 140;
	t_bird3.w = 150;
	t_bird3.x = 1300;
	t_bird3.y = 350;

	//Source Dimensions for Pipe
	
	srcpipe.h = 736;
	srcpipe.w = 160;

	srcpipe.x = 0;
	srcpipe.y = 0;


	//Destination Dimensions for Pipe1

	despipe1a.h = 600;
	despipe1a.w = 140;
	despipe1a.x = SCREEN_HEIGHT;
	despipe1a.y = SCREEN_WIDTH-despipe1a.h +160 ;

	despipe1b.h = 500;
	despipe1b.w = 140;	   
	despipe1b.x = despipe1a.x;
	despipe1b.y = -180;


	//Destination of pipe2
	despipe2a.h = despipe1a.h;
	despipe2a.w = despipe1a.w;
	despipe2a.x = despipe1a.x +600;
	despipe2a.y = despipe1a.y - 180;

	despipe2b.h = despipe1b.h;
	despipe2b.w = despipe1b.w;
	despipe2b.x = despipe1b.x + 600;
	despipe2b.y = despipe1b.y -180;


	//Destination of Pipe3
	despipe3a.h = despipe2a.h;
	despipe3a.w = despipe2a.w;
	despipe3a.x = despipe2a.x + 600;
	despipe3a.y = despipe1a.y + 100;

	despipe3b.h = despipe2b.h;
	despipe3b.w = despipe2b.w;
	despipe3b.x = despipe2b.x + 600;
	despipe3b.y = despipe1b.y + 100;

	//Destination of Pipe 4

	despipe4a.h = despipe3a.h;
	despipe4a.w = despipe3a.w;
	despipe4a.x = despipe3a.x + 600;
	despipe4a.y = despipe1a.y -30;

	despipe4b.h = despipe3b.h;
	despipe4b.w = despipe3b.w;
	despipe4b.x = despipe3b.x + 600;
	despipe4b.y = despipe1b.y - 30;

	//Destination of Pipe5

	despipe5a.h = despipe4a.h;
	despipe5a.w = despipe4a.w;
	despipe5a.x = despipe4a.x + 600;
	despipe5a.y = despipe1a.y +160;

	despipe5b.h = despipe4b.h;
	despipe5b.w = despipe4b.w;
	despipe5b.x = despipe4b.x + 600;
	despipe5b.y = despipe1b.y +160;


	gamestate = false;
	playstate = true;
	menustate = true;
	bool success = true;

	SDL_Init(SDL_INIT_EVERYTHING);

	


	
	window = SDL_CreateWindow(" Flappy Bird ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);
	if (!(window))
	{
		std::cout << "Error Creating renderer , Error is : \n", SDL_GetError();
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

		std::cout << "\n\nWindow Closed\n\n";
	}
	
}

bool Game:: init_render()
{
	render = SDL_CreateRenderer(window, -1, 0);
	if (render)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Game::Menu()
{
	while (menustate == true)
	{

		//SDL_RenderCopy(render,)


		SDL_PollEvent(&mainevent);

		if (mainevent.type == SDL_KEYUP)
		{
			if (mainevent.key.keysym.sym == SDLK_SPACE)
			{
				return true;
			}
		}
	}
	
}

bool Game::init_game()
{
	bool success = true;
	
	

	if (render)
	{
		gamestate = true;
		std::cout << "Successfully Created Window";


		player1 = TextureManager::Texture("Assets/bird1.png", render);
		player2 = TextureManager::Texture("Assets/bird2.png",render);

		
		bg = TextureManager::Texture("Assets/BG.png", render);

		levelloop1 = TextureManager::Texture("Assets/ground.png", render);
		levelloop2 = TextureManager::Texture("Assets/ground.png", render);
		
		pipe1a = TextureManager::Texture("Assets/pillar.png", render);
		pipe1b = TextureManager::Texture("Assets/pillar_inverted.png",render);

		cloud1 = TextureManager::Texture("Assets/cloud 1.png", render);
		cloud2 = TextureManager::Texture("Assets/cloud 2.png", render);
		cloud3 = TextureManager::Texture("Assets/cloud 3.png", render);

		tempbird1 = TextureManager::Texture("Assets/birdtilt.png", render);
		

		mainmenu = TextureManager::Texture("Assets/menu_bg.png", render);


		static const char* mainmenu_bg = "Assets/menu_music.mpeg";

		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
		Mix_Music* music = Mix_LoadMUS(mainmenu_bg);
		Mix_PlayMusic(music, 1);

		SDL_RenderClear(render);
		while (menustate == true)
		{
			

			


			SDL_RenderCopy(render, bg, NULL, NULL);

			SDL_RenderCopy(render, cloud1, &srccloud1, &descloud1);
			SDL_RenderCopy(render, cloud2, &srccloud2,&descloud2 );
			SDL_RenderCopy(render, cloud3, &srccloud3, &descloud3);

			SDL_RenderCopy(render, pipe1a, &srcpipe, &menupipe1);
			SDL_RenderCopy(render, pipe1b, &srcpipe, &menupipe2);
			SDL_RenderCopy(render, pipe1a, &srcpipe, &menupipe3);
			SDL_RenderCopy(render, pipe1b, &srcpipe, &menupipe4);

			SDL_RenderCopy(render, tempbird1, &srcbird, &t_bird1);
			SDL_RenderCopy(render, tempbird1, &srcbird, &t_bird2);
			SDL_RenderCopy(render, player1, &srcplayer, &t_bird3);

			SDL_PollEvent(&mainevent);

			if (mainevent.type == SDL_KEYUP)
			{
				if (mainevent.key.keysym.sym == SDLK_SPACE)
				{
					playstate == true;
					menustate = false;

				}
				else if (mainevent.key.keysym.sym == SDLK_ESCAPE)
				{
					exit(90);
				}
			}

			SDL_RenderPresent(render);
		}
		
			
		while (playstate == true)
		{



			if (desplayer.y <900)
			{
				//cout << "true" << endl;

				SDL_RenderCopy(render, bg, NULL, NULL);

				desplayer.y = desplayer.y + 11;

				bird_rotate = 0;

				//cout << desplayer.y << endl;

				SDL_RenderCopy(render, cloud1, &srccloud1, &descloud1);

				descloud1.x -= 3;

				SDL_PollEvent(&pEvent);

				if (desplayer.y > 0)
				{


					if (pEvent.type == SDL_KEYDOWN)
					{

						if (pEvent.key.keysym.sym == SDLK_SPACE)
						{




							desplayer.y = desplayer.y - 80;

							if (bird_rotate < -60)
							{
								bird_rotate -= 10;
							}
							
							//acc++;

							std::cout << "Space" << endl;

						}




						if (pEvent.key.keysym.sym == SDLK_ESCAPE)
						{
							std::cout << "Escape" << endl;
							gamestate = false;
							break;
						}

						//cout << "Key pressed" << endl;




					}




				}




				if (desplayer.y <= 900)
				{

					despipe1a.x -= 10;
					despipe1b.x -= 10;

					despipe2a.x -= 10;
					despipe2b.x -= 10;

					despipe3a.x -= 10;
					despipe3b.x -= 10;

					despipe4a.x -= 10;
					despipe4b.x -= 10;

					despipe5a.x -= 10;
					despipe5b.x -= 10;




					SDL_RenderCopy(render, pipe1a, &srcpipe, &despipe1a);
					SDL_RenderCopy(render, pipe1b, &srcpipe, &despipe1b);


					SDL_RenderCopy(render, pipe1a, &srcpipe, &despipe2a);
					SDL_RenderCopy(render, pipe1b, &srcpipe, &despipe2b);

					SDL_RenderCopy(render, pipe1a, &srcpipe, &despipe3a);
					SDL_RenderCopy(render, pipe1b, &srcpipe, &despipe3b);

					SDL_RenderCopy(render, pipe1a, &srcpipe, &despipe4a);
					SDL_RenderCopy(render, pipe1b, &srcpipe, &despipe4b);

					SDL_RenderCopy(render, pipe1a, &srcpipe, &despipe5a);
					SDL_RenderCopy(render, pipe1b, &srcpipe, &despipe5b);



					//Collision for pipe 1

					if (desplayer.x + desplayer.w / 2 > despipe1b.x - (despipe1b.w / 2) + 30 && desplayer.x < despipe1b.x + (despipe1b.w / 2) + 30)
					{
						//cout << desplayer.x << endl;

						if (desplayer.x == despipe1a.x)
						{
							score++;
						}
						if (desplayer.y <= despipe1b.h + despipe1b.y - 30 || desplayer.y >= despipe1a.h - 40)
						{



							exit(0);
						}
					}

					//Collision for pipe 2
					if (desplayer.x + desplayer.w / 2 > despipe2a.x - (despipe2a.w / 2) && desplayer.x < despipe2a.x + (despipe2a.w / 2) + 30)
					{
						if (desplayer.x == despipe2a.x)
						{
							score++;
						}
						if (desplayer.y <= despipe2b.h + despipe2b.y - 30 || desplayer.y >= despipe2a.h - 30)
						{

							exit(0);
						}
					}


					//Collision for pipe 3
					if (desplayer.x + desplayer.w / 2 > despipe3a.x - (despipe3a.w / 2) + 30 && desplayer.x < despipe3a.x + (despipe3a.w / 2) + 30)
					{
						if (desplayer.x == despipe3a.x)
						{
							score++;
						}

						if (desplayer.y <= despipe3b.h + despipe3b.y - 30 || desplayer.y >= despipe3a.h + 10)
						{


							exit(0);
						}
					}

					//Collision for pipe 4

					if (desplayer.x + desplayer.w / 2 > despipe4a.x - (despipe4a.w / 2) + 30 && desplayer.x < despipe4a.x + (despipe4a.w / 2) + 30)
					{

						if (desplayer.x == despipe4a.x)
						{
							score++;
						}
						if (desplayer.y <= despipe4b.h + despipe4b.y - 30 || desplayer.y >= despipe4a.h - 20)
						{

							exit(0);
						}
					}

					//Collision for pipe 5

					if (desplayer.x + desplayer.w / 2 > despipe5a.x - (despipe5a.w / 2) + 30 && desplayer.x < despipe5a.x + (despipe5a.w / 2) + 30)
					{

						if (desplayer.x == despipe5a.x)
						{
							score++;
						}
						if (desplayer.y <= despipe5b.h + despipe5b.y - 30 || desplayer.y >= despipe5a.h + 100)
						{



							exit(0);
						}
					}


					SDL_RenderPresent(render);





				}




				/*if (desplayer.y % 2 == 0)
				{
					SDL_RenderCopy(render, player1, &srcplayer, &desplayer);


				}
				else if (desplayer.y % 2 != 0)
				{
					SDL_RenderCopy(render, player2, &srcplayer, &desplayer);


				}*/

				SDL_RenderCopyEx(render, SDL_GetTicks() % 200 > 150 ? player1 : player2, & srcplayer, & desplayer, 0 , NULL, SDL_FLIP_NONE);

				if (despipe1a.x < -1100)
				{
					despipe1a.x = SCREEN_HEIGHT;
					despipe1b.x = despipe1a.x;
				}

				if (despipe2a.x < -1100)
				{
					despipe2a.x = despipe1a.x + 600;
					despipe2b.x = despipe1b.x + 600;
				}

				if (despipe3a.x < -1100)
				{
					despipe3a.x = despipe2a.x + 600;
					despipe3b.x = despipe2b.x + 600;
				}

				if (despipe4a.x < -1100)
				{
					despipe4a.x = despipe3a.x + 600;
					despipe4b.x = despipe3b.x + 600;
				}

				if (despipe5a.x < -1100)
				{
					despipe5a.x = despipe4a.x + 600;
					despipe5b.x = despipe4b.x + 600;
				}

				SDL_RenderCopy(render, levelloop1, &srcground, &desground1);
				SDL_RenderCopy(render, levelloop2, &srcground, &desground2);

				desground1.x -= 11;
				desground2.x -= 11;
				if (desground1.x < -1920)
				{
					desground1.x = 0;
					desground2.x = 1920;

				}






				SDL_RenderPresent(render);

				SDL_Delay(1000 / 24);

				std::cout << score << endl;








			}




		}
	}

	else
	{
		//success = false;
	}
	
	
	

	return success;
}




Game:: ~Game()
{

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}
