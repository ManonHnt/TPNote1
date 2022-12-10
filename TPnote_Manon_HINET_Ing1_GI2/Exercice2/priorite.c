#include "main.h"

PtrFile ajout_activite_priorite(PtrFile file, processus ps) 
{
	PtrFile nouveau = creerNoeud(ps, NULL);
	PtrFile p = file;
	
	//si la file est vide on renvoie le nouveau noeud cree
	if(p == NULL) 
	{	
		return nouveau;
	}
	
	
	//si le numero de priorite de la tete de la file est plus grand que celui du processus a ajouter, alors on ajoute ce nouveau a la tete de la file
	if(p->val.priorite > ps.priorite) 
	{
		nouveau->suiv = p;
		return nouveau;
	}
	
	while(p->suiv != NULL && p->suiv->val.priorite < ps.priorite)
	{ 
		//tant que le numero de priorite du nouveau processus est plus grand on parcourt la file
		p = p->suiv;
	}
	
	//on ajoute le processus a la file
	nouveau->suiv = p->suiv;
	p->suiv = nouveau;
	
	return file;
}

int verification_priorite(PtrFile file, processus ps)
{
	PtrFile p = file;
	
	//tant que la file n'est pas vide et que l'on n'a pas trouve de processus avec un certain numero de priorite on parcourt la file
	while (p != NULL && p->val.priorite != ps.priorite)
	{
		p = p->suiv;
	}
	
	//aucun processus dans la file n'a le meme numero de priorite que celui passe en parametre
	if(p == NULL)
	{
		return 0;
	}
	
	//un processus dans la file a le meme numero de priorite que celui passe en parametre
	return 1;
}

void priorite(PtrFile file)
{
	processus ps;
	int nb = nombre_processus();
	
	for(int i=0;i<nb;i++)
	{
		ps.nom = 97+i;
		//on genere aleatoirement un temps d'execution pour le nouveau processus a ajouter a la file	
		ps.duree_exec = (rand() % (10 + 1 - 1)) + 1;
		
		///on genere aleatoirement un temps d'execution pour le nouveau processus a ajouter a la file et on verifie que ce numero n'est pas deja attribue a un processus dans la file
		do {
			ps.priorite = (rand() % (nb + 1 - 1)) + 1;
		} while (verification_priorite(file,ps) == 1);
		
		//on ajoute le processus a la file tel que les processus avec les plus petits numeros de priorite vont etre en tete de file
		file = ajout_activite_priorite(file,ps);
	}
	
	//on lance l'ordonnancement (on execute les processus)
	run(file);
}
