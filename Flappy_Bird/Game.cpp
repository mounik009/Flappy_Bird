#include "Game.h"

namespace Gameloop
{

	class Game
	{
	public:

		SDL_Window* window;
		SDL_Renderer* render;
		SDL_Surface* gSurface;
		SDL_Surface* gTest_image;


		bool init();
		bool loadmedia();
		void close();

	};

}







