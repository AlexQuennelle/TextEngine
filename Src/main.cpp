#include "Scene.h"

#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

struct FontData
{
	uint32_t vChars;
	uint32_t hChars;
};

FontData FONTDATA{30, 87};

int main()
{
	InitWindow(1200, 900, "Text Adventure Engine");

	YAML::Node rootNode = YAML::LoadFile(RESOURCES_PATH "test.yaml")["scenes"];
	std::vector<tae::Scene> scenes;
	scenes.reserve(rootNode.size());

	Font font =
		LoadFontEx(RESOURCES_PATH "/Fonts/JetBrainsMonoNerdFont-Bold.ttf",
				   GetScreenHeight() / FONTDATA.vChars, 0, 250);

	std::cout << "font padding: "
			  << MeasureTextEx(font,
							   "The text can contain newlines and whitespace "
							   "as long as a vertical bar is placed before ",
							   static_cast<float>(font.baseSize), 0.6f)
					 .x
			  << '\n';

	for (auto scene : rootNode)
	{
		scenes.emplace_back(scene);
	}

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({0, 0, 0, 255});
		DrawTextEx(font, scenes[0].GetText().c_str(), {0.0f, 0.0f},
				   static_cast<float>(font.baseSize), 0.6f, WHITE);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
