
#include "Creature.h"
#include <string>
#include <iostream>
#ifndef ATTAQUEMAGIQUE_H
#define ATTAQUEMAGIQUE_H

using namespace std;
class AttaqueMagique {

public:

	AttaqueMagique();
	AttaqueMagique(const int&duree);
	virtual ~AttaqueMagique()=default;

	int obtenirDuree() const;
	void modifierDuree(const int&duree);
    string obtenirTypeAttaque() const;
	virtual void appliquerAttaque(Creature&creature)=0;
	bool estfini();

	friend ostream&operator<<(ostream&os,const AttaqueMagique&attaqueMagique);

	



private:
	unsigned int duree_;



};





#endif
