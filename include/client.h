#ifndef CLIENT_H
#define CLIENT_H


class client
{
    public:
        client();
        virtual ~client();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        String Getnom() { return nom; }
        void Setnom(String val) { nom = val; }
        String Getprenom() { return prenom; }
        void Setprenom(String val) { prenom = val; }

    protected:

    private:
        int id;
        String nom;
        String prenom;
        list<int> matricules;
};

#endif // CLIENT_H
