#include <string>
#include "event.h"


Events::Events() {

}

Events::Events(char name, bool controlable) {
	this->name = name;
	this->controlable = controlable;
};

string Events::getName() {
	return name;
}

bool Events::getType() {
	return controlable;
}