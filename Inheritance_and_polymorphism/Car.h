#pragma once
#include <string>
#include <vector>
#include <vcruntime_exception.h>
#include <exception>
#include <algorithm>
#include <cassert>
#include <iostream>

//12:35 - 13:10
class Car {
private:
	std::string brand;
	int score;
public:
	Car(std::string brand, int score) {
		this->brand = brand;
		this->score = score;
	}
	~Car(){}

	bool operator>(const Car& car) {
		return this->score > car.score;
	}

	bool operator>=(Car& car) {
		return this->score >= car.score;
	}

	bool operator<(Car& car) {
		return this->score < car.score;
	}

	bool operator<=(const Car& car) {
		return this->score <= car.score;
	}

	friend std::ostream& operator<<(std::ostream& os, const Car& car) {
		os << car.brand << " " << car.score << " ";
		return os;
	}
};

template <typename TElem, typename Attribute>
class List {
private:
	std::vector<std::pair<TElem, Attribute>> elements;
public:
	List(){}
	~List(){}

	void add(TElem element, Attribute attribute) {
		this->elements.push_back(std::pair<TElem, Attribute>{element, attribute});
	};

	//the list is sorted by the first component
	//using a lambda sort rule and a lambda sort
	//throws error if the list is empty
	void sortByFirstComponent() {
		if (this->elements.size() == 0){
			//throw "error";
			//int* p = NULL;
			//*p = 42;
		}
		auto sortByFirstComponentRule = [](std::pair<TElem, Attribute> elem1, std::pair<TElem, Attribute> elem2) {
			return elem1.first < elem2.first;
		};
		std::sort(this->elements.begin(), this->elements.end(), sortByFirstComponentRule);
	};

	void sortBySecondComponent() {
		auto sortBySecondComponentRule = [](std::pair<TElem, Attribute> const& elem1, std::pair<TElem, Attribute> const& elem2) {
			return elem1.second < elem2.second;
		};
		std::sort(this->elements.begin(), this->elements.end(), sortBySecondComponentRule);
	};

	void printReverse(std::ostream& os) {
		for (int i = this->elements.size() - 1; i > 0; i--) {
			os << this->elements[i].first << "->" << this->elements[i].second << "; ";
		}
		os << this->elements[0].first << "->" << this->elements[0].second << "\n";
	}
};

void function1() {
	List<Car, int> list1;
	try {
		list1.sortByFirstComponent();
		assert(false);
	}
	catch (std::runtime_error & e) { assert(strcmp(e.what(), "List is empty!") == 0); }

	list1.add(Car{ "Audi", 20 }, 8);
	list1.add(Car{ "Volkswagen", 10 }, 9);
	list1.add(Car{ "Bentley", 300 }, 10);

	list1.sortByFirstComponent();
	list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Audi 20 -> 8; Volkswagen 10 -> 9 
	list1.sortBySecondComponent();
	list1.printReverse(std::cout); // prints: Bentley 300 -> 10; Volkswagen 10 -> 9; Audi 20 -> 8;
}