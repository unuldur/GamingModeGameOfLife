#include <iostream>
#include "src/Mode.h"
#include "src/FactoryMode.h"

int main() {

    Mode* mode= FactoryMode::createInstance("Conquest");
    mode->addJoueur(new Player("coucou", NULL));
    mode->addJoueur(new Player("sla", NULL));
    mode->initializeZone();
    mode->setByte(-1,-1,0);
    mode->setByte(0,0,0);
    mode->setByte(1,0,0);
    mode->setByte(-1,1,0);
    mode->setByte(0,1,0);
    mode->startRunning();
    std::cout << "coucou" << std::endl;
    return 0;
}