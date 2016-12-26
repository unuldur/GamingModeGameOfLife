//
// Created by Juju_et_yaya on 03/12/2016.
//


#include "Mode.h"

int Mode::globId = 0;

string Mode::infos() {
    stringstream ss;
    ss << "id="<<id<<",name=" << name << ",nbJoueur=" << idJoueurs.size() << ",nbJoueurMax=" << nbJoueur;
    return ss.str();
}

int Mode::getId() const {
    return id;
}

bool Mode::complete() {
    return idJoueurs.size() >= nbJoueur;
}

vector<Player *> Mode::getJoueurs() const {
    return idJoueurs;
}

int Mode::deleteJoueur(const int id) {
    int pos = -1;
    auto it = find_if(idJoueurs.begin(),idJoueurs.end(),[id](const Player* play){return play->getId() == id;});
    if(it == idJoueurs.end()){
        return -1;
    }
    idJoueurs.erase(it);
    if(idJoueurs.size() <= 1)
    {
        return  0;
    }
    return 1;
}

int Mode::addJoueur(Player *player) {
    if(idJoueurs.size() >= nbJoueur)
    {
        cerr << "partie pleine";
        return -1;
    }
    idJoueurs.push_back(player);
    if(idJoueurs.size() == nbJoueur)
    {
        return 1;
    }
    return 0;
}

string Mode::getZone() {

    return zone->getZone();
}

int Mode::startRunning() {
    nbPlayerStart++;
    if(nbPlayerStart != nbJoueur)
    {
        return 0;
    }

    for (int i = 0; i < nbMaxGenerations; ++i) {
        generations[i] = nullptr;
    }
    generations[0] = treeUniverse->getRoot();
    CreateThread(NULL, 0,Mode::startThread, this,0,NULL);
    nbPlayerStart = 0;
    return 1;
}

DWORD WINAPI Mode::startThread(void * arg) {
    Mode *Obj = static_cast<Mode*>(arg);
    return Obj->running();
}

DWORD Mode::running() {
    for (int i = 1; i <= nbMaxGenerations; ++i) {
        treeUniverse->runStep();
        generations[i] = treeUniverse->getRoot();
    }
}

string Mode::getDifferenceGeneration(const int gen) {
    if(gen <= 0)
    {
        return "ERROR";
    }
    if(gen > nbMaxGenerations)
    {
        return "FIN";
    }
    TreeNode* actualTree = generations[gen];
    TreeNode* previousTree = generations[gen - 1];
    if(actualTree == nullptr || previousTree == nullptr) return "";
    return actualTree->getDifference(previousTree,0,0);
}

