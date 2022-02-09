#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<Windows.h>
#include "Game.h"
using namespace std;



int main(int argc, char* argv[])
{

	play.init();


	if(play.getgamestate())
	{
		//play.update_dimensions();
		play.init_renderer();
		play.Event();


		
	}

	
	

	return 0;
}



	

	
	

	


