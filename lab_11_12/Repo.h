#pragma once
#include "Tenisi.h"

class Repo {
private:
    int nr_tenisi;
protected:
    Tenisi tenisi[101];
public:
    Repo();
    ~Repo();
    Tenisi* get_all();

    void add(int marime,int pret, int id);
    void delete_(int marime, int pret, int id);
    void update(int id, int new_marime, int new_pret);
    void list();

    int get_nr_tenisi();

};