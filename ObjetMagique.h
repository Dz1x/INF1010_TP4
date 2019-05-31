/****************************************************************************
 * Fichier: ObjetMagique.h
 * Auteur: Alexandre Mao
 * Date: 31 ao�t 2016
 * Mise � jour : 14 mai par David Dratwa
 * Mise � jour : 31 mai 2019 par Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Description: D�finition de la classe ObjetMagique
 *				La classe ObjetMagique correspond aux differents objets utilisable
 *				par le dresseur sur ses cr�atures.
 ****************************************************************************/

#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>

using namespace std;

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const string &nom, int bonus);
	~ObjetMagique();

	string obtenirNom() const;
	int obtenirBonus() const;

	void modifierNom(const string& nom);
	void modifierBonus(int bonus);

	friend ostream& operator<<(ostream&o, const ObjetMagique&objet); 

private:
	string nom_;
	int bonus_;
};
#endif //!OBJETMAGIQUE_H
