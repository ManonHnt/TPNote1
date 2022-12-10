#include "main.h"


void afficher_file(PtrListe liste) 
{
	PtrListe ptr = liste;
	if (liste == NULL)
	{
		puts("La file est vide");
	}
	else 
	{
		while(ptr != NULL) 
		{
			printf("[%c : %.0fs | %d] -> ",ptr->val.nom,ptr->val.duree_exec,ptr->val.priorite);
			ptr = ptr->suiv;
		}
		printf("\n");
	}
}



/* Creation d'un noeud de valeur x et de suivant suiv, retourne le noeud cree*/

PtrListe creerNoeud(processus ps, PtrListe suiv) 
{
	PtrListe noeud = malloc(sizeof(PtrListe));
	
	if(noeud == NULL)
	{
		puts("Erreur malloc création noeud");
		exit(1);
	}
	
	noeud->val.nom = ps.nom;
	noeud->val.duree_exec = ps.duree_exec;
	noeud->val.priorite = ps.priorite;
	noeud->suiv = suiv;
	
	return noeud;
}




// Ajout trie dans la liste : renvoi de liste





PtrListe step(PtrListe liste)
{
	PtrListe p = liste;
	if(liste != NULL)
	{
		printf("\nVoici la liste de processus :\n");
		afficher_file(liste);
		printf("\n");
		
		while(liste->val.duree_exec > 0)
		{
			printf("[%c] : %.0f\n",liste->val.nom,liste->val.duree_exec);
			liste->val.duree_exec--;
			sleep(1);
		}
		
		liste = liste->suiv;
		free(p);
	}
	
	return liste;
}

void run(PtrListe liste)
{
	while(liste != NULL)
	{
		liste = step(liste);
	}
}



PtrListe ajout_activite_priorite(PtrListe liste, processus ps) 
{
	PtrListe ptr = creerNoeud(ps, NULL);
	PtrListe p = liste;
	
	if (p == NULL) 
	{	
		return ptr;
	}
	
	// Liste vide ==> ptr devient la liste
	if (p->val.priorite > ps.priorite) 
	{
		// x plus petit => insere en tete
		ptr->suiv = p;
		return ptr;
	}
	
	while (p->suiv && p->suiv->val.priorite < ps.priorite)
	{ 
		p = p->suiv; // Recherche de la place de x
	}
	
	ptr->suiv = p->suiv;	// chainage entre p et son suivant
	p->suiv = ptr;
	
	return liste;
}


PtrListe ajout_activite_FCFS(PtrListe liste, processus ps) 
{
	PtrListe nouveau = creerNoeud(ps, NULL);
	PtrListe p = liste;
	
	if(p == NULL) 
	{	
		return nouveau;
	}
	
	while (p->suiv != NULL)
	{ 
		p = p->suiv; 
	}
	
	p->suiv = nouveau;
	
	return liste;
}


int nombre_processus()
{
	int nb;
	printf("Combien de processus voulez-vous ajouter ?\n");
	scanf("%d",&nb);
	
	return nb;
}


void FCFS(PtrListe liste)
{
	processus ps;
	int nb = nombre_processus();
	
	for(int i=0;i<nb;i++)
	{
		ps.nom = 97+i;
			
		ps.duree_exec = (rand() % (10 + 1 - 1)) + 1;
		ps.priorite = i+1;
		
		liste = ajout_activite_FCFS(liste,ps);
	}
	run(liste);
}



int verification_priorite(PtrListe liste, processus ps)
{
	PtrListe p = liste;
	while (p != NULL && p->val.priorite != ps.priorite)
	{
		p = p->suiv;
	}
	
	if (p == NULL)
	{
		return 0;
	}
	return 1;
}




void priorite(PtrListe liste)
{
	processus ps;
	int nb = nombre_processus();
	
	for(int i=0;i<nb;i++)
	{
		ps.nom = 97+i;
		ps.duree_exec = (rand() % (10 + 1 - 1)) + 1;
		
		do {
			ps.priorite = (rand() % (nb + 1 - 1)) + 1;
		} while (verification_priorite(liste,ps) == 1);
		
		
		liste = ajout_activite_priorite(liste,ps);
	}
	run(liste);
}











PtrListe ajout_activite_SJF(PtrListe liste, processus ps) 
{
	PtrListe ptr = creerNoeud(ps, NULL);
	PtrListe p = liste;
	
	if (p == NULL) 
	{	
		return ptr;
	}
	
	// Liste vide ==> ptr devient la liste
	if (p->val.duree_exec > ps.duree_exec) 
	{
		// x plus petit => insere en tete
		ptr->suiv = p;
		return ptr;
	}
	
	while (p->suiv && p->suiv->val.duree_exec < ps.duree_exec)
	{ 
		p = p->suiv; // Recherche de la place de x
	}
	
	ptr->suiv = p->suiv;	// chainage entre p et son suivant
	p->suiv = ptr;
	
	return liste;
}


void SJF(PtrListe liste)
{
	processus ps;
	int nb = nombre_processus();
	
	for(int i=0;i<nb;i++)
	{
		ps.nom = 97+i;
			
		ps.duree_exec = (rand() % (10 + 1 - 1)) + 1;
		ps.priorite = i+1;
		
		liste = ajout_activite_SJF(liste,ps);
	}
	run(liste);
}










int main() 
{
	srand(time(NULL));
	
	
	int choix = 0;
	
	int i=0;
	
	PtrListe liste = NULL;	
	
	//liste = randomListe(liste);
	
	
	
	do {
		printf("Veuillez choisir une technique d'ordonnancement non-préemptif: 1. FCFS 2. SJF 3. Priorité\n");
		scanf("%d",&choix);
	
	} while (choix != 1 && choix != 2 && choix != 3);
	
	switch (choix)
	{
		case 1 : 
			FCFS(liste);
			
		break;
		
		case 2 : 
			SJF(liste);
		break;
		
		case 3 : 
			priorite(liste);
			
		break;
	}
	

	return 0;	
}
