#include "agence.h"
#include "vehicule.h"
#include<typeinfo>
#include<fstream>
agence::agence()
{
    //ctor
}
agence::agence(const agence&);//constructeur par copie
{    vehicule *v;
    for(vector <vehicule*>::iterator it =V.begin(); it!=V.end(); it++)
    {
        if(typeid(**it)==typeid(vehicule))
            v=new vehicule(**it);
        else if(typeid(**it)==typeid(vehiculeTourisme))
            v=new vehiculeTourisme(static_cast<const vehiculeTourisme&>(**it));
    }
    V.push_back(v);
    L=agence.L;
    adresse=agence.adresse;
}


agence& agence::operator=(const agence& a)
{
    if(&a!=this)
    {
        for(vector <vehicule*>::iterator it =V.begin(); it!=V.end(); it++)
            delete(*it);
        V.clear();
        L.clear();
        vehicule *Vehicule;
        for(vector <vehicule*>::iterator it =V.begin(); it!=V.end(); it++)
        {
        if(typeid(**it)==typeid(vehicule))
            v=new vehicule(**it);
        else if(typeid(**it)==typeid(vehiculeTourisme))
            v=new vehiculeTourisme(static_cast<const vehiculeTourisme&>(**it));
        }
        V.push_back(Vehicule);
        L=a.L;
        adresse=a.adresse;
    }
    return *this;
}

agence::~agence()
{
       for(vector <vehicule*>::iterator it =V.begin(); it!=V.end(); it++)
        delete(*it);
}

vector<vehicule*>::iterator agence::rechercherVehicule(string id)
{
    for(vector <vehicule*>::iterator it =V.begin(); it!=V.end(); it++)
    {
        if(id==(**it).Getmatricule())
            return it;
    }

    return V.end();
}


void agence::ajouter(const vehicule& v)
{
    if(rechercherVehicule(V.Getmatricule())==V.end())
    {
        vehicule* veh=new vehicule(v);
        V.push_back(veh);
    }
    else
        cout << "cette vehicule existe d�ja" << endl;
}
void agence::ajouter(const vehiculeTourisme& a)
{
    if(rechercherVehicule(a.Getmatricule())==V.end())
    {
        vehicule* p=new vehiculeTourisme(a);
        V.push_back(p);
    }
    else
        cout << "cet voiture tourisme existe d�ja" << endl;
}


vector<loueur>::iterator agence::rechercherLoueur(int cin)
{
    for(vector <loueur>::iterator it =L.begin(); it!=L.end(); it++)
    {
        if(cin==(*it).GetCIN())
            return it;
    }
    return L.end();
}

void agence::ajouter(const loueur& l,string a){
        if((rechercherVehicule(a)!=V.end())&&(rechercherLoueur(l.GetCIN())==L.end()))
    {
        loueur lou;
        lou.Setmatricule(a);

        L.push_back(lou);
        vehicule* p=rechercherVehicule(a);
        p->Setetat(0);
    }
    else
        cout << "ERREUR" << endl;
}

void agence::rendre(int m){
    loueur *lou;
    lou=rechercherLoueur(m);
    vehicule* p=rechercherVehicule(lou.Getmatricule());
        try
    {
        if((lou!=L.end())&&(p!=V.end())
        {
            p.Setetat(1);
            //V.pop
        }
        else
            throw string("ce parking existe d�ja");
    }
    catch(string const& erreur)
    {
        cerr << erreur ;
    }
}

float agence::prix_tot(){
    float prixtot;
        for(vector <vehicule*>::iterator it =V.begin(); it!=V.end(); it++)
    {
       prixtot += (*it).Getprix();
    }
    return prixtot;
}

void agence::afficher(float f){
        for(vector <vehicule*>::iterator it =V.begin(); it!=V.end(); it++)
    {
       if ((*it)<f){
       std::cout<<(*it).Getmatricule() <<*it).Getprix() <<*it).Getetat()<<endl;
       }
    }
}

void agence::enregistrer(string nom){

        ofstream fichier;
    fichier.open("fichier.txt");

    if(fichier)
    {
            for(vector <vehicule*>::iterator it =V.begin(); it!=V.end(); it++)
    {
       if ((*it).Getnom()==nom){
       fichier << it->Getmatricule() << endl;
       }
    }
        fichier.close();
    }
    else
        cout << "erreur d'ouverture" << endl;
}



