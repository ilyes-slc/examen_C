#ifndef VEHICULE_H
#define VEHICULE_H
#include <string>

class vehicule
{
    public:
        vehicule();
       // virtual ~vehicule();

        string Getmatricule() { return matricule; }
        void Setmatricule(string val) { matricule = val; }
        int Getetat() { return etat; }
        void Setetat(int val) { etat = val; }
        int Getduree() { return duree; }
        void Setduree(int val) { duree = val; }
        float Getprix() { return prix; }
        void Setprix(float val) { prix = val; }
        bool operator<(const vehicule&,float);
    protected:
        string matricule;
        int etat;
        int duree;
        float prix;

    private:
};

#endif // VEHICULE_H
