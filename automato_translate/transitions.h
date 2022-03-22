#pragma once
#include <string>

using std::string;

class Transitions
{
public:
	Transitions();
	Transitions(string, string, string); // Construtor	
	void setData(string, string, string);
	string getEventName();
	string getEntraceState();
	string getExitState();
	bool getControlableEvent();
	void setControlableEvent();
	void setInicialState();
	bool getInitialState();

private:
	string existState;
	string eventName;
	string entraceState;
	bool controlableEvent;
	bool initialState;
};
