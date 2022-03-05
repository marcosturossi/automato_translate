#include "event.h"
#include "transitions.h"



Transitions::Transitions() {

}

Transitions::Transitions(char existState, char eventName, char entraceState) {
	this->existState = existState;
	this->eventName = eventName;
	this->entraceState = entraceState;
}

void Transitions::setData(char existState, char eventName, char entraceState) {
	this->existState = existState;
	this->eventName = eventName;
	this->entraceState = entraceState;
}
	

char Transitions::getEntraceState() {
	return entraceState;
}

char Transitions::getExitState() {
	return existState;
}

char Transitions::getEventName() {
	return eventName;
}