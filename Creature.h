/****************************************************************************
 * Fichier: Creature.h
 * Auteur: Alexandre Mao
 * Date: 31 août 2016
 * Mise à jour : 14 mai par David Dratwa
 * Mise à jour : 31 mai 2019 par Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Description: Définition de la classe ObjetMagique
 *				Les créatures sont des êtres destinées au combat.
 ****************************************************************************/

#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "ObjetMagique.h"
#include "Pouvoir.h"
#include <vector>

class Creature
{
public:
	Creature();
	Creature(const string& nom, unsigned int attaque, unsigned int defense, unsigned int pointDeVie, unsigned int energie);
	Creature(const Creature& creature);
	virtual ~Creature();

	string obtenirNom() const;
	unsigned int obtenirAttaque() const;
	unsigned int obtenirDefense() const;
	unsigned int obtenirPointDeVie() const;
	unsigned int obtenirPointDeVieTotal() const;
	unsigned int obtenirEnergie() const;
	unsigned int obtenirEnergieTotale() const;
	unsigned int obtenirExperience() const;
	unsigned int obtenirExperienceNecessaire() const;
	unsigned int obtenirNiveau() const;

	virtual void attaquer(const Pouvoir& pouvoir, Creature& creature);
	int experienceGagnee(const Creature& creature);

	void modifierAttaque(unsigned int attaque);
	void modifierDefense(unsigned int defense);
	void modifierPointDeVie(unsigned int pointDeVie);
	void modifierEnergie(unsigned int energie);
	void modifierExperience(unsigned int experience);
	void modifierNiveau(unsigned int niveau);
	void modifierNom(const string&nom);

	vector<Pouvoir*> obtenirPouvoirs() const;
	bool apprendrePouvoir(Pouvoir* pouvoir);
	bool oublierPouvoir(const Pouvoir* pouvoir);
	void modifierPouvoirs(vector<Pouvoir*> pouvoirs);

	bool operator==(const Creature& creature) const;
	bool operator==(const string& nom) const;
	Creature& operator=(const Creature& creature);
	friend bool operator==(const string& nom, const Creature&creature);
	friend ostream& operator<<(ostream& o, const Creature&creature);

	virtual string obtenirTypeCreature();

private:

	string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	vector<Pouvoir*> pouvoirs_;
};
#endif // !CREATURE_H
