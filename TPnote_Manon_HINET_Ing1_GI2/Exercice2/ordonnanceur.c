#include "main.h"


void afficher_file(PtrFile file) 
{
	PtrFile ptr = file;
	
	//si la file est vide
	if (file == NULL)
	{
		puts("La file est vide");
	}
	else //si la file n'est pas vide
	{
		while(ptr != NULL) 
		{
			//on affiche [nom du processus : temps execution | numero de priorite]
			printf("[%c : %.0fs | %d] -> ",ptr->val.nom,ptr->val.duree_exec,ptr->val.priorite); 
			
			//on passe au processus suivant de la file
			ptr = ptr->suiv;
		}
		printf("\n");
	}
}


PtrFile creerNoeud(processus ps, PtrFile suiv) 
{
	PtrFile noeud = malloc(sizeof(PtrFile));
	
	if(noeud == NULL)
	{
		puts("Erreur malloc création noeud");
		exit(1);
	}
	
	//on crée un noeud dans la file
	noeud->val.nom = ps.nom;
	noeud->val.duree_exec = ps.duree_exec;
	noeud->val.priorite = ps.priorite;
	noeud->suiv = suiv;
	
	return noeud;
}


PtrFile step(PtrFile file)
{
	PtrFile p = file;
	if(file != NULL)
	{
		printf("\nVoici la file de processus :\n");
		afficher_file(file);
		printf("\n");
		
		//tant que la duree d'execution du processus en train d'etre execute est positive on continue l'execution
		while(file->val.duree_exec > 0)
		{
			//on afficher un decompte du temps d'execution du processus en cours
			printf("[%c] : %.0f\n",file->val.nom,file->val.duree_exec);
			file->val.duree_exec--;
			
			//on attend 1 seconde
			sleep(1);
		}
		
		//on supprime le processus en tete de la file
		file = file->suiv;
		free(p);
	}
	
	return file;
}

void run(PtrFile file)
{
	//tant que la file n'est pas vide on effectue un tour d'ordonnancement
	while(file != NULL)
	{
		file = step(file);
	}
}


int nombre_processus()
{
	int nb;
	//on demande a l'utilisateur combien de processus il souhaite ajouter a la file
	printf("Combien de processus voulez-vous ajouter ?\n");
	scanf("%d",&nb);
	
	return nb;
}
