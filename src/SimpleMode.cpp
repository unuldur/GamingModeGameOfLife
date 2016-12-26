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
}

void SimpleMode::setByte(const int x, const int y, const int idJoueur) {
    int byte = treeUniverse->getByte(x,y);
    treeUniverse->setByte(x, y, byte == 0);
}



int SimpleMode::getWinner() {
    return 0;
}

void SimpleMode::initializeZone() {

}


