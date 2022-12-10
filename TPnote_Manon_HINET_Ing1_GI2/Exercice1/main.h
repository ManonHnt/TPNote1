#ifndef __MAIN__H__
#define __MAIN__H__
	
	//INCLUSION DE FICHIERS.H
	#include <math.h>
	#include <stdio.h>
	#include <time.h>
	#include <stdlib.h>
	#include <string.h>
	
	//VARIABLES PRE DEFINIES
	#define nb_colonnes 9

	//STRUCTURES
	typedef struct Logement {		 

		float number;
		float accomodates;
		float bedrooms;
		float bathrooms;
		float beds;
		float price;
		float minimum_nights;
		float maximum_nights;
		float number_of_reviews;
		float distance[nb_colonnes];
	} logement;
	
	//PROTOTYPES
	//fichier.c
	int nbLignes(char*);
	void remplirTabFichierCSV(logement*, logement, char*);
	
	
	//tab.c
	void randomTab(logement*, int);
	void echangeTab(logement*, int, int);
	void selection(logement*, int, int);
	void intialisationTab(logement*, int);
	
	//logement.c
	void calculDistance(logement*,logement, int);
	void intialisationLogementx(logement*);
	void prixMoyen(logement*);
#endif
