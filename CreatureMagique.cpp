/****************************************************************************
 * Fichier: CreatureMagique.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 28 mai 2019
 * Description: Implémentation de la classe CreatureMagique
 ****************************************************************************/

#include <iostream>
#include <string>
#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(): Creature(), attaqueMagique_(nullptr) {
}
 /****************************************************************************
   * Fonction: CreatureMagique::CreatureMagique
   * Description: Appel du constructeur par parametre de la classe mere avant de definir le bonus
 ****************************************************************************/
CreatureMagique::CreatureMagique(const Creature& creature, unsigned int bonus): Creature(creature), bonus_(bonus), attaqueMagique_(nullptr) {
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

AttaqueMagique* CreatureMagique::obtenirAttaque() const {
	return attaqueMagique_;
}

void CreatureMagique::modifierBonus(unsigned int bonus) { bonus_ = bonus; }

bool CreatureMagique::apprendreAttaqueMagique(const AttaqueMagique* attaqueMagique) {

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
		nom_ = creatureMagique.obtenirNom();
		attaque_ = creatureMagique.attaque_;
		defense_ = creatureMagique.defense_;
		pointDeVie_ = creatureMagique.pointDeVie_;
		pointDeVieTotal_ = creatureMagique.pointDeVieTotal_;
		energie_ = creatureMagique.energie_;
		energieTotal_ = creatureMagique.energieTotal_;
		experience_ = creatureMagique.experience_;
		experienceNecessaire_ = creatureMagique.experienceNecessaire_;
		niveau_ = creatureMagique.niveau_;
		pouvoirs_ = creatureMagique.pouvoirs_;
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
		modifierPointDeVie(pointDeVieTotal_);
	}
}

/****************************************************************************
  * Fonction:  operator<<
  * Description: surcharge de l'operateur << en utilisant celui de la classe creature pour afficher 
				 les attributs de base avant de rajouter l'affichage du bonus
****************************************************************************/
ostream & operator<<(ostream & os, const CreatureMagique & creatureMagique)
{
	os << "La creature magique " << creatureMagique.obtenirNom() << " a " << creatureMagique.obtenirAttaque() << " en attaque et " << creatureMagique.obtenirDefense() << " en defense, " << endl
		<< "Il a " << creatureMagique.obtenirPointDeVie() << "/" << creatureMagique.obtenirPointDeVieTotal() << " PV et " << creatureMagique.obtenirEnergie() << "/" << creatureMagique.obtenirEnergieTotale() << " Energie" << endl
		<< "Il est au niveau " << creatureMagique.obtenirNiveau() << " avec " << creatureMagique.obtenirExperience() << "d'XP" << endl
		<< "Il lui manque " << creatureMagique.obtenirExperienceNecessaire() - creatureMagique.obtenirExperience() << " jusqu'au prochain niveau " << endl;
	os << "Pouvoirs : " << endl;
	if (!creatureMagique.obtenirPouvoirs().empty()) {
		for (Pouvoir* pouvoir : creatureMagique.obtenirPouvoirs()) {
			os << *pouvoir << " ";
		}
	}
	else
		os << creatureMagique.obtenirNom() << " ne connait aucun pouvoir";
	os << endl;
	os << "Le bonus de la creature est de " << creatureMagique.obtenirBonus();
	os << *(creature.obtenirAttaqueMagique()) << endl;
	return os;
}