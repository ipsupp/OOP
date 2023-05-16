#include "UI.h"
#include <iostream>
using namespace std;
UI::UI()
{
    this->suma = 0;
}
UI::~UI() {}

void UI::adaugare_tenisi()
{
    int marime = 0, pret = 0, id  = 0;
    cout<<"Precizati marimea, pretul si id-ul tenisilor."<<endl;
    cin>>marime>>pret>>id;
    service.add_tenisi(marime,pret,id);
}

void UI::stergere_tenisi()
{
    int marime = 0, pret = 0, id  = 0;
    cout<<"Precizati marimea, pretul si id-ul tenisilor."<<endl;
    cin>>marime>>pret>>id;
    service.delete_tenisi(marime,pret,id);
}

void UI::modificare_tenisi()
{
    int marime = 0, pret = 0, id  = 0;
    cout<<"Precizati noua marime, noul pretul si id-ul tenisilor."<<endl;
    cin>>marime>>pret>>id;
    service.update_tenisi(id,marime,pret);
}

void UI::afisare_tenisi()
{
    service.list_all_tenisi();
}

void UI::achizitionare_tenisi()
{
    int id = 0, fonduri = 0;
    cout<<"Precizati id-ul tenisilor."<<endl;
    cin>>id;
    cout<<"Suma cu care achitati?"<<endl;
    cin>>fonduri;
    int result = service.achizitionare_tenisi(fonduri, id);
    if (result == 0){
            cout<<"Tenisii precizati nu exista."<<endl;
        }
    else if (result == -1)
        {
            cout<<"Fonduri insuficiente."<<endl;
        }
    else
        {
            cout<<"Tenisi achizitionati."<<endl;
            if (suma!=0)
                cout<<"Fonduri returnate: "<<suma<<endl;
            this->suma = result;
        }
    }


void UI::filtrare_dupa_marime()
{
    int marime = 0;
    cout<<"Precizati marimea."<<endl;
    cin>>marime;
    service.tenisi_de_marime_x(marime);
}

void UI::main_menu()
{
    cout<<"1. Adaugare tenisi."<<endl;
    cout<<"2. Stergere tenisi."<<endl;
    cout<<"3. Modificare tenisi."<<endl;
    cout<<"4. Afisare tenisi."<<endl;
    cout<<"5. Achizitionare tenisi. ( nu functioneaza) "<<endl;
    cout<<"6. Afisati tenisii de marime x."<<endl;
    cout<<"0. Iesire din program."<<endl;
}


void UI::menu()
{
    int optiune = -1, ok = 1;
    while (ok)
    {
        main_menu();
        cout<<"Optiune dorita?"<<endl;
        cin>>optiune;
        switch (optiune){
            case 1:
            {
                adaugare_tenisi();
                break;
            }
            case 2:
            {
                stergere_tenisi();
                break;
            }
            case 3:
            {
                modificare_tenisi();
                break;
            }
            case 4:
            {
                afisare_tenisi();
                break;
            }
            case 5:
            {
                achizitionare_tenisi();
                break;
            }
            case 6:
            {
                filtrare_dupa_marime();
                break;
            }
            case 0:
            {
                ok = 0;
                break;
            }
            default:
            {
                cout<<"Optiune invalida!"<<endl;
                break;
            }
        }
    }
}