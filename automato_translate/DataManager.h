#pragma once
#include <string>

using std::string;

class DataManager
{
public:
	DataManager();
	string openADS(string *);
	void setFileName(string);
	void salvarData(string);

private:
	string newFile = "supervisor.txt";
};

