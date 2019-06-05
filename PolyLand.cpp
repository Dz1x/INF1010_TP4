/****************************************************************************
 * Fichier: Polyland.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 15 mai 2019
 * Mise à jour : 31 mai 2019
 * Description: Implémentation de la classe Polyland
 *				Polyland represente le pays que l'on va explorer, il va contenir les differents éléments du jeu.
 ****************************************************************************/

#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

 /****************************************************************************
	* Fonction: PolyLand::PolyLand
	* Description: Constructeur par défaut
	* Paramètres: aucun
	* Retour: aucun
	****************************************************************************/
PolyLand::PolyLand() : creatures_(), dresseurs_() {

}

/****************************************************************************
 * Fonction: PolyLand::~PolyLand
 * Description: Destructeur de l'objet Dresseur
 * Paramètres: aucun
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
 * Description: Il prend en paramètre un dresseur et qui l’ajoute au
 *				tableau de dresseur. Deux dresseurs ne peuvent pas avoir le même nom.
 * Paramètres: - (Dresseur*) dresseur: C'est le nouveau dresseur à ajouter au tableau dresseurs_
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
 * Description: Il qui permet d’ajouter la créature reçue en paramètre au
 *				tableau de créature. Deux créature ne peuvent pas avoir le même nom.
 * Paramètres: - (Creature) creature: C'est la nouvelle créature à ajouter au tableau creatures_
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
 * Description: Il prend en paramètre le nom d'un dresseur et retire le dresseur
 *				associé à ce nom du tableau dresseurs_, si celui-ci le possède. Cette méthode doit renvoyer true si
 *				l’opération est un succès, false sinon.
 * Paramètres: - (string) nom: C'est le nom du dresseur à retirer du tableau dresseurs_
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
 * Description: Il prend en paramètre le nom d'une créature et retire la créature
 *				associé à ce nom du tableau creatures_, si celui-ci le possède. Cette méthode doit renvoyer true si
 *				l’opération est un succès, false sinon.
 * Paramètres: - (string) nom: C'est le nom de la créature à retirer du tableau creatures_
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
 * Description: Il retourne un dresseur choisi aléatoirement
 *				dans le tableau de dresseurs.
 * Paramètres: aucun
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
 * Description: Il retourne une créature choisi aléatoirement
 *				dans le tableau de dresseurs.
 * Paramètres: aucun
 * Retour: Un pointeur vers une créature.
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
 * Description: Il prend en paramètre un dresseur et une créature, elle
 *				renvoie true si la créature a bien été capturée par le dresseur, false sinon. Chaque
 *				dresseur possède une version unique de ses créatures.
 * Paramètres: - (Creature*) creature: C'est la créature à capturer
 *			   - (Dresseur*) dresseur: C'est le dresseur qui a capturé la créature
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature) {
	return dresseur->ajouterCreature(creature);
}

/****************************************************************************
 * Fonction: PolyLand::relacherCreature
 * Description:  Il prend en paramètre un dresseur et le nom d’une
 *				 créature, elle renvoie true si la créature a bien été relâchée par le dresseur, false sinon.
 * Paramètres: - (Creature*) creature: C'est la créature à relâcher
 *			   - (Dresseur*) dresseur: C'est le dresseur qui relâche sa créature
 * Retour: (bool) true or false
 ****************************************************************************/
bool PolyLand::relacherCreature(Dresseur* dresseur, const string& nomCreature) {
	return dresseur->enleverCreature(nomCreature);
}

/****************************************************************************
 * Fonction: operator+=
 * Description: Surcharge l'opérateur += qui prend en paramètre un dresseur,
 *				qui l’ajoute au vecteur de dresseurs et qui retourne la Polyland
 *				avec les nouvelles modifications
 * Paramètres: - (Dresseur) dresseur : Le dresseur à ajouter
 * Retour: *this
 ****************************************************************************/
PolyLand& PolyLand::operator+=(Dresseur* dresseur) {
	ajouterDresseur(dresseur);
	return *this;
}

/****************************************************************************
 * Fonction: operator+=
 * Description: Surcharge l'opérateur += qui prend en paramètre une créature,
 *				qui l’ajoute au vecteur de créatures et qui retourne la Polyland
 *				avec les nouvelles modifications
 * Paramètres: - (Creature) creature : La créature à ajouter
 * Retour: *this
 ****************************************************************************/
PolyLand& PolyLand::operator+=(Creature* creature) {
	ajouterCreature(creature);
	return *this;
}

/****************************************************************************
 * Fonction: operator-=
 * Description: Surcharge l'opérateur -= qui prend en paramètre un dresseur,
				qui l’enlève du vecteur de dresseurs et qui retourne la Polyland
				avec les nouvelles modifications
 * Paramètres: - (Dresseur) dresseur : Le dresseur à enlever
 * Retour: *this
 ****************************************************************************/
PolyLand& PolyLand::operator-=(const Dresseur* dresseur) {
	retirerDresseur(dresseur->obtenirNomDresseur());
	return *this;
}

/****************************************************************************
 * Fonction: operator-=
 * Description: Surcharge l'opérateur -= qui prend en paramètre une créature,
 *				qui l’enlève du vecteur de créatures et qui retourne la Polyland
 *				avec les nouvelles modifications
 * Paramètres: - (Creature) creature : La créature à retirer
 * Retour: *this
 ****************************************************************************/
PolyLand& PolyLand::operator-=(const Creature* creature) {
	retirerCreature(creature->obtenirNom());
	return *this;
}


/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'opérateur == pour comparer deux dresseurs
 * Paramètres: - (Dresseur) dresseur : L'objet à comparer
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
 * Description: Surcharge l'opérateur == pour comparer deux créature
 * Paramètres: - (Creature) creature : L'objet à comparer
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
 * Description: Surcharge l'opérateur << pour afficher toute les informations d'un pays
 * Paramètres: - (ostream&) os : objet de la classe ios qui permet la sortie
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
