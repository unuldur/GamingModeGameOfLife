//
// Created by julie on 20/12/2016.
//

#ifndef GAMEOFLIFEMODE_MODECONQUEST_H
#define GAMEOFLIFEMODE_MODECONQUEST_H


#include "Mode.h"

class ModeConquest : public Mode{
public:
    ModeConquest();

    virtual string getDifferenceGeneration(const int gen) override;

    virtual int startRunning() override;

    virtual void setByte(const int x, const int y, const int idJoueur) override;

    virtual int getWinner() override;

};


#endif //GAMEOFLIFEMODE_MODECONQUEST_H
