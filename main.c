#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int ch,loop=1;
    int p_l;
    file fv;
    vehicule v;
    Arbre A;
    place tab_parking;
    int nbr_places;
    place pl;
    place* pl_libre;
    FILE* f;

    fv=initialiserFile(fv);
    do
    {

        printf("1- ajouter une vehicule a la file\n2- afficher la liste de toutes les places et la liste des places libres\n");
        printf("3- placer le 1er vehicule de la file d attente dans le parking\n4- construire un arbre de vehicule\n5- afficher les vehicules places selon un ordre decriossant de leur duree de parkin\n");
        printf("6- quitter\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
           v=saisirVehicule();
           fv=ajouterVehicule(fv,v);

            break;
        case 2:
            afficherPlaces(&pl,nbr_places);
            p_l=listerPlacesLibre(&tab_parking,&pl_libre,nbr_places);
            break;
        case 3:
            break;
        case 4:
            construireVehicules(&tab_parking,nbr_places,A);
            break;
        case 5:
            //afficherVehicules(A,&nomFichier);
            break;
        case 6:
            loop=0;
        }
    }
    while(loop==1);
    return 0;
}
