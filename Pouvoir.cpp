/****************************************************************************
 * Fichier: Pouvoir.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 15 mai 2019
 * Mise à jour : 31 mai 2019
 * Description: Implémentation de la classe Pouvoir
 *				La classe Pouvoir correspond aux differentes attaques.
 ****************************************************************************/

#include "Pouvoir.h"
#include <iostream>

 /****************************************************************************
  * Fonction: Pouvoir::Pouvoir
  * Description: Constructeur par défaut
  * Paramètres: aucun
  * Retour: aucun
  ****************************************************************************/
Pouvoir::Pouvoir() {
	nom_ = "";
	nombreDeDegat_ = 0;
	energieNecessaire_ = 0;
}

/****************************************************************************
 * Fonction: Pouvoir::Pouvoir
 * Description: Constructeur par paramètres
 * Paramètres: - (string) nom: nom du pouvoir
 *             - (unsigned int) nombreDeDegat: Un nommbre de dégâts
 *             - (unsigned int) manaNecessaire: Une valeur d'énergie necessaire
 * Retour: aucun
 ****************************************************************************/
Pouvoir::Pouvoir(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire) {
	nom_ = nom;
	nombreDeDegat_ = nombreDeDegat;
	energieNecessaire_ = energieNecessaire;
}

/****************************************************************************
 * Fonction: Pouvoir::Pouvoir
 * Description: Constructeur par copie de l'objet Pouvoir
 * Paramètres: - (Const Pouvoir&) pouvoir: l'objet à copier
 * Retour: aucun
 ****************************************************************************/
Pouvoir::Pouvoir(const Pouvoir& pouvoir) {
	nom_ = pouvoir.obtenirNom();
	nombreDeDegat_ = pouvoir.obtenirNombreDeDegat();
	energieNecessaire_ = pouvoir.obtenirEnergieNecessaire();
}

/****************************************************************************
 * Fonction: Pouvoir::~Pouvoir
 * Description: Destructeur de l'objet Pouvoir
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Pouvoir::~Pouvoir() {}

/****************************************************************************
 * Fonction: Pouvoir::obtenirNom
 * Description: Retourne le nom du pouvoir
 * Paramètres: aucun
 * Retour: (string) la valeur de nom_
 ****************************************************************************/
string Pouvoir::obtenirNom() const { return nom_; }

/****************************************************************************
 * Fonction: Pouvoir::obtenirNombreDeDegat
 * Description: Retourne le nombre de dégat
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de nombreDeDegat_
 ****************************************************************************/
unsigned int Pouvoir::obtenirNombreDeDegat() const { return nombreDeDegat_; }

/****************************************************************************
 * Fonction: Pouvoir::obtenirEnergieNecessaire
 * Description: Retourne la valeur d'énergie nécessaire
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de energieNecessaire_
 ****************************************************************************/
unsigned int Pouvoir::obtenirEnergieNecessaire() const { return energieNecessaire_; }

/****************************************************************************
 * Fonction: Pouvoir::modifierNom
 * Description: Modifie le nom du pouvoir
 * Paramètres: - (string) nom : Le nouveau nom du pouvoir
 * Retour: aucun
 ****************************************************************************/
void Pouvoir::modifierNom(const string& nom) { nom_ = nom; }

/****************************************************************************
 * Fonction: Pouvoir::modifierNombreDeDegat
 * Description: Modifie nombreDeDegat_
 * Paramètres: - (unsigned int) nombreDeDegat: la nouvelle valeur de nombreDeDegat_
 * Retour: aucun
 ****************************************************************************/
void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat) { nombreDeDegat_ = nombreDegat; }

/****************************************************************************
 * Fonction: Pouvoir::modifierEnergieNecessairie
 * Description: Modifie energieNecessaire_
 * Paramètres: - (unsigned int) energieNecessaire: la nouvelle valeur de energieNecessaire_
 * Retour: aucun
 ****************************************************************************/
void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire) { energieNecessaire_ = energieNecessaire; }



// __________TP2__________

/****************************************************************************
 * Fonction: operator=
 * Description: Surcharge l'opérateur = qui écrase les attributs de l’objet de
				gauche par les attributs l’objet passés en paramètre.
 * Paramètres: - (Pouvoir) pouvoir : L'objet à écraser
 * Retour: *this
 ****************************************************************************/
Pouvoir& Pouvoir::operator=(const Pouvoir& pouvoir) {
	if (this != &pouvoir) {
		nom_ = pouvoir.obtenirNom();
		nombreDeDegat_ = pouvoir.obtenirNombreDeDegat();
		energieNecessaire_ = pouvoir.obtenirEnergieNecessaire();
	}
	return *this;
}

/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'opérateur == pour comparer deux pouvoirs
 * Paramètres: - (Pouvoir) pouvoir : L'objet à comparer
 * Retour: (bool) true or false
 ****************************************************************************/
bool Pouvoir::operator==(const Pouvoir & pouvoir) const {
	return (nom_ == pouvoir.obtenirNom());
}

/****************************************************************************
 * Fonction: operator<<
 * Description: Surcharge l'opérateur << pour afficher toute les informations d'un pouvoir
 * Paramètres: - (ostream&) os : objet de la classe ios qui permet la sortie
 *			   - (objetMagique) objetMagique  : L'objet pouvoir que l'on veut afficher
 * Retour: aucun
 ****************************************************************************/
ostream& operator<<(ostream& os, const Pouvoir& pouvoir) {
	return os << pouvoir.nom_ << " possede un nombre de dégat de " << pouvoir.nombreDeDegat_ << " et une energie necessaire de " << pouvoir.energieNecessaire_ << std::endl;	return os;
}