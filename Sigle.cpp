#include "Sigle.h"
#include "Chaine.h"
#include <iostream>
#include <string>
using namespace std;
Sigle::Sigle(Chaine leSigle,Chaine tableau[]):Chaine(leSigle){
    m_tabSigle= new Chaine[leSigle.quelleTaille()];
    for (int i=0;i<leSigle.quelleTaille();i++){
        m_tabSigle[i]=tableau[i];
    }
}
Sigle::Sigle(const Sigle &s):Chaine(s){
    m_tabSigle= new Chaine[s.m_taille];
    for (int i=0;i<s.m_taille;i++){m_tabSigle[i]=s.m_tabSigle[i];}
}
Sigle & Sigle::operator=(const Sigle &s){
    if(this!=&s){
        delete [] m_tabSigle;
        delete [] m_tab;
        m_taille=s.m_taille;
        m_tab=new char[m_taille];
        for(int i=0; i<m_taille;i++){
            m_tab[i]=s.m_tab[i];
        }
        m_tabSigle= new Chaine[m_taille];
        for (int i=0;i<m_taille;i++){
            char *tabCharMot = new char[s.m_tabSigle[i].quelleTaille()];
            for(int j=0;j<s.m_tabSigle[i].quelleTaille();j++){
                tabCharMot[j]=s.m_tabSigle[i].unElement(j);
            }
            m_tabSigle[i].putdata(s.m_tabSigle[i].quelleTaille(),tabCharMot);
            delete [] tabCharMot;
        }
    }
    return *this;
}
void Sigle::operator [](int i){
    cout << m_tab[i];
}
Chaine & Sigle::operator()(int i){
    return m_tabSigle[i];
}
void Sigle::afficherSigleMots(){
    this->afficher();
    cout << " est le sigle de :";
    for(int i=0;i<m_taille;i++){
        cout << " ";
        m_tabSigle[i].afficher();
    }
    cout <<"."<<endl;
}
int Sigle::quelleTailleSigle(){
    return m_taille;
}
char Sigle::PremiereLettreDeCeMot(int i){
    return m_tab[i];
}
void Sigle::quelEstCeMot(int i){
    m_tabSigle[i].afficher();
}
Sigle Sigle::operator+(Sigle &s2){
    int tailleS1=m_taille;
    int tailleS2=s2.m_taille;
    int tailleS3=tailleS1+tailleS2;
    char *tabcharSigle=new char[tailleS3];
    for(int i=0;i<tailleS1;i++){
        tabcharSigle[i]=m_tab[i];
    }
    for(int i=0;i<tailleS2;i++){
        tabcharSigle[i+tailleS1]=s2.m_tab[i];
    }
    Chaine *tabChaineSigle= new Chaine[tailleS3];
    for(int i=0;i<tailleS1;i++){
        char *tabCharMot = new char[m_tabSigle[i].quelleTaille()];
        for(int j=0;j<m_tabSigle[i].quelleTaille();j++){
            tabCharMot[j]=m_tabSigle[i].unElement(j);
        }
        tabChaineSigle[i].putdata(m_tabSigle[i].quelleTaille(),tabCharMot);
        delete [] tabCharMot;
    }
    for(int i=0;i<tailleS2;i++){
        char *tabCharMot = new char[s2.m_tabSigle[i].quelleTaille()];
        for(int j=0;j<s2.m_tabSigle[i].quelleTaille();j++){
            tabCharMot[j]=s2.m_tabSigle[i].unElement(j);
        }
        tabChaineSigle[i+tailleS1].putdata(s2.m_tabSigle[i].quelleTaille(),tabCharMot);
        delete [] tabCharMot;
    }
    Chaine Chaineadd(tailleS3,tabcharSigle);
    Sigle sigleSomme(Chaineadd,tabChaineSigle);
    delete [] tabcharSigle;
    delete [] tabChaineSigle;
    return sigleSomme;
}
Sigle::~Sigle(){
    delete [] m_tabSigle;
}

