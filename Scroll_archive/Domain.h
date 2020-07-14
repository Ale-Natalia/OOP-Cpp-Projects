#pragma once
#include <string>
#include <iostream>
#include <vector>

class Document {
private:
	std::string name;
	std::vector<std::string> keywords;
	std::string content;
public:
	Document() {
		this->content = "";
		this->name = "";
		this->keywords = std::vector<std::string>();
	}
	Document(const std::string& name, const std::vector<std::string>& keywords, const std::string& content) {
		this->content = content;
		this->name = name;
		this->keywords = keywords;
	};
	std::string getContent()const { return this->content; };
	std::string getName()const { return this->name; };
	std::vector<std::string> getKeywords()const { return this->keywords; };
	void setContent(std::string content) { this->content = content; };
	void setName(std::string name) { this->name = name; };
	void setKeywords(std::vector<std::string> keywords) { this->keywords = keywords; };
	std::string toString()const;
	std::string toStringContent()const;
	std::string keywordsString()const;

	friend std::istream& operator>>(std::istream& is, Document& element);
	friend std::ostream& operator<<(std::ostream& os, const Document& element);
};