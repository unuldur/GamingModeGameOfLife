//
// Created by PAYS on 20/10/2016.
//

#ifndef SERVERGAMEOFLIFE_SIMPLEMODE_H
#define SERVERGAMEOFLIFE_SIMPLEMODE_H


#include "Mode.h"

class SimpleMode : public Mode {
public:
    SimpleMode();

private:
    virtual void setByte(const int x, const int y, const int idJoueur) override;

    virtual string getDifferenceGeneration(const int gen) override;

    virtual void startRunning() override;

    virtual int getWinner() override;
};


#endif //SERVERGAMEOFLIFE_SIMPLEMODE_H
