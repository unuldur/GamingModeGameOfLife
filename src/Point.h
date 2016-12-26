//
// Created by julie on 24/12/2016.
//

#ifndef GAMEOFLIFEMODE_POINT_H
#define GAMEOFLIFEMODE_POINT_H


class Point {
public:
    Point(int X, int Y, int idPlayer);

    int getX() const;

    int getY() const;

    int getIdPlayer() const;

private:
    int X;
    int Y;
    int idPlayer;

};


#endif //GAMEOFLIFEMODE_POINT_H
