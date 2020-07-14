#pragma once
#include "Repository.h"
#include "Domain.h"
#include <vector>

typedef Document TElement;

class InMemoryRepository : public Repository {

private:
    std::vector<TElement> elements;
public:
    // default constructor
    InMemoryRepository() {};

    int searchElementByTitle(const std::string& title)override;

    void addElement(const TElement& element)override;

    void deleteElement(const TElement& element)override;

    void updateElement(const TElement& element)override;

    std::vector<TElement> getElements() const override { return  this->elements; }

    int getSize()override;
};