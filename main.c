#include <stdio.h>
#include <stdlib.h>
#include "bibliotheque.c"
#include "emprunteur.h"
#include "password.c"
#define MAX_NAME 100

// la fonction  du menu accueil du programme
void accueil(){
    while (1)
    {


            int reponse;
            printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf("::::::::::::::::::::::::::::::::::::::::::::::::::::||==============================================||:::::::::::::::::::::::::::::::::::::::::::::\n");
            printf("::::::::::::::::::::::::::::::::::::::::::::::::::::||          BIENVENUE   A LA BIBLIOTHEQUE       ||:::::::::::::::::::::::::::::::::::::::::::::\n");
            printf("::::::::::::::::::::::::::::::::::::::::::::::::::::||==============================================||:::::::::::::::::::::::::::::::::::::::::::::\n");
            printf("::::::::::::::::::::::::::::::::::::::::::::::::::::||         ENRICHISSEZ VOTRE CONNAISSANCE       ||:::::::::::::::::::::::::::::::::::::::::::::\n");
            printf("::::::::::::::::::::::::::::::::::::::::::::::::::::||==============================================||:::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

            printf("                            ==>> PARTIE LECTEUR <<==               ==>> Quitter <<==                ==>> PARTIE BIBLIOTHECAIRE <<== \n");
            printf("                                     >> 1 <<                            >> 3 <<                                 >> 2 << \n");
            printf("                                                                        >> ");scanf("%d",&reponse);
            printf("\n");

                if(reponse == 1){
                      menu_lecteur();
                    }
                else if(reponse == 2)
                    {
                       connexion();
                       menu_bibliothecaire();

                    }
                else if (reponse == 3)
                    {
                        sauvegarder_bibliotheque();
                        sauvegarder_emprunteurs();
                        printf("                                          :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                        printf("                                          ::::::::::::: Merci d avoir visiter notre bibliotheque a bientot !! :::::::::::\n");
                        printf("                                          :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");

                        exit(0);
                    }
                else {
                        printf("                                                         :::::::::::::::::::::::::::::::::::::::\n");
                        printf("                                                         ::::::::::::: Mauvais choix :::::::::::\n");
                        printf("                                                         :::::::::::::::::::::::::::::::::::::::\n\n\n");
                        main();
                     }



    }

}

// Fonction pour créer le pour la partie bibliothecaire
void menu_bibliothecaire() {
    int choix;
    char titre[MAX_TITLE];
    char auteur[MAX_AUTHOR];
    char nom[MAX_NAME];
    int annee, id_livre, id_emprunteur;

    while (1) {
        printf("\n                                                            ========== PARTIE DE BIBLIOTHECAIRE ==========\n\n");
        printf("                                      >> 1. Ajouter Livre\n");
        printf("                                      >> 2. Rechercher Livre par Titre\n");
        printf("                                      >> 3. Rechercher Livre par Auteur\n");
        printf("                                      >> 4. Afficher Tous les Livres\n");
        printf("                                      >> 5. Ajouter Emprunteur\n");
        printf("                                      >> 6. Generer Rapport des Livres Empruntes\n");
        printf("                                      >> 7. Configuration de mot de passe\n");
        printf("                                      >> 8. Menu Accueil\n");
        printf("                                      >> 9. Quitter\n\n");
        printf("                                            Entrez votre choix >> ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("                                         ||  Entrez le titre >> ");
                scanf(" %[^\n]%*c", titre);
                printf("                                         ||  Entrez l'auteur >> ");
                scanf(" %[^\n]%*c", auteur);
                printf("                                         ||  Entrez l'annee: >> ");
                scanf("%d", &annee);
                ajouter_livre(titre, auteur, annee);
                break;
            case 2:
                printf("                                         ||  Entrez le titre >> ");
                scanf(" %[^\n]%*c", titre);
                rechercher_livres_par_titre(titre);
                break;
            case 3:
                printf("                                         ||  Entrez l'auteur >> ");
                scanf(" %[^\n]%*c", auteur);
                rechercher_livres_par_auteur(auteur);
                break;
            case 4:
                afficher_tous_les_livres();
                break;
            case 5:
                printf("                                         ||  Entrez le nom >> ");
                scanf(" %[^\n]%*c", nom);
                ajouter_emprunteur(nom);
                break;

            case 6:
                generer_rapport_livres_empruntes();
                break;

            case 7:
                sauvegarder_mot_de_passe();
                ;break;
            case 8: accueil();
                    break;

            case 9:
                sauvegarder_bibliotheque();
                sauvegarder_emprunteurs();
                                        printf("                         ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                        printf("                                         :::::::::::: Merci d'avoir visiter notre bibliotheque a bientot !! :::::::::::\n");
                        printf("                                         ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
                exit(0);
            default:
                printf("                                                             :::::::::::::::::::::::::::::::::::::::::::::::\n");
                printf("                                                             ::::: Choix invalide. Veuillez réessayer. :::::\n");
                printf("                                                             :::::::::::::::::::::::::::::::::::::::::::::::\n");

        }
    }
}

// la fonction pour le menu de la partie lecteur

void menu_lecteur(){
    int choix;
    char titre[MAX_TITLE];
    char auteur[MAX_AUTHOR];
    char nom[MAX_NAME];
    int annee, id_livre, id_emprunteur;

    while (1) {
        printf("\n                                                            ================  PARTIE LECTEUR  ===============\n\n");
        printf("                                      >>  1. Rechercher Livre par Titre\n");
        printf("                                      >>  2. Rechercher Livre par Auteur\n");
        printf("                                      >>  3. Afficher Tous les Livres\n");
        printf("                                      >>  4. Emprunter Livre\n");
        printf("                                      >>  5. Retourner Livre\n");
        printf("                                      >>  6. Menu accueil\n");
        printf("                                      >>  7. Quitter\n\n");
        printf("                                             Entrez votre choix >> ");
        scanf("%d", &choix);



        switch (choix) {
            case 1:
                printf("                                          ||  Entrez le titre >> ");
                scanf(" %[^\n]%*c", titre);
                rechercher_livres_par_titre(titre);
                break;
            case 2:
                printf("                                          ||  Entrez l'auteur >> ");
                scanf(" %[^\n]%*c", auteur);
                rechercher_livres_par_auteur(auteur);
                break;

            case 3:
                afficher_tous_les_livres();
                break;

            case 4:
                printf("                                          ||  Entrez l'ID de l'emprunteur >> ");
                scanf("%d", &id_emprunteur);
                printf("                                          ||  Entrez l'ID du livre >> ");
                scanf("%d", &id_livre);
                emprunter_livre(id_emprunteur, id_livre);
                break;
            case 5:
                printf("                                          ||  Entrez l'ID de l'emprunteur >> ");
                scanf("%d", &id_emprunteur);
                printf("                                          ||  Entrez l'ID du livre >> ");
                scanf("%d", &id_livre);
                retourner_livre(id_emprunteur, id_livre);
                break;
            case 6:accueil();
                   break;
            case 7:
                sauvegarder_bibliotheque();
                sauvegarder_emprunteurs();

                printf("                                         ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                printf("                                         :::::::::::: Merci d'avoir visiter notre bibliotheque a bientot !! :::::::::::\n");
                printf("                                         ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
                exit(0);
            default:
                printf("                                                               :::::::::::::::::::::::::::::::::::::::::::::::\n");
                printf("                                                               ::::: Choix invalide. Veuillez réessayer. :::::\n");
                printf("                                                               :::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    }
 }
}


// le code principal

int main(){
    printf("                                                      ::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                                                      ::::::::: LISTE DE MEMBRE DU GROUPE   ::::::::::\n");
    printf("                                                      ::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf("                                                                1. NYEMBO KAMWANGA Michel\n");
    printf("                                                                2. YAV A MUTOMB Samuel\n");
    printf("                                                                3. VUNDULA KASEYA Bertin\n");
    printf("                                                                4. SUMPI MUSABUKA Othniel\n\n");
    printf("                                                      ::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                                                      ::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    charger_emprunteurs(); //permet de charger  ou appeller la fonction emprunteur
    charger_bibliotheque(); // permet de charger ou appeller la fonction  bibliotheque
    accueil(); // Permet d'appeller la fonction pour le menu principal
    return 0;

    }
