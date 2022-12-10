#include "main.h"

PtrFile ajout_activite_FCFS(PtrFile file, processus ps) 
{
	PtrFile nouveau = creerNoeud(ps, NULL);
	PtrFile p = file;
	
	//si la file est vide on renvoie le nouveau noeud cree
	if(p == NULL) 
	{	
		return nouveau;
	}
	
	//on parcourt la file pour ajouter le nouveau processus a la fin de la file
	while (p->suiv != NULL)
	{ 
		p = p->suiv; 
	}
	
	//on ajoute le processus a la file
	p->suiv = nouveau;
	
	return file;
}

void FCFS(PtrFile file)
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
		
		//on ajoute le processus a la file tel que le premier arrivee va etre en tete de file
		file = ajout_activite_FCFS(file,ps);
	}

	//on lance l'ordonnancement (on execute les processus)
	run(file);
}
