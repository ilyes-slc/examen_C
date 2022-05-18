#include "header.h"



void saisirProcessus(processus *p);
{
    strcpy(p->etat,"pret");
    scanf("%d",&p->priorite);
    scanf("%d",&p->pid);
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


Routeur enfiler(Routeur RT, Paquet pqt)
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


Cellule* chercherProcessus(LC L, int pid)
{
    if(L.suivant==NULL)
    {
        printf("Liste vide.\n");
        //exit(1);
    }
    else
    {
        LC nouv=L.suivant;
        while(nouv!=NULL && (nouv->pr.pid!=pid) )
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
        while(nouv!=NULL && (strcmp ( nouv->pqt.destination, adresse)!=0) )
        {
            if (strcmp ( nouv->pqt.destination, adresse)==0)
            {
                printf("%s",nouv->pqt.destination);
                printf("%s",nouv->pqt.source);
                printf("%d",nouv->pqt.id);
            }
            nouv=nouv->suivant;

        }
    }
}

LC ajouterProcessus(LC l,processus p)
{
    Cellule *element;
    element=malloc(sizeof(*Cellule));
    element->pr=p;
    element->suivant=NULL;
    if(l==NULL)
        return element;
    Cellule *tmp;
    tmp=l;
    while(tmp->suivant!=NULL)
    {
        tmp=tmp->suivant;
    }
    tmp->suivant=element;
    return l;
}


void sauvegarderProcessus(processus p, char nomfichier[])
{
    int n,i;
    FILE *f;
    f=fopen(nomfichier,"w");
    if(f!=NULL)
    {

            fprintf(f,"%d %d %s \n",p.pid,p.priorite,p.etat);

    }
    else
    {
        printf("Erreur le Ficher N\'est Pas NuLL");
    }
    fclose(f);
}


void Supprimer_debut (File *f)
{
if (f->tete==NULL)
{
f->tete=NULL;
f->queu=NULL;

}

f->tete=f->tete->suivant;



}
