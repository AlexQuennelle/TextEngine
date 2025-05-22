#include "GameInstance.h"

#include <cmath>
#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

namespace tae
{

GameInstance::GameInstance()
{
	std::string fontPath =
		RESOURCES_PATH "/Fonts/JetBrainsMonoNerdFont-Bold.ttf";
	this->LoadFont(fontPath, this->vChars);
	this->LoadAdventure(RESOURCES_PATH "example.yaml");
	this->state = GameState::Adventure;
}
void GameInstance::Update()
{
	switch (this->state)
	{
	default:
		break;
	}
	// TODO: Update loop
	this->Draw();
}

void GameInstance::Draw()
{
	BeginDrawing();
	ClearBackground({0, 0, 0, 255});
	switch (this->state)
	{
	case GameState::MainMenu:
		break;
	case GameState::Adventure:
		DrawTextEx(this->font, this->scenes[0].GetText(92).c_str(), {0.0f, 0.0f},
				   static_cast<float>(this->font.baseSize), 0.0f, WHITE);
		break;
	default:
		break;
	}
	EndDrawing();
}
void GameInstance::LoadAdventure(const std::string& filePath)
{
	YAML::Node rootNode = YAML::LoadFile(filePath)["scenes"];
	this->scenes.reserve(rootNode.size());
	for (auto scene : rootNode)
	{
		this->scenes.emplace_back(scene);
	}
}
void GameInstance::LoadFont(const std::string& filePath, uint8_t lineCount)
{
	this->font = LoadFontEx(filePath.c_str(), GetScreenHeight() / lineCount,
							nullptr, 240);
	float charWidth =
		MeasureTextEx(this->font, " ", this->font.baseSize, 0.0f).x;
	this->hChars = std::floor(GetScreenWidth() / charWidth);
}

} //namespace tae
