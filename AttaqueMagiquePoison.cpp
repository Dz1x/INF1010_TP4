/****************************************************************************
 * Fichier: AttaqueMagiquePoison.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 05 juin 2019
 * Description: Implémentation de la classe AttaqueMagiquePoison
 ****************************************************************************/

#include "AttaqueMagiquePoison.h"

 /****************************************************************************
  * Fonction: AttaqueMagiquePoison::AttaqueMagiquePoison
  * Description: Constructeur par défaut qui initialise la duré à 2.
  * Paramètres: aucun
  * Retour: aucun
  ****************************************************************************/
AttaqueMagiquePoison::AttaqueMagiquePoison(): AttaqueMagique(DURE_MINMUM) {}

/****************************************************************************
 * Fonction: AttaqueMagiquePoison::AttaqueMagiquePoison
 * Description: Constructeur par paramètres
 * Paramètres: - (unsigned int) duree: durée de l'attaque magique poison
 * Retour: aucun
 ****************************************************************************/
AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree) {}

/****************************************************************************
 * Fonction: AttaqueMagiquePoison::~AttaqueMagiquePoison
 * Description: Destructeur de l'objet AttaqueMagiquePoison
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
AttaqueMagiquePoison::~AttaqueMagiquePoison() {}

/****************************************************************************
 * Fonction: AttaqueMagiquePoison::appliquerAttaque
 * Description: L’attaque magique poison permet, dans le tiers des cas, de réduire
				l’énergie de la créature adverse de 2 points, dans le cas où celle-ci
				à au moins 5 points d’énergie (si bien-sûr la durée de l’attaque
				magique n’est pas nulle).
 * Paramètres: (Creature) creature: La creature adverse.
 * Retour: aucun
 ****************************************************************************/
void AttaqueMagiquePoison::appliquerAttaque(Creature& creature) {
	
	if (obtenirDuree() > 0 && creature.obtenirEnergie() >= 5) {
		unsigned int energie = creature.obtenirEnergie();
		
		if (rand() % 3 == 0) {
			creature.modifierPointDeVie(energie - 2);
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
bool AttaqueMagiquePoison::estFini() {
	if (obtenirDuree() == 0) {
		return true;
	}
	return false;
}
