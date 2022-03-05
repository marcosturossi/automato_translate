#pragma once


class Transitions
{
public:
	Transitions();
	Transitions(char, char, char); // Construtor	
	void setData(char, char, char);
	char getEventName();
	char getEntraceState();
	char getExitState();

private:
	char existState;
	char eventName;
	char entraceState;
};