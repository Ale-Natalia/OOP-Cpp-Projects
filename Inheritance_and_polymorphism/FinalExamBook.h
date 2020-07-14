#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

std::vector<std::string> tokenize(const std::string& str, char delimiter)
{
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

class Section {
protected:
	std::string title;
	std::string content;
	Checker* checker;
public:
	Section() {
		this->checker = NULL;
	}
	Section(std::string title, std::string content) {
		this->title = title;
		this->content = content;
		this->checker = new DoubleChecker();
	}
	~Section() {
		delete this->checker;
	}
	std::string getTitle() { return this->title; }
	std::string getContent(){ return this->content; }

	virtual void addSection(Section* s) = 0;
	void generate() {
		if (this->checker->check(this))
			std::cout << this->title << "\n" << this->content << "\n\n";
	};
};

class Preface : public Section {
public:
	Preface() : Section(){}
	Preface(std::string title, std::string content) : Section(title, content) {}
	~Preface() {
		delete this->checker;
	}
	void addSection(Section* s)override {
	}
};

class Chapter : public Section {
private:
	std::vector<Section*> sections;
	std::string title;
	std::string content;
	Checker* checker;
public:
	Chapter() : Section() {}
	Chapter(std::string title, std::string content) : Section(title, content) {}
	~Chapter() {
		delete this->checker;
	}
	void addSection(Section* s)override {
		this->sections.push_back(s);
	}
	void generate() {
		if (this->checker->check(this)) {
			std::cout << this->title << "\n";
			for (auto& section : this->sections) {
				section->generate();
			}
		}
	}
};

class Checker {
public:
	Checker(){}
	~Checker(){}
	virtual bool check(Section* s) = 0;
};

class TitleChecker : public Checker {
public:
	TitleChecker() : Checker() {}
	~TitleChecker(){}
	bool check(Section* s) override {
		if (s->getTitle().size() >= 2)
			return true;
		return false;
	}
};

class ContentChecker : public Checker {
public:
	ContentChecker() : Checker(){}
	~ContentChecker(){}
	bool check(Section* s) override {
		std::string content = s->getContent();
		std::vector<std::string> sentences = tokenize(content, '.');
		if (!isupper(sentences[0][0]))
			return false;
		for (int i = 1; i < sentences.size(); i++) {
			if (!isupper(sentences[i][1])) //first character - position 0 is space, the second is the letter
				return false;
		}
		return true;
	}
};

class DoubleChecker : public Checker {
private:
	TitleChecker* titleChecker;
	ContentChecker* contentChecker;
public:
	DoubleChecker() {
		this->titleChecker = new TitleChecker();
		this->contentChecker = new ContentChecker();
	}
	~DoubleChecker() {
		delete this->titleChecker;
		delete this->contentChecker;
	}
	bool check(Section* s) override {
		if (!this->titleChecker->check(s))
			return false;
		if (!this->contentChecker->check(s))
			return false;
		return true;
	}
};

void generateBook() {
	Preface* preface = new Preface("Preface", "This is a beautiful preface. Thanks.");
	Chapter* chapter = new Chapter("Main chapter", "");
	Chapter* subChapter1 = new Chapter("Subchapter 1", "This is. Subchapter. One");
	Chapter* subChapter2 = new Chapter("Subchapter 2", "This is. Subchapter. Two");
	Chapter* subChapter3 = new Chapter("3", "This is. Subchapter. three");
	chapter->addSection(subChapter1);
	chapter->addSection(subChapter2);
	chapter->addSection(subChapter3);
	preface->generate();
	chapter->generate();
}