#include<SDL.h>
#include<iostream>
#include<Windows.h>
using namespace std;

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window;
	SDL_Renderer* render;

	window = NULL;
	render = NULL;

	window = SDL_CreateWindow("My New Game ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 480, SDL_WINDOW_RESIZABLE);

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

	cout << "\n\n\t\tGame Window will open and Close after 10 seconds\n\n";
	int i = 1;
	while (i<=10)
	{
		SDL_RenderClear(render);
		SDL_RenderPresent(render);
		Sleep(1000);
		cout << "\t\t" << i << endl;
		i++;
	}


	return 0;
}
