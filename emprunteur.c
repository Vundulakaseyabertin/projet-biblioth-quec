#include "emprunteur.h"
#include "bibliotheque.h"


Livre *bibliotheque = NULL;
Emprunteur *emprunteurs = NULL;
int nombre_emprunteurs = 0;

// Fonction pour sauvegarder les données des emprunteurs dans un fichier
void sauvegarder_emprunteurs() {
    FILE *file = fopen("emprunteurs.txt", "w");
    if (file == NULL) {
        printf("                                                                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("                                                                       ::::: Impossible d'ouvrir emprunteurs.txt pour ecrire. :::::\n");
        printf("                                                                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        return;
    }
    fprintf(file, "%d\n", nombre_emprunteurs);
    for (int i = 0; i < nombre_emprunteurs; i++) {
        fprintf(file, "%d %s %d\n", emprunteurs[i].id, emprunteurs[i].nom, emprunteurs[i].nombre_emprunts);
        for (int j = 0; j < emprunteurs[i].nombre_emprunts; j++) {
            fprintf(file, "%d %d %ld %ld\n", emprunteurs[i].historique_emprunts[j].id_livre, emprunteurs[i].historique_emprunts[j].id_emprunteur, emprunteurs[i].historique_emprunts[j].date_emprunt, emprunteurs[i].historique_emprunts[j].date_retour);
        }
    }
    fclose(file);
}

// Fonction pour charger les données des emprunteurs depuis un fichier
void charger_emprunteurs() {
    FILE *file = fopen("emprunteurs.txt", "r");
    if (file == NULL) {
        printf("                                                                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("                                                                       ::::: Impossible d ouvrir emprunteurs.txt pour lecture. :::::\n");
        printf("                                                                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
        return;
    }
    fscanf(file, "%d\n", &nombre_emprunteurs);
    emprunteurs = (Emprunteur *)malloc(nombre_emprunteurs * sizeof(Emprunteur));
    for (int i = 0; i < nombre_emprunteurs; i++) {
        fscanf(file, "%d %s %d\n", &emprunteurs[i].id, emprunteurs[i].nom, &emprunteurs[i].nombre_emprunts);
        emprunteurs[i].historique_emprunts = (Emprunt *)malloc(emprunteurs[i].nombre_emprunts * sizeof(Emprunt));
        for (int j = 0; j < emprunteurs[i].nombre_emprunts; j++) {
            fscanf(file, "%d %d %ld %ld\n", &emprunteurs[i].historique_emprunts[j].id_livre, &emprunteurs[i].historique_emprunts[j].id_emprunteur, &emprunteurs[i].historique_emprunts[j].date_emprunt, &emprunteurs[i].historique_emprunts[j].date_retour);
        }
    }
    fclose(file);
}

// Fonction pour ajouter un nouvel emprunteur
void ajouter_emprunteur(char *nom) {
    emprunteurs = (Emprunteur *)realloc(emprunteurs, (nombre_emprunteurs + 1) * sizeof(Emprunteur));
    Emprunteur nouvel_emprunteur = {nombre_emprunteurs + 1, "", NULL, 0};
    strncpy(nouvel_emprunteur.nom, nom, MAX_NAME);
    emprunteurs[nombre_emprunteurs] = nouvel_emprunteur;
    nombre_emprunteurs++;
    printf("                                                                            :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                                                                            ::::::::::::::::::: Emprunteur ajoute : %s  ::::::::::::::\n", nom);
    printf("                                                                            :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    sauvegarder_emprunteurs();
}

// Fonction pour générer un rapport des livres empruntés
void generer_rapport_livres_empruntes() {
        for (int i = 0; i < nombre_emprunteurs; i++) {
            for (int j = 0; j < emprunteurs[i].nombre_emprunts; j++) {
                printf("                                                              ******       Emprunteur: %s      *****\n", emprunteurs[i].nom);
                if (emprunteurs[i].historique_emprunts[j].date_retour == 0) {
                    printf("                                                 || ID Livre: %d || Titre: %s || Emprunte par: %s ||\n\n",
                           &emprunteurs[i].historique_emprunts[j].id_livre,
                           bibliotheque[emprunteurs[i].historique_emprunts[j].id_livre].titre,
                           emprunteurs[i].nom);
                }
            }
        }
}
