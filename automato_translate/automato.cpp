#include <string>
#include "automato.h"
#include <stdio.h>
#include <iostream>
#include <regex>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::fgets;
using std::regex_search;
using std::regex;
using std::vector;


Automato::Automato() {

}

Automato::Automato(string path) { // Construtor
	string * pathPrt = &path;
	openData(pathPrt);
}

void Automato::openData(string *path) {
	int err;
	err = fopen_s(&arq, path->c_str(), "r");
	if (err == 0) {
		cout << "Arquivo aberto com sucesso" << endl;
	}
	else {
		cout << "Não foi possível abrir o arquivo" << endl;
	}
}

void Automato::setTransitions() {
	char data[74];
	int i = 1;
	int j = 0;
	while (!feof(arq)) {
		fgets(data, 74, arq);
		if (regex_search(data, regex("^[0-9]")) && i > 27) {			
			transitionsVector.push_back(Transitions(data[0], data[6], data[10]));
			j++;
		}
		i++;
	}	
	fclose(arq);
}


bool Automato::checkAvalanche() {
	/* Verifica se existe efeito avalanche no automato */
	int avalanche = 0;
	for (int i = 0; i < transitionsVector.size(); i++) {
		for (int j = 0; j < transitionsVector.size(); j++) {
			if (transitionsVector[i].getEventName() == transitionsVector[j].getEventName() && i!=j ) {
				if (transitionsVector[i].getExitState() < transitionsVector[j].getEntraceState())
					avalancheVector.push_back(i); // passar a posição do vetor 
					avalanche = 1;
			}
		}
	}
	return avalanche;
}

void Automato::solveAvalanche() {
	while (checkAvalanche()) {
		Transitions aux;
		for (int i:  avalancheVector) {
			for (int j: avalancheVector){
				if (transitionsVector[i].getEventName() == transitionsVector[j].getEventName() && i != j) {
					aux = transitionsVector[i];
					transitionsVector[i] = transitionsVector[j];
					transitionsVector[j] = aux;
				}
			}
		}
	}
}


vector <Transitions> Automato::getTransitions() {
	return transitionsVector;
}

