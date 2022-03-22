#pragma once
#include "Automato.h"

class Supervisor : public Automato
{
public:
    bool checkAvalanche();
    void solveAvalanche();
    void checkChoiceProblem();

private:
    vector <int> avalancheVector;
    vector <Transitions> choiceVector;
};

