#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct processus{
    char etat[20];
    int priorite;
    int pid;
}processus;

typedef struct Cellule* LC;




typedef struct Cellule
{
    processus pr;
     struct Cellule *suivant;
}

typedef struct File pr1;

typedef struct File pr2;

typedef struct File pr3;


typedef struct File
{

 struct Cellule *tete;
 struct Cellule *queu;
};



void saisirProcessus(processus *p);
LC ajouterProcessus(LC l,processus p);
void afficher_paquet(Routeur RT, char * destination);
Cellule* chercherProcessus(LC L, int pid)
void defiler(Routeur *RT);
Routeur enfiler(Routeur RT , Paquet pqt);

#endif // HEADER_H_INCLUDED
