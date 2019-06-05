/****************************************************************************
 * Fichier: AttaqueMagiqueConfusion.h
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 05 juin 2019
 * Description: Définition de la classe AttaqueMagiqueConfusion
 ****************************************************************************/
#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H

#include "AttaqueMagique.h"

class AttaqueMagiqueConfusion : public AttaqueMagique {

public:
	AttaqueMagiqueConfusion();
	AttaqueMagiqueConfusion(unsigned int duree);
	virtual ~AttaqueMagiqueConfusion();

	virtual void appliquerAttaque(Creature& creature);

	virtual bool estFini();
};

#endif // !ATTAQUEMAGIQUECONFUSION_H