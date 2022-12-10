#include "main.h"

int main()
{
	 srand(time(NULL));
	
	//---------------------------------------------------------------------------INITIALISATION-----------------------------------------------------------------------------
	
	//on initialise notre logement x
	logement x;
	intialisationLogementx(&x);
	
	//on compte le nombre de lignes/logements dans le fichier (sans compter la 1ère ligne)
	int nb_lignes = nbLignes("airbnb_donnees_propre.csv");
	
	//on initialise le tableau qui va contenir tous les logements
	logement tab[nb_lignes];
	
	intialisationTab(tab,nb_lignes);
	
	//------------------------------------------------------------------REMPLISSAGE DU TABLEAU AVEC LES LOGEMENTS---------------------------------------------------------------
	
	remplirTabFichierCSV(tab,x,"airbnb_donnees_propre.csv");

	//-------------------------------------------------------------------------CALCUL DISTANCE POUR TOUTES LES CARACTERISTIQUES---------------------------------------------------------------
	
	calculDistance(tab,x,nb_lignes);
	
	//--------------------------------------------------------------------------------TRI ALEATOIRE------------------------------------------------------------------------------
	
	randomTab(tab,nb_lignes);
	
	int choiceA = 0;
	int choiceB = 0;
		
	do {
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		//-------------------------------------------------------------------------------CHOIX DE LA CARACTERISTIQUE-----------------------------------------------------------------
		
		do {
			printf("\nVeuillez choisir une caractéristique : 1. Accomodates | 2. Bedrooms | 3. Bathrooms | 4. Beds | 5. Minimum nights | 6. Maximum nights\n");
			scanf("%d",&choiceA);
		} while(choiceA < 1 || choiceA > 6);
		
		//-------------------------------------------------------------------------------TRI CROISSANT-------------------------------------------------------------------------------
		
		if(choiceA > 4)
		{
			selection(tab,nb_lignes,choiceA+1);
		}
		else
		{
			selection(tab,nb_lignes,choiceA);
		}
		
		//-------------------------------------------------------------------------------AFFICHAGE-------------------------------------------------------------------------------
		
		prixMoyen(tab);
		
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\nVoulez-vous tester le programme avec une autre caractéristiques ? 1. oui 2 non\n");
		scanf("%d",&choiceB);
		
	} while(choiceB == 1);
	
	return 0;
}
