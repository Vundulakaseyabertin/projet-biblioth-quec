#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

            printf("                                    ==>> PARTIE LECTEUR <<==               ==>> Quitter <<==                ==>> PARTIE BIBLIOTHECAIRE <<== \n");
            printf("                                             >> 1 <<                            >> 3 <<                           >> 2 << \n\n");
            printf("                                                                                >> ");
            scanf("%d",&reponse);
            printf("\n");

                if(reponse == 1){
                      menu_lecteur();
                    }
                else if(reponse == 2)
                    {
                       menu_bibliothecaire();
                    }
                else if (reponse == 3)
                    {
                        sauvegarder_bibliotheque();
                        sauvegarder_emprunteurs();
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