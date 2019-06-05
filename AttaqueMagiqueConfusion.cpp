/****************************************************************************
 * Fichier: AttaqueMagiqueConfusion.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 05 juin 2019
 * Description: Implémentation de la classe AttaqueMagiqueConfusion
 ****************************************************************************/

#include "AttaqueMagiqueConfusion.h"

 /****************************************************************************
  * Fonction: AttaqueMagiqueConfusion::AttaqueMagiqueConfusion
  * Description: Constructeur par défaut qui initialise la duré à 2.
  * Paramètres: aucun
  * Retour: aucun
  ****************************************************************************/
AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(): AttaqueMagique(DURE_MINMUM) {}

/****************************************************************************
 * Fonction: AttaqueMagiqueConfusion::AttaqueMagiqueConfision
 * Description: Constructeur par paramètres
 * Paramètres: - (unsigned int) duree: durée de l'attaque magique confusion
 * Retour: aucun
 ****************************************************************************/
AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) : AttaqueMagique(duree) {}

/****************************************************************************
 * Fonction: AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion
 * Description: Destructeur de l'objet AttaqueMagiqueConfusion
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion() {}

/****************************************************************************
 * Fonction: AttaqueMagiqueConfusion::appliquerAttaque
 * Description: L’attaque magique confusion permet, dans le tiers des cas, de réduire 
				les points de vie de la créature adverse de 2 points, dans le cas où 
				celle-ci à au moins 5 points d’énergie (si bien-sûr la durée de l’attaque 
				magique n’est pas nulle).
 * Paramètres: (Creature) creature: La creature adverse.
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
 * Description: Retourne vrai si la durée est fini
 * Paramètres: aucun
 * Retour: (bool) true of false
 ****************************************************************************/
bool AttaqueMagiqueConfusion::estFini() {
	if (obtenirDuree() == 0) {
		return false;
	}
	return true;
}

