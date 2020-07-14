#pragma once
#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>

//15:22
class Rational {
private:
	int numerator;
	int denominator;
public:
	Rational() {
		this->numerator = 0;
		this->denominator = 1;
	}
	
	Rational(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
	}
	
	Rational(const Rational& other) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}

	~Rational(){}

	int getNumerator() {
		return this->numerator;
	}

	int getDenominator() {
		return this->denominator;
	}

	//returns the greates common divisor
	int gcd(int a, int b) {
		if (a == 0)
			return 0;
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	//simplifies a rational number
	Rational simplify() {
		Rational simplified = Rational();
		int gcdNumbers = gcd(this->numerator, this->denominator);
		if (gcdNumbers != 0) {
			simplified.numerator = this->numerator / gcdNumbers;
			simplified.denominator = this->denominator / gcdNumbers;
		}
		return simplified;
	};

	bool operator==(Rational& other) {
		Rational thisSimplified = this->simplify();
		Rational otherSimplified = other.simplify();
		if (thisSimplified.numerator == otherSimplified.numerator && thisSimplified.denominator == otherSimplified.denominator)
			return true;
		return false;
	}

	Rational operator/(Rational& other) {
		//int checkDiv0 = this->numerator / other.numerator;
		if (other.numerator == 0) {
			std::exception ex = std::exception("Division by zero!");
			throw ex;
		}
		Rational divisionResult = Rational();
		divisionResult.numerator = this->numerator * other.denominator;
		divisionResult.denominator = this->denominator * other.numerator;
		return divisionResult;
	}

	friend std::ostream& operator<<(std::ostream& os, Rational& rational) {
		os << rational.numerator << "/" << rational.denominator;
		return os;
	}
};
//15:48

template <typename TElem>
class Vector {
private:
	std::vector<TElem> elements;
public:
	Vector(std::vector<TElem> elements) : elements{elements}{}
	void printAll(std::ostream& os) {
		for (auto it = elements.begin(); it < elements.end() - 1; it++)
			os << *it << " ";
		auto it = elements.end() - 1;
		os << *it << "\n";
	}
};
//15:55

void rational() {
	Rational a{}, b{ 6, 15 }, c{ 3, 5 }, d{ b };
	assert(a.getNumerator() == 0);
	assert(c.getDenominator() == 5);
	assert(b == d);
	Rational res1 = b / c;
	std::cout << res1 << "\n";
	try {
		Rational res2 = b / a;
	}
	catch (std::exception & e) {
		assert(strcmp(e.what(), "Division by zero!") == 0);
	}

	Vector<int> v1{ std::vector<int>{1, 2, 3} };
	v1.printAll(std::cout);

	Vector<Rational> v2{ std::vector<Rational>{a, b, c, d} };
	v2.printAll(std::cout);
}