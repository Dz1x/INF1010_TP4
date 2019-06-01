
#include "AttaqueMagique.h"

ostream & operator<<(ostream & os, const AttaqueMagique & attaqueMagique)
{
	os << "attaque de type :" << attaqueMagique.obtenirTypeAttaque() << " qui a une duree de " << attaqueMagique.obtenirDuree() << endl;
	return os;
}

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
	return typeid(*this).name();
}

void AttaqueMagique::appliquerAttaquer(Creature & creature)
{
}



bool AttaqueMagique::estfini()
{
	return true;
}
