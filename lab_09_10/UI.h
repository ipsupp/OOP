#pragma once
#include "Service.h"

class UI {
private:
    Service service;
    int suma;
public:
    UI();
    ~UI();

    void main_menu();
    void menu();
    void adaugare_tenisi();
    void stergere_tenisi();
    void modificare_tenisi();
    void afisare_tenisi();
    void achizitionare_tenisi();
    void filtrare_dupa_marime();

};
