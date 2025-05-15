#pragma once

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

namespace tae
{

using std::vector;
using std::string;

class Scene
{
	public:
	private:
};

vector<Scene>* ParseFile(const string& filePath);

std::ostream& operator<<(std::ostream& os, const std::vector<char>& data);

} //namespace tae
