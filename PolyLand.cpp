/****************************************************************************
 * Fichier: Polyland.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 15 mai 2019
 * Mise � jour : 31 mai 2019
 * Description: Impl�mentation de la classe Polyland
 *				Polyland represente le pays que l'on va explorer, il va contenir les differents �l�ments du jeu.
 ****************************************************************************/

#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

 /****************************************************************************
	* Fonction: PolyLand::PolyLand
	* Description: Constructeur par d�faut
	* Param�tres: aucun
	* Retour: aucun
	****************************************************************************/
PolyLand::PolyLand() : creatures_(), dresseurs_() {

}

/****************************************************************************
 * Fonction: PolyLand::~PolyLand
 * Description: Destructeur de l'objet Dresseur
 * Param�tres: aucun
 * Retour: aucun
 ****************************************************************************/
PolyLand::~PolyLand() {
	while (creatures_.size() != 0)
	{
		delete creatures_.back();
		creatures_.back() = nullptr;
		creatures_.pop_back();
	}
	while (dresseurs_.size() != 0)
	{
		dresseurs_.back() = nullptr;
		dresseurs_.pop_back();
	}
}

/****************************************************************************
 * Fonction: PolyLand::ajouterDresseur
 * Description: Il prend en param�tre un dresseur et qui l�ajoute au
 *				tableau de dresseur. Deux dresseurs ne peuvent pas avoir le m�me nom.
 * Param�tres: - (Dresseur*) dresseur: C'est le nouveau dresseur � ajouter au tableau dresseurs_
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::ajouterDresseur(Dresseur* dresseur) {
	for (Dresseur* dresseurDansVecteur : dresseurs_) {
		if (dresseurDansVecteur == dresseur) {
			cout << dresseur->obtenirNomDresseur() << " n'a pas bien ete ajoute" << endl;
			return false;
		}
	}

	dresseurs_.push_back(dresseur);
	cout << dresseur->obtenirNomDresseur() << " a bien ete ajoute" << endl;
	return true;
}

/****************************************************************************
 * Fonction: PolyLand::ajouterCreature
 * Description: Il qui permet d�ajouter la cr�ature re�ue en param�tre au
 *				tableau de cr�ature. Deux cr�ature ne peuvent pas avoir le m�me nom.
 * Param�tres: - (Creature) creature: C'est la nouvelle cr�ature � ajouter au tableau creatures_
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::ajouterCreature(Creature* creature) {
	for (Creature* creatureDansVecteur : creatures_) {
		if (creatureDansVecteur == creature) {
			cout << creature->obtenirNom() << " n'a pas bien ete ajoute" << endl;
			return false;
		}
	}
	creatures_.push_back(new Creature(*creature));
	cout << creature->obtenirNom() << " a bien ete ajoute" << endl;
	return true;
}

/****************************************************************************
 * Fonction: PolyLand::retirerDresseur
 * Description: Il prend en param�tre le nom d'un dresseur et retire le dresseur
 *				associ� � ce nom du tableau dresseurs_, si celui-ci le poss�de. Cette m�thode doit renvoyer true si
 *				l�op�ration est un succ�s, false sinon.
 * Param�tres: - (string) nom: C'est le nom du dresseur � retirer du tableau dresseurs_
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::retirerDresseur(const string& nom) {
	for (Dresseur* dresseurDansVecteur : dresseurs_) {
		if (*dresseurDansVecteur == nom) {
			dresseurDansVecteur = dresseurs_[dresseurs_.size() - 1];
			dresseurs_.pop_back();
			return true;
		}
	}
	return false;
}

/****************************************************************************
 * Fonction: PolyLand::retirerCreature
 * Description: Il prend en param�tre le nom d'une cr�ature et retire la cr�ature
 *				associ� � ce nom du tableau creatures_, si celui-ci le poss�de. Cette m�thode doit renvoyer true si
 *				l�op�ration est un succ�s, false sinon.
 * Param�tres: - (string) nom: C'est le nom de la cr�ature � retirer du tableau creatures_
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::retirerCreature(const string& nom) {
	for (Creature* creatureDansVecteur : creatures_) {
		if (creatureDansVecteur->obtenirNom() == nom) {
			creatureDansVecteur = creatures_[creatures_.size() - 1];
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}

/****************************************************************************
 * Fonction: PolyLand::choisirDresseurAleatoire
 * Description: Il retourne un dresseur choisi al�atoirement
 *				dans le tableau de dresseurs.
 * Param�tres: aucun
 * Retour: Un pointeur vers un dresseur.
 ****************************************************************************/
Dresseur* PolyLand::choisirDresseurAleatoire() const {
	if (!dresseurs_.empty()) {
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else {
		return nullptr;
	}
}

/****************************************************************************
 * Fonction: PolyLand::choisirCreatureAleatoire
 * Description: Il retourne une cr�ature choisi al�atoirement
 *				dans le tableau de dresseurs.
 * Param�tres: aucun
 * Retour: Un pointeur vers une cr�ature.
 ****************************************************************************/
Creature* PolyLand::choisirCreatureAleatoire() const {
	if (!creatures_.empty()) {
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

/****************************************************************************
 * Fonction: PolyLand::attraperCreature
 * Description: Il prend en param�tre un dresseur et une cr�ature, elle
 *				renvoie true si la cr�ature a bien �t� captur�e par le dresseur, false sinon. Chaque
 *				dresseur poss�de une version unique de ses cr�atures.
 * Param�tres: - (Creature*) creature: C'est la cr�ature � capturer
 *			   - (Dresseur*) dresseur: C'est le dresseur qui a captur� la cr�ature
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature) {
	return dresseur->ajouterCreature(creature);
}

/****************************************************************************
 * Fonction: PolyLand::relacherCreature
 * Description:  Il prend en param�tre un dresseur et le nom d�une
 *				 cr�ature, elle renvoie true si la cr�ature a bien �t� rel�ch�e par le dresseur, false sinon.
 * Param�tres: - (Creature*) creature: C'est la cr�ature � rel�cher
 *			   - (Dresseur*) dresseur: C'est le dresseur qui rel�che sa cr�ature
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::relacherCreature(Dresseur* dresseur, const string& nomCreature) {
	return dresseur->enleverCreature(nomCreature);
}

/****************************************************************************
 * Fonction: operator+=
 * Description: Surcharge l'op�rateur += qui prend en param�tre un dresseur,
 *				qui l�ajoute au vecteur de dresseurs et qui retourne la Polyland
 *				avec les nouvelles modifications
 * Param�tres: - (Dresseur) dresseur : Le dresseur � ajouter
 * Retour: *this
 ****************************************************************************/
PolyLand& PolyLand::operator+=(Dresseur* dresseur) {
	ajouterDresseur(dresseur);
	return *this;
}

/****************************************************************************
 * Fonction: operator+=
 * Description: Surcharge l'op�rateur += qui prend en param�tre une cr�ature,
 *				qui l�ajoute au vecteur de cr�atures et qui retourne la Polyland
 *				avec les nouvelles modifications
 * Param�tres: - (Creature) creature : La cr�ature � ajouter
 * Retour: *this
 ****************************************************************************/
PolyLand& PolyLand::operator+=(Creature* creature) {
	ajouterCreature(creature);
	return *this;
}

/****************************************************************************
 * Fonction: operator-=
 * Description: Surcharge l'op�rateur -= qui prend en param�tre un dresseur,
				qui l�enl�ve du vecteur de dresseurs et qui retourne la Polyland
				avec les nouvelles modifications
 * Param�tres: - (Dresseur) dresseur : Le dresseur � enlever
 * Retour: *this
 ****************************************************************************/
PolyLand& PolyLand::operator-=(const Dresseur* dresseur) {
	retirerDresseur(dresseur->obtenirNomDresseur());
	return *this;
}

/****************************************************************************
 * Fonction: operator-=
 * Description: Surcharge l'op�rateur -= qui prend en param�tre une cr�ature,
 *				qui l�enl�ve du vecteur de cr�atures et qui retourne la Polyland
 *				avec les nouvelles modifications
 * Param�tres: - (Creature) creature : La cr�ature � retirer
 * Retour: *this
 ****************************************************************************/
PolyLand& PolyLand::operator-=(const Creature* creature) {
	retirerCreature(creature->obtenirNom());
	return *this;
}


/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'op�rateur == pour comparer deux dresseurs
 * Param�tres: - (Dresseur) dresseur : L'objet � comparer
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::operator==(const Dresseur& dresseur) const {
	for (Dresseur* dresseurDansVecteur : dresseurs_) {
		if (dresseurDansVecteur == &dresseur) {
			return false;
		}
	}
	return true;
}

/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'op�rateur == pour comparer deux cr�ature
 * Param�tres: - (Creature) creature : L'objet � comparer
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::operator==(const Creature& creature) const {
	for (Creature* creatureDansVecteur : creatures_) {
		if (creatureDansVecteur == &creature) {
			return false;
		}
	}
	return true;
}

/****************************************************************************
 * Fonction: operator<<
 * Description: Surcharge l'op�rateur << pour afficher toute les informations d'un pays
 * Param�tres: - (ostream&) os : objet de la classe ios qui permet la sortie
 *			   - (PolyLand) objetMagique  : L'objet polyLand que l'on veut afficher
 * Retour: aucun
 ****************************************************************************/
ostream& operator<<(ostream& os, const PolyLand& polyLand) {

	os << "INFORMATION SUR POLYLAND" << endl;

	for (Dresseur* dresseur : polyLand.dresseurs_) {
		os << *dresseur;
	}
	os << endl;

	for (Creature* creature : polyLand.creatures_) {
		os << *creature;
	}
	os << endl;

	return os;
}
