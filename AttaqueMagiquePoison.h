
#include "AttaqueMagique.h"

#ifndef   ATTAQUEMAGIQUEPOISON_H
#define   ATTAQUEMAGIQUEPOISON_H

class AttaqueMagiquePoison : public AttaqueMagique {

public:
	AttaqueMagiquePoison();
	AttaqueMagiquePoison(const int&duree);
	~AttaqueMagiquePoison();
	virtual void appliquerAttaque(Creature&creature);
	bool estFini();




};







#endif
