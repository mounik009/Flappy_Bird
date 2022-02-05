#include<SDL.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window;
	SDL_Renderer* render;

	window = NULL;
	render = NULL;

	window = SDL_CreateWindow(" Flappy Bird ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 480, SDL_WINDOW_RESIZABLE);

	if (window)
	{

		render = SDL_CreateRenderer(window, -1, 0);

		if (render)
		{
			cout << "Successfully Created Window";
		}
		else
		{
			cout << "Not Created";
		}
	}
	else
	{
		cout << "Error Creating Window";
	}

	while (1)
	{
		SDL_RenderClear(render);
		SDL_RenderPresent(render);
	}


	return 0;
}
