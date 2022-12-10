#include "main.h"


//On echange les cases indiceA et indiceB
void echangeTab(logement tab[],int indiceA, int indiceB)
{
	float tmp=tab[indiceA].number;
	tab[indiceA].number=tab[indiceB].number;
	tab[indiceB].number=tmp;
			
	tmp=tab[indiceA].accomodates;
	tab[indiceA].accomodates=tab[indiceB].accomodates;
	tab[indiceB].accomodates=tmp;
			
	tmp=tab[indiceA].bedrooms;
	tab[indiceA].bedrooms=tab[indiceB].bedrooms;
	tab[indiceB].bedrooms=tmp;
			
	tmp=tab[indiceA].bathrooms;
	tab[indiceA].bathrooms=tab[indiceB].bathrooms;
	tab[indiceB].bathrooms=tmp;
			
	tmp=tab[indiceA].beds;
	tab[indiceA].beds=tab[indiceB].beds;
	tab[indiceB].beds=tmp;
			
	tmp=tab[indiceA].price;
	tab[indiceA].price=tab[indiceB].price;
	tab[indiceB].price=tmp;
			
	tmp=tab[indiceA].minimum_nights;
	tab[indiceA].minimum_nights=tab[indiceB].minimum_nights;
	tab[indiceB].minimum_nights=tmp;
			
	tmp=tab[indiceA].maximum_nights;
	tab[indiceA].maximum_nights=tab[indiceB].maximum_nights;
	tab[indiceB].maximum_nights=tmp;
			
	tmp=tab[indiceA].number_of_reviews;
	tab[indiceA].number_of_reviews=tab[indiceB].number_of_reviews;
	tab[indiceB].number_of_reviews=tmp;
	
	for(int i=0;i<nb_colonnes;i++)
	{
		tmp=tab[indiceA].distance[i];
		tab[indiceA].distance[i]=tab[indiceB].distance[i];
		tab[indiceB].distance[i]=tmp;
	}
}


//on choisi 2 indices du tableau aléatoirement pour ensuite echanger ces 2 cases
void randomTab(logement tab[], int n)
{
	int indiceA = 0;
	int indiceB = 0;
	
	for(int i=0;i<n;i++)
	{
		indiceA = (rand() % ((n-1) + 1 - 0)) + 0;
		indiceB = (rand() % ((n-1) + 1 - 0)) + 0;
		echangeTab(tab,indiceA,indiceB);
	}
}

//tri par selection par odre croissant de la distance correspondant a la caracteristique choisie
void selection(logement tab[], int nb_logements, int caracteristique)
{
	int min;
	int j;
	for(int i=0;i<nb_logements-1;i++)
	{
		min=i;
		
		for(j=i+1;j<nb_logements;j++)
		{
			if(tab[j].distance[caracteristique] < tab[min].distance[caracteristique])
			{
				min=j;
			}
		}
		
		if(i!=min)
		{
			echangeTab(tab,i,min);
		}
	}
}


void intialisationTab(logement tab[], int nb_lignes)
{
	for(int i=0;i<nb_lignes;i++)
	{
		tab[i].number = -1;
		tab[i].accomodates = 0;
		tab[i].bedrooms = 0;
		tab[i].bathrooms = 0;
		tab[i].beds = 0;
		tab[i].price = 0;
		tab[i].minimum_nights = 0;	
		tab[i].maximum_nights = 0;	
		tab[i].number_of_reviews = 0;
		
		for(int j=0;j<nb_colonnes;j++)
		{
			tab[i].distance[j] = 0;
		}
	}
}

