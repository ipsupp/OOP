#include "Service.h"
#include <iostream>
using namespace std;
Service::Service() {}

Service::~Service() {}

void Service::add_tenisi(int marime, int pret) {
    repo.add(marime, pret);
}

void Service::delete_tenisi(int marime, int pret) {
    repo.delete_(marime, pret);
}

void Service::update_tenisi(int marime, int pret, int new_marime, int new_pret) {
    repo.update(marime, pret, new_marime, new_pret);
}

void Service::list_all_tenisi() {
    Tenisi* all_tenisi = repo.get_all();

    for (int i = 0; i < repo.get_nr_tenisi(); i++)
        cout<<"ID: "<<all_tenisi[i].get_id()<<" | Size: "<<all_tenisi[i].get_marime()<<" | Price: "<<all_tenisi[i].get_pret()<<endl;

}
