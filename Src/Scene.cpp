#include "Scene.h"

#include <cassert>
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

} //namespace tae
