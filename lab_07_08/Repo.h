#pragma once
#include "Cheltuiala.h"

class Repo
{
private:
    Cheltuiala cheltuieli[101];
    int nr_ch;
public:
    Repo();
    ~Repo();
    Repo& swap_repos(Repo repository,int new_size);
    Cheltuiala* get_all();
    int get_size();
    Repo& set_size(int new_size);
    Repo& sortare_dupa_zi();
    Repo& sterge_cheltuiala(int zi, int suma, char* type);
    //1.
    // adaugare cheltuiala
    void add_cheltuieli(const Cheltuiala &c);
    void add_cheltuieli_zi_curenta(int suma, char e[]);
    void add_cheltuieli_zi_suma_type(int zi,int suma, char type[]);

    // modificare cheltuieli din lista - done
    Repo& stergere_cheltuiala_dupa_zi(int zi);
    Repo& stergere_cheltuiala_dupa_type(char type[]);

    //cheltuieli cu anumite proprietati - done
    void afisare_cheltuiala(Cheltuiala c);
    void afisare_cheltuieli();
    void afisare_cheltuieli_type(char e[]);
    void afisare_cheltuieli_type_mmare_suma(char e[], int suma);
    void afisare_cheltuieli_type_suma(char e[], int suma);

    //proprietati speciale - done
    int suma_totala_type(char e[]);
    void ziua_suma_totala_max();
    void sortare_zilnic_descr();
    void sortare_zilnica_type_cresc(char e[]);

    //filtrare - done
    Repo& filtrare_type(char e[]); // sterge tot mai putin type
    Repo& filtrare_type_mai_mica_suma(char e[], int suma); // sterge tot mai putin type si < suma
    Repo& filtrare_type_suma_fixa(char e[], int suma);


    //undo - done, trebuie implementat in service
    Repo& undo(int zi, int suma, char type[]); //caut ultima tranz adaugata, PE CARE AM SALVAT-O, ca sa o sterg;

};