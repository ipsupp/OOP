#include "UI.h"
#include "teste.h"
#include <iostream>
using namespace std;
UI::UI() {}

UI::~UI() {}

void UI::adaugare()
{
    int zi,suma;
    char e[101];

    cout<<"Ziua:";
    cin>>zi;
    cout<<"Suma:";
    cin>>suma;
    cout<<"Tipul:";
    cin>>e;
    cout<<endl;
    char* type = e;

    service.add(zi,suma,type);
}

void UI::adaugare_zi_curenta()
{
    int suma;
    char e[101];

    cout<<"Suma:"; cin>>suma;
    cout<<"Tipul:"; cin>>e;
    cout<<endl;
    char* type = e;
    service.add_current_zi(suma,type);
}

//modificari

void UI::sterge_dupa_zi()
{
    int zi;
    cout<<"Ziua:"; cin>>zi;
    cout<<endl;
    service.delete_all_per_zi(zi);
}

void UI::sterge_de_la_pana_la()
{
    int zi1,zi2;
    cout<<"Ziua de inceput:"; cin>>zi1;
    cout<<"Ziua de sfarsit:"; cin>>zi2;
    cout<<endl;
    service.delete_from_to_zi(zi1,zi2);
}

void UI::sterge_dupa_tip()
{
    char e[101];
    cout<<"Tipul:"; cin>>e;
    cout<<endl;
    char* type = e;
    service.delete_by_type(type);
}

void UI::afisare_toate()
{
    service.list_all();
}

void UI::afisare_dupa_tip()
{
    char e[101];
    cout<<"Tipul:"; cin>>e;
    cout<<endl;
    service.list_by_type(e);
}

void UI::afisare_dupa_tip_si_mai_mare_decat_suma()
{
    int suma;
    char e[101];
    cout<<"Suma:"; cin>>suma;
    cout<<"Tipul:"; cin>>e;
    cout<<endl;
    char* type = e;
    service.list_type_more_than_sum(type,suma);
}

void UI::afisare_dupa_tip_egal_cu_suma()
{
    int suma;
    char e[101];
    cout<<"Suma:"; cin>>suma;
    cout<<"Tipul:"; cin>>e;
    cout<<endl;
    char* type = e;
    service.list_type_equal_to_sum(type, suma);
}

void UI::afisare_suma_totala_pe_zi_dupa_tip()
{
    char e[101];
    cout<<"Tipul:"; cin>>e;
    cout<<endl;
    char* type = e;
    cout<<"Suma totala este:"<<service.list_total_sum_from_type(type)<<endl;
}

void UI::afisare_suma_maxima_pe_zi()
{
    service.list_max_sum_from_zi();
}

void UI::afisare_sume_pe_zi_sortate_descr()
{
    service.list_daily_sums_sorted_desc();
}

void UI::afisare_dupa_tip_sume_zilnice_sortate_cresc()
{
    char e[101];
    cout<<"Tipul: "; cin>>e;
    cout<<endl;
    char* type = e;
    service.list_type_daily_sums_sorted_asc(type);
}

void UI::filtrare_dupa_tip()
{
    char e[101];
    cout<<"Tipul:"; cin>>e;
    cout<<endl;
    char* type = e;
    service.filter_type(type);
}

void UI::filtrare_dupa_tip_mai_mic_decat_suma()
{
    int suma;
    char e[101];
    cout<<"Suma:"; cin>>suma;
    cout<<"Tipul:"; cin>>e;
    cout<<endl;
    char* type = e;
    service.filter_type_less_than_sum(type,suma);
}

void UI::filtrare_dupa_tip_egala_cu_suma()
{
    int suma;
    char e[101];
    cout<<"Suma:"; cin>>suma;
    cout<<"Tipul:"; cin>>e;
    cout<<endl;
    char* type = e;
    service.filter_type_equal_to_sum(type,suma);
}


UI& UI::submeniu_adaugari()
{

    cout << "1. Adaugare." << endl;
    cout << "2. Adaugare pentru ziua curenta." << endl;
    cout << "Optiune dorita?";
    int optiune_1 = 0;
    cin >> optiune_1;
    if (optiune_1 == 1)
        adaugare();
    else
    {
        if (optiune_1 == 2)
        {
            adaugare_zi_curenta();
        }
        else cout << "Optiune invalida!" << endl;
    }
}
UI& UI::submeniu_modificari()
{

    cout<<"1. Sterge dupa ziua."<<endl;
    cout<<"2. Sterge zilele din intervalul."<<endl;
    cout<<"3. Sterge dupa tipul."<<endl;
    cout<<"Optiune dorita?";
    int optiune_1 = 0;
    cin>>optiune_1;
    if (optiune_1 == 1)
        sterge_dupa_zi();
    if (optiune_1 == 2)
        sterge_de_la_pana_la();
    if (optiune_1 == 3)
        sterge_dupa_tip();
}

UI& UI::submeniu_afisari()
{

    cout<<"1. Afisare toate cheltuielile."<<endl;
    cout<<"2. Afisare dupa tip."<<endl;
    cout<<"3. Afisare dupa tip si mai mare decat suma."<<endl;
    cout<<"4. Afisare dupa tip si egala cu suma."<<endl;
    cout<<"Optiune dorita?";
    int optiune_1 = 0;
    cin>>optiune_1;
    if (optiune_1 == 1)
        afisare_toate();
    if (optiune_1 == 2)
        afisare_dupa_tip();
    if (optiune_1 == 3)
        afisare_dupa_tip_si_mai_mare_decat_suma();
    if (optiune_1 == 4)
        afisare_dupa_tip_egal_cu_suma();
}

UI& UI::submeniu_prop()
{

    cout<<"1. Sumele totale pe zi dupa tip."<<endl;
    cout<<"2. Suma maxima per zi."<<endl;
    cout<<"3. Sumele pe zi sortate descrescator."<<endl;
    cout<<"4. Sumele pe zi sortate crescator."<<endl;
    cout<<"Optiune dorita?";
    int optiune_1 = 0;
    cin>>optiune_1;
    if (optiune_1 == 1)
        afisare_suma_totala_pe_zi_dupa_tip();
    if (optiune_1 == 2)
        afisare_suma_maxima_pe_zi();
    if (optiune_1 == 3)
        afisare_sume_pe_zi_sortate_descr();
    if (optiune_1 == 4)
        afisare_dupa_tip_sume_zilnice_sortate_cresc();
}

UI& UI::submeniu_filtrari()
{

    cout<<"1. Filtrare dupa tip"<<endl;
    cout<<"2. Filtrare dupa tip si mai putin decat suma."<<endl;
    cout<<"3. Filtrare dupa tip egala cu suma"<<endl;
    cout<<"Optiune dorita?";
    int optiune_1 = 0;
    cin>>optiune_1;
    if (optiune_1 == 1)
        filtrare_dupa_tip();
    if (optiune_1 == 2)
        filtrare_dupa_tip_mai_mic_decat_suma();
    if (optiune_1 == 3)
        filtrare_dupa_tip_egala_cu_suma();
}



UI& UI::menu()
{
    cout<<"1. Adaugari."<<endl;
    cout<<"2. Modificari."<<endl;
    cout<<"3. Afisari."<<endl;
    cout<<"4. Proprietati speciale."<<endl;
    cout<<"5. Filtrari."<<endl;
    cout<<"6. Anulati ultima actiune."<<endl;
    cout<<"0. Exit program."<<endl;
}

Repo UI::copy_of_repo()
{
        return service.create_repo_copy();
}

UI& UI::undo()
{
    Repo new_rep = copy_of_repo();
    service.swap_repo_with_copy(new_rep);
}

void UI::submeniu_undo()
{
    cout<<"Doriti sa anulati ultima actiune?"<<endl;
    cout<<"y/n"<<endl;
    char opt;
    cin>>opt;
    if (opt == 'y')
        undo();
}

UI& UI::main_menu()
{
    int ok = 1, optiune =0;
    while (ok)
    {
        Repo repo_copy;
        menu();
        cout<<endl;
        cout<<"Optiune dorita?";
        cin>>optiune;
        cout<<endl;
        switch (optiune)
        {
            case 1:
            {
                Repo repo_copy = copy_of_repo();

                submeniu_adaugari();
                submeniu_undo();
                break;
            }
            case 2:
            {
                Repo repo_copy = copy_of_repo();

                submeniu_modificari();
                submeniu_undo();
                break;
            }
            case 3:
            {

                submeniu_afisari();
                break;
            }
            case 4:
            {
                submeniu_prop();
                break;
            }
            case 5:
            {
                Repo repo_copy = copy_of_repo();

                submeniu_filtrari();
                break;
            }
            case 6:
            {
                undo();

                cout<<"Ultima actiune a fost anulata."<<endl;
                break;
            }
            case 0:
            {
                ok = 0;
                cout<<"Done.";
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
