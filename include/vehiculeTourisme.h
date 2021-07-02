#ifndef VEHICULETOURISME_H
#define VEHICULETOURISME_H

#include <vehicule.h>


class vehiculeTourisme : public vehicule
{
    public:
        vehiculeTourisme();
        virtual ~vehiculeTourisme();

        float Getremise() { return remise; }
        void Setremise(float val) { remise = val; }
        string Getnom_C() { return nom_C; }
        void Setnom_C(string val) { nom_C = val; }

    protected:
        float remise;
        string nom_C;

    private:
};

#endif // VEHICULETOURISME_H
