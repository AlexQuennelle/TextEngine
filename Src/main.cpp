#include "Scene.h"

#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

int main()
{
	InitWindow(1200, 900, "Text Adventure Engine");

	YAML::Node rootNode = YAML::LoadFile(RESOURCES_PATH "test.yaml")["scenes"];
	std::vector<tae::Scene> scenes;
	scenes.reserve(rootNode.size());

	Font font =
		LoadFontEx(RESOURCES_PATH "/Fonts/JetBrainsMonoNerdFont-Bold.ttf",
				   GetScreenHeight() / 30, nullptr, 250);

	float textWidth =
		MeasureTextEx(font, " ", static_cast<float>(font.baseSize / 2), 0.0f).x;

	for (auto scene : rootNode)
	{
		scenes.emplace_back(scene);
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({0, 0, 0, 255});
		DrawTextEx(font, scenes[0].GetText().c_str(), {0.0f, 0.0f},
				   static_cast<float>(font.baseSize / 2), 0.0f, WHITE);

		DrawRectangle(0, 30, static_cast<int>(textWidth), 5, RED);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
