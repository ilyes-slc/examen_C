#ifndef AGENCE_H
#define AGENCE_H
#include <string>
#include <vector>
#include "loueur.h"
#include "vehicule.h"

class agence
{
    public:
        agence();
        virtual ~agence();

        string Getadresse() { return adresse; }
        void Setadresse(string val) { adresse = val; }
        agence(const agence&);//constructeur par copie
        agence& operator=(const agence&);
        void ajouter(const vehicule&);
        void ajouter(const vehiculeTourisme&);
        void ajouter(const loueur&,string);
        vector<vehicule*>::iterator rechercherVehicule(string);
        vector<loueur*>::iterator rechercherLoueur(int);
        void rendre(string);
        float prix_tot();
        void afficher(float);
        void enregistrer(string);
    protected:
        string adresse;
        vector <loueur> L;
        vector <vehicule*> V;

    private:
};

#endif // AGENCE_H
