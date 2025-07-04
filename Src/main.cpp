#include "GameInstance.h"
#include "Scene.h"

#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED);
	InitWindow(1200, 900, "Text Adventure Engine");
	SetWindowOpacity(100.0f);
	auto* game = new tae::GameInstance();


	while (!WindowShouldClose())
	{
		game->Update();
	}

	delete game;
	CloseWindow();

	return 0;
}
