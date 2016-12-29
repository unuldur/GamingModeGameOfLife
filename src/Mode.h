//
// Created by PAYS on 20/10/2016.
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include "Player.h"
#include "../HashlifeGameOfLife/src/TreeNode.h"
#include "Zone.h"
#include "../HashlifeGameOfLife/src/TreeUniverse.h"

#ifndef SERVERGAMEOFLIFE_MODE_H
#define SERVERGAMEOFLIFE_MODE_H

using namespace std;

class Mode {
    public:
        Mode(int nbJoueur, int nbMaxGeneration,TreeUniverse* universe,string name) : id(globId++), nbJoueur(nbJoueur),
                                                                                    nbMaxGenerations(nbMaxGeneration),
                                                                                    name(name), treeUniverse(universe) {
            generations = new TreeNode*[nbMaxGeneration];
            zone = new Zone();
        }

        /**
         * change le byte x,y avec l'id Joueur.
         */
        virtual void setByte(const int x,const int y,const int idJoueur) = 0;

        /**
         * permet d'obtenir les difference entre la generation gen et la generation gen-1
         *
         * @param gen (gen > 0) la generation voulue
         *
         * @return la liste des difference entre la gen et la gen - 1.
         * Format : (posX posY idJoueur),...,(posXn posYn idJoueurn) fini
         * typeDeCase:
         *  0 modifie la valeur life dead d'une case
         * idJoueur: -1 si case a aucun joueur sinon id du joueur
         * fini: 1 si c'était la derniere generation.
         */
        virtual string getDifferenceGeneration(const int gen);

        /**
         * Fait tourner l'algorithme de HashLife sur nbGeneration.
         * @return 0 si tout le monde n'as pas commencer sinon 1.
         */
        virtual int startRunning();

        /**
         * retourne l'id du gagnant du mode.
         * @return
         */
        virtual int getWinner()= 0;

        /**
         * ajoute le joueur id à la partie
         * @param id
         * @return retourne -1 si la partie est pleine, 0 si la partie n'est pas encore pleine et 1 si la partie est complete
         */
        int addJoueur(Player * player);;

        /**
         * initialise la zone de départ pour les différent joueurs
         */
        virtual void initializeZone()= 0;

        /**
         * obtiens la zone entiere des joueur
         */
        virtual string getZone();

        /**
             * suprime le joueur id à la partie
             * @param id
             * @return retourne 0 si la partie est vide ou qu'il n'y a plus qu'un joueur, 1 si la partie n'est pas encore pleine, -1 si le joueur n'existe pas.
             */
        int deleteJoueur(const int id);;

        vector<Player *> getJoueurs() const;

        bool complete();

        string infos();

        int getId() const;

        static DWORD WINAPI startThread(void *);

        DWORD running();

protected:
        static int globId ;
        int id;
        int nbJoueur;
        vector<Player *> idJoueurs;
        int nbMaxGenerations;
        int nbPlayerStart = 0;
        string name;
        TreeNode** generations;
        Zone* zone;
        TreeUniverse* treeUniverse;


};

#endif //SERVERGAMEOFLIFE_MODE_H
