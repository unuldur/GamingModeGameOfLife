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

#ifndef SERVERGAMEOFLIFE_MODE_H
#define SERVERGAMEOFLIFE_MODE_H

using namespace std;

class Mode {
    public:
        Mode(int nbJoueur, int nbMaxGeneration,string name) : id(globId++), nbJoueur(nbJoueur), nbMaxGenerations(nbMaxGeneration), name(name) {
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
         * @return 0 si tout le monde n'as pas commencer sinon 1.
         */
        virtual int startRunning()= 0;

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
        int addJoueur(Player * player){
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
        };

        /**
             * suprime le joueur id à la partie
             * @param id
             * @return retourne 0 si la partie est vide ou qu'il n'y a plus qu'un joueur, 1 si la partie n'est pas encore pleine, -1 si le joueur n'existe pas.
             */
        int deleteJoueur(const int id){
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
        };

        vector<Player *> getJoueurs() const
        {
            return idJoueurs;
        }

        bool complete()
        {
            return idJoueurs.size() >= nbJoueur;
        }

        string infos()
        {
            stringstream ss;
            ss << "id="<<id<<",name=" << name << ",nbJoueur=" << idJoueurs.size() << ",nbJoueurMax=" << nbJoueur;
            return ss.str();
        }

        int getId() const {
            return id;
        }

protected:
        static int globId ;
        int id;
        int nbJoueur;
        vector<Player *> idJoueurs;
        int nbMaxGenerations;
        int nbPlayerStart = 0;
        string name;


};

#endif //SERVERGAMEOFLIFE_MODE_H
