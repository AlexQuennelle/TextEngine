#include "GameInstance.h"
#include "Scene.h"

#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

int main()
{
	InitWindow(1200, 900, "Text Adventure Engine");
	auto* game = new tae::GameInstance();

	while (!WindowShouldClose())
	{
		game->Update();
	}

	delete game;
	CloseWindow();

	return 0;
}
