//
// Created by PAYS on 20/10/2016.
//

#ifndef SERVERGAMEOFLIFE_FACTORYMODE_H
#define SERVERGAMEOFLIFE_FACTORYMODE_H

#include <map>
#include "Mode.h"
#include "SimpleMode.h"

template <typename T> Mode* createT(){return new T;}

class FactoryMode {

public :
    static Mode* createInstance(std::string const& s){
        if(s == "SimpleMode")
        {
            return new SimpleMode();
        }
    }
};


#endif //SERVERGAMEOFLIFE_FACTORYMODE_H
