
#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(): AttaqueMagique(2){
	

}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(const int&duree) : AttaqueMagique(duree) {

}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}




void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature)
{
	if (obtenirDuree() > 0 && creature.obtenirPointDeVie() >= 5)
	{
		unsigned int pointDeVie = creature.obtenirPointDeVie();
		if (rand() % 3 == 0)
		{
			creature.modifierPointDeVie(pointDeVie - 2);
		}
		modifierDuree(obtenirDuree()-1);
	}
}

bool AttaqueMagiqueConfusion::estFini()
{
	if (obtenirDuree() == 0) {
		return false;
	}
	return true;
}

