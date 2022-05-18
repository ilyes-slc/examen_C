#ifndef BIEN_H
#define BIEN_H


class bien
{
    public:
        bien();
        virtual ~bien();

        int Getmatricule() { return matricule; }
        void Setmatricule(int val) { matricule = val; }
        string Getsuperfice() { return superfice; }
        void Setsuperfice(string val) { superfice = val; }
        int Getetat() { return etat; }
        void Setetat(int val) { etat = val; }
        bool operator==(string sperfice);

    protected:
        int matricule;
        String superfice;
        int etat;

    private:
};

#endif // BIEN_H
