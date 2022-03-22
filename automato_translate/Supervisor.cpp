#include "Supervisor.h"


bool Supervisor::checkAvalanche() {
	/* Verifica se existe efeito avalanche no automato */
	// TODO verificar a lógica
	int avalanche = 0;
	for (int i = 0; i < getTransitions().size(); i++) {
		for (int j = 0; j < getTransitions().size(); j++) {
			if (getTransitions()[i].getEventName() == getTransitions()[j].getEventName() && i != j) {
				if (getTransitions()[i].getExitState() < getTransitions()[j].getEntraceState()) {
					avalancheVector.push_back(i); // passar a posição do vetor 
					avalanche = 1;
				}
				else if (getTransitions()[i].getExitState() < getTransitions()[j].getEntraceState()) {
					/// verfificar
				}
			}
		}
	}
	return avalanche;
}

void Supervisor::solveAvalanche() {
	while (checkAvalanche()) {
		Transitions aux;
		for (int i : avalancheVector) {
			for (int j : avalancheVector) {
				if (getTransitions()[i].getEventName() == getTransitions()[j].getEventName() && i != j) {
					aux = getTransitions()[i];
					getTransitions()[i] = getTransitions()[j];
					getTransitions()[j] = aux;
				}
			}
		}
	}
}

void Supervisor::checkChoiceProblem() {
	for (int i = 0; i < sizeof(getTransitions()); i++) {
		for (int j = 0; j < sizeof(getTransitions()); j++) {
			if (getTransitions()[i].getEventName() == getTransitions()[j].getEventName() && i!=j) {
				if (stoi(getTransitions()[i].getEventName()) % 2 == 0) {
					choiceVector.push_back(getTransitions()[i]);
				}

			}
		}
	}
}