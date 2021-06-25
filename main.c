#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    int s;
    int cd;
    livreur l;
    livreur tabl[50];
    int nbl;
    char id[10];
    float totcom;
    float pr;
   do
{do
{
printf("MENU:1-ajouter un nouveau livreur 2-afficher les livreurs 3-ajouter une commande 4-confirmer une commande 5- nombre des commandes non confirmee d un livreur 6-prix totale et pourcentage des commandes non confirmees 7-supprimer une commande 8-quitter ");
scanf("%d",&s);
}
while((s>8)||(s<0));
switch(s)
{
case1:
saisir_livreur(&l);
ajouter_livreur(tabl,&nbl,l);
break;

case2:
afficher_livreur(tabl,nbl);
break;

case3:
saisir_commande();
break;

case4:
confirmer_commande(tabl,nbl,id,cd);
break;

case5:

non_confimee(tabl,nbl,id);

break;

case6:

pourcentage(tabl,nbl,&totcom,&pr);

break;

case7:

supprimer_commande(tabl,nbl,id,cd);

break;

case8:

printf("----------FIN------------");

break;
}
}
while(s!=0);
    return 0;
}