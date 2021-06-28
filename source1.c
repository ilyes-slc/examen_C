#include "header.h"
#include <stdio.h>
#include <stdlib.h>



file initialiserFile(file fv){
    fv.tete = NULL;
    fv.queu = NULL;
    return fv;

}

place saisir_place(){
    place p;
    scanf("%d",&p.num);
    p.v.num=0;
    p.v.duree=0;
    p.etat=0;
    scanf("%s",p.v.type);
    return p;
}

int chercherPlace(place *tab_parking,int nump,int nbr_places){
   int i=0;
while((tab_parking[i].num!=nump)&&(i<nbr_places))
i++;
if(tab_parking[i].num==nump)
return i;
return -1;
}

void remplirParking(place *tab_parking,int nbr_places){
    int i;
    for ( i = 0; i < nbr_places; i++)
    {
        tab_parking[i]=saisir_place();
    }
}

vehicule saisirVehicule(){
    vehicule v;
    printf("entrer identifiant vehicule:\n");
    scanf("%d",&v.num);
    printf("entrer duree de parking:\n");
    scanf("%d",&v.duree);
    printf("choisir type:\n");
    scanf("%s",v.type);
    return v;
}

file ajouterVehicule(file fv,vehicule v){
    struct Cellule *nouv = malloc(sizeof(struct Cellule));

    nouv->v = v;
    nouv->suiv = NULL;


        fv.queu->suiv = nouv;
        fv.queu = nouv;
    return fv;
}

int listerPlacesLibre(place* tab_parking,place* pl_libre,int nbr_places){
    int count=0,i;
    for ( i = 0; i < nbr_places; i++)
    {
        if (tab_parking[i].etat==0)
        {
            pl_libre[count].etat=tab_parking[i].etat;
            pl_libre[count].num=tab_parking[i].num;
            pl_libre[count].v.duree=tab_parking[i].v.duree;
            pl_libre[count].v.num=tab_parking[i].v.num;
            strcpy(pl_libre[count].v.type,tab_parking[i].v.type);
            count++;
        }

    }
    return count;
}


void afficherPlaces(place* pl,int nbr_places){
    int i;
    for ( i = 0; i < nbr_places; i++)
    {
        printf("%d\n",pl[i].num);
        printf("%d\n",pl[i].etat);
        printf("vehicule %d\n",pl[i].v.num);
        printf("duree %d\n",pl[i].v.duree);
        printf("%s\n",pl[i].v.type);
    }

}

vehicule defilerVehicule(file*fv){
        vehicule veh ;
        veh.num=-1;

    if( fv->queu == NULL && fv->tete == NULL )
    {
        return veh;
    }
    else
    {
        struct Cellule *suppr;

        veh = fv->tete->v;
        suppr = fv->tete;
        fv->tete = fv->tete->suiv;
        if( fv->tete == NULL )
            fv->queu = NULL;
        free(suppr);
    }

    return veh;
}

void placerVehicule(place* tab_parking,file fv,int n){
    /////
}


Arbre insererVehicule(Arbre A,vehicule v)
{

        if (A == NULL)
        A = initialiser_Etudiant(v);
    else
    {
        if (v.duree <= A->v.duree)
            A->pL = insererVehicule(A->pL, v);
        else
            A->pR = insererVehicule(A->pR, v);
    }
    return A;
}
Arbre construireVehicules(place* tab_parking,int nbr_places,Arbre A){
    int i;
    for ( i = 0; i < nbr_places; i++)
    {
        A=insererVehicule(A,tab_parking[i].v);
    }
}




void afficherVehicules(Arbre A,char* nomFichier){
        if ( A != NULL )
    {
        afficherVehicules(A->pL,"nom");
        printf("Num: %s\duree: %d\t\ttype: %s\n",
               A->v.num, A->v.duree, A->v.type);
        afficherVehicules(A->pR, "nom");
    }
}
