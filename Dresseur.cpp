/****************************************************************************
 * Fichier: Dresseur.cpp
 * Auteur: Anass Bahir <anass.bahir@polymtl.ca> et Haroun Khalfi <haroun.khalfi@polymtl.ca>
 * Date: 15 mai 2019
 * Mise à jour : 21 mai 2019
 * Description: Implémentation de la classe Dresseur
 *				Les dresseurs sont les êtres capables d'attraper des créatures.
 ****************************************************************************/

#include "Dresseur.h"
#include <iostream>

 /****************************************************************************
  * Fonction: Dresseur::Dresseur
  * Description: Constructeur par défaut
  * Paramètres: aucun
  * Retour: aucun
  ****************************************************************************/
Dresseur::Dresseur() : nomDresseur_(""), nomEquipe_(""), objetMagique_() {};

/****************************************************************************
 * Fonction: Dresseur::Dresseur
 * Description: Constructeur par paramètres
 * Paramètres: - (string) nom: nom du dresseur
 * Retour: aucun
 ****************************************************************************/
Dresseur::Dresseur(const string& nomDresseur, const string& nomEquipe) : objetMagique_()
{
	nomDresseur_ = nomDresseur;
	nomEquipe_ = nomEquipe;
}

/****************************************************************************
 * Fonction: Dresseur::~Dresseur
 * Description: Destructeur de l'objet Dresseur
 * Paramètres: aucun
 * Retour: aucun
 ****************************************************************************/
Dresseur::~Dresseur() {
	while (creatures_.size() != 0)
	{
		creatures_.back() = nullptr;
		creatures_.pop_back();
	}
}

/****************************************************************************
 * Fonction: Dresseur::obtenirNomDresseur
 * Description: Retourne le nom du dresseur
 * Paramètres: aucun
 * Retour: (string) la valeur de nomDresseur_
 ****************************************************************************/
string Dresseur::obtenirNomDresseur() const { return nomDresseur_; }

/****************************************************************************
 * Fonction: Dresseur::obtenirNomEquipe
 * Description: Retourne le nom de l'équipe du dresseur
 * Paramètres: aucun
 * Retour: (string) la valeur de nomEquipe_
 ****************************************************************************/
string Dresseur::obtenirNomEquipe() const { return nomEquipe_; }

/****************************************************************************
 * Fonction: Dresseur::obtenirUneCreatures
 * Description: Retourne d'adresse d'une créature
 * Paramètres: - (string) nom : le nom de la créature que l'on cherche
 * Retour: (Creature*) creatureDansVecteur ou nullptr
 ****************************************************************************/
Creature * Dresseur::obtenirUneCreature(const string & nom) const{
	for (Creature* creatureDansVecteur : creatures_) {
		if (creatureDansVecteur->operator==(nom)) {
			return creatureDansVecteur;
		}
	}
	return nullptr;
}

/****************************************************************************
 * Fonction: Dresseur::obtenirObjetMagique
 * Description: Retourne un objet magique d'un dresseur
 * Paramètres: aucun
 * Retour: (ObjetMagique) objetMagique_
 ****************************************************************************/
ObjetMagique Dresseur::obtenirObjetMagique() const { return objetMagique_; }

/****************************************************************************
 * Fonction: Dresseur::obtenirNombreCreatures
 * Description: Retourne un nombre de créature
 * Paramètres: aucun
 * Retour: (unsigned int) la valeur de nombreCreature_
 ****************************************************************************/
unsigned int Dresseur::obtenirNombreCreatures() const { return creatures_.size(); }

/****************************************************************************
 * Fonction: Dresseur::obtenirCreatures
 * Description: Retourne la liste de créatures du dresseur sous forme de vecteur
 * Paramètres: aucun
 * Retour: (vector<Creature*>) la valeur de Creature_
 ****************************************************************************/
vector<Creature*> Dresseur::obtenirCreatures() const { return creatures_; }

/****************************************************************************
 * Fonction: Dresseur::modifierNomDresseur
 * Description: Modifie le nom du dresseur
 * Paramètres: - (string) nomDresseur: la nouvelle valeur de nomDresseur_
 * Retour: aucun
 ****************************************************************************/
void Dresseur::modifierNomDresseur(const string& nomDresseur) { nomDresseur_ = nomDresseur; }

/****************************************************************************
 * Fonction: Dresseur::modifierNomEquipe
 * Description: Modifie le nom de l'équipe du dresseur
 * Paramètres: - (string) nomDresseur: la nouvelle valeur de nomEquipe_
 * Retour: aucun
 ****************************************************************************/
void Dresseur::modifierNomEquipe(const string& nomEquipe) { nomEquipe_ = nomEquipe; }

/****************************************************************************
 * Fonction: Dresseur::modifierCreature
 * Description: Modifie le tableau creatures_
 * Paramètres: - (Creature**) creature: les nouvelles données du tableau Creatures_
 * Retour: aucun
 ****************************************************************************/
void Dresseur::modifierCreature(vector<Creature*> creatures) { creatures_ = creatures; }

/****************************************************************************
 * Fonction: Dresseur::modifierObjetMagique
 * Description: Modifie objetMagique_
 * Paramètres: - (ObjetMagique) objetMagique: la nouvelle valeur de objetMagique_
 * Retour: aucun
 ****************************************************************************/
void Dresseur::modifierObjetMagique(const ObjetMagique & objetMagique) { objetMagique_ = objetMagique; }

/****************************************************************************
 * Fonction: Dresseur::utiliserObjetMagique
 * Description:  Elle applique le bonus de l’attribut objetMagique du dresseur
 *				 à une créature. L’application de l’objet magique sur la créature
 *				 va augmenter l’attribut point de vie et l’attribut energie de
 *               la créature selon la valeur du bonus de l’objetMagique.
 * Paramètres: - (Creature*) creature: un pointeur sur une créature
 * Retour: aucun
 ****************************************************************************/
void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
		creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
	}
	if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus()) {
		creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());
	}
	else {
		creature->modifierEnergie(creature->obtenirEnergieTotale());
	}
}

/****************************************************************************
 * Fonction: Dresseur::ajouterCreature
 * Description: Il prend en paramètre une créature et qui l’ajoute au
 *				vecteur de créatures du dresseur. L’ajout de la créature ne se
 *				fait que si le dresseur ne la possède pas encore. Cette méthode doit renvoyer true si
 *				l’opération est un succès, false sinon.
 * Paramètres: - (Creature) creature: C'est la nouvelle créature à ajouter au vecteur creatures_
 * Retour: (bool) true or false
 ****************************************************************************/
bool Dresseur::ajouterCreature(Creature* creature) {
	for (Creature* creatureDansVecteur : creatures_) {
		if (creatureDansVecteur == creature)
			return false;
	}
	creatures_.push_back(creature);
	return true;
}

/****************************************************************************
 * Fonction: Dresseur::retirerCreature
 * Description: Il qui prend en paramètre un nom et retire la créature
 *				avec le nom associé si le dresseur la possède. Cette méthode doit renvoyer true si
 *				l’opération est un succès, false sinon.
 * Paramètres: - (Creature) creature: C'est le nom de la créature à retirer
 * Retour: (bool) true or false
 ****************************************************************************/
bool Dresseur::enleverCreature(const string& nom) {
	for (Creature* creatureDansVecteur : creatures_) {
		if (creatureDansVecteur->obtenirNom() == nom) {
			creatureDansVecteur = creatures_[creatures_.size() - 1];
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}

/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'opérateur == pour comparer deux dresseurs
 * Paramètres: - (Dresseur) dresseur : L'objet à comparer
 * Retour: (bool) true or false
 ****************************************************************************/
bool Dresseur::operator==(const Dresseur & dresseur) const
{
	bool estLeMeme;
	if (creatures_.size() != dresseur.obtenirNombreCreatures()) {
		return false;
	}
	for (Creature* creatureDansVecteur : creatures_) {
		estLeMeme = false;
		for (Creature* dresseurDansVecteur : dresseur.obtenirCreatures()) {
			if (creatureDansVecteur == dresseurDansVecteur) {
				estLeMeme = true;
			}
		}
		if (estLeMeme == false) {
			return false;
		}

	}
	return true;

}

/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'opérateur == pour comparer deux nom de dresseur
 * Paramètres:  - (String) nom : le nom à comparer
 * Retour: (bool) true or false
 ****************************************************************************/
bool Dresseur::operator==(const string&nom)const {
	if (nomDresseur_ == nom) {
		return true;
	}
	return false;
}

/****************************************************************************
 * Fonction: operator==
 * Description: Surcharge l'opérateur == pour comparer un nom de dresseur avec un dresseur
 * Paramètres:  - (String) nom : le nom à comparer
 *				- (Dresseur) dresseur : L'objet à comparer
 * Retour: (bool) true or false
 ****************************************************************************/
bool operator==(const string & nom, const Dresseur & dresseur) { return dresseur == nom; }

/****************************************************************************
 * Fonction: operator<<
 * Description: Surcharge l'opérateur << pour afficher toute les informations d'un dresseur
 * Paramètres: - (ostream&) os : objet de la classe ios qui permet la sortie
 *			   - (Dresseur) dresseur : L'objet dresseur que l'on veut afficher
 * Retour: aucun
 ****************************************************************************/
ostream & operator<<(ostream & os, const Dresseur & dresseur)
{
	return os << dresseur.nomDresseur_ << " possede " << dresseur.creatures_.size() << " creature(s) et appartient a l'equipe " << dresseur.nomEquipe_ << std::endl;
}
