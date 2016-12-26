//
// Created by julien on 24/12/2016.
//

#ifndef GAMEOFLIFEMODE_ZONE_H
#define GAMEOFLIFEMODE_ZONE_H

#include "Point.h"
#include <stdio.h>
#include <vector>

using namespace std;
class Zone {
public:
    void addPoint(const Point&);
    Point getPoint(int X,int Y);
    bool exist(int X,int Y, int id);
    string getZone();
private:
    vector<Point> zone;
};


#endif //GAMEOFLIFEMODE_ZONE_H
