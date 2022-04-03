#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include "Chaine.h"
#include "Sigle.h"
#include <cstdlib>
using namespace std;
Chaine operator+(Chaine c1, Chaine c2){
    int tailleC1=c1.m_taille;
    int tailleC2=c2.m_taille;
    int tailleC3=tailleC1+tailleC2;
    char tabchar[tailleC3];
    for(int i=0;i<tailleC1;i++){
        tabchar[i]=c1[i];
    }
    for(int i=0;i<tailleC2;i++){
        tabchar[i+tailleC1]=c2[i];
    }
    Chaine c3(tailleC3,tabchar);
    return c3;
}
void convertMaj(Chaine &c){
    for(int i=0;i<c.m_taille;i++){
        if(c[i]>=97 && c[i]<=122){
            c[i]=c[i]-32; //En comptant avec le systeme ASCII : 65 a 90 pour les majuscules, 97 a 122 pour les minuscules
        }
    }
}
void convertMin(Chaine &c){
    for(int i=0;i<c.m_taille;i++){
        if(c[i]<=90 && c[i]>=65){
            c[i]=c[i]+32; //En comptant avec le systeme ASCII : 65 a 90 pour les majuscules, 97 a 122 pour les minuscules
        }
    }
}
bool estAnagramme(Chaine c1,Chaine c2){
    bool Reponse=true;
    int tailleC1=c1.m_taille;
    int tailleC2=c2.m_taille;
    if(tailleC1!=tailleC2){
        Reponse=false;
    }
    else{
        //Idee : on va supprimer les lettres en commun dans deux mots de meme taille et regarder si il nous en reste grace a un compteur de lettres differentes
        //Il faut tout d'abord mettre les deux mots en minucule afin de ne pas avoir de problemes du type 'C'=='c' qui retournerait False
        convertMin(c1);
        convertMin(c2);
        int compteur=0;
        for(int i=0;i<tailleC1;i++){
            for(int j=0;j<tailleC2;j++){
                    if(c1[i]==c2[j]){
                        c1[i]='<';
                        c2[j]='>'; // < et > permetteront d'identifier les caracteres deja traites
                        compteur++;
                    }
            }
        }
        if(compteur!=tailleC1){Reponse=false;}
    }
    return Reponse;
}
bool estPalindrome(Chaine c1){
    bool Reponse=true;
    convertMin(c1);
    int taille=c1.m_taille;
    for(int i=0;i<taille;i++){
        if(c1[i]!=c1[taille-i-1]){Reponse=false;}
    }
    return Reponse;
}
int main()
{
    //Partie 1 :
    //Creation d'un premier objet
    cout << "Bonjour," << endl;
    cout << "Commencons par creer notre premier objet 'Chaine'. Tout d'abord, entrez la taille de la Chaine souhaitee : ";
    int tailleChaine;
    cin >> tailleChaine;
    while(tailleChaine<=0){
        cout << endl << "Veuillez entrer un nombre entier superieur a 0 : ";
        cin >> tailleChaine;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   // On vide le buffer pour eviter d'avoir la meme erreur de nouveau
    }
    cout << endl << "Entrez maintenant les caracteres composant cette chaine (ceux hors index ne seront pas pris en compte et supprimes - Gestion Buffer) : ";
    char tabchar[tailleChaine];
    cin >> tabchar;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //Permet de supprimer les char en trop dans le cas ou l'utilisateur en rentrerait trop
    Chaine MaChaine(tailleChaine,tabchar);
    //Verification du bon fonctionnement du constructeur de recopie et affichage
    Chaine MaChaine2(MaChaine);
    cout << endl << "Voici votre premier objet 'Chaine' : ";
    MaChaine2.afficher();
    cout << ". Bravo :) " << endl;
    //Verification du bon fonctionnement de la surdefinition de l'operateur d'affectation =
    char tabtest[6]={'b','a','b','a','b','a'}; //Creation d'un nouvel objet de type Chaine : Chaine3
    Chaine MaChaine3(6,tabtest);
    MaChaine3=MaChaine2;
    cout << "En fait, le but de notre aventure sera de faire en sorte que '";
    MaChaine3.afficher();
    cout << "' s'apparente a un string ! " << endl;
    //Verification du bon fonctionnement de la surdefinition de l'operateur []
    cout << "Ainsi, n'etant rien d'autre qu'un tableau de caracteres, vous pouvez essayer d'afficher un caractere. Une idee ? (attention on commence a compter a partir de 0) ";
    int indexCaractere;
    cin >> indexCaractere;
    while(indexCaractere>=tailleChaine || indexCaractere<0){
        cout << endl <<"Attention, veuillez entrer un index valide (c'est a dire < a la taille de votre chaine -1) :";
        cin >>indexCaractere;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<< endl <<"Voici donc le " << indexCaractere+1 << "eme caractere de votre Chaine : " << MaChaine3[indexCaractere] << endl;
    cout<<"Et on peut meme le changer, on essaye ? Une idee d'un nouveau caractere ? ";
    char nvCaractere;
    cin >> nvCaractere;
    MaChaine3[indexCaractere]=nvCaractere;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //afin que le buffer ne conserve pas des char pour les affectations suivantes
    cout<< endl << "Voici donc votre nouvelle Chaine : ";
    MaChaine3.afficher();
    //Verification du bon fonctionnement de la surdefinition de l'operateur +
    cout << endl << "Il nous est aussi possible de concatener deux Chaines. Creons une nouvelle Chaine ; Une idee de taille ?";
    int tailleChaine2;
    cin >> tailleChaine2;
    while(tailleChaine2<=0){
        cout << endl << "Veuillez entrer un nombre entier superieur a 0 : ";
        cin >> tailleChaine2;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl << "Entrez maintenant les caracteres composant cette chaine : ";
    char tabchar2[tailleChaine2];
    cin >> tabchar2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Chaine MaChaine4(tailleChaine2,tabchar2);
    Chaine MaChaine5;
    MaChaine5=MaChaine3+MaChaine4;
    cout << endl << "Et voici la concatenation : ";
    MaChaine5.afficher();
    //Verification du bon fonctionnement de la fonction convertMaj et convertMin
    convertMaj(MaChaine5);
    cout << endl << "Il nous est aussi possible de convertir notre Chaine en majuscule : ";
    MaChaine5.afficher();
    convertMin(MaChaine5);
    cout << " ou en minuscule : ";
    MaChaine5.afficher();
    //Verification du bon fonctionnement de la fonction estAnagramme
    cout << endl << "Parlons maintenant Anagramme ! En voici un exemple celebre a partir de ces deux chaines : " << endl;
    char testAnagramme1[17]={'A','l','b','e','r','t',' ',' ',' ','E','i','n','s','t','e','i','n'};
    char testAnagramme2[17]={'R','i','e','n',' ','n',' ','e','s','t',' ','e','t','a','b','l','i'};
    Chaine MaChaine6(17,testAnagramme1);
    Chaine MaChaine7(17,testAnagramme2);
    MaChaine6.afficher();
    cout << endl;
    MaChaine7.afficher();
    cout << "." << endl;
    cout << "Ces deux Chaines sont des anagrammes (0 pour Non, 1 pour Oui) : " << estAnagramme(MaChaine6,MaChaine7) <<endl;
    cout << "Vous voulez essayer ? Partons alors de votre toute premiere chaine : ";
    MaChaine.afficher();
    cout << ", puis crees-en une nouvelle : Une taille ?";
    int tailleAnagramme;
    cin >> tailleAnagramme;
    while(tailleAnagramme<=0){
        cout << endl << "Veuillez entrer un nombre entier superieur a 0 : ";
        cin >> tailleAnagramme;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl << "Entrez maintenant les caracteres composant cette chaine : ";
    char tabcharAna[tailleAnagramme];
    cin >> tabcharAna;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Chaine ChaineAna(tailleAnagramme,tabcharAna);
    cout << endl << "Ces deux Chaines sont des anagrammes (0 pour Non, 1 pour Oui) : " << estAnagramme(MaChaine,ChaineAna) <<endl;
    //Testons maintenant la fonction Palindrome :
    cout << "Terminons avec les Palindromes ! Considerons par exemple ce mot : ";
    char testPalindrome[5]={'K','a','y','a','k'};
    Chaine testChainePal(5,testPalindrome);
    testChainePal.afficher();
    cout << endl << "Cette chaine est un Palindrome (0 pour Non, 1 pour Oui) : " << estPalindrome(testChainePal) <<endl;
    cout << "Vous voulez essayer ? Alors il nous faut une nouvelle chaine ; une taille ? ";
    int taillePal;
    cin >> taillePal;
    while(taillePal<=0){
        cout << endl << "Veuillez entrer un nombre entier superieur a 0 : ";
        cin >> taillePal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout <<endl<< "Entrez maintenant les caracteres composant cette chaine : ";
    char tabcharPal[taillePal];
    cin >> tabcharPal;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Chaine ChainePal(taillePal,tabcharPal);
    cout << endl << "Cette chaine est un Palindrome (0 pour Non, 1 pour Oui) : " << estPalindrome(ChainePal) <<endl;

    //Partie 2 :
    //Creation d'un premier objet
    cout << endl << endl << "Parlons maintenant Sigle et creons notre premier Sigle. Choisissez une taille : ";
    int tailleSigle;
    cin >> tailleSigle;
    while(tailleSigle<=0){
        cout << endl << "Veuillez entrer un nombre entier superieur a 0 : ";
        cin >> tailleSigle;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl << "Entrez maintenant les caracteres composant ce Sigle : ";
    char tabcharS[tailleSigle];
    cin >> tabcharS;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Chaine leSigle1(tailleSigle,tabcharS);
    convertMaj(leSigle1);
    cout << endl << "Entrez maintenant les mots associes a ce Sigle : ";
    int tailleMotSigle;
    Chaine tabChaine[tailleSigle];
    for(int i=0;i<tailleSigle;i++){
        cout << endl << "La lettre " << leSigle1[i] << " correspond au mot de taille : ";
        cin >> tailleMotSigle;
        while(tailleMotSigle<=0){
                cout << endl << "Veuillez entrer un nombre entier superieur a 0 : ";
                cin >> tailleMotSigle;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl << "Entrez maintenant les caracteres composant ce mot : ";
        char tabcharSMot[tailleMotSigle];
        cin >> tabcharSMot;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tabChaine[i].putdata(tailleMotSigle,tabcharSMot);
        convertMin(tabChaine[i]);
        if(tabChaine[i][0]>=97 && tabChaine[i][0]<=122){
            tabChaine[i][0]=tabChaine[i][0]-32; //En comptant avec le systeme ASCII : 65 a 90 pour les majuscules, 97 a 122 pour les minuscules
        }
    }
    Sigle Sigle1(leSigle1,tabChaine);
    //Verification du bon fonctionnement du constructeur de recopie et affichage
    Sigle Sigle2(Sigle1);
    cout << endl << "Et Voici le sigle cree : ";
    Sigle2.afficherSigleMots();
    //Verification du bon fonctionnement du l'operateur +
    cout << endl << "Il nous est aussi possible de concatener deux Sigles. Creons un nouveau Sigle ; Une idee de taille ?";
    int tailleSigle2;
    cin >> tailleSigle2;
    while(tailleSigle2<=0){
        cout << endl << "Veuillez entrer un nombre entier superieur a 0 : ";
        cin >> tailleSigle2;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl << "Entrez maintenant les caracteres composant ce Sigle : ";
    char tabcharS2[tailleSigle2];
    cin >> tabcharS2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Chaine leSigle2(tailleSigle2,tabcharS2);
    convertMaj(leSigle2);
    cout << endl << "Entrez maintenant les mots associes a ce Sigle : ";
    int tailleMotSigle2;
    Chaine tabChaine2[tailleSigle2];
    for(int i=0;i<tailleSigle2;i++){
        cout << endl << "La lettre " << leSigle2[i] << " correspond au mot de taille : ";
        cin >> tailleMotSigle2;
        while(tailleMotSigle2<=0){
                cout << endl << "Veuillez entrer un nombre entier superieur a 0 : ";
                cin >> tailleMotSigle2;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << endl << "Entrez maintenant les caracteres composant ce mot : ";
        char tabcharSMot2[tailleMotSigle2];
        cin >> tabcharSMot2;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tabChaine2[i].putdata(tailleMotSigle2,tabcharSMot2);
        convertMin(tabChaine2[i]);
        if(tabChaine2[i][0]>=97 && tabChaine2[i][0]<=122){
            tabChaine2[i][0]=tabChaine2[i][0]-32; //En comptant avec le systeme ASCII : 65 a 90 pour les majuscules, 97 a 122 pour les minuscules
        }
    }
    Sigle Sigle4(leSigle2,tabChaine2);
    Sigle1=Sigle2+Sigle4;
    cout << endl << "Et voici la concatenation : ";
    Sigle1.afficherSigleMots();
    //Verification du bon fonctionnement du l'operateur d'affectation
    Sigle4=Sigle1;
    cout << endl << "Et voila son jumeau : ";
    Sigle4.afficherSigleMots();
    //Verification du bon fonctionnement de la surdefinition de l'operateur []
    cout << "Vous pouvez essayer d'afficher un des caracteres du Sigle. Une idee ? (attention on commence a compter a partir de 0) ";
    int indexCaractereSigle;
    cin >> indexCaractereSigle;
    while(indexCaractereSigle>=Sigle1.quelleTailleSigle() || indexCaractereSigle<0){
        cout << endl <<"Attention, veuillez entrer un index valide (c'est a dire < a la taille de votre Sigle -1) :";
        cin >>indexCaractereSigle;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<< endl <<"Voici donc le " << indexCaractereSigle+1 << "eme caractere de votre Sigle : ";
    Sigle1[indexCaractereSigle];
    //Verification du bon fonctionnement de la surdefinition de l'operateur ()
    cout<< endl << "On peut aussi changer les mots correspondants au sigle!" << endl;
    cout << "Lequel voulez vous changer ? (on attend un indice entier et attention, ici on commence a compter a partir de 0) ";
    int emplacementNvMot;
    cin >> emplacementNvMot;
    while(emplacementNvMot>=Sigle1.quelleTailleSigle() || emplacementNvMot<0){
        cout << endl <<"Attention, veuillez entrer un index valide (c'est a dire < a la taille de votre Sigle -1) :";
        cin >>emplacementNvMot;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl << "Et par un mot de quelle taille voulez-vous remplacer ";
    Sigle1.quelEstCeMot(emplacementNvMot);
    cout << " : ";
    int tailleNvMot;
    cin >> tailleNvMot;
    while(tailleNvMot<=0){
        cout << endl <<"Veuillez entrer un nombre entier superieur a 0 : ";
        cin >>tailleNvMot;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << endl << "Et pour finir quels sont les caracteres de ce nouveau mot : (commencant par " << Sigle1.PremiereLettreDeCeMot(emplacementNvMot) << " bien sur)" ;
    char NvMot[tailleNvMot];
    cin >>NvMot;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(NvMot[0]!=Sigle1.PremiereLettreDeCeMot(emplacementNvMot)){
        cout << endl <<"Aie le sigle ! Pour le respecter veuillez entrer un mot commencant par " << Sigle1.PremiereLettreDeCeMot(emplacementNvMot) << endl;
        cout << "Reprenons, quels sont les caracteres de ce nouveau mot : ";
        cin >>NvMot;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Chaine leNvMot(tailleNvMot,NvMot);
    Sigle1(emplacementNvMot)=leNvMot;
    cout << endl << "Et voici donc votre nouveau Sigle : ";
    Sigle1.afficherSigleMots();
    cout << endl << "Et voila, notre aventure se termine ici, merci d'etre reste jusqu'a la fin :)";
    return 0;
}
