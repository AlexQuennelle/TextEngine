#include "Scene.h"

#include <fstream>
#include <iosfwd>
#include <iostream>

namespace tae
{

using std::ios;

vector<Scene>* ParseFile(const string& filePath)
{
	auto* scenes = new vector<Scene>();
	std::streampos fileSize;
	vector<char> fileData;

	std::ifstream file(filePath.c_str(), ios::in | ios::ate);
	if (file.is_open())
	{
		fileSize = file.tellg();
		fileData.resize(fileSize);
		file.seekg(0, ios::beg);
		file.read(fileData.data(), fileSize);
		file.close();
		std::cout << fileData;
	}
	else
	{
		std::cout << "Unable to open " << filePath << '\n';
	}
	return scenes;
}
std::ostream& operator<<(std::ostream& os, const std::vector<char>& data)
{
	os << '\n';
	for (auto character : data)
	{
		os << character;
	}
	os << '\n';
	return os;
}

} //namespace tae
