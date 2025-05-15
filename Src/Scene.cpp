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
	}
	else
	{
		std::cerr << "Invalid scene.\n";
	}
}

} //namespace tae
