#pragma once

#include "DialogueOption.h"

#include <cstdint>
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
	std::string GetText(uint16_t hChars);

	std::vector<DialogueOption> options;

	private:
	std::string text;
};

} //namespace tae
