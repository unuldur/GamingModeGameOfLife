//
// Created by julie on 20/12/2016.
//

#ifndef GAMEOFLIFEMODE_MODECONQUEST_H
#define GAMEOFLIFEMODE_MODECONQUEST_H


#include "Mode.h"
#include "../HashlifeGameOfLife/src/TreeNode.h"
#include "Zone.h"

class ModeConquest : public Mode{
public:
    ModeConquest();

    virtual bool setByte(const int x, const int y, const int idJoueur) override;

    virtual int getWinner() override;

    void initializeZone() override;

private:


};


#endif //GAMEOFLIFEMODE_MODECONQUEST_H
