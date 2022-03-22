#include <string>

#include "Event.h"
#include "Transitions.h"

using std::string;

Transitions::Transitions() {

}

Transitions::Transitions(string existState, string eventName, string entraceState) {
	this->existState = existState;
	this->eventName = eventName;
	this->entraceState = entraceState;
	setControlableEvent();
	setInicialState();
}

void Transitions::setData(string existState, string eventName, string entraceState) {
	this->existState = existState;
	this->eventName = eventName;
	this->entraceState = entraceState;
	setControlableEvent();
	setInicialState();
}

void Transitions::setControlableEvent() {
	if (stoi(eventName) % 2 == 0)
	{
		controlableEvent = 0;
	}
	else
	{
		controlableEvent = 1;
	}
}

void Transitions::setInicialState() {
	if (stoi(existState) == 0) {
		initialState = 1;
	}
	else {
		initialState = 0;
	}
}


bool Transitions::getInitialState() {
	return initialState;
}


bool Transitions::getControlableEvent() {
	return controlableEvent;
}

string Transitions::getEntraceState() {
	return entraceState;
}

string Transitions::getExitState() {
	return existState;
}

string Transitions::getEventName() {
	return eventName;
}