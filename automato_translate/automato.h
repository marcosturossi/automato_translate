#pragma once
#include <string>
#include <vector>

#include "Transitions.h"

using std::string;
using std::vector;


class Automato
{
public:
	Automato();
	Automato(string);
	void setTransitions(string);
	vector <Transitions> getTransitions();
	vector <Transitions> getControlables();
	vector <Transitions> getUncontrolables();
	void setEvents();

private:	
	string automatoName;
	vector <Transitions> transitionsVector;
	vector <Transitions> controlableVector;
	vector <Transitions> uncontrolableVector;
	vector <Transitions> allStatesVector;	
};
