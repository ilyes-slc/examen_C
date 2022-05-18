#include "agence.h"

agence::agence()
{
    //ctor
}

agence::~agence()
{
    //dtor
}

 list<client*>::iterator agence::getclient(int id)
{  list<client*>::iterator it=cl.begin();
    while(it!=cl.end()){
        if((*it)->Getid()==id){
            return it;
        }
        it++;
    }
    return it;
}


 list<bien*>::iterator agence::getbien(int id)
{  list<bien*>::iterator it=b.begin();
    while(it!=b.end()){
        if((*it)->Getmatricule()==id){
            return it;
        }
        it++;
    }
    return it;
}


void agence::ajouter(const client& q)
{list<client*>::iterator it=getclient(q.Getid());
     if(it!=cl.end()){
        cout<<"id existe déja"<<endl;
     }else{
      client *pQ=new client(q);
        cl.push_back(pQ);
     }
}

void agence::ajouter(const bien& ep)
{
     list<bien*>::iterator it=getbien(ep.Getmatricule());
     if(it!=b.end()){
        cout<<"id existe déja"<<endl;
     }else{
      bien *pE=new bien(ep);
        b.push_back(pE);
     }

}

void agence::ajouter(const maison& q)
{list<bien*>::iterator it=getbien(q.Getmatricule());
     if(it!=b.end()){
        cout<<"id existe déja"<<endl;
     }else{
      maison *pQ=new maison(q);
        b.push_back(pQ);
     }
}


void agence::afficher(string superfice)
{
list<bien*>::iterator it=b.begin();
while(it!=b.end()){
    if (*it==superfice)
        cout<<*it->Getsuperfice<<*it->Getetat<<;
it++;
}

if(test==false)throw string("theme invalid");
}
