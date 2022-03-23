#include "Monolitic.h"
#include "Transitions.h"
#include "DataManager.h"

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;

Monolitic::Monolitic(string path, vector <string> *plantasPath ) {
	this->path = path;
	this->plantsPath = *plantasPath;
	string rawData;
	DataManager data;
	rawData = data.openADS(&path);
	setTransitions(rawData);
	setPlantas();
	cout << generateCode();
	data.salvarData(generateCode());	
}

string Monolitic::generateCode() {	
	string code = "";
	code += generateVars();
	code += generateReadInputs();
	code += generateUpdateState();
	code += generateExits();
	return code;
}

string Monolitic::generateVars(){
	string statevars = "//ESTADOS \n";
	string eventvars = "\n//EVENTOS \n";
	string inputvars = "\n//ENTRADAS \n";
	string exitvars = "\n//SAIDAS \n";
	for (Transitions t : getTransitions()) {
		statevars += declareVars(t.getExitState(), t.getInitialState(), 1); // State		
	}
	for (Transitions t : getTransitions()) {
		eventvars += declareVars(t.getEventName(), 0, 2); // Event		
	}
	for (Transitions t : getControlables()) {
		exitvars += declareVars(t.getEventName(), 0, 3); // Exit;
	}
	for (Transitions t : getUncontrolables()) {
		inputvars += declareVars(t.getEventName(), 0, 4); // Input;
	}
	return blockVars("VAR", statevars + eventvars + inputvars + exitvars );
}

string Monolitic::generateReadInputs() {
	string data = "\n//LER ENTRADAS \n";
	for (Transitions t : getUncontrolables()) {
		data += getReadInputs(t);
	}
	return data;
}

string Monolitic::generateUpdateState() {
	string data = "\n//Atualiza ESTADOS \n";
	for (Transitions t : getTransitions()) {
		data += updateState(t);
	}
	return data;
}

string Monolitic::generateExits() {
	string data = "\n//Atualiza SAIDAS \n";
	for (Automato i : getPlants()) {
		for (int j = 0; j < i.getTransitions().size(); j++) {
			for (int k = 0; k < i.getTransitions().size(); k++) {
				if (i.getTransitions()[j].getExitState() == i.getTransitions()[k].getEntraceState() &&
					i.getTransitions()[k].getExitState() == i.getTransitions()[j].getEntraceState() && k!=j) {
					if (i.getTransitions()[j].getControlableEvent()) {
						data += updateExit(i.getTransitions()[j].getEventName(), i.getTransitions()[k].getEventName());
					}
				}
			}
		}
	}
	return data;
}

void Monolitic::setPlantas() {
	for (string i : plantsPath) {
		plants.push_back(Automato(i));
	}
}

vector <Automato> Monolitic::getPlants() {
	return plants;
}