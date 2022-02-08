#pragma once

#include "Game.h"

class TextureManager
{
public:
	static SDL_Texture* Texture(const char* filelocation, SDL_Renderer* ren);
};

SDL_Texture* TextureManager::Texture(const char* filelocation, SDL_Renderer* ren)
{
	SDL_Surface* surface = NULL;
	surface = IMG_Load(filelocation);

	SDL_Texture* tex = NULL;

	tex = SDL_CreateTextureFromSurface(ren, surface);
	return tex;
}
