#include <iostream>
#include "NumarComplex.h"
#include "Repo.h"
using namespace std;

//numar complex

//nr cu virgula

//parte reala, parte imaginara

//seteri, geteri, destructor

//adunare, scadere, inmultire, modulul unui nr complex

//in acoladele destructorului e gol

//ce mai trebuie sa fac: destructor, adunare, scadere, inmultire, modulul

void meniu()
{
    cout<<"1. Introducere numar complex "<<endl;
    cout<<"2. Afisati numerele"<<endl;
    cout<<"x. Exit program."<<endl;
}

int console() {
    Repo rep;
    rep = Repo();
    int ok = 1;
    while (ok == 1) {
        meniu();
        cout << endl;
        char opt;
        cout << "Introduceti optiunea dorita: ";
        cin >> opt;

        switch (opt) {
            case '1': {
                float x, y;
                cout << "Parte reala: ";
                cin >> x;
                cout << "Parte complexa: ";
                cin >> y;
                NumarComplex n(x, y);
                rep.add_number(n);
                break;
            }

            case '2': {
                rep.afisare();
                cout << endl;
                break;
            }

            case 'x': {
                ok = 0;
                cout << "Program exited.";
                break;
            }
            default: {
                cout << "Optiune invalida!";
                return 0;
            }
        }
    }
}


int main()
{
    console();
    return 0;
}



//    NumarComplex n1(2,3);
//    NumarComplex n2(0,5);
//    NumarComplex n3(1,2);
//
//    cout<<n1.get_pr()<<"+"<<n1.get_pc()<<"i"<<endl;
//    cout<<n2.get_pr()<<"+"<<n2.get_pc()<<"i"<<endl;
//
//    n3.set_pr(3);
//    n3.set_pc(0);
//    n3.get_pr();
//    n3.get_pc();
//
//    cout<<endl;
//    NumarComplex n4;
//    n4 = NumarComplex(n1);
//    cout<<n4.get_pr()<<"+"<<n4.get_pc()<<"i"<<endl;
//
//    cout<<"Adunare: "<<endl;
//    n3.adunare(n1,n2);
//
//    cout<<"Scadere: "<<endl;
//    n3.scadere(n1, n2);
//
//    cout<<"Inmultire: "<<endl;
//    n3.inmultire(n1,n2);
//
//    cout<<"Modul: "<<endl;
//    n3.modul(n1);



