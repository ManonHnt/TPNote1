#include "main.h"


void calculDistance(logement tab[],logement x, int nb_lignes)
{
	for(int i=0;i<nb_lignes;i++)
	{
		tab[i].distance[1] = (x.accomodates - tab[i].accomodates)*(x.accomodates - tab[i].accomodates);
		tab[i].distance[1] = sqrt(tab[i].distance[1]);
		
		tab[i].distance[2] = (x.bedrooms - tab[i].bedrooms)*(x.bedrooms - tab[i].bedrooms);
		tab[i].distance[2] = sqrt(tab[i].distance[2]);
		
		tab[i].distance[3] = (x.bathrooms - tab[i].bathrooms)*(x.bathrooms - tab[i].bathrooms);
		tab[i].distance[3] = sqrt(tab[i].distance[3]);
		
		tab[i].distance[4] = (x.beds - tab[i].beds)*(x.beds - tab[i].beds);
		tab[i].distance[4] = sqrt(tab[i].distance[4]);
		
		tab[i].distance[6] = (x.minimum_nights - tab[i].minimum_nights)*(x.minimum_nights - tab[i].minimum_nights);
		tab[i].distance[6] = sqrt(tab[i].distance[6]);
		
		tab[i].distance[7] = (x.maximum_nights - tab[i].maximum_nights)*(x.maximum_nights - tab[i].maximum_nights);
		tab[i].distance[7] = sqrt(tab[i].distance[7]);
	}
}

void intialisationLogementx(logement* x)
{
	printf("Nous allons commencer par initialiser le logement x. Veuillez saisir les caractéristiques suivantes :\n");
	
	(*x).number = 0;
	for(int i=0;i<nb_colonnes;i++)
	{
		(*x).distance[i] = 0;
	}
	(*x).price = 0;
	(*x).number_of_reviews = 0;
	
	printf("Entrez la valeur pour 'accomodates' :\n");
	scanf("%f",&(*x).accomodates);
	
	printf("Entrez la valeur pour 'bedrooms' :\n");
	scanf("%f",&(*x).bedrooms);
	
	printf("Entrez la valeur pour 'bathrooms' :\n");
	scanf("%f",&(*x).bathrooms);
	
	printf("Entrez la valeur pour 'beds' :\n");
	scanf("%f",&(*x).beds);
	
	printf("Entrez la valeur pour 'minimum_nights' :\n");
	scanf("%f",&(*x).minimum_nights);
	
	printf("Entrez la valeur pour 'maximum_nights' :\n");
	scanf("%f",&(*x).maximum_nights);		
}

void prixMoyen(logement tab[])
{
	float moy_price = 0;
	int k;
	
	printf("\nAvec combien de logements voulez-vous comparer le logement x ?\n");
	scanf("%d",&k);
	
	
	printf("\nLes %d logements les plus similaires au logement x sont les logements avec les numéros : \n",k);
	for(int j=0;j<k;j++)
	{
		printf("%.0f  ",tab[j].number);
	}
	
	for(int j=0;j<k;j++)
	{
		moy_price += tab[j].price;
	}
	
	moy_price /= k;
	
	printf("\nLe prix recommandé pour le logement x d'après la moyenne est de %.2f €\n",moy_price);
}
