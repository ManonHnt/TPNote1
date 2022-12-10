#include "main.h"


int nbLignes(char* nom_fichier)
{
	//-------------------------------------------------------------------------OUVERTURE DU FICHIER-------------------------------------------------------------------------
	
	FILE* fichier = fopen(nom_fichier,"r");
	if(fichier == NULL)
	{
		printf("Impossible d'ouvrir le document\n");
		exit(1);
	}
	
	//---------------------------------------------------------------------------INITIALISATION-----------------------------------------------------------------------------
	
	//on initialise la variable qui prend le contenu de chaque ligne au fur et a mesure (environ un maximum de nb_colonnes*100 caracteres par attribut par ligne)
	char ligne[nb_colonnes*100];
	
	//on initialise le nombre de lignes/logements a 0
	int nb_lignes = 0;
	
	//-------------------------------------------------------------------------------CALCUL---------------------------------------------------------------------------------
	
	//on parcourt le fichier ligne par ligne, on ajoute 1 au nombre de lignes quand on passe a la ligne dans le fichier
	while(fgets(ligne,sizeof(ligne),fichier) != NULL)
	{
		nb_lignes++;
	}
	
	//---------------------------------------------------------------------------FERMETURE DU FICHIER-----------------------------------------------------------------------
	fclose(fichier);
	
	//----------------------------------------------------------------------------RETOUR DU RESULTAT------------------------------------------------------------------------
	//On ignore la 1ère ligne
	return nb_lignes - 1;
}


void remplirTabFichierCSV(logement tab[], logement x, char* nom_fichier)
{	
	FILE* fichier = fopen(nom_fichier,"r");
	if(fichier == NULL)
	{
		printf("Impossible d'ouvrir le document\n");
		exit(1);
	}
	char ligne[nb_colonnes*100];
	
	
	//on parcourt la premiere ligne sans rien faire car elle n est pas utile pour nous (il y a juste le nom des colonnes) et on ne la stocke pas dans le tableau
	fgets(ligne,sizeof(ligne),fichier);
	
	int k=0;
	
	//on parcourt le fichier ligne par ligne
	while(fgets(ligne,sizeof(ligne),fichier) != NULL)
	{
		//on recupere sur la ligne en cours le contenu (en char) de chaque colonne/caracteristique (separe par la virgule)
		char *colonne = strtok(ligne,",");
		
		//NUMBER
		//on utilise la fonction atoi pour convertir le char en int
		tab[k].number = atof(colonne);
			
		//ACCOMODATES
		//on passe la colonne suivante
		colonne = strtok(NULL,",");
		tab[k].accomodates = atof(colonne);
		
		//BEDROOMS
		colonne = strtok(NULL,",");
		tab[k].bedrooms = atof(colonne);
		
		//BATHROOMS
		colonne = strtok(NULL,",");
		tab[k].bathrooms = atof(colonne);
			
		//BEDS
		colonne = strtok(NULL,",");
		tab[k].beds = atof(colonne);
			
		//PRICE
		colonne = strtok(NULL,",");
		//on utilise la fonction atof pour convertir le char en float
		tab[k].price = atof(colonne);
			
		//MINIMUM NIGHTS
		colonne = strtok(NULL,",");
		tab[k].minimum_nights = atof(colonne);
			
		//MAXIMUM NIGHTS
		colonne = strtok(NULL,",");
		tab[k].maximum_nights = atof(colonne);
			
		//NUMBER OF REVIEWS
		colonne = strtok(NULL,",");
		tab[k].number_of_reviews = atof(colonne);
		
		//on passe a la case suivante du tableau donc au logement suivant
		k++;
	}
	fclose(fichier);
}
