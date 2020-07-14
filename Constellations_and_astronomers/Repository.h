#pragma once
#include "Domain.h"
#include "Observer.h"
#include <string>

//typedef Star TElement;

template <typename TElement>
class Repository : public Observable {
public:
    virtual int searchElementByName(const std::string& name) = 0;

    virtual int searchElement(const TElement& element) = 0;

    /*
          adds an element to the repository
          throws error if invalid
      */
    virtual void addElement(const TElement& element) = 0;

    /*
        updates the info of a given element from the repository
        returns the old element
        throws error if invalid
    */
    virtual TElement updateElement(const TElement& element) = 0;

    /*
        removes an element from the repository
        returns the deleted element
        throws error if invalid
    */
    virtual TElement deleteElement(const TElement& element) = 0;


    //getter for all the elements in the repository
    virtual std::vector<TElement> getElements() = 0;

    //getter for the size of the dynamic vector in the repo
    virtual int getSize() = 0;

    virtual ~Repository() {}
};