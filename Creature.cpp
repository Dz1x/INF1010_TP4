/****************************************************************************
 * Fichier: Creature.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 15 mai 2019
 * Mise à jour : 21 mai 2019
 * Description: Implémenta tion de la classe Créature
 *				Les créatures sont des êtres destinées au combat.
 ****************************************************************************/

#include "Creature.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

 /****************************************************************************
  * Fonction: Creature::Creature
  * Description: Constructeur par défaut
  * Paramètres: aucun
  * Retour: aucun
  ****************************************************************************/
Creature::Creature() :nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
energie_(0), experience_(0), niveau_(1), pouvoirs_()
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

/****************************************************************************
 * Fonction: Creature::Creature
 * Description: Constructeur par paramètres
 * Paramètres: - (string) nom: nom de la créature
 *             - (unsigned int) attaque: attaque de la créature
 *             - (unsigned int) defense: défense de la créature
 *             - (unsigned int) pointDeVie: point de vie de la créature
 *             - (unsigned int) energie: attaque de la créature pour une attaque
 *             - (Pouvoir) pouvoir: pouvoir magique de la créature
 * Retour: aucun
 ****************************************************************************/
Creature::Creature(const string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie) :
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1), pouvoirs_()
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}

/****************************************************************************
 * Fonction: Creature::Creature
 * Description: Constructeur par copie
 * Paramètres: - (Creature) creature: L'objet créature à copier
 * Retour: aucun
 ****************************************************************************/
Creature::Creature(const Creature& creature)
	: nom_(creature.nom_), attaque_(creature.attaque_), defense_(creature.defense_), pointDeVie_(creature.pointDeVie_),
	energie_(creature.energie_), experience_(creature.experience_), niveau_(creature.niveau_), pouvoirs_(creature.pouvoirs_),
	energieTotal_(creature.energieTotal_), experienceNecessaire_(creature.experienceNecessaire_), pointDeVieTotal_(creature.pointDeVieTotal_)
{
	for (unsigned int i = 0; i < creature.pouvoirs_.size(); i++)
	{
		pouvoirs_.push_back(new Pouvoir(*creature.pouvoirs_[i]));
	}
}

/****************************************************************************
 * Fonction: Creature::~Creature
 * Description: Destructeur de l'objet Creature
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Creature::~Creature() {
	while (pouvoirs_.size() != 0)
	{
		delete pouvoirs_.back();
		pouvoirs_.back() = nullptr;
		pouvoirs_.pop_back();
	}
}

/****************************************************************************
 * Fonction: Creature::obtenirNom
 * Description: Retourne le nom de la créature
 * Paramètres: aucun
 * Retour: (string) la valeur de nom_
 ****************************************************************************/
string Creature::obtenirNom() const { return nom_; }

/****************************************************************************
 * Fonction: Creature::obtenirAttaque
 * Description: Retourne les points d'attaque de la créature
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de attaque_
 ****************************************************************************/
unsigned int Creature::obtenirAttaque() const { return attaque_; }

/****************************************************************************
 * Fonction: Creature::obtenirDefense
 * Description: Retourne les points de defense de la creature
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de defense_
 ****************************************************************************/
unsigned int Creature::obtenirDefense() const { return defense_; }

/****************************************************************************
 * Fonction: Creature::obtenirPointDeVie
 * Description: Retourne le nombre de point de vie courant de la créature
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de pointDeVie_
 ****************************************************************************/
unsigned int Creature::obtenirPointDeVie() const { return pointDeVie_; }

/****************************************************************************
 * Fonction: Creature::obtenirPointDeVieTotal
 * Description: Retourne le nombre de point de vie maximum de la créature
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de pointDeVieTotal_
 ****************************************************************************/
unsigned int Creature::obtenirPointDeVieTotal() const { return pointDeVieTotal_; }

/****************************************************************************
 * Fonction: Creature::obtenirEnergie
 * Description: Retourne le niveau d'énergie de la créature
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de energie_
 ****************************************************************************/
unsigned int Creature::obtenirEnergie() const { return energie_; }

/****************************************************************************
 * Fonction: Creature::obtenirNomEnergieTotale
 * Description: Retourne le niveau d'énergie maximum que peut avoir la créature
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de energieTotal_
 ****************************************************************************/
unsigned int Creature::obtenirEnergieTotale() const { return energieTotal_; }

/****************************************************************************
 * Fonction: Creature::obtenirExperience
 * Description: Retourne le nombre de points d'expérience de la créature
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de experience_
 ****************************************************************************/
unsigned int Creature::obtenirExperience() const { return experience_; }

/****************************************************************************
 * Fonction: Creature::obtenirExperienceNecessaire
 * Description: Retourne l'expérience necessaire, de la créature, pour
 *              qu'il puisse atteindre le prochain
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de experienceNecessaire_
 ****************************************************************************/
unsigned int Creature::obtenirExperienceNecessaire() const { return experienceNecessaire_; }

/****************************************************************************
 * Fonction: Creature::obtenirNiveau
 * Description: Retourne le niveau de la créature
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de niveau_
 ****************************************************************************/
unsigned int Creature::obtenirNiveau() const { return niveau_; }

/****************************************************************************
 * Fonction: Creature::attaquer
 * Description: Fait une attaque sur une autre créature
 * Paramètres: - (Creature) creature: la créature qui va subir l'attaque
 * Retour: aucun
 ****************************************************************************/
void Creature::attaquer(const Pouvoir& pouvoir, Creature& creature)// A MODIFIER... (si necessaire)
{
	if (energie_ >= pouvoir.obtenirEnergieNecessaire())
	{
		if (creature.obtenirPointDeVie() >= 0)
		{
			//Calcul du nombre de degat selon une formule 
			unsigned int degat = (pouvoir.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				cout << nom_ << " lance " << pouvoir.obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
				if (degat > creature.obtenirPointDeVie()) {
					creature.modifierPointDeVie(0);
					int xp = experienceGagnee(creature);
					cout << nom_ << " a gagné " << xp << " XP" << endl;
				}
				else
					creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
				cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
				energie_ -= pouvoir.obtenirEnergieNecessaire();
			}
			else {
				cout << "Attaque " << pouvoir.obtenirNom() << " a échouée" << endl;
			}
		}
		else
			cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
	}

}

/****************************************************************************
 * Fonction: Creature::experienceGagnee
 * Description: Calcule et donne l’expérience gagnée lors d’un combat avec une autre créature
 * Paramètres: - (Creature) creature: un ojet de la classe creature qui est passé par adresse
 * Retour: la valeur de experience ou 0
 ****************************************************************************/
int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0)
	{
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_))
		{
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else
		{
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

/****************************************************************************
 * Fonction: Creature::modifierAttaque
 * Description: Modifie attaque_
 * Paramètres: - (unsigned int) attaque: la nouvelle valeur de attaque_
 * Retour: aucun
 ****************************************************************************/
void Creature::modifierAttaque(unsigned int attaque) { attaque_ = attaque; }

/****************************************************************************
 * Fonction: Creature::modifierDefense
 * Description: Modifie defense_
 * Paramètres: - (unsigned int) defense: la nouvelle valeur de defense_
 * Retour: aucun
 ****************************************************************************/
void Creature::modifierDefense(unsigned int defense) { defense_ = defense; }

/****************************************************************************
 * Fonction: Creature::modifierPointDeVie
 * Description: Modifie pointDeVie_
 * Paramètres: - (unsigned int) pointDeVie: la nouvelle valeur de pointDeVie_
 * Retour: aucun
 ****************************************************************************/
void Creature::modifierPointDeVie(unsigned int pointDeVie) { pointDeVie_ = pointDeVie; }

/****************************************************************************
 * Fonction: Creature::modifierEnergie
 * Description: Modifie energie_
 * Paramètres: - (unsigned int) energie: la nouvelle valeur de energie_
 * Retour: aucun
 ****************************************************************************/
void Creature::modifierEnergie(unsigned int energie) { energie_ = energie; }

/****************************************************************************
 * Fonction: Creature::modifierExperience
 * Description: Modifie experience_
 * Paramètres: - (unsigned int) experience: la nouvelle valeur de experience_
 * Retour: aucun
 ****************************************************************************/
void Creature::modifierExperience(unsigned int experience) { experience_ = experience; }

/****************************************************************************
 * Fonction: Creature::modifierNiveau
 * Description: Modifie niveau_
 * Paramètres: - (unsigned int) niveau: la nouvelle valeur de niveau_
 * Retour: aucun
 ****************************************************************************/
void Creature::modifierNiveau(unsigned int niveau) { niveau_ = niveau; }

/****************************************************************************
 * Fonction: Creature::modifierNom
 * Description: Modifie nom_
 * Paramètres: - (string) nom: Le nouveau nom de la créature
 * Retour: aucun
 ****************************************************************************/
void Creature::modifierNom(const string & nom) { nom_ = nom; }

// __________TP2__________

/****************************************************************************
 * Fonction: Creature::obtenirPouvoir
 * Description: Retourne la liste de pouvoir d'une créature
 * Paramètres: aucun
 * Retour: pouvoirs_
 ****************************************************************************/
vector<Pouvoir*> Creature::obtenirPouvoirs() const { return pouvoirs_; }

/****************************************************************************
 * Fonction: Creature::apprendrerPouvoir
 * Description: Qui permet d'ajouter un pouvoir à une créature
 * Paramètres: - (Pouvoir*) pouvoir : Le pouvoir que l'on veut ajouter
 * Retour: aucun
 ****************************************************************************/
bool Creature::apprendrePouvoir(Pouvoir* pouvoir) { 
	for (unsigned int i = 0; i < pouvoirs_.size(); i++)
	{
		if (*pouvoirs_[i] == *pouvoir)
		{
			return false;
		}
	}
	pouvoirs_.push_back(new Pouvoir(*pouvoir));
	return true;
}

/****************************************************************************
 * Fonction: Creature::oublierPouvoir
 * Description: Qui permet à une créature d'oublier un de ses pouvoirs
 * Paramètres: - (Pouvoir*) pouvoir : Le pouvoir que l'on veut faire oublier
 * Retour: (bool) true or false
 ****************************************************************************/
bool Creature::oublierPouvoir(const Pouvoir* pouvoir)
{
	for (int i = 0; i < pouvoirs_.size(); i++)
	{
		if (*(pouvoirs_[i]) == *pouvoir)
		{
			delete pouvoirs_[i];
			pouvoirs_[i] = nullptr;
			pouvoirs_[i] = pouvoirs_.back();
			pouvoirs_.pop_back();
			std::cout << "Le pouvoir " << pouvoir->obtenirNom() << " a bien ete retire." << std::endl;
			return true;
		}
	}
	std::cout << "Le pouvoir " << pouvoir->obtenirNom() << " n'a pas ete retire." << std::endl;
	return false;
}

/****************************************************************************
 * Fonction: Creature::modifierPouvoirs
 * Description: Qui permet de modifier les pouvoirs d'une créature
 * Paramètres: - (vector<Pouvoir*>) pouvoirs : La liste des nouveaux pouvoir
 * Retour: aucun
 ****************************************************************************/
void Creature::modifierPouvoirs(vector<Pouvoir*> pouvoirs) {
	while (pouvoirs_.size() != 0)
	{
		delete pouvoirs_.back();
		pouvoirs_.back() = nullptr;
		pouvoirs_.pop_back();
	}
	for (unsigned int i = 0; i < pouvoirs.size(); i++)
	{
		pouvoirs_.push_back(new Pouvoir(*pouvoirs[i]));
	}
}

/****************************************************************************
 * Fonction: operator=
 * Description: Surcharge l'opérateur = qui écrase les attributs de l’objet de gauche par les attributs l’objet passés en paramètre.
 * Paramètres: - (Creature) Creature : L'objet à écraser
 * Retour: *this
 ****************************************************************************/
Creature& Creature::operator=(const Creature& creature) {
	if (this != &creature) {
		nom_ = creature.obtenirNom();
		attaque_ = creature.obtenirAttaque();
		defense_ = creature.obtenirDefense();
		pointDeVie_ = creature.obtenirPointDeVie();
		pointDeVieTotal_ = creature.obtenirPointDeVieTotal();
		energie_ = creature.obtenirEnergie();
		energieTotal_ = creature.obtenirEnergieTotale();
		experience_ = creature.obtenirExperience();
		experienceNecessaire_ = creature.obtenirExperienceNecessaire();
		niveau_ = creature.obtenirNiveau();
		for (unsigned int i = 0; i < creature.pouvoirs_.size(); i++)
		{
			delete pouvoirs_[i];
			pouvoirs_.push_back(new Pouvoir(*creature.pouvoirs_[i]));
		}
	}
	return *this;
}

/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'opérateur == pour comparer deux créatures sans comparer leurs pouvoirs
 * Paramètres: - (Dresseur) dresseur : L'objet à comparer
 * Retour: (bool) true or false
 ****************************************************************************/
bool Creature::operator==(const Creature & creature) const {
	return (nom_ == creature.nom_ && attaque_ == creature.attaque_ && defense_ == creature.defense_ && pointDeVie_ == creature.pointDeVie_
		&& pointDeVieTotal_ == creature.pointDeVieTotal_ && energie_ == creature.energie_ && energieTotal_ == creature.energieTotal_
		&& experience_ == creature.experience_ && experienceNecessaire_ == creature.experienceNecessaire_ && niveau_ == creature.niveau_);
}

/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'opérateur == pour comparer deux nom de créature
 * Paramètres:  - (String) nom : le nom à comparer
 * Retour: (bool) true or false
 ****************************************************************************/
bool Creature::operator==(const string & nom) const {
	return (nom_ == nom);
}

/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'opérateur == pour comparer un nom d'une creature avec une creature
 * Paramètres:  - (String) nom : le nom à comparer
 *				- (creature) creature : L'objet à comparer
 * Retour: (bool) true or false
 ****************************************************************************/
bool operator==(const string& nom, const Creature& creature)
{
	return (creature == nom);
}

/****************************************************************************
 * Fonction: operator<<
 * Description: Surcharge l'opérateur << pour afficher toute les informations d'une créature
 * Paramètres: - (ostream&) os : objet de la classe ios qui permet la sortie
 *			   - (Creature) creature  : L'objet creature que l'on veut afficher
 * Retour: aucun
 ****************************************************************************/
ostream & operator<<(ostream & os, const Creature & creature)
{
	os << creature.nom_ << " a " << creature.attaque_ << " en attaque et " << creature.defense_ << " en defense, " << std::endl
		<< "Il a " << creature.pointDeVie_ << "/" << creature.pointDeVieTotal_ << " PV et " << creature.energie_ << "/" << creature.energieTotal_ << " Energie" << std::endl
		<< "Il est au niveau " << creature.niveau_ << " avec " << creature.experience_ << "d'XP" << std::endl
		<< "Il lui manque " << creature.experienceNecessaire_ - creature.experience_ << " jusqu'au prochain niveau " << std::endl;
	os << "Pouvoirs : " << std::endl;
	if (!creature.pouvoirs_.empty()) {
		for (unsigned int i = 0; i < creature.pouvoirs_.size(); i++) {
			os << *(creature.pouvoirs_[i]);
		}
	}
	else
		os << creature.nom_ << " ne connait aucun pouvoir";
	os << std::endl;
	return os;
}