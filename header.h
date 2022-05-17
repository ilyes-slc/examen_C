#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct paquet{
    char source[20];
    char destination[20];
    int id;
}Paquet;

typedef struct Cellule* Liste;
typedef struct Cellule* Pile;




typedef struct Cellule
{
    Paquet pqt;
     struct Cellule *suivant;
}

typedef struct FileElment
{
Paquet pqt;
 struct FileElment *suivant;
}
FileElment;
typedef struct File
{

 struct FileElment *tete;
 struct FileElment *queu;
}
File;

typedef struct noeud noeud;
struct noeud
{
    Paquet pqt;
    noeud *ABG;
    noeud *ABD;

};

typedef noeud* ABR ;



typedef struct Routeur
{

 Pile port1;
File port2;
Liste port3;
ABR port4;
}
Routeur;



Routeur init_routeur();
void saisir(Paquet *pqt);
Routeur empiler(Routeur RT,Paquet pqt);
void afficher_paquet(Routeur RT, char * destination);
Cellule* chercher(Routeur RT , char *adresse);
void defiler(Routeur *RT);
Routeur enfiler(Routeur RT , Paquet pqt);

#endif // HEADER_H_INCLUDED
