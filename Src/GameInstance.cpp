#include "GameInstance.h"

#include <cmath>
#include <cstdint>
#include <iostream>
#include <raylib.h>

namespace tae
{

GameInstance::GameInstance()
{
	std::string fontPath =
		RESOURCES_PATH "/Fonts/JetBrainsMonoNerdFont-Bold.ttf";
	LoadFont(fontPath, this->vChars);
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
