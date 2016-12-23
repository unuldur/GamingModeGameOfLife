//
// Created by Juju_et_yaya on 03/12/2016.
//
#include <iostream>
#include <winsock2.h>
#include <sstream>

#ifndef SERVERGAMEOFLIFE_PLAYER_H
#define SERVERGAMEOFLIFE_PLAYER_H

using namespace std;
class Player {
public:
    Player(const string &name, SOCKET socket) : id(globId++), name(name), socket(socket) {}

    const int &getId() const {
        return id;
    }

    const string &getName() const {
        return name;
    }

    SOCKET getSocket() const {
        return socket;
    }

    const string getInfo() const{
        stringstream ss;
        ss << "id=" << id <<",name=" << name;
        return ss.str();
    }

private:
    static int globId;
    int id;
    string name;
    SOCKET socket;

};

#endif //SERVERGAMEOFLIFE_PLAYER_H
