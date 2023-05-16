#include "Service.h"
#include <iostream>
using namespace std;
Service::Service() {}

Service::~Service() {}

void Service::add_tenisi(int marime, int pret, int id) {
    repo.add(marime, pret, id);
}

void Service::delete_tenisi(int marime, int pret, int id) {
    repo.delete_(marime, pret, id);
}

void Service::update_tenisi(int id, int new_marime, int new_pret) {
    repo.update( id, new_marime, new_pret);
}

void Service::list_all_tenisi() {
    Tenisi* all_tenisi = repo.get_all();

    for (int i = 0; i < repo.get_nr_tenisi(); i++)
        cout<<"ID: "<<all_tenisi[i].get_id()<<" | Size: "<<all_tenisi[i].get_marime()<<" | Price: "<<all_tenisi[i].get_pret()<<endl;
}

int Service::achizitionare_tenisi(int suma, int id)
{
    Tenisi* all_tenisi = repo.get_all();
    for (int i = 0; i < repo.get_nr_tenisi(); i++)
        if (all_tenisi[i].get_id() == id)
        {
            if (suma >= all_tenisi[i].get_pret())
            {
                delete_tenisi(all_tenisi[i].get_marime(),all_tenisi[i].get_pret(),all_tenisi[i].get_id());
                return suma - all_tenisi[i].get_pret();
            }
            if (suma < all_tenisi[i].get_pret())
                return -1;
        }
    return 0;
}

Repo Service::tenisi_de_marime_x(int marime)
{
    Repo filtrare;
    Tenisi* all_tenisi = repo.get_all();
    int ok = 0;
    for (int i = 0; i<repo.get_nr_tenisi(); i++)
    {
            if (all_tenisi[i].get_marime() == marime)
            {
                int a,b;
                a = all_tenisi[i].get_pret();
                b = all_tenisi[i].get_id();
                filtrare.add(marime,a,b);
            }
    }
    filtrare.list();
}