//
// Created by julie on 24/12/2016.
//

#include <sstream>
#include <algorithm>
#include "Zone.h"

void Zone::addPoint(const Point & point) {
    zone.push_back(point);
}

Point Zone::getPoint(int X, int Y) {
    auto it = find_if(zone.begin(),zone.end(),[&](const Point& point){return point.getX() == X && point.getY() == Y;});
    return (*it);
}

bool Zone::exist(int X, int Y,int id) {
    auto it = find_if(zone.begin(),zone.end(),[&X,&Y,&id](const Point& point){return point.getX() == X && point.getY() == Y && point.getIdPlayer() == id;});
    return !(it == zone.end());
}

string Zone::getZone() {
    stringstream ss;
    for (auto i = zone.begin(); i < zone.end(); ++i) {
        ss << "x=" << (*i).getX() << ",y=" <<(*i).getY() << ",id=" << (*i).getIdPlayer() << " ";
    }
    return ss.str();
}
