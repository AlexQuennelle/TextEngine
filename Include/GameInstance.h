#pragma once

#include "Scene.h"

#include <cstdint>
#include <raylib.h>
#include <string>
#include <vector>

namespace tae
{

enum class GameState : uint8_t
{
	MainMenu,
	Adventure,
};

/**
 * Class that contains data and functionality related to an instance of the game
 */
class GameInstance
{
	public:
	GameInstance();
	void Update();

	private:
	void Draw();
	void DrawGameplay();
	void LoadAdventure(const std::string& filePath);
	/**
	 * Loads a font and sets some related variables
	 * @param lineCount Number of characters that fit on the screen vertically.
	 */
	void LoadFont(const std::string& filePath, uint8_t lineCount);

	uint16_t hChars;
	uint8_t vChars{30};
	uint32_t sceneIndex{0};
	Vector2 fontSize;
	GameState state{GameState::MainMenu};
	Font font;
	std::vector<tae::Scene> scenes;
};

} //namespace tae
