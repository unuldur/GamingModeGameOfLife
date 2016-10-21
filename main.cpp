#include <iostream>
#include "src/Mode.h"
#include "src/FactoryMode.h"

int main() {
    Mode* mode= FactoryMode::createInstance("SimpleMode");

    std::cout << mode->getDifferenceGeneration(1) << std::endl;
    return 0;
}