#include "bibliotheque.h"
#include "emprunteur.c"


//Livre *bibliotheque = NULL;
int nombre_livres = 0;

// Fonction pour sauvegarder les données de la bibliothèque dans un fichier
void sauvegarder_bibliotheque() {
    FILE *file = fopen("bibliotheque.txt", "w"); // Ouverture de fichier BIBLIOTHEQUE
    if (file == NULL) { // pour verifier si le fichier est bien ouvert
        printf("                                                                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("                                                                       ::::: Impossible d'ouvrir bibliotheque.txt pour ecrire. :::::\n");
        printf("                                                                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
               return;
    }
    fprintf(file, "%d\n", nombre_livres); // permet de compter le nombre de livres qui sont dans la bibliotheque
    for (int i = 0; i < nombre_livres; i++) {
        fprintf(file, "%d %s %s %d %d\n", bibliotheque[i].id, bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].annee, bibliotheque[i].disponible); // pour l'ecriture dans le fichier bibliotheque
    }
    fclose(file);
}

// Fonction pour charger les données de la bibliothèque depuis un fichier
void charger_bibliotheque() {
    FILE *file = fopen("bibliotheque.txt", "r"); // ouvrire le fichier bibliotheque
    if (file == NULL) {
        printf("                                                                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("                                                                       ::::: Impossible d'ouvrir bibliotheque.txt pour lecture. ::::\n");
        printf("                                                                       :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        return;
    }
    fscanf(file, "%d\n", &nombre_livres); // pour compter les livres
    bibliotheque = (Livre *)malloc(nombre_livres * sizeof(Livre)); // location de l'espace de la variable bibliotheque dynamique
    for (int i = 0; i < nombre_livres; i++) {
        fscanf(file, "%d %s %s %d %d\n", &bibliotheque[i].id, bibliotheque[i].titre, bibliotheque[i].auteur, &bibliotheque[i].annee, &bibliotheque[i].disponible); // ecrire dans le fichier
    }
    fclose(file); // fermeture de fichier
}



// Fonction pour ajouter un nouveau livre à la bibliothèque
void ajouter_livre(char *titre, char *auteur, int annee) {
    bibliotheque = (Livre *)realloc(bibliotheque, (nombre_livres + 1) * sizeof(Livre));
    Livre nouveau_livre = {nombre_livres + 1, "", "", annee, 1};
    strncpy(nouveau_livre.titre, titre, MAX_TITLE);
    strncpy(nouveau_livre.auteur, auteur, MAX_AUTHOR); // stocker les differentes informations sur un livre
    bibliotheque[nombre_livres] = nouveau_livre;
    nombre_livres++;
    printf("                                                                           ****************************************\n");
    printf("                                                                           **** Livre Ajouter avec succes *********\n");
    printf("                                                                           ****************************************\n\n");
   //printf("Titre : %s || Auteur : %s || Annee : %d\n",bibliotheque[i].titre,bibliotheque[i].auteur,&bibliotheque[i].annee);

    sauvegarder_bibliotheque();
}

// Fonction pour rechercher des livres par titre
void rechercher_livres_par_titre(char *titre) {
    for (int i = 0; i < nombre_livres; i++) {
        if (strstr(bibliotheque[i].titre, titre) != NULL) {
            if (i == 0){
                   printf("                                                             *******************************************\n");
                   printf("                                                             **************  Livre trouve (S) **********\n\n");
            }


            printf("                                                   || ID : %d || Titre : %s || Auteur : %s || Annee : %d || Disponibilite : %d\n", bibliotheque[i].id, bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].annee, bibliotheque[i].disponible);
        }
    }
}

// Fonction pour rechercher des livres par auteur
void rechercher_livres_par_auteur(char *auteur) {
    for (int i = 0; i < nombre_livres; i++) { //boucle pour parcourir le fichier bibliotheque pour chercher un livre
        if (strstr(bibliotheque[i].auteur, auteur) != NULL) {
            if (i == 0){
                   printf("                                                             *******************************************\n");
                   printf("                                                             **************  Livre trouve (S) **********\n\n");
            }

            printf("                                                   || ID : %d || Titre : %s || Auteur : %s || Annee : %d || Disponibilite : %d\n", bibliotheque[i].id, bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].annee, bibliotheque[i].disponible);
        }
    }
}


// Fonction pour afficher tous les livres de la bibliothèque
void afficher_tous_les_livres() {
    for (int i = 0; i < nombre_livres; i++) {
        printf("                                                       || ID: %d || Titre: %s || Auteur: %s || Annee: %d || Disponible: %d\n",bibliotheque[i].id, bibliotheque[i].titre, bibliotheque[i].auteur, bibliotheque[i].annee, bibliotheque[i].disponible);
    }
}



// Fonction pour emprunter un livre
void emprunter_livre(int id_emprunteur, int id_livre) {
    if (emprunteurs[id_emprunteur].nombre_emprunts < MAX_BOOKS && bibliotheque[id_livre].disponible) {
        emprunteurs[id_emprunteur].historique_emprunts = (Emprunt *)realloc(emprunteurs[id_emprunteur].historique_emprunts, (emprunteurs[id_emprunteur].nombre_emprunts + 1) * sizeof(Emprunt));
        Emprunt nouvel_emprunt = {id_livre, id_emprunteur, time(NULL), 0};
        emprunteurs[id_emprunteur].historique_emprunts[emprunteurs[id_emprunteur].nombre_emprunts] = nouvel_emprunt;
        emprunteurs[id_emprunteur].nombre_emprunts++;
        bibliotheque[id_livre].disponible = 0;
        printf("                                                                  || Livre emprunte : %s || Auteur %s || Annee : %d\n", bibliotheque[id_livre].titre, bibliotheque[id_livre].auteur,bibliotheque[id_livre].annee);
        sauvegarder_bibliotheque();
        sauvegarder_emprunteurs();
    } else {
        printf("                                                           :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
        printf("                                                           ::::::::::::: Impossible d'emprunter le livre. Soit il n est pas disponible,:::::::::::\n                                                           :::::::::::::  soit l emprunteur a atteint la limite maximale.::::::::::::::::::\n");
        printf("                                                           :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    }
}

// Fonction pour retourner un livre
void retourner_livre(int id_emprunteur, int id_livre) {
    for (int i = 0; i < emprunteurs[id_emprunteur].nombre_emprunts; i++) { // partie qui permet de parcourir la bibliotheque
        if (emprunteurs[id_emprunteur].historique_emprunts[i].id_livre == id_livre && emprunteurs[id_emprunteur].historique_emprunts[i].date_retour == 0) {
            emprunteurs[id_emprunteur].historique_emprunts[i].date_retour = time(NULL);
            bibliotheque[id_livre].disponible = 1;
            printf("                                                               || Livre retourne : %s || Auteur %s || Annee : %d\n", bibliotheque[id_livre].titre, bibliotheque[id_livre].auteur,bibliotheque[id_livre].annee);
            sauvegarder_bibliotheque();
            sauvegarder_emprunteurs();
            return;
        }
    }
    printf("                                                                :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                                                                :::::::::::  Livre non trouve dans l'historique de l'emprunteur ou deja retourne. :::::::::::::\n");
    printf("                                                                :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

