
#include "AttaqueMagique.h"

#ifndef   ATTAQUEMAGIQUEPOISON_H
#define   ATTAQUEMAGIQUEPOISON_H

class AttaqueMagiquePoison : public AttaqueMagique {

public:
	AttaqueMagiquePoison();
	AttaqueMagiquePoison(const int&duree);
	virtual ~AttaqueMagiquePoison();
	virtual void appliquerAttaque(Creature&creature);
	bool estFini();




};







#endif
