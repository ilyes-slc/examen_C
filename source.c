#include "header.h"

void saisir_livreur(livreur *l){
    printf("identifiant: ");
    fflush(stdin);
    gets(l->id);
    l->nbr_cmd=0;
    l->prix=0;


}

int chercher_livreur(livreur tabL[],int nbL,char idL[]){
  int  i=0;
while((strcmp(tabL[i].id,idL)!=0)&&(i<nbL))
i++; 
if(strcmp(tabL[i].id,idL)!=0) 
return i;
else return -1;
}
void ajouter_livreur(livreur tabL[],int *nbL,livreur l){
    do
    {
        
        saisir_livreur(&l);
    } while (chercher_livreur(tabL,nbL,l.id)!=0);
    tabL[(*nbL)]=l;
    (*nbL)++;
    

}

void afficher_livreur(livreur tabL[],int nbL){
    int i,j;
    for ( i = 0; i < nbL; i++)
    {
        printf("id :%s\n",tabL[i].id);
        printf("nombre de commandes :%d\n",tabL[i].nbr_cmd);
        printf("prix totale :%d\n",tabL[i].prix);
        for ( j = 0; j < tabL[i].nbr_cmd; j++)
        {
            printf("code :%d\n",tabL[i].tab[j].code);
            printf("prix :%f\n",tabL[i].tab[j].prix);
            printf("etat :%s\n",tabL[i].tab[j].etat);
        }
        
    }
    
}


commande saisir_commande(){
    commande c;
    scanf("%d",&c.code);
    c.prix=0;
    strcpy(c.etat,"non confirmé");
}

int chercher_commande(livreur tabL[],int nbL,char idL[],int code){
    int a,i;
    a=chercher_livreur(tabL,nbL,idL);
    i==0;
while((tabL[a].tab[i].code!=code)&&(i<tabL[a].nbr_cmd))
i++; 
if(tabL[a].tab[i].code==code) 
return i;
else return -1;
}

void confirmer_commande(livreur tabL[],int nbL,char id[],int code){
    int a,b;
    a=chercher_livreur(tabL,nbL,id);
    b=chercher_commande(tabL,nbL,id,code);
    if (b==-1)
    {
        printf("erreur\n");
    }else
    strcpy(tabL[a].tab[b].etat,"confirmé");
    
    }

int non_confimee(livreur tabl[],int nbl,char id[]){
    int i,count=0,a;
    a=chercher_livreur(tabl,nbl,id);
    for ( i = 0; i < tabl[a].nbr_cmd; i++)
    {
        if (strcmp(tabl[a].tab[i].etat,"confirmé")==0)
        {
            count++;
        }
        
    }
    return count;
    
}

void pourcentage(livreur tabl[],int nbl,float *totcom,float *pr){
    *totcom=0;
    int i,j,count,nbr=0;
    for ( i = 0; i < nbl; i++)
    {
        for ( j = 0; j < tabl[i].nbr_cmd; j++)
        {
         *totcom += tabl[i].tab[j].prix;
         nbr+=tabl[i].nbr_cmd;
        if (strcmp(tabl[i].tab[j].etat,"non confirmé")==0)
        {
            count++;
        }
        }
        
    }
    *pr=(float)(count/nbr)*100;
    
}