#pragma once
#include <string>
#include <vector>

#include "Supervisor.h"
#include "DataManager.h"
#include "StructuredText.h"

using std::string;

class Monolitic : public Supervisor, public StructuredText
{
public:
	Monolitic(string);
	string generateCode();

private:
	string path;
	string data;
};

