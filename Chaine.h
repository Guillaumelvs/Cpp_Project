#ifndef CHAINE_H_INCLUDED
#define CHAINE_H_INCLUDED
class Chaine{
    protected:
    int m_taille;
    char *m_tab;


    public:
    Chaine();
    Chaine(int, char tableau[]);
    Chaine(const Chaine &);
    Chaine & operator = (const Chaine &);
    char & operator [] (int);
    friend Chaine operator+(Chaine,Chaine);
    friend void convertMaj(Chaine &);
    friend void convertMin(Chaine &);
    friend bool estAnagramme(Chaine,Chaine);
    friend bool estPalindrome(Chaine);
    void putdata(int, char tableau[]);
    int quelleTaille();
    char unElement(int);
    ~Chaine();
    void afficher();
};


#endif // CHAINE_H_INCLUDED
