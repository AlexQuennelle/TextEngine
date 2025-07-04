#pragma once

#include <cstdint>
#include <string>
#include <yaml-cpp/node/node.h>

namespace tae
{

class DialogueOption
{
	public:
	DialogueOption(YAML::Node node);
	std::string GetText(uint16_t hChars, uint16_t prefix);

	int32_t sceneID;
	std::string text;

	private:
};

} //namespace tae
