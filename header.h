#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Commande commande;

struct Commande
{
    int code;
    char etat;
    float prix;
};

typedef struct liv livreur;

struct liv
{
    char id[10];
    int nbr_cmd;
    float prix;
    commande tab[20];
};

void saisir_livreur(livreur *l);
void chercher(livreur tabl[],int nbl,char id[]);
void ajouter_livreur(livreur tabl[],int* nbl,livreur l);
void afficher_livreur(livreur tabl[],int nbl);
commande saisir_commande();
int chercher_commande(livreur tabl[],int nbl,char id[],int code);
void ajouter_commande(livreur tabl[],int nbl,char id[],commande c);
void confirmer_commande(livreur tabl[],int nbl,char id[],int code);
int non_confimee(livreur tabl[],int nbl,char id[]);
void pourcentage(livreur tabl[],int nbl,float*totcom,float *pr);
void supprimer_commande(livreur tabl[],int nbl,char id[],int cd);
#endif // PILE_FILE_H_INCLUDED