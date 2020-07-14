#include "FileRepository.h"

void FileRepository::setFilename(const std::string& filename)
{
	this->filename = filename;
	std::fstream file;
	file.open(this->filename, std::fstream::in | std::fstream::out | std::fstream::app);
	file.close();
}

std::string FileRepository::getFilename()
{
	return this->filename;
}
