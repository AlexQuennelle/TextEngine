#include "Scene.h"
#include "raylib.h"

int main()
{
	InitWindow(800, 800, "Text Adventure Engine");

	tae::ParseFile(RESOURCES_PATH "test.json");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground({100, 149, 237, 255});
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
