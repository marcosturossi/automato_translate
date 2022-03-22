#include <string>
#include <iostream>

#include "Transitions.h"
#include "StructuredText.h"

using std::cout;

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
	return tipo + "\n" + data + "\n" + "ENDVAR \n";
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
	else {
		name = eventDeclared;
	}
	return name + var + " BOOL := " + init + ";\n";
}

string StructuredText::updateState(Transitions transitions) {
	string data = "";
	if (stoi(transitions.getEventName()) % 2 == 0) {
		data = "IF " + eventDeclared + transitions.getExitState() + " AND " +
			stateDeclared + transitions.getExitState() + " THEN \n" +
			stateDeclared + transitions.getEntraceState() + " := 1; \nENDIF \n";
	}
	else {
		data = "IF " + stateDeclared + transitions.getExitState() + " THEN \n" +
			stateDeclared + transitions.getEntraceState() + " := 1; \n" +
			eventDeclared + transitions.getEventName() + " := 1; \nENDIF \n";
	}
	return data;
}

string StructuredText::updateExit(Transitions transitions) {
	string data;
	data = "IF " + eventDeclared + transitions.getEventName() + " "
		+ exitEventDeclared + transitions.getEventName() +  " := TRUE; \n";
	// Verificar quand ocorre o desligamento da saída
	cout << data;
	return data;
}
