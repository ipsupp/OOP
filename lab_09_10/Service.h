#pragma once
#include "Repo.h"

class Service {
private:
    Repo repo;
public:
    Service();
    ~Service();
    void add_tenisi(int marime, int pret);
    void delete_tenisi(int marime, int pret);
    void update_tenisi(int marime, int pret, int new_marime, int new_pret);
    void list_all_tenisi();
};
