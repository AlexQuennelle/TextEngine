#include "Scene.h"

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <yaml-cpp/node/node.h>
#include <yaml-cpp/yaml.h>

namespace tae
{

Scene::Scene(YAML::Node node)
{
	if (node.IsMap())
	{
		this->text = node["text"].as<std::string>();
		this->options.reserve(node["options"].size());
		for (auto optionData : node["options"])
		{
			auto* option = new DialogueOption(optionData);
			this->options.push_back(*option);
		}
	}
	else
	{
		std::cerr << "Invalid scene.\n";
	}
}

std::string Scene::GetText(uint16_t hChars)
{
	std::string wrappedString = this->text;
	uint16_t charsOnLine{0};
	uint16_t lastSpace{0};
	for (uint16_t i{0}; i < this->text.length(); i++)
	{
		if (this->text[i] == ' ')
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

		if (this->text[i] == '\n')
		{
			charsOnLine = 0;
		}
	}
	return wrappedString;
}

} //namespace tae
