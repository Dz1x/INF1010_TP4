/****************************************************************************
 * Fichier: AttaqueMagique.h
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 05 juin 2019
 * Description: Définition de la classe AttaqueMagique
 ****************************************************************************/
#ifndef ATTAQUEMAGIQUE_H
#define ATTAQUEMAGIQUE_H


#include <string>
#include <iostream>
#include "Creature.h"

#define DURE_MINMUM 2

using namespace std;

class AttaqueMagique {

public:

	AttaqueMagique();
	AttaqueMagique(unsigned int duree);
	virtual ~AttaqueMagique();

	int obtenirDuree() const;

	void modifierDuree(unsigned int duree);

	virtual void appliquerAttaque(Creature& creature) = 0;

	virtual bool estfini();

	friend ostream&operator<<(ostream& os, const AttaqueMagique& attaqueMagique);

private:
	unsigned int duree_;

}; // !ATTAQUEMAGIQUE_H
#endif