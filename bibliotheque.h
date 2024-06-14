#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_BOOKS 5

typedef struct {
    int id;
    char titre[MAX_TITLE];
    char auteur[MAX_AUTHOR];
    int annee;
    int disponible; // 1 si disponible, 0 si emprunté
} Livre;

void sauvegarder_bibliotheque();
void charger_bibliotheque();
void ajouter_livre(char *titre, char *auteur, int annee);
void rechercher_livres_par_titre(char *titre);
void rechercher_livres_par_auteur(char *auteur);
void afficher_tous_les_livres();
void emprunter_livre(int id_emprunteur, int id_livre);
void retourner_livre(int id_emprunteur, int id_livre);



#endif
