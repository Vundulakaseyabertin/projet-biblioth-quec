#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password.h"

#define MAX_PASS_LENGTH 50
#define FILENAME "password.txt"

// Fonction pour vérifier le mot de passe
int verifyPassword(char *inputPassword) {
    FILE *file = fopen(FILENAME, "r");
    char storedPassword[MAX_PASS_LENGTH];

    if (file == NULL) { // permet de nous rassurer que le fichier mot de passe est bien ouvert
        printf("Aucun mot de passe enregistré.\n");
        return 0; // Échec de vérification
    }

    fscanf(file, "%s", storedPassword); // permet d'ecrire ou de stocker le mot de passe dans le fichier (mot de passe )
    fclose(file);

    if (strcmp(inputPassword, storedPassword) == 0) {
        return 1; // Mot de passe correct
    } else {
        return 0; // Mot de passe incorrect
    }
    int isLoggedIn = 0; // Variable pour suivre l'état de connexion


}


// Fonction pour enregistrer le mot de passe dans un fichier
void savePassword(char *password) {
    FILE *file = fopen(FILENAME, "w");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    fprintf(file, "%s", password);
    fclose(file);
}

void sauvegarder_mot_de_passe () {
    char password[MAX_PASS_LENGTH];
    printf("                                                     || Veuillez enregistrer votre mot de passe >> ");
    scanf("%s", password);


    savePassword(password);
    printf("                                                                          ::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                                                                          :::: Mot de passe enregistre avec succes. ::::\n");
    printf("                                                                          ::::::::::::::::::::::::::::::::::::::::::::::\n\n");

   /*
     */
    return 0;
}

void connexion()
{
     // Boucle pour demander le mot de passe à chaque connexion
    int isLoggedIn = 0;
    int NbreEssaie = 0; // la variable pour compter le nombres d'essaies
    while (!isLoggedIn) { // permet de verifier le mot de passe si est  correct ou pas
        char inputPassword[MAX_PASS_LENGTH];

        NbreEssaie += 1;
        printf("\n");
        printf("                                                || Veuillez entrer votre mot de passe pour vous connecter >> ");
        scanf("%s", inputPassword);

        isLoggedIn = verifyPassword(inputPassword);

        if (isLoggedIn) {
            printf("\n");
            printf("                                                                  :::::::::::::::::::::::::::::::\n");
            printf("                                                                  ::::: Connexion reussie ! :::::\n");
            printf("                                                                  :::::::::::::::::::::::::::::::");
         }else if (NbreEssaie==4){
             printf("\n");
             printf("                                                     :::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
             printf("                                                     ::::: Vous venez de depasser le nombre d'essaie,:::::\n                                                     :::::          Veillez ressayer plutard !!      :::::\n");
             printf("                                                     :::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
             accueil ();
             break;
         }
         else  {
            printf("\n");
            printf("                                                  ************************************************************\n");
            printf("                                                  ******** Mot de passe incorrect. Veuillez reessayer. *******\n");
            printf("                                                  ************************************************************\n\n");

        }


    }
}


