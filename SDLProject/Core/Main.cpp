#include "SDL.h"
#include "GameClient.h"

GameClient* client = nullptr;

int main(int argc, char* argv[])
{

	const int FPS = 60;
	const int frameDelay = 1000 / FPS; //max time between frames

	Uint32 frameStart;
	int frameTime;

	client = new GameClient();

	client->Init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (client->IsRunning())
	{
		frameStart = SDL_GetTicks();

		client->HandleEvents();
		client->Update();
		client->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	client->Clean();

	return 0;
}