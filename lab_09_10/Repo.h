#pragma once
#include "Tenisi.h"

class Repo {
private:
    Tenisi tenisi[101];
    int nr_tenisi;
public:
    Repo();
    ~Repo();
    Tenisi* get_all();

    void add(int marime,int pret);
    void delete_(int marime, int pret);
    void update(int marime, int pret , int new_marime, int new_pret);
    void list();

    int get_nr_tenisi();

};