#pragma once

#include "Repository.h"
#include <fstream>

template <typename TElement>
class FileRepository : public Repository<TElement> {
protected:
    std::string filename;

public:
    //sets repo filename
    void setFilename(const std::string& filename) {
        this->filename = filename;
        std::fstream file;
        file.open(this->filename, std::fstream::in | std::fstream::out | std::fstream::app);
        file.close();
    };

    //returns repo filename
    std::string getFilename() {
        return this->filename;
    };
};