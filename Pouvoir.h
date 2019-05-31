/****************************************************************************
 * Fichier: Pouvoir.h
 * Auteur: Alexandre Mao
 * Date: 31 août 2016
 * Mise à jour : 14 mai par David Dratwa
 * Mise à jour : 31 mai 2019 par Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Description: Définition de la classe Pouvoir
 *				La classe Pouvoir correspond aux differentes attaques.
 ****************************************************************************/

#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>

using namespace std;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	Pouvoir(const Pouvoir&pouvoir);

	~Pouvoir();

	unsigned int obtenirNombreDeDegat() const;
	unsigned int obtenirEnergieNecessaire() const;
	string obtenirNom() const;

	void modifierNombreDeDegat(unsigned int nombreDegat);
	void modifierEnergieNecessarie(unsigned int energieNecessaire);
	void modifierNom(const string& nom);

	Pouvoir& operator=(const Pouvoir& pouvoir);
	bool operator==(const Pouvoir& pouvoir) const;
	friend ostream& operator<<(ostream& o, const Pouvoir&pouvoir);

private:
	string nom_;
	unsigned int nombreDeDegat_;
	unsigned int energieNecessaire_;
};

#endif // !POUVOIR_H
