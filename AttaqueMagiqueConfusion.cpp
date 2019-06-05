/****************************************************************************
 * Fichier: AttaqueMagiqueConfusion.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 05 juin 2019
 * Description: Impl�mentation de la classe AttaqueMagiqueConfusion
 ****************************************************************************/

#include "AttaqueMagiqueConfusion.h"

 /****************************************************************************
  * Fonction: AttaqueMagiqueConfusion::AttaqueMagiqueConfusion
  * Description: Constructeur par d�faut qui initialise la dur� � 2.
  * Param�tres: aucun
  * Retour: aucun
  ****************************************************************************/
AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(): AttaqueMagique(DURE_MINMUM) {}

/****************************************************************************
 * Fonction: AttaqueMagiqueConfusion::AttaqueMagiqueConfision
 * Description: Constructeur par param�tres
 * Param�tres: - (unsigned int) duree: dur�e de l'attaque magique confusion
 * Retour: aucun
 ****************************************************************************/
AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) : AttaqueMagique(duree) {}

/****************************************************************************
 * Fonction: AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion
 * Description: Destructeur de l'objet AttaqueMagiqueConfusion
 * Param�tres: aucun
 * Retour: aucun
 ****************************************************************************/
AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion() {}

/****************************************************************************
 * Fonction: AttaqueMagiqueConfusion::appliquerAttaque
 * Description: L�attaque magique confusion permet, dans le tiers des cas, de r�duire 
				les points de vie de la cr�ature adverse de 2 points, dans le cas o� 
				celle-ci � au moins 5 points d��nergie (si bien-s�r la dur�e de l�attaque 
				magique n�est pas nulle).
 * Param�tres: (Creature) creature: La creature adverse.
 * Retour: aucun
 ****************************************************************************/
void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) {
	if (obtenirDuree() > 0 && creature.obtenirPointDeVie() >= 5) {
		unsigned int pointDeVie = creature.obtenirPointDeVie();
		
		if (rand() % 3 == 0) {
			creature.modifierPointDeVie(pointDeVie - 2);
		}
		modifierDuree(obtenirDuree()-1);
	}
}

/****************************************************************************
 * Fonction: AttaqueMagiqueConfusion::estFini
 * Description: Retourne vrai si la dur�e est fini
 * Param�tres: aucun
 * Retour: (bool) true of false
 ****************************************************************************/
bool AttaqueMagiqueConfusion::estFini() {
	if (obtenirDuree() == 0) {
		return false;
	}
	return true;
}

