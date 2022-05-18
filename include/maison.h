#ifndef MAISON_H
#define MAISON_H

#include <bien.h>


class maison : public bien
{
    public:
        maison();
        virtual ~maison();

    protected:

    private:
        int nbPieces;
};

#endif // MAISON_H
