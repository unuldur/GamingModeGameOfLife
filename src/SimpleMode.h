//
// Created by PAYS on 20/10/2016.
//

#ifndef SERVERGAMEOFLIFE_SIMPLEMODE_H
#define SERVERGAMEOFLIFE_SIMPLEMODE_H

#include "Mode.h"
#include "../HashlifeGameOfLife/src/TreeUniverse.h"
class SimpleMode : public Mode {
public:
    SimpleMode();

private:
    virtual bool setByte(const int x, const int y, const int idJoueur) override;

    virtual int getWinner() override;

public:
    void initializeZone() override;
};


#endif //SERVERGAMEOFLIFE_SIMPLEMODE_H
