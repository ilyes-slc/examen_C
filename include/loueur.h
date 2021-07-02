#ifndef LOUEUR_H
#define LOUEUR_H
#include <string>

class loueur
{
    public:
        loueur();
      //  virtual ~loueur();

        int GetCIN() { return CIN; }
        void SetCIN(int val) { CIN = val; }
        string Getnom() { return nom; }
        void Setnom(string val) { nom = val; }
        string Getprenom() { return prenom; }
        void Setprenom(string val) { prenom = val; }
        string Getmatricule() { return matricule; }
        void Setmatricule(string val) { matricule = val; }


    protected:
        int CIN;
        string nom;
        string prenom;
        string matricule;

    private:
};

#endif // LOUEUR_H
