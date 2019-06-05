
#include "AttaqueMagique.h"
#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"



AttaqueMagique::AttaqueMagique():duree_(0)
{

}

AttaqueMagique::AttaqueMagique(const int & duree):duree_(duree)
{
}

AttaqueMagique::~AttaqueMagique()
{




}

int AttaqueMagique::obtenirDuree() const
{
	return duree_;
}

void AttaqueMagique::modifierDuree(const int & duree)
{
	duree_ = duree;
}

string AttaqueMagique::obtenirTypeAttaque() const
{
	
}

void AttaqueMagique::appliquerAttaque(Creature & creature)
{
}



bool AttaqueMagique::estfini()
{
	return true;
}
ostream & operator<<(ostream & os,AttaqueMagique & attaqueMagique)
{
	if(dynamic_cast<AttaqueMagiqueConfusion*>(&attaqueMagique))
	 return os << "attaque magique confusion " << " qui a une duree de " << attaqueMagique.obtenirDuree() << endl;
	else if (dynamic_cast<AttaqueMagiquePoison*>(&attaqueMagique))
	return os << "attaque magique poison " << " qui a une duree de " << attaqueMagique.obtenirDuree() << endl;


	
}
