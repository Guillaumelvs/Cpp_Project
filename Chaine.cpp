#include "Chaine.h"
#include <iostream>
#include <string>
using namespace std;
Chaine::Chaine(int n,char tableau[]):m_taille(n){
    m_tab= new char[n];
    for (int i=0;i<n;i++){
        m_tab[i]=tableau[i];
    }
}
Chaine::Chaine(const Chaine &c){
    m_taille=c.m_taille;
    m_tab = new char[m_taille];
    for (int i=0;i<m_taille;i++){m_tab[i]=c.m_tab[i];}
}
Chaine::Chaine():m_taille(1){
    m_tab= new char[1];
    m_tab[0]='a';
}
int Chaine::quelleTaille(){
    return m_taille;
}
Chaine::~Chaine(){
    delete [] m_tab;
}
char Chaine::unElement(int i){
    return m_tab[i];
}
void Chaine::putdata(int n,char tableau[]){
    if(n>0){
        m_taille=n;
        m_tab= new char[n];
        for (int i=0;i<n;i++){
            m_tab[i]=tableau[i];
        }
    }
}
void Chaine::afficher(){
    for(int i=0;i<m_taille;i++){cout<<m_tab[i];}
}
Chaine & Chaine::operator=(const Chaine &c){
    if(this!=&c){
        delete m_tab;
        m_taille=c.m_taille;
        m_tab=new char[m_taille];
        for(int i=0; i<m_taille;i++){
            m_tab[i]=c.m_tab[i];
        }
    }
    return *this;
}
char & Chaine::operator [](int i){
    return m_tab[i];
}
