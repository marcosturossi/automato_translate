#include <string>
#include <iostream>
#include <filesystem>
#include <regex>

#include "DataManager.h"
#include "Transitions.h"

using std::string;
using std::cout;
using std::endl;
using std::regex;
using std::regex_search;


DataManager::DataManager() {
}

string DataManager::openADS(string *path) {
	int err;
	char data[74];
	string transistions = "";
	FILE arq;
	FILE * arqPtr = &arq;
	int i = 1;
	err = fopen_s(&arqPtr, path->c_str(), "r");
	if (err == 0) {
		cout << "Arquivo aberto com sucesso" << endl;
	}
	else {
		cout << "Não foi possível abrir o arquivo" << endl;
	}	
	while (!feof(arqPtr))
	{
		fgets(data, 74, arqPtr);
		if (regex_search(data, regex("^[0-9]")) && i > 27) {
			transistions += string(1, data[0]) + string(1, data[6]) + string(1, data[10]);
		}
		i++;
	}
	fclose(arqPtr);
	return transistions;
}

void DataManager::salvarData(string data) {
	// TODO Alterar o método pois ele vai salvar sempre em cima do arquivo
	FILE* arq;
	int result, err;
	err = fopen_s(&arq, newFile.c_str(), "wt");
	result = fputs(data.c_str(), arq);
}

void DataManager::setFileName(string name) {
	newFile = name;
}