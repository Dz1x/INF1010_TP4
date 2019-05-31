/****************************************************************************
 * Fichier: ObjetMagique.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> and Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 15 mai 2019
 * Mise a jour : 31 mai 2019
 * Description: Impl�mentation de la classe ObjetMagique
 *				La classe ObjetMagique correspond aux differents objets utilisable
 *				par le dresseur sur ses cr�atures.
 ****************************************************************************/

#include "ObjetMagique.h"
#include <iostream>

 /****************************************************************************
  * Fonction: ObjetMagique::ObjetMagique
  * Description: Constructeur par d�faut
  * Param�tres: aucun
  * Retour: aucun
  ****************************************************************************/
ObjetMagique::ObjetMagique()
{
	nom_ = "";
	bonus_ = 0;
}

/****************************************************************************
 * Fonction: ObjetMagique::ObjetMagique
 * Description: Constructeur par param�tres
 * Param�tres: - (string) nom: nom de l'objet magique
 *             - (int) bonus: le bonus fourni par l'objet magique
 * Retour: aucun
 ****************************************************************************/
ObjetMagique::ObjetMagique(const string& nom, int bonus) {
	nom_ = nom;
	bonus_ = bonus;
}

/****************************************************************************
 * Fonction: ObjetMagique::~ObjetMagique
 * Description: Destructeur de l'objet ObjetMagique
 * Param�tres: aucun
 * Retour: aucun
 ****************************************************************************/
ObjetMagique::~ObjetMagique() {}

/****************************************************************************
 * Fonction: ObjetMagique::obtenirNom
 * Description: Retourne le nom de l'objet magique
 * Param�tres: aucun
 * Retour: (string) la valeur de nom_
 ****************************************************************************/
string ObjetMagique::obtenirNom() const { return nom_; }

/****************************************************************************
 * Fonction: ObjetMagique::obtenirBonus
 * Description: Retourne le bonus
 * Param�tres: aucun
 * Retour: (int) la valeur de bonus_
 ****************************************************************************/
int ObjetMagique::obtenirBonus() const { return bonus_; }

/****************************************************************************
 * Fonction: ObjetMagique::modifierNom
 * Description: Modifie nom_
 * Param�tres: - (string) nom: la nouvelle valeur de nom_
 * Retour: aucun
 ****************************************************************************/
void ObjetMagique::modifierNom(const string& nom) { nom_ = nom; }

/****************************************************************************
 * Fonction: ObjetMagique::modifierBonus
 * Description: Modifie bonus_
 * Param�tres: - (int) bonus: la nouvelle valeur de bonus_
 * Retour: aucun
 ****************************************************************************/
void ObjetMagique::modifierBonus(int bonus) { bonus_ = bonus; }

/****************************************************************************
 * Fonction: operator<<
 * Description: Surcharge l'op�rateur << pour afficher toute les informations d'un objet magique
 * Param�tres: - (ostream&) os : objet de la classe ios qui permet la sortie
 *			   - (objetMagique) objetMagique : L'objet objetMagique que l'on veut afficher
 * Retour: aucun
 ****************************************************************************/
ostream& operator<<(ostream& os, const ObjetMagique & objet) {
	return os << "l'objet " << objet.nom_ << "fournit un bonus de " << objet.bonus_ << std::endl;
}
