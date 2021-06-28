#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


typedef struct Vehicule vehicule;

struct Vehicule
{
    int num;
    char type[20];
    int duree;
};


struct noeud
{
    vehicule v;
    struct noeud* pL;
    struct noeud* pR;
};
typedef struct noeud* Arbre;
typedef struct Place place;

struct Place
{
    int num;
    vehicule v;
    int etat;
};

struct Cellule
{
    vehicule v;
    struct Cellule *suiv;
};

typedef struct
{
    struct Cellule* tete;
    struct Cellule* queu;
} file;

typedef struct Cellule cellule;



file initialiserFile(file fv);
place saisir_place();
int chercherPlace(place* tab_parking,int nump,int nbr_places);
void remplir_Parking(place* tab_parking,int nbr_places);
vehicule saisirVehicule();
file ajouterVehicule(file fv,vehicule v);
int listerPlacesLibre(place* tab_parking,place* pl_libre,int nbr_places);
void afficherPlaces(place* pl,int nbr_places);
vehicule defilerVehicule(file*fv);
void placerVehicule(place* tab_parking,file fv,int n);
Arbre insererVehicule(Arbre A,vehicule v);
Arbre construireVehicules(place* tab_parking,int nbr_places,Arbre A);
void afficherVehicules(Arbre A,char* nomFichier);


#endif // HEADER_H_INCLUDED
