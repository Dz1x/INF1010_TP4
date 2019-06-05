/****************************************************************************
 * Fichier: CreatureMagique.h
 * Auteur: Philippe Troclet
 * Date: 15 mai 2019
 * Révision: 11 octobre 2016 par Maude Carrier
 * Mise à jour : 31 mai 2019 par  Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Description: Les creatures magiques peuvent bénificier d'une attaque magique
 ****************************************************************************/
#ifndef CREATURE_MAGIQUE_H
#define CREATURE_MAGIQUE_H


#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"

using namespace std;

class CreatureMagique : public Creature
{
public:

	CreatureMagique();
	CreatureMagique(const Creature& creature, unsigned int bonus);

    CreatureMagique(const CreatureMagique& creatureMagique);

	virtual ~CreatureMagique();

    virtual void attaquer(const Pouvoir& pouvoir, Creature& creature); 

	unsigned int obtenirBonus() const;
	AttaqueMagique* obtenirAttaqueMagique() const;

	void modifierBonus(unsigned int bonus);

	bool apprendreAttaqueMagique(AttaqueMagique* attaqueMagique);
	bool oublierAttaqueMagique(const AttaqueMagique* attaqueMagique);

	CreatureMagique& operator=(const CreatureMagique& creatureMagique);



	friend ostream& operator<<(ostream& os, const CreatureMagique& creature); 

private:
    unsigned int bonus_;
	AttaqueMagique* attaqueMagique_;
};

#endif // !CREATUREMAGIQUE_H