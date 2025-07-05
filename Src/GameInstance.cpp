#include "GameInstance.h"

#include <cmath>
#include <cstdint>
#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/node/parse.h>
#include <yaml-cpp/yaml.h>

namespace tae
{
RenderTexture2D target;

const Color fg = {242, 244, 248, 255};

GameInstance::GameInstance()
{
	std::string fontPath =
		RESOURCES_PATH "/Fonts/JetBrainsMonoNerdFont-Bold.ttf";
	this->LoadFont(fontPath, this->vChars);
	this->fontSize = MeasureTextEx(this->font, " ", this->font.baseSize, 0);
	SetWindowSize(82 * this->fontSize.x, 25 * this->fontSize.y);
	this->LoadAdventure(RESOURCES_PATH "example.yaml");
	this->state = GameState::Adventure;
	std::cout << "\033[38;2;220;220;0m" << "Font dimensions: ";
	std::cout << "(" << fontSize.x << ", " << fontSize.y << ")\n\033[0m";
	target = LoadRenderTexture(82 * this->fontSize.x, 25 * this->fontSize.y);
}
void GameInstance::Update()
{
	uint16_t key = GetKeyPressed();
	switch (this->state)
	{
	case GameState::MainMenu:
		// TODO: List all yaml files in resources directory
		// Also display any image that shares a name with the yaml file
		// Use arrow keys for navigation.
		break;
	case GameState::Adventure:
		// Subtract 49 from key to rebase the values such that the 1 key is 0
		if (key - 49 < 9 && key - 49 < scenes[sceneIndex].options.size())
		{
			sceneIndex = scenes[sceneIndex].options[key - 49].sceneID;
		}
		if (sceneIndex == -1)
		{
			state = GameState::MainMenu;
		}
		break;
	default:
		break;
	}
	this->Draw();
}

void GameInstance::Draw()
{
	BeginDrawing();
	BeginTextureMode(target);
	ClearBackground(BLANK);
	switch (this->state)
	{
	case GameState::MainMenu:
		break;
	case GameState::Adventure:
		DrawGameplay();
		break;
	default:
		break;
	}
	EndTextureMode();
	ClearBackground({20, 20, 20, 216});
	DrawTexturePro(target.texture,
				   {0.0f, 0.0f, static_cast<float>(GetRenderWidth()),
					-static_cast<float>(GetRenderHeight())},
				   {0.0f, 0.0f, static_cast<float>(GetRenderWidth()),
					static_cast<float>(GetRenderHeight())},
				   {0.0f, 0.0f}, 0.0f, fg);
	EndDrawing();
}
void GameInstance::DrawGameplay()
{
	DrawTextEx(this->font, this->scenes[this->sceneIndex].GetText(80).c_str(),
			   {this->fontSize.x, this->fontSize.y / 2.0f},
			   static_cast<float>(this->font.baseSize), 0.0f, fg);
	std::vector<DialogueOption> options =
		this->scenes[this->sceneIndex].options;

	auto pos = Vector2(this->fontSize.x,
					   GetRenderHeight() - (this->fontSize.y * 2.5f));
	//for (auto& option : std::ranges::reverse_view(options))
	for (uint64_t i{options.size()}; i > 0; i--)
	{
		std::string text = options[i - 1].GetText(80, i);
		float textH =
			MeasureTextEx(this->font, text.c_str(), this->font.baseSize, 0.0f)
				.y;
		//DrawTextEx(this->font, option.GetText(80).c_str(), pos,
		DrawTextEx(this->font, text.c_str(), pos,
				   static_cast<float>(this->font.baseSize), 0.0f, WHITE);
		pos.y -= textH;
	}
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
