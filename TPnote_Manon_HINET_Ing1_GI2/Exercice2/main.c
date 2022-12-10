#include "main.h"

int main() 
{
	srand(time(NULL));
	PtrFile file = NULL;	
	
	int choix = 0;

	do {
		printf("Veuillez choisir une technique d'ordonnancement non-préemptif : 1. FCFS 2. SJF 3. Priorité\n");
		scanf("%d",&choix);
	
	} while (choix != 1 && choix != 2 && choix != 3);
	
	switch (choix)
	{
		case 1 : 
			FCFS(file);
			
		break;
		
		case 2 : 
			SJF(file);
		break;
		
		case 3 : 
			priorite(file);
		break;
		
		default :
			printf("Erreur\n");
	}
	
	return 0;	
}
