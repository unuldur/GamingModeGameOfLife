#include <iostream>
#include "src/Mode.h"
#include "src/FactoryMode.h"

int main() {
    Mode* mode= FactoryMode::createInstance("SimpleMode");
    mode->setByte(-1,-1,0);
    mode->setByte(0,0,0);
    mode->setByte(1,0,0);
    mode->setByte(-1,1,0);
    mode->setByte(0,1,0);
    mode->startRunning();
    cout << mode->getDifferenceGeneration(3) << endl;
    return 0;
}