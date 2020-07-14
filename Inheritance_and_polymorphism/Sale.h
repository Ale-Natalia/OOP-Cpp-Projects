#pragma once
#include <vector>
#include <string>
#include <iostream>
//11:27

class SaleItem {
private:
	int code;
	double price;
public:
	SaleItem(int code, double price) {
		this->code = code;
		this->price = price;
	}
	int getCode() { return this->code; }
	double getPrice() { return this->price; }
};

class Sale {
private:
	std::vector<SaleItem> elements;
public:
	std::vector<SaleItem> getSaleItems() {
		return this->elements;
	};
	void addItem(SaleItem item) {
		this->elements.push_back(item);
	}
};

class Discount {
public:
	virtual double calc(Sale s) = 0;
};

class ItemDiscount : public Discount {
private:
	int code;
	int percentage;
public:
	ItemDiscount(int code, int percentage) : code{ code }, percentage{percentage} {}
	double calc(Sale s) override {
		for (auto& saleItem : s.getSaleItems()) {
			if (saleItem.getCode() == this->code)
				return this->percentage * 0.01 * saleItem.getPrice();
		}
	}
};
//11:41

class SumDiscount : public Discount {
private:
	std::vector<Discount*> discounts;
public:
	void add(Discount* discount) {
		this->discounts.push_back(discount);
	}
	double calc(Sale s) override{
		double totalDiscount = 0.0;
		for (Discount* discount : this->discounts) {
			totalDiscount += discount->calc(s);
		}
		return totalDiscount;
	}
};
//11:45

void printSale() {
	Sale s;
	SaleItem s1 = SaleItem(1, 5.6);
	SaleItem s2 = SaleItem(2, 20.35);
	SaleItem s3 = SaleItem(3, 99.99);
	s.addItem(s1);
	s.addItem(s2);
	s.addItem(s3);
	ItemDiscount d2 = ItemDiscount(2, 10);
	ItemDiscount d3 = ItemDiscount(3, 15);
	SumDiscount sum;
	sum.add(&d2);
	sum.add(&d3);
	std::cout << "Total discount of the sale: " << sum.calc(s);
}