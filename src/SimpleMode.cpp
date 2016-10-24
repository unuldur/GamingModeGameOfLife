//
// Created by PAYS on 20/10/2016.
//

#include "SimpleMode.h"
#include <math.h>
#include <sstream>

SimpleMode::SimpleMode() : Mode(2, 10) {
    universe = new TreeUniverse();
}

void SimpleMode::setByte(const int x, const int y, const int idJoueur) {
    universe->setByte(x,y);
}

string SimpleMode::getDifferenceGeneration(const int gen) {
    if(gen <= 0)
    {
        return "";
    }
    stringstream convert;
    string genStr = generations[gen];
    string postGen = generations[gen - 1];

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
            convert << x << " " << y  << " 0 0/";
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

void SimpleMode::startRunning() {
    for (int i = 0; i < nbMaxGenerations; ++i) {
        generations[i] = universe->getRoot()->getThis();
        universe->runStep();
    }
}

int SimpleMode::getWinner() {
    return 0;
}
