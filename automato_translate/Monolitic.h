#pragma once
#include <string>
#include <vector>

#include "Supervisor.h"
#include "DataManager.h"
#include "StructuredText.h"
#include "Automato.h"

using std::string;

class Monolitic : public Supervisor, public StructuredText
{
public:
	Monolitic(string, vector <string> *);
	string generateCode();
	string generateVars();
	string generateReadInputs();
	string generateUpdateState();
	string generateExits();
	vector <Automato> getPlants();
	void setPlantas();

private:
	string path;
	string data;
	vector <string> plantsPath;
	vector <Automato> plants;
};

