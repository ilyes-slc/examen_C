#include "vehicule.h"

vehicule::vehicule()
{
    //ctor
}

bool vehicule::operator<(const vehicule& v1,float v2){
    if (v1->Getprix() < v2) return 1;
    else return 0;
}

vehicule::~vehicule()
{
    //dtor
}
