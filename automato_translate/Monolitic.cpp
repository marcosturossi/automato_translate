#include "Monolitic.h"
#include "Transitions.h"
#include "DataManager.h"

#include <string>
#include <iostream>

using std::string;
using std::cout;

Monolitic::Monolitic(string path) {
	this->path = path;

}

string Monolitic::generateCode() {
	string rawData;
	DataManager data;
	string code = "";
	string vars = "";
	rawData = data.openADS(&path);
	setTransitions(rawData);
	for (Transitions t : getTransitions()) {
		vars += declareVars(t.getEntraceState(), t.getInitialState(), 1); // State
		vars += declareVars(t.getEventName(), 0, 2); // Event
	}
	code += blockVars("VAR", vars);
	cout << code;
	return "";
}