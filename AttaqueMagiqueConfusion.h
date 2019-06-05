
#include "AttaqueMagique.h"

#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H


class AttaqueMagiqueConfusion : public AttaqueMagique {
	
public:
	AttaqueMagiqueConfusion();
	AttaqueMagiqueConfusion(const int&duree);
	virtual ~AttaqueMagiqueConfusion();
	
	virtual void appliquerAttaque(Creature&creature);

	bool estFini();








};














#endif
