
#include "AttaqueMagique.h"

#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H


class AttaqueMagiqueConfusion : public AttaqueMagique {
	

	AttaqueMagiqueConfusion();
	AttaqueMagiqueConfusion(const int&duree);
	~AttaqueMagiqueConfusion();
	
	virtual void appliquerAttaque(Creature&creature);

	bool estFini();








};














#endif
