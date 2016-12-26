//
// Created by julie on 24/12/2016.
//

#include "Point.h"


int Point::getX() const {
    return X;
}

int Point::getY() const {
    return Y;
}

Point::Point(int X, int Y, int idPlayer) : X(X), Y(Y), idPlayer(idPlayer) {}

int Point::getIdPlayer() const {
    return idPlayer;
}
