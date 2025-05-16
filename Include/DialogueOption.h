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

	int32_t sceneID;
	std::string text;

	private:
};

} //namespace tae
