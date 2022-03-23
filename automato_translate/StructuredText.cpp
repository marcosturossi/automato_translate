#include <string>
#include <iostream>
#include <regex>

#include "Transitions.h"
#include "StructuredText.h"


using std::cout;
using std::regex;
using std::regex_replace;

StructuredText::StructuredText() {

}


void StructuredText::setDeclarationType(bool declaration) {
	declarationVar = declaration;
}

void StructuredText::setVarNames(string state, string events) {
	stateDeclared = state;
	eventDeclared = events;
}

string StructuredText::blockVars(string tipo, string data) {
	return tipo + "\n" + data + "END_VAR \n";
}

string StructuredText::declareVars(string var, bool initial, int type) {
	string init;
	string name;
	if (initial == 0) {
		init = "FALSE";
	}
	else {
		init = "TRUE"; 
	}	 
	if (type == 1) {
		name = stateDeclared;
	}
	else if(type == 2) {
		name = eventDeclared;
	}
	else if (type == 3) {
		name = exitDeclared;
	}
	else if (type == 4) {
		name = inputDeclared;
	}
	return name + var + ": BOOL := " + init + ";\n";
}

string StructuredText::updateState(Transitions transitions) {
	string data = "";
	if (stoi(transitions.getEventName()) % 2 == 0) {
		data = "IF " + eventDeclared + transitions.getExitState() + " AND " +
			stateDeclared + transitions.getExitState() + " THEN \n" + identation +
			stateDeclared + transitions.getEntraceState() + " := TRUE; \n" + identation +
			eventDeclared + transitions.getExitState() + " := FALSE; \nEND_IF \n";
	}
	else {
		data = "IF " + stateDeclared + transitions.getExitState() + " THEN \n" + identation +
			stateDeclared + transitions.getEntraceState() + " := TRUE; \n"+  identation +
			eventDeclared + transitions.getEventName() + " := TRUE; \n" + identation +
			eventDeclared + transitions.getExitState() + " := FALSE; \nEND_IF \n";
	}
	return data;
}

string StructuredText::updateExit(string controlable, string noncontrolable) {
	string data;
	data = "IF " + eventDeclared + controlable + " THEN \n" + identation +
		exitDeclared + controlable +  " := TRUE; \nEND_IF \n" +
		"IF " + eventDeclared + noncontrolable + " THEN \n" + identation +
		exitDeclared + controlable + " := FALSE; \nEND_IF \n";
	return data;
}

string StructuredText::getReadInputs(Transitions transitions) {
	string data;
	data = "IF " + inputDeclared + transitions.getEventName() + " THEN \n" + identation +
		eventDeclared + transitions.getEventName() + " := TRUE; \nEND_IF \n";
	return data;
}
