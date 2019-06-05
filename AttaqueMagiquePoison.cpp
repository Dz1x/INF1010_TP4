/****************************************************************************
 * Fichier: AttaqueMagiquePoison.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 05 juin 2019
 * Description: Impl�mentation de la classe AttaqueMagiquePoison
 ****************************************************************************/

#include "AttaqueMagiquePoison.h"

 /****************************************************************************
  * Fonction: AttaqueMagiquePoison::AttaqueMagiquePoison
  * Description: Constructeur par d�faut qui initialise la dur� � 2.
  * Param�tres: aucun
  * Retour: aucun
  ****************************************************************************/
AttaqueMagiquePoison::AttaqueMagiquePoison(): AttaqueMagique(DURE_MINMUM) {}

/****************************************************************************
 * Fonction: AttaqueMagiquePoison::AttaqueMagiquePoison
 * Description: Constructeur par param�tres
 * Param�tres: - (unsigned int) duree: dur�e de l'attaque magique poison
 * Retour: aucun
 ****************************************************************************/
AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree) {}

/****************************************************************************
 * Fonction: AttaqueMagiquePoison::~AttaqueMagiquePoison
 * Description: Destructeur de l'objet AttaqueMagiquePoison
 * Param�tres: aucun
 * Retour: aucun
 ****************************************************************************/
AttaqueMagiquePoison::~AttaqueMagiquePoison() {}

/****************************************************************************
 * Fonction: AttaqueMagiquePoison::appliquerAttaque
 * Description: L�attaque magique poison permet, dans le tiers des cas, de r�duire
				l��nergie de la cr�ature adverse de 2 points, dans le cas o� celle-ci
				� au moins 5 points d��nergie (si bien-s�r la dur�e de l�attaque
				magique n�est pas nulle).
 * Param�tres: (Creature) creature: La creature adverse.
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
 * Description: Retourne vrai si la dur�e est fini
 * Param�tres: aucun
 * Retour: (bool) true of false
 ****************************************************************************/
bool AttaqueMagiquePoison::estFini() {
	if (obtenirDuree() == 0) {
		return true;
	}
	return false;
}
