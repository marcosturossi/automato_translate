#pragma once
#include "Automato.h"
#include <string>

using std::string;

class Supervisor : public Automato
{
public:
    Supervisor();
    bool checkAvalanche();
    void solveAvalanche();
    void checkChoiceProblem();

private:
    vector <int> avalancheVector;
    vector <Transitions> choiceVector;
};

