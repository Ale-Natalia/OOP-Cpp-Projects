#include "FileFunctions.h"

void clearFile(const std::string& filename)
{
	std::fstream file;
	file.open(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
	file.close();
}

std::vector<std::string> readConfigurationFile(const std::string& filename)
{
	std::vector<std::string> repoTypes;
	std::ifstream file(filename);
	std::string repoType;
	int index = 0;
	while (file >> repoType)
	{
		repoTypes.push_back(repoType);
	}
	file.close();
	return repoTypes;
}
