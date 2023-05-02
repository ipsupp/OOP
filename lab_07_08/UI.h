#pragma once
#ifndef LAB_07_UI_H
#define LAB_07_UI_H
#include "Service.h"

class UI {
private:
    Service service;
public:
    UI();
    ~UI();

    void main_menu();
    void menu();
    void submeniu_adaugari();
    void submeniu_modificari();
    void submeniu_afisari();
    void submeniu_prop();
    void submeniu_filtrari();
    void submeniu_undo(); // not done

    //adaugari
    void adaugare();
    void adaugare_zi_curenta();

    //modificari
    void sterge_dupa_zi();
    void sterge_de_la_pana_la();
    void sterge_dupa_tip();

    //afisari
    void afisare_toate();
    void afisare_dupa_tip();
    void afisare_dupa_tip_si_mai_mare_decat_suma();
    void afisare_dupa_tip_egal_cu_suma();

    //proprietati speciale
    void afisare_suma_totala_pe_zi_dupa_tip();
    void afisare_suma_maxima_pe_zi();
    void afisare_sume_pe_zi_sortate_descr();
    void afisare_dupa_tip_sume_zilnice_sortate_cresc();

    //filtrare
    void filtrare_dupa_tip();
    void filtrare_dupa_tip_mai_mic_decat_suma();
    void filtrare_dupa_tip_egala_cu_suma();

    //undo
    void undo();



};


#endif //LAB_07_UI_H