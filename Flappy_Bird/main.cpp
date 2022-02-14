#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<Windows.h>
#include "Game.h"
using namespace std;



int main(int argc,char** argv)
{

	play.init();


	while(play.getgamestate())
	{
		if (play.init_render())
		{
			play.init_game();
			play.Event();
			
			
		}
			
	}

	
	

	return 0;
}



	

	
	

	


