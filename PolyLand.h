/****************************************************************************
 * Fichier: PolyLand.h
 * Auteur: Alexandre Mao
 * Date: 31 août 2016
 * Mise à jour : 14 mai par David Dratwa
 * Mise à jour : 31 mai 2019 par Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Description: Définition de la classe PolyLand
 *				Polyland represente le pays que l'on va explorer, il va contenir les differents éléments du jeu.
 ****************************************************************************/

#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"

class PolyLand
{
public:

	PolyLand(); 
	~PolyLand(); 

	bool ajouterDresseur(Dresseur* dresseur); 
	bool ajouterCreature(Creature* creature);
	bool retirerDresseur(const string& nom);
	bool retirerCreature(const string& nom);

	Dresseur* choisirDresseurAleatoire() const;
	Creature* choisirCreatureAleatoire() const;

	bool attraperCreature(Dresseur* dresseur, Creature& creature);
	bool relacherCreature(Dresseur* dresseur, const string& nomCreature);

	PolyLand& operator+=(Dresseur* dresseur);
	PolyLand& operator+=(Creature* creature) ;

	PolyLand& operator-=(const Dresseur* dresseur);
	PolyLand& operator-=(const Creature* creature);

	// A retirer peut-etre
	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const Creature& creature) const;

	friend ostream& operator<<(ostream& os, const PolyLand& polyLand);

private:

	vector<Creature*> creatures_;
	vector<Dresseur*> dresseurs_;

};
#endif // !POLYLAND_H
