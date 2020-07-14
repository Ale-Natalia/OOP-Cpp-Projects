#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <memory>
//11:47


class Beverage {
protected:
	std::string description;
public:
	//default constructor
	Beverage() {}

	//constructor with parameters
	Beverage(std::string description) {
		this->description = description;
	};

	//copy constructor
	Beverage(Beverage* beverage) {
		this->description = beverage->description;
	}
	virtual double price() const = 0;
	void print() {
		std::cout << description << " " << price() << " ";
	};
};

class Coffee : public Beverage {
public:
	Coffee() : Beverage("Coffee") {}
	Coffee(Coffee* coffee) : Beverage("Coffee") {}
	double price() const override {
		return 2.5;
	}
};

class Tea : public Beverage {
public:
	Tea() : Beverage("Tea") {}
	Tea(Tea* tea) : Beverage("Tea") {}
	double price() const override {
		return 1.5;
	}
};

class BeverageWithExtraIngredient : public Beverage {
protected:
	Beverage* beverage;
public: 
	BeverageWithExtraIngredient(Beverage* _beverage) {
		this->beverage = _beverage;
	};
	double price() const override {
		return this->beverage->price();
	}
	void print() {
		this->beverage->print();
	}
};

class BeverageWithMilk : public BeverageWithExtraIngredient {
private:
	int milkCount;
	//Beverage* beverage;
public:
	BeverageWithMilk(BeverageWithExtraIngredient* beverage, int milkCount) : BeverageWithExtraIngredient(beverage), milkCount{ milkCount } {
	};
	double price() const override {
		return BeverageWithExtraIngredient::price() + 0.5 * this->milkCount;
	}
	void print() {
		Beverage::print();
		std::cout << "price" << this->price() << " ";
		std::cout << std::to_string(milkCount) << " extra milk" << " ";
	}
};

class BeverageWithSugar : public BeverageWithExtraIngredient {
private:
	int sugarCount;
	//Beverage* beverage;
public:
	BeverageWithSugar(BeverageWithExtraIngredient* beverage, int sugarCount) : BeverageWithExtraIngredient(beverage), sugarCount{ sugarCount } {
	};
	double price() const override {
		return BeverageWithExtraIngredient::price() + 0.3 * this->sugarCount;
	}
	void print() {
		Beverage::print();
		std::cout << "price" << this->price() << " ";
		std::cout << std::to_string(sugarCount) << " extra sugar" << " ";
	}
};

class BeverageMachine {
public:
	BeverageMachine() {};
	void prepare(std::string beverageType, int milkCount, int sugarCount) {
		if (beverageType == "Tea") {
			Tea* tea = new Tea();
			BeverageWithExtraIngredient* teaExtra = new BeverageWithExtraIngredient(tea);
			BeverageWithMilk* milkTea = new BeverageWithMilk(teaExtra, milkCount);
			//BeverageWithSugar* milkSugarTea = new BeverageWithSugar(milkTea, sugarCount);
			//milkSugarTea->print();
			milkTea->print();
			std::cout << "\n";
		}
		else if (beverageType == "Coffee") {
			Coffee* coffee = new Coffee();
			BeverageWithExtraIngredient* coffeeExtra = new BeverageWithExtraIngredient(coffee);
			BeverageWithMilk* milkCoffee = new BeverageWithMilk(coffeeExtra, milkCount);
			//BeverageWithSugar* milkSugarCoffee = new BeverageWithSugar(milkCoffee, sugarCount);
			//milkSugarCoffee->print();
			milkCoffee->print();
			std::cout << "\n";
		}
	}
};

