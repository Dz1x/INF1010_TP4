
#include "AttaqueMagiquePoison.h"

AttaqueMagiquePoison::AttaqueMagiquePoison(): AttaqueMagique(2)
{

}

AttaqueMagiquePoison::AttaqueMagiquePoison(const int & duree): AttaqueMagique(duree)
{
}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{
}

void AttaqueMagiquePoison::appliquerAttaque(Creature & creature)
{
	
	if (obtenirDuree() > 0 && creature.obtenirEnergie() >= 5)
		{
			unsigned int energie = creature.obtenirEnergie();
			if (rand() % 3 == 0)
			{
				creature.modifierPointDeVie(energie - 2);
			}
			modifierDuree(obtenirDuree()-1);
		}
	
}

bool AttaqueMagiquePoison::estFini()
{
	if (obtenirDuree() == 0) {
		return true;
	}
	return false;

}
