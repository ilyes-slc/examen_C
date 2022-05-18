#ifndef AGENCE_H
#define AGENCE_H
#include "bien.h"
#include "client.h"
#include <list>
#include <fstream>

class agence
{
    public:
        agence();
        virtual ~agence();
        void ajouter(const client&);
        list<client*>::iterator getclient(int id);
        void ajouter(const bien&);
        void ajouter(const maison&);
        void afficher(string);

    protected:

    private:
        list<client*>cl;
        list<bien*>b;
};

#endif // AGENCE_H
