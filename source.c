#include "header.h"

Routeur init_routeur()
{
Routeur R;
R.port1.suivant = NULL;
R.port2.tete = NULL;
R.port2.queu = NULL;
R.port3.suivant = NULL;
R.port4.ABG = NULL;
R.port4.ABD = NULL;
return R;
}

void saisir(Paquet *pqt)
{
    scanf("%s",pqt->destination);
    scanf("%s",pqt->source);
    scanf("%d",pqt->id);
}

Routeur empiler(Routeur RT,Paquet pqt)
{

Cellule *element;
    element=malloc(sizeof(*Cellule));
    element->pqt=pqt;
    element->suivant=RT.port1;
    RT.port1 = element;
return RT;

}


void depiler(Routeur *RT)
{
RT->port1= RT->port1.suivant;
}


Routeur enfiler(Routeur RT , Paquet pqt)
{
    FileElment *element;
element=malloc(sizeof(FileElment));

element->suivant=NULL;
element->pqt=pqt;

if (RT.port2.queu==NULL & RT.port2.tete==NULL)
{
RT.port2.queu=element;
RT.port2.tete=element;
return RT;
}


RT.port2.queu->suivant=element;
RT.port2.queu=element;



return RT;
}


void defiler(Routeur *RT)
{
    if (RT->port2.tete==NULL)
{
RT->port2.tete=NULL;
RT->port2.queu=NULL;

}

RT->port2.tete=RT->port2.tete->next;


}


Cellule* chercher(Routeur RT , char *adresse)
{
    if(RT.port3.suivant==NULL)
    {
        printf("Liste vide.\n");
        //exit(1);
    }
    else
    {
        Liste nouv=RT.port3.suivant;
        while(nouv!=NULL && (strcmp ( nouv->pqt.destination , adresse)!=0) )
        {
            nouv=nouv->suivant;

        }
        return nouv;
    }
}


void afficher_paquet(Routeur RT, char * destination)
{
        if(RT.port3.suivant==NULL)
    {
        printf("Liste vide.\n");
        //exit(1);
    }
    else
    {
        Liste nouv=RT.port3.suivant;
        while(nouv!=NULL && (strcmp ( nouv->pqt.destination , adresse)!=0) )
        {
            if (strcmp ( nouv->pqt.destination , adresse)==0){
                printf("%s",nouv->pqt.destination);
                printf("%s",nouv->pqt.source);
                printf("%d",nouv->pqt.id);
            }
            nouv=nouv->suivant;

        }
    }
}
