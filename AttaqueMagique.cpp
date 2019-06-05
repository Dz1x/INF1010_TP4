/****************************************************************************
 * Fichier: AttaqueMagique.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 05 juin 2019
 * Description: Impl�mentation de la classe AttaqueMagique
 ****************************************************************************/

#include "AttaqueMagique.h"
#include "AttaqueMagiqueConfusion.h"
#include "AttaqueMagiquePoison.h"



 /****************************************************************************
  * Fonction: AttaqueMagique::AttaqueMagique
  * Description: Constructeur par d�faut qui initialise la dur� � 2.
  * Param�tres: aucun
  * Retour: aucun
  ****************************************************************************/
AttaqueMagique::AttaqueMagique(): duree_(DURE_MINMUM) {}

/****************************************************************************
 * Fonction: AttaqueMagique::AttaqueMagique
 * Description: Constructeur par param�tres
 * Param�tres: - (unsigned int) duree: dur�e de l'attaque magique
 * Retour: aucun
 ****************************************************************************/
AttaqueMagique::AttaqueMagique(unsigned int duree): duree_(duree) {}

/****************************************************************************
 * Fonction: AttaqueMagiquePoison::~AttaqueMagiquePoison
 * Description: Destructeur de l'objet AttaqueMagiquePoison
 * Param�tres: aucun
 * Retour: aucun
 ****************************************************************************/
AttaqueMagique::~AttaqueMagique() {}

/****************************************************************************
  * Fonction: CreatureMagique::obtenirDuree
  * Description: Permet d'obtenir la dur�e de l'attaque magique
****************************************************************************/
int AttaqueMagique::obtenirDuree() const { return duree_; }

/****************************************************************************
 * Fonction: CreatureMagique::modifierDuree
 * Description: Modifie Duree_
 * Param�tres: - (unsigned int) duree: la nouvelle dur�e du l'attaque magique
 * Retour: aucun
 ****************************************************************************/
void AttaqueMagique::modifierDuree(unsigned int duree) { duree_ = duree; }

/****************************************************************************
 * Fonction: CreatureMagique::appliquerAttaque
 * Description: Permet d'appliquer l'attaque magique sur une cr�ature
 * Param�tres: - (Creature) creature: La cr�ature qui subit l'attaque magique
 * Retour: aucun
 ****************************************************************************/
void AttaqueMagique::appliquerAttaque(Creature & creature) {}

/****************************************************************************
 * Fonction: AttaqueMagique::estFini
 * Description: Retourne vrai si la dur�e est fini
 * Param�tres: aucun
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