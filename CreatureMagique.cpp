/****************************************************************************
 * Fichier: CreatureMagique.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 28 mai 2019
 * Description: Implémentation de la classe CreatureMagique
 ****************************************************************************/

#include <iostream>
#include <string>
#include "CreatureMagique.h"
#include "AttaqueMagiquePoison.h"
#include "AttaqueMagiqueConfusion.h"

CreatureMagique::CreatureMagique() : Creature(), attaqueMagique_(nullptr) {
}
/****************************************************************************
  * Fonction: CreatureMagique::CreatureMagique
  * Description: Appel du constructeur par parametre de la classe mere avant de definir le bonus
****************************************************************************/
CreatureMagique::CreatureMagique(const Creature& creature, unsigned int bonus) : Creature(creature), bonus_(bonus), attaqueMagique_(nullptr) {
}

/****************************************************************************
  * Fonction: CreatureMagique::CreatureMagique
  * Description: Constructeur par copie
****************************************************************************/
CreatureMagique::CreatureMagique(const CreatureMagique & creatureMagique)
{
	Creature::Creature(creatureMagique);
	bonus_ = creatureMagique.obtenirBonus();
}

CreatureMagique::~CreatureMagique() {
	// Voir si il y a un truc a faire ici
}

/****************************************************************************
  * Fonction: CreatureMagique::obtenirBonus
  * Description: Permet d'obtenir le bonus de la creature magique
****************************************************************************/
unsigned int CreatureMagique::obtenirBonus() const
{
	return bonus_;
}

/****************************************************************************
  * Fonction: CreatureMagique::obtenirAttaque
  * Description: Permet d'obtenir l'attaque magique de la creature magique
****************************************************************************/
AttaqueMagique* CreatureMagique::obtenirAttaque() const {
	return attaqueMagique_;
}

/****************************************************************************
 * Fonction: CreatureMagique::modifierBonus
 * Description: Modifie bonus_
 * Paramètres: - (unsigned int) bonus: la nouvelle valeur du bonus
 * Retour: aucun
 ****************************************************************************/
void CreatureMagique::modifierBonus(unsigned int bonus) { bonus_ = bonus; }

/****************************************************************************
 * Fonction: CreatureMagique::apprendreAttaqueMagique
 * Description: Permet d'apprendre à une créature magique une nouvelle attaque magique
 * Paramètres: - (AttaqueMagique*) attaqueMagique: Un pointeur qui pointe vers la nouvelle attaque magique.
 * Retour: (bool) true or false
 ****************************************************************************/
bool CreatureMagique::apprendreAttaqueMagique(AttaqueMagique* attaqueMagique) {

	if (attaqueMagique_ == nullptr) {
		attaqueMagique_ = attaqueMagique;
	}
	else if (typeid(*attaqueMagique_).name() == typeid(*attaqueMagique).name())
	{
		delete attaqueMagique_;
		attaqueMagique_ = new AttaqueMagiquePoison;
	}
	else
	{
		delete attaqueMagique_;
		attaqueMagique_ = new AttaqueMagiqueConfusion;
	}
	return true;
}

/****************************************************************************
 * Fonction: CreatureMagique::oublierAttaqueMagique
 * Description: Permet à une créature magique d'oublier une attaque magique
 * Paramètres: - (AttaqueMagique*) attaqueMagique: Un pointeur qui pointe vers l'attaque magique à oublier.
 * Retour: (bool) true or false
 ****************************************************************************/
bool CreatureMagique::oublierAttaqueMagique(const AttaqueMagique* attaqueMagique) {
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
	return true;
}

/****************************************************************************
  * Fonction: CreatureMagique::operator=
  * Description: Utilisation de l'operateur = de la classe creature pour les attributs de base avant de modifier le bonus
****************************************************************************/
CreatureMagique & CreatureMagique::operator=(const CreatureMagique&creatureMagique)
{
	if (this != &creatureMagique)
	{
		*this = creatureMagique;
		bonus_ = creatureMagique.bonus_;
		if (typeid(*attaqueMagique_).name() == typeid(AttaqueMagiquePoison).name())
		{
			attaqueMagique_ = new AttaqueMagiquePoison;
		}
		else
		{
			attaqueMagique_ = new AttaqueMagiqueConfusion;
		}
	}
	return *this;
}

/****************************************************************************
  * Fonction: CreatureMagique::attaque
  * Description: Surcharge de la fonction attaque en utilisant la fonction de la classe creature avant de rajouter le bonus
****************************************************************************/
void CreatureMagique::attaquer(const Pouvoir & pouvoir, Creature& creature)
{
	if (attaqueMagique_->obtenirDuree() != 0)
	{
		attaqueMagique_->appliquerAttaque(creature);
	}
	Creature::attaquer(pouvoir, creature);
	modifierPointDeVie(obtenirPointDeVie() + bonus_);
	if (obtenirPointDeVie() > obtenirPointDeVieTotal())
	{
		modifierPointDeVie(creature.obtenirPointDeVie());
	}
}

/****************************************************************************
  * Fonction:  operator<<
  * Description: surcharge de l'operateur << en utilisant celui de la classe creature pour afficher
				 les attributs de base avant de rajouter l'affichage du bonus
****************************************************************************/
ostream & operator<<(ostream & os, const CreatureMagique & creatureMagique)
{
	os << creatureMagique;
	os << endl;
	os << "Le bonus de la creature est de " << creatureMagique.obtenirBonus();
	os << *(creatureMagique.obtenirAttaque()) << endl;
	return os;
}