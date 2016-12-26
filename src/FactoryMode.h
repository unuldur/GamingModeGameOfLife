//
// Created by PAYS on 20/10/2016.
//

#ifndef SERVERGAMEOFLIFE_FACTORYMODE_H
#define SERVERGAMEOFLIFE_FACTORYMODE_H

#include <map>
#include "Mode.h"
#include "SimpleMode.h"
#include "ModeConquest.h"

class FactoryMode {

public :
    static Mode* createInstance(std::string const& s){
        if(s == "SimpleMode")
        {
            return new SimpleMode();
        }
        if(s == "Conquest")
        {
            return new ModeConquest();
        }
    }
};


#endif //SERVERGAMEOFLIFE_FACTORYMODE_H
