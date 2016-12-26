//
// Created by julie on 20/12/2016.
//

#include "ModeConquest.h"

ModeConquest::ModeConquest() : Mode(2, 100,new TreeUniverse(),"Conquest") {

}

int ModeConquest::getWinner() {
    int nbPlayer1 = 0;
    int nbPlayer2 = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            int byte = treeUniverse->getByte(i,j);
            if(byte == 1)
            {
                if(j < 50){
                    nbPlayer1++;
                }else{
                    nbPlayer2++;
                }
            }
        }
    }
    if(nbPlayer1>nbPlayer2){
        return idJoueurs[0]->getId();
    }else
    {
        return idJoueurs[1]->getId();
    }
}

void ModeConquest::setByte(const int x, const int y, const int idJoueur) {
    if(zone->exist(x,y,idJoueur))
    {
        int byte = treeUniverse->getByte(x,y);
        treeUniverse->setByte(x, y, byte == 0);
    }
}

void ModeConquest::initializeZone() {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if(j < 50)
            {
                zone->addPoint(Point(i,j,idJoueurs[0]->getId()));
            }else{
                zone->addPoint(Point(i,j,idJoueurs[1]->getId()));
            }
        }
    }
}
