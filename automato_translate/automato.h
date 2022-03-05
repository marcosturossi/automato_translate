#pragma once
#include <string>
#include "transitions.h"
#include <vector>
using std::string;
using std::vector;


class Automato
{
public:
	Automato();
	Automato(string); // Construtor com parametros
	void openData(string *); 
	void setTransitions();
	vector <Transitions> getTransitions();
	bool checkAvalanche();
	void solveAvalanche();

private:	
	string automatoName;
	vector <int> avalancheVector;
	vector <Transitions> transitionsVector;
	string rawData;
	FILE* arq;
};