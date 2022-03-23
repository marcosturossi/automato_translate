#include <string>
#include <stdio.h>
#include <iostream>
#include <regex>
#include <vector>

#include "Automato.h"
#include "DataManager.h"

using std::string;
using std::cout;
using std::endl;
using std::regex; 
using std::regex_search;


Automato::Automato(){}

Automato::Automato(string path) {
	DataManager openData;
	string rawData = openData.openADS(&path);
	setTransitions(rawData);

}


void Automato::setTransitions(string data) {
	for (int i = 0; i < data.size(); i += 3) {
		transitionsVector.push_back(Transitions(
			string(sizeof(data[i]), data[i]),
			string(sizeof(data[i+1]), data[i+1]),
			string(sizeof(data[i+2]), data[i+2])));
	}
	setEvents();
}



void Automato::setEvents() {
	/*Divide as transições em controláveis e não controláveis*/
	for (Transitions i : transitionsVector) {
		if (stoi(i.getEventName()) % 2 == 0) {
			controlableVector.push_back(i);
		}
		else {
			uncontrolableVector.push_back(i);
		}
	}
}


vector <Transitions> Automato::getControlables() {
	return controlableVector;
}


vector <Transitions> Automato::getUncontrolables() {
	return uncontrolableVector;
}


vector <Transitions> Automato::getTransitions() {
	return transitionsVector;
}
