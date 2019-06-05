/****************************************************************************
 * Fichier: Dresseur.h
 * Auteur: Alexandre Mao
 * Date: 31 août 2016
 * Mise à jour : 14 mai par David Dratwa
 * Mise à jour : 31 mai 2019 par Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Description: Définition de la classe Dresseur
 *				Les dresseurs sont les êtres capables d'attraper des créatures.
 ****************************************************************************/

#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <vector>
#include "Creature.h"

class Dresseur
{
public:

	Dresseur();
	Dresseur(const string& nom, const string&equipe);
	~Dresseur();

	string obtenirNomDresseur() const;
	string obtenirNomEquipe() const;
	Creature* obtenirUneCreature(const string&nom) const;
	ObjetMagique obtenirObjetMagique() const;
	unsigned int obtenirNombreCreatures() const;
	vector<Creature*> obtenirCreatures() const;

	void modifierNomDresseur(const string& nom);
	void modifierNomEquipe(const string& nom);
	void modifierCreature(vector<Creature*> creatures);
	void modifierObjetMagique(const ObjetMagique& objetMagique);

	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const string& nom);

	void utiliserObjetMagique(Creature* creature);

	bool operator==(const Dresseur&dresseur) const;
	bool operator==(const string&nom) const;
	friend bool operator==(const string&nom, const Dresseur&dresseur);

	friend ostream&operator<<(ostream&os, const Dresseur&dresseur);

private:

	string nomDresseur_;
	string nomEquipe_;

	ObjetMagique objetMagique_;
	vector<Creature*> creatures_;

};
#endif //!DRESSEUR_H
