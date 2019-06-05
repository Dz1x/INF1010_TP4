/****************************************************************************
 * Fichier: AttaqueMagique.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 05 juin 2019
 * Description: Implémentation de la classe AttaqueMagique
 ****************************************************************************/

#include "AttaqueMagique.h"
#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"



 /****************************************************************************
  * Fonction: AttaqueMagique::AttaqueMagique
  * Description: Constructeur par défaut qui initialise la duré à 2.
  * Paramètres: aucun
  * Retour: aucun
  ****************************************************************************/
AttaqueMagique::AttaqueMagique(): duree_(DURE_MINMUM) {}

/****************************************************************************
 * Fonction: AttaqueMagique::AttaqueMagique
 * Description: Constructeur par paramètres
 * Paramètres: - (unsigned int) duree: durée de l'attaque magique
 * Retour: aucun
 ****************************************************************************/
AttaqueMagique::AttaqueMagique(unsigned int duree): duree_(duree) {}

/****************************************************************************
 * Fonction: AttaqueMagiquePoison::~AttaqueMagiquePoison
 * Description: Destructeur de l'objet AttaqueMagiquePoison
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
AttaqueMagique::~AttaqueMagique() {}

/****************************************************************************
  * Fonction: CreatureMagique::obtenirDuree
  * Description: Permet d'obtenir la durée de l'attaque magique
****************************************************************************/
int AttaqueMagique::obtenirDuree() const { return duree_; }

/****************************************************************************
 * Fonction: CreatureMagique::modifierDuree
 * Description: Modifie Duree_
 * Paramètres: - (unsigned int) duree: la nouvelle durée du l'attaque magique
 * Retour: aucun
 ****************************************************************************/
void AttaqueMagique::modifierDuree(unsigned int duree) { duree_ = duree; }

/****************************************************************************
 * Fonction: CreatureMagique::appliquerAttaque
 * Description: Permet d'appliquer l'attaque magique sur une créature
 * Paramètres: - (Creature) creature: La créature qui subit l'attaque magique
 * Retour: aucun
 ****************************************************************************/
void AttaqueMagique::appliquerAttaque(Creature & creature) {}

/****************************************************************************
 * Fonction: AttaqueMagique::estFini
 * Description: Retourne vrai si la durée est fini
 * Paramètres: aucun
 * Retour: (bool) true of false
 ****************************************************************************/
bool AttaqueMagique::estfini() { return true; }

/****************************************************************************
  * Fonction:  operator<<
  * Description: surcharge de l'operateur << en utilisant dynamic_cast pour afficher
				 les information d'une attaque magique.
****************************************************************************/
ostream & operator<<(ostream & os, AttaqueMagique* attaqueMagique) {
	if (dynamic_cast<AttaqueMagiqueConfusion*>(attaqueMagique))
	return os << "attaque magique confusion " << " qui a une duree de " << attaqueMagique->obtenirDuree() << endl;
	else if (dynamic_cast<AttaqueMagiquePoison*>(attaqueMagique))
		return os << "attaque magique poison " << " qui a une duree de " << attaqueMagique->obtenirDuree() << endl;
}