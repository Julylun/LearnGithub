#include <SDL.h>
#include <iostream>
//#undef main


SDL_Window* gMainFrame = nullptr;
SDL_Surface* gMainFrameSurface = nullptr;
bool init();

bool loadMedia(char path[]) {
	SDL_Surface* surfaceImage = nullptr;

	surfaceImage = SDL_LoadBMP(path);
	if (surfaceImage == NULL) {
		std::cout << "Load image gets errors " << SDL_GetError() << "\n";
		return false;
	}

	SDL_BlitSurface(surfaceImage, NULL, gMainFrameSurface, NULL);
	return true;
}

bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL Init gets error - " << SDL_GetError() << "\n";
		return false;
	}
	gMainFrame = SDL_CreateWindow("Project 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 300, SDL_WINDOW_SHOWN);
	gMainFrameSurface = SDL_GetWindowSurface(gMainFrame);

	return true;
}

int main(int argc, char* args[]) {
	init();
	loadMedia("resources/Untitled.bmp");
	return 0;
}