#pragma once
#include "Repo.h"
#include "RepoFile.h"
class Service {
private:
    Repo repo;
public:
    Service();
    ~Service();
    void add_tenisi(int marime, int pret, int id);
    void delete_tenisi(int marime, int pret, int id);
    void update_tenisi(int id, int new_marime, int new_pret);
    void list_all_tenisi();
    int achizitionare_tenisi(int suma, int id);
    Repo tenisi_de_marime_x(int marime);
};