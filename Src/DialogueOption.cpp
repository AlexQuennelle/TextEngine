#include "DialogueOption.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/yaml.h>

namespace tae
{

DialogueOption::DialogueOption(YAML::Node node)
{
	if (node.IsMap())
	{
		this->text = node["text"].as<std::string>();
		this->sceneID = node["sceneID"].as<int32_t>();
	}
	else
	{
		std::cerr << "Invalid dialogue option.\n";
	}
}
std::string DialogueOption::GetText(uint16_t hChars, uint16_t prefix)
{
	std::string interim = std::to_string(prefix) + ". " + this->text;
	std::string wrappedString = interim;
	uint16_t charsOnLine{0};
	uint16_t lastSpace{0};
	for (uint16_t i{0}; i < interim.length(); i++)
	{
		if (interim[i] == ' ')
		{
			lastSpace = i;
		}

		if (charsOnLine < hChars)
		{
			charsOnLine++;
		}
		else
		{
			wrappedString[lastSpace] = '\n';
			charsOnLine = 0;
		}

		if (interim[i] == '\n')
		{
			charsOnLine = 0;
		}
	}
	return wrappedString;
}

} //namespace tae
