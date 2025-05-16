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

} //namespace tae
