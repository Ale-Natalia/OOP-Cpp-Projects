#pragma once
#include "Repository.h"
#include "Task.h"

typedef Task TElement;

class InMemoryRepository : public Repository {

private:
    std::vector<TElement> elements;
public:
    // default constructor
    InMemoryRepository() {};

    int searchElementByTitle(const std::string& title)override;
    
    void addElement(const TElement& element)override;

    TElement deleteElement(const TElement& element)override;

    TElement updateElement(const TElement& element)override;

    std::vector<TElement> getElements() const override { return  this->elements; }

    int getSize()override;
};