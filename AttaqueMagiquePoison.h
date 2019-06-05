/****************************************************************************
 * Fichier: AttaqueMagiquePoison.h
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 05 juin 2019
 * Description: Définition de la classe AttaqueMagiquePoison
 ****************************************************************************/
#ifndef ATTAQUEMAGIQUEPOISON_H
#define ATTAQUEMAGIQUEPOISON_H

#include "AttaqueMagique.h"

class AttaqueMagiquePoison : public AttaqueMagique {

public:
	AttaqueMagiquePoison();
	AttaqueMagiquePoison(unsigned int duree);
	virtual ~AttaqueMagiquePoison();
	
	virtual void appliquerAttaque(Creature& creature);
	
	virtual bool estFini();
};
#endif // !ATTAQUEMAGIQUEPOISON_H