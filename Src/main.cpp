#include "GameInstance.h"

#include <raylib.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED);
	InitWindow(1200, 900, "Text Adventure Engine");
	SetTargetFPS(60);
	auto* game = new tae::GameInstance();

	while (!WindowShouldClose())
	{
		game->Update();
	}

	delete game;
	CloseWindow();

	return 0;
}
