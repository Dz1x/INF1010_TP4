void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature)
{
	if (duree_ > 0 && creature.obtenirPointDeVie() >= 5)
	{
		unsigned int pointDeVie = creature.obtenirPointDeVie();
		if (rand() % 3 == 0)
		{
			creature.modifierPointDeVie(pointDeVie - 2);
		}
		duree_--;
	}
}