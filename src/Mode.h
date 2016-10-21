//
// Created by PAYS on 20/10/2016.
//

#include <iostream>
#include <string>
#include <list>
#include "../GameOfLife/src/TreeNode.h"

#ifndef SERVERGAMEOFLIFE_MODE_H
#define SERVERGAMEOFLIFE_MODE_H

using namespace std;

class Mode {
    public:
        Mode(int nbJoueur, int nbMaxGeneration) : nbJoueur(nbJoueur), nbMaxGenerations(nbMaxGeneration) {
            idJoueurs = new int[nbJoueur];
        }
        /**
         * change le byte x,y avec l'id Joueur.
         */
        virtual void setByte(const int x,const int y,const int idJoueur)= 0;

        /**
         * permet d'obtenir les difference entre la generation gen et la generation gen-1
         *
         * @param gen (gen > 0) la generation voulue
         *
         * @return la liste des difference entre la gen et la gen - 1.
         * Format : (posX posY typeDeCase idJoueur),...,(posXn posYn typeDeCasen idJoueurn) fini
         * typeDeCase:
         *  0 modifie la valeur life dead d'une case
         *  1 modifie l'appartenance d'une case a un joueur
         * idJoueur: -1 si case a aucun joueur sinon id du joueur
         * fini: 1 si c'était la derniere generation.
         */
        virtual string getDifferenceGeneration(const int gen)= 0;

        /**
         * Fait tourner l'algorithme de HashLife sur nbGeneration.
         */
        virtual void startRunning()= 0;

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
        int addJoueur(const int id){
            if(indexId >= nbJoueur)
            {
                cerr << "partie pleine";
                return -1;
            }
            idJoueurs[indexId] = id;
            indexId++;
            if(indexId == nbJoueur)
            {
                return 1;
            }
            return 0;
        };



    private:
        int nbJoueur;
        int idJoueurs[];
        int nbMaxGenerations;
        int indexId = 0;

};


#endif //SERVERGAMEOFLIFE_MODE_H
