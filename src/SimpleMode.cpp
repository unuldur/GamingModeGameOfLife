//
// Created by PAYS on 20/10/2016.
//

#include "SimpleMode.h"
#include <math.h>
#include <sstream>
#include <pthread.h>
#include <iostream>
using namespace std;
SimpleMode::SimpleMode() : Mode(2, 10,new TreeUniverse(),"SimpleMode") {
    universe = new TreeUniverse();
}

void SimpleMode::setByte(const int x, const int y, const int idJoueur) {
    int byte = universe->getByte(x,y);
    universe->setByte(x, y, byte == 0);
}

string SimpleMode::getDifferenceGeneration(const int gen) {
    if(gen <= 0)
    {
        return "ERROR";
    }
    if(gen > nbMaxGenerations)
    {
        return "FIN";
    }

    return "";
}

int SimpleMode::startRunning() {
    nbPlayerStart++;
    if(nbPlayerStart != nbJoueur)
    {
        return 0;
    }
    cout << "creation thread players" <<endl;
    for (int i = 0; i < nbMaxGenerations; ++i) {
    }
    CreateThread(NULL, 0,SimpleMode::running, this,0,NULL);
    nbPlayerStart = 0;
    return 1;
}



int SimpleMode::getWinner() {
    return 0;
}

DWORD SimpleMode::test()
{
    for (int i = 1; i <= nbMaxGenerations; ++i) {
        universe->runStep();
    }
}

DWORD WINAPI SimpleMode::running(void *arg) {
    cout << "debut thread game" << endl;
    SimpleMode *Obj = static_cast<SimpleMode*>(arg);
    return Obj->test();
}


