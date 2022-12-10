#ifndef __MAIN__H__
#define __MAIN__H__
	
	//INCLUSION DE FICHIERS.H
	
	#include <stdio.h>
	#include <time.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>
	

	//STRUCTURES
	
	typedef struct Processus
	{
		char nom;
		float duree_exec;
		int priorite;
	} processus;


	typedef struct ordonnanceur 
	{
		processus val;
		struct ordonnanceur * suiv;
	} File;


	typedef File * PtrFile;
	
	//PROTOTYPES
	
	//ordonnanceur.c
	void afficher_file(PtrFile);
	PtrFile creerNoeud(processus, PtrFile);
	PtrFile step(PtrFile);
	void run(PtrFile);
	int nombre_processus();
	
	
	//FCFS.c
	PtrFile ajout_activite_FCFS(PtrFile, processus);
	void FCFS(PtrFile);
	
	
	//SJF.c
	PtrFile ajout_activite_SJF(PtrFile, processus);
	void SJF(PtrFile);
	
	
	//priorite.c
	PtrFile ajout_activite_priorite(PtrFile, processus);
	int verification_priorite(PtrFile, processus);
	void priorite(PtrFile);
#endif
