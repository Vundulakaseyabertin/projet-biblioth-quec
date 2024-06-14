#ifndef EMPRUNTEUR_H
#define EMPRUNTEUR_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME 100

typedef struct {
    int id_livre;
    int id_emprunteur;
    time_t date_emprunt;
    time_t date_retour;
} Emprunt;

typedef struct {
    int id;
    char nom[MAX_NAME];
    Emprunt *historique_emprunts;
    int nombre_emprunts;
} Emprunteur;

void sauvegarder_emprunteurs();
void charger_emprunteurs();
void ajouter_emprunteur(char *nom);
void generer_rapport_livres_empruntes();


#endif
