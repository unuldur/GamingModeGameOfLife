//
// Created by PAYS on 20/10/2016.
//

#include "SimpleMode.h"
#include <math.h>
#include <sstream>
#include <pthread.h>
#include <iostream>
using namespace std;

SimpleMode::SimpleMode() : Mode(2, 10,"SimpleMode") {
    universe = new TreeUniverse();
}

void SimpleMode::setByte(const int x, const int y, const int idJoueur) {
    int byte = universe->getByte(x,y);
    universe->setByte(x, y, byte == 0);
}

string SimpleMode::getDifferenceGeneration(const int gen) {
    if(gen <= 0)
    {
        return "ERROR";
    }
    if(gen > nbMaxGenerations)
    {
        return "FIN";
    }
    stringstream convert;
    string genStr = generations[gen];
    string postGen = generations[gen - 1];
    if(genStr=="" || postGen=="")
        return "ERROR";
    int mid;
    int decalageGen = 0,decalagePost = 0;
    int taille;
    if (genStr.length() > postGen.length())
    {
        mid  = (int)(sqrt(postGen.length())/2);
        taille = postGen.length();
        decalageGen = mid*mid*4 + 2 * mid ;
    } else {
        mid  = (int)(sqrt(genStr.length())/2);
        taille = genStr.length();
        if(genStr.length() != postGen.length())
        {
            decalagePost = mid*mid*4 + 2 * mid;
        }
    }
    int x = 0 - mid;
    int y = 0 - mid;
    for (int i = 0; i < taille; ++i) {
        if(genStr[i + decalageGen] != postGen[i + decalagePost] && genStr[i + decalageGen] != '\n' && postGen[i + decalagePost] != '\n')
        {
            convert <<"x="<< x << ",y=" << y  << ",mode=0,idP=-1 ";
        }
        x++;
        if (x >= mid)
        {
            x =  0 - mid;
            y++;
            if(decalageGen != 0)
            {
                decalageGen += mid*2 ;
            }

            if(decalagePost != 0)
            {
                decalagePost += mid*2;
            }
            i++;
        }
    }
    return convert.str();
}

int SimpleMode::startRunning() {
    nbPlayerStart++;
    if(nbPlayerStart != nbJoueur)
    {
        return 0;
    }
    cout << "creation thread players" <<endl;
    for (int i = 0; i < nbMaxGenerations; ++i) {
        generations[i] == "";
    }
    generations[0] = universe->getRoot()->getThis();
    CreateThread(NULL, 0,SimpleMode::running, this,0,NULL);
    nbPlayerStart = 0;
    return 1;
}



int SimpleMode::getWinner() {
    return 0;
}

DWORD SimpleMode::test()
{
    for (int i = 1; i <= nbMaxGenerations; ++i) {
        universe->runStep();
        generations[i] = universe->getRoot()->getThis();
    }
}

DWORD WINAPI SimpleMode::running(void *arg) {
    cout << "debut thread game" << endl;
    SimpleMode *Obj = static_cast<SimpleMode*>(arg);
    return Obj->test();
}


