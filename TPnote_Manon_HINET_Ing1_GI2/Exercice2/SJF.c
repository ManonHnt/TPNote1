#include "main.h"

PtrFile ajout_activite_SJF(PtrFile file, processus ps) 
{
	PtrFile nouveau = creerNoeud(ps, NULL);
	PtrFile p = file;
	
	//si la file est vide on renvoie le nouveau noeud cree 
	if (p == NULL) 
	{	
		return nouveau;
	}
	
	//si le temps d'execution de la tete de la file est plus grand que celui du processus a ajouter, alors on ajoute ce nouveau a la tete de la file
	if(p->val.duree_exec > ps.duree_exec) 
	{
		nouveau->suiv = p;
		return nouveau;
	}
	
	//tant que le temps d'execution du nouveau processus est plus grand on parcourt la file
	while (p->suiv != NULL && p->suiv->val.duree_exec < ps.duree_exec)
	{ 
		p = p->suiv;
	}
	
	//on ajoute le processus a la file
	nouveau->suiv = p->suiv;
	p->suiv = nouveau;
	
	return file;
}


void SJF(PtrFile file)
{
	processus ps;
	int nb = nombre_processus();
	
	for(int i=0;i<nb;i++)
	{
		ps.nom = 97+i;
		//on genere aleatoirement un temps d'execution pour le nouveau processus a ajouter a la file	
		ps.duree_exec = (rand() % (10 + 1 - 1)) + 1;
		//l'ordre de priorite n'est pas important dans la technique FCFS, on l'attribue donc en fonction de l'ordre d'arrivee
		ps.priorite = i+1;
		
		//on ajoute le processus a la file tel que les processus avec les plus petits temps d'execution vont etre en tete de file
		file = ajout_activite_SJF(file,ps);
	}
	
	//on lance l'ordonnancement (on execute les processus)
	run(file);
}


