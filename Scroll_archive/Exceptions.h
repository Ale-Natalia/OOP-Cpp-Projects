#pragma once
#include <string>
class Exception
{
public:
	std::string message;
	Exception(std::string message = "Error");
};

class RepoError : public Exception
{
public:
	RepoError(std::string message) : Exception(message) {};
};

class InvalidInputError : public Exception
{
public:
	InvalidInputError(std::string message) : Exception(message) {};
};

class ModeError : public Exception
{
public:
	ModeError(std::string message) : Exception(message) {};
};

