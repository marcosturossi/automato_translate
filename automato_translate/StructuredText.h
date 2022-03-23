#pragma once
#include <string>
#include "Transitions.h"

using std::string;


class StructuredText
{
public:	
	StructuredText();
	string declareVars(string, bool, int);
	string blockVars(string, string);
	string updateState(Transitions);
	void setVarNames(string, string);
	void setDeclarationType(bool);
	string updateExit(string, string);
	string getReadInputs(Transitions);
	string setIdentation(string);

private:
	string stateDeclared = "STATE";
	string eventDeclared = "EVENT";
	string inputDeclared = "INPUT";
	string exitDeclared = "EXIT";
	string identation = "    ";
	bool declarationVar = 1;
	
};
