#pragma once

#include "Repository.h"
#include <fstream>

class FileRepository : public Repository {
protected:
    std::string filename;

public:
    //sets repo filename
    void setFilename(const std::string& filename);

    //returns repo filename
    std::string getFilename();
};