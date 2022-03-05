#pragma once
#include <string>

using std::string;

class Events {
public:
	Events();
	Events(char, bool);
	string getName();
	bool getType();

private:
	string name;
	bool controlable;
};