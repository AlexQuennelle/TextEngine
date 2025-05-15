#pragma once

#include <string>
#include <vector>
#include <yaml-cpp/node/node.h>

namespace tae
{

using std::vector;

class Scene
{
	public:
	Scene(YAML::Node node);

	std::string text;

	private:
};

} //namespace tae
