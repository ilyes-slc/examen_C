#include "header.h"
#include <string.h>

file_vehicules enfiler(file_vehicules F, Vehicule V)
{
    Cellule_file *element;
    element=malloc(sizeof(Cellule_file));

    element->next=NULL;
    element->Veh=V;

    if (F.queu==NULL && F.tete==NULL)
    {
        F.queu=element;
        F.tete=element;
        return F;
    }


    F.queu->next=element;
    F.queu=element;



    return F;
}


void defiler(file_vehicules* F)
{
    if (F->tete==NULL)
    {
        F->tete=NULL;
        F->queu=NULL;

    }
    F->tete=F->tete->next;


}


file_vehicules affichage_file(file_vehicules f)
{
    if((f.tete==NULL)&&(f.queu==NULL))
    {
        printf("file vide");
    }
    else
    {
        printf("numero immatricule:%s\n",(f.tete)->Veh.num_im);
    }
}




Cellule_liste* chercher_guichet(liste_guichets L, int num)
{
    int n=0;
    int s=-1;
    while(L!=NULL)
    {
        if(L->g.num==num)
        {
            return L
            break;
        }

        else
        {
            L=L->next;
            n++;
        }
    }
    return NULL;
}


void saisir_guichet(guichet *G,liste_guichets L)
{
    do
    {
        scanf("%d",&G->num);
    }
    while (chercher_guichet(L,G->num)!=NULL);
    scanf("%s",G->nom_agent);
    G->F.queu=NULL;
    G->F.tete=NULL;
}

liste_guichets ouvrir_guichet(liste_guichets L,guichet G)
{
    Cellule_liste *element,*precedent,*courant;
    element=malloc(sizeof(Cellule_liste));
    element->g=G;
    int i=1;
    element->next=NULL;
    if (L==NULL)
        return element;
    if(L->g.num>G.num)
    {
        element->next=L;
        L=element;
    }
    else
    {


        precedent=L;
        courant=L->next;
        while(courant!=NULL && courant->g.num < G.num)
        {
            precedent=precedent->next;
            courant=courant->next;
        }

        element->next=courant;
        precedent->next=element;
    }

    return L;

}


void afficher(liste_guichets L){
        if (L==NULL)
    {
        printf("il y a rien !! ");
    }
    while (L!=NULL)
    {
        printf("[%d] [%s] \n",L->g.num,L->g.nom_agent);
        affichage_file(L->g.F);
        L=L->next;
    }

}


void ajouter_vehicules(liste_guichets L,int numGuichet,int nbVehicule){
    int i;
    Vehicule V;
    Cellule_liste * c = chercher_guichet(L,numGuichet);
    for (i=0;i<nbVehicule;i++){
        scanf("%s %s %s",V.num_im,V.marque,V.type);
        enfiler(c->g.F,V);
    }
}

void remplier_station(L){
    int nbVoitures;
         if (L==NULL)
    {
        printf("il y a rien !! ");
    }
    while (L!=NULL)
    {
        scanf("%d",&nbVoitures);
        ajouter_vehicules(L,L->g.num,nbVoitures);
    }
}

float recette_guichet(guichet G){
    float recette=0;
    float montant;
    Cellule_file* C;
    C=G.F.tete;
    while(C!=NULL){
        if (strcmp(C.Veh.type,"moto")==0) recette+=1.5;
        else if (strcmp(C.Veh.type,"voiture")==0) recette+=2;
        else if (strcmp(C.Veh.type,"camion")==0) recette+=2.5;
        else if (strcmp(C.Veh.type,"bus")==0) recette+=3;
        C=C.next;
    }
    return recette;
}
