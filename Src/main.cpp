#include "Scene.h"

#include <iostream>
#include <raylib.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

int main()
{
	InitWindow(800, 800, "Text Adventure Engine");

	YAML::Node rootNode = YAML::LoadFile(RESOURCES_PATH "test.yaml")["scenes"];
	std::vector<tae::Scene> scenes;
	scenes.reserve(rootNode.size());
	for (auto scene : rootNode)
	{
		scenes.emplace_back(scene);
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({100, 149, 237, 255});
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
