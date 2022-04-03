#ifndef SIGLE_H_INCLUDED
#define SIGLE_H_INCLUDED
#include "Chaine.h"
class Sigle:public Chaine{
    private:
    Chaine *m_tabSigle;

    public:
    Sigle(Chaine leSigle,Chaine tableau[]);
    Sigle & operator = (const Sigle &);
    void operator[] (int);
    Chaine & operator()(int);
    void afficherSigleMots();
    Sigle operator+(Sigle &);
    Sigle(const Sigle &);
    int quelleTailleSigle();
    void quelEstCeMot(int);
    char PremiereLettreDeCeMot(int);
    ~Sigle();



};


#endif // SIGLE_H_INCLUDED



