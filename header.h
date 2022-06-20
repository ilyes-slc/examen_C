#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct vehicule
{
char num_im[10],marque[20],type[20];
}
Vehicule;



typedef struct Cellule_file
{
Vehicule Veh;
 struct Cellule_file *next;
}
Cellule_file;
typedef struct File
{

 struct Cellule_file *tete;
 struct Cellule_file *queu;
}
file_vehicules;





typedef struct guichet
{
    int num;
    char nom_agent[20];
    file_vehicules F;
}
guichet;

typedef struct Cellule_liste
{
    guichet g;
     struct Cellule_liste *next;
}
Cellule_liste,*liste_guichets;
file_vehicules enfiler(file_vehicules F, Vehicule V);
void defiler(file_vehicules* F);
file_vehicules affichage_file(file_vehicules f);
void saisir_guichet(guichet *G,liste_guichets L);
liste_guichets ouvrir_guichet(liste_guichets L,guichet G);
void afficher(liste_guichets L);
Cellule_liste* chercher_guichet(liste_guichets L, int num);
void ajouter_vehicules(liste_guichets L,int numGuichet,int nbVehicule);
void remplier_station(L);
float recette_guichet(guichet G);
#endif // HEADER_H_INCLUDED
