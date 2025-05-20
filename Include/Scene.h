#pragma once

#include "DialogueOption.h"

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
	std::string GetText();

	private:
	std::string text;
	std::vector<DialogueOption> options;
};

} //namespace tae
