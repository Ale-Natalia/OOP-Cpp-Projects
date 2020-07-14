#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cassert>

class Object {
public:
	Object(){}
	~Object(){}
	virtual void print() = 0;
};

class Integer : public Object {
private:
	int integer;
public:
	Integer() : integer{ 0 } {}
	Integer(int integer) : integer{integer} {}
	~Integer(){}
	void print() override {
		std::cout << this->integer << " ";
	}
};

class String : public Object {
private:
	std::string str;
public:
	String() {}
	String(std::string str) : str{ str } {}
	~String() {}
	bool operator==(const std::string& s) {
		String thisStr = this->str;
		return (thisStr == s);
	}
	void print() override {
		std::cout << this->str << " ";
	}
};

class MyObjectList {
private:
	std::vector<Object*> elements;
	friend class ListIterator;
public:
	MyObjectList(){}
	~MyObjectList() {
		for (auto& element : elements)
			delete element;
	}
	MyObjectList add(Object* element) {
		 this->elements.push_back(element);
		 return *this;
	}
	int length()const {
		return this->elements.size();
	}
};

class ListIterator {
private:
	MyObjectList* list;
	int current;
public:
	ListIterator() {
		this->list = new MyObjectList();
		this->current = 0;
	}
	ListIterator(MyObjectList list) {
		this->list = &list;
		this->current = 0;
	}
	~ListIterator() { delete this->list; }
	bool isValid() {
		if (this->current < this->list->length())
			return true;
		return false;
	}
	Object* element(){
		return this->list->elements[current];
	};
	void next() {
		this->current++;
	}
};

void function()
{
	MyObjectList list{};
	list.add(new Integer{ 2 }).add(new String{ "Hi" });
	String* s = new String{ "Bye" };
	assert(*s == "Bye");
	list.add(s).add(new Integer{ 5 });
	assert(list.length() == 4);

	ListIterator i{ list };
	while (i.isValid()) {
		Object* o = i.element();
		o->print();
		i.next();
	} // prints: 2 Hi Bye 5
}