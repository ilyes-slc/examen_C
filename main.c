#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main()
{ processus p;
LC L;
pr1 Pr1;
int choix;

        do {
        printf("---------------------------Menu---------------------- \n ");
        printf("1-ajouter \n ");
        printf("2-afficher \n ");
        printf("3-executer et sauvegarder \n ");
        printf("0-quitter \n ");
    printf("\n Donner votre choix : \n ");
    scanf("%d",&choix);
    switch(choix){
    case 1:
        saisirProcessus(&p);
        L=ajouterProcessus(l,p);
        break;
    case 2:
        printf("bbbbbbbbbb");
        break;
    case 3:
        printf("ccccccccc");
        break;

        }



        printf(" \n voulez vous faire une autre operation? \n");
        printf("1-oui, 0-non \n");
        scanf("%d",&choix);


    } while ((choix!=0)||((choix<0)&&(choix>7)));






    return 0;
}
