#include <iostream>

using namespace std;
#include "agence.h"
int main()
{
    cout << "Hello world!" << endl;
    agence a=new agence();
    bien b = new bien();
    maison m = new maison();
    client c = new client();
    b.Setetat(1);
    b.Setmatricule(123);
    b.Setsuperfice("123");
    a.ajouter(b);
    a.ajouter(m);
    a.ajouter(c);
    a.afficher(c);
    return 0;
}
