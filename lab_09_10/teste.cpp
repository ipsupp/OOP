#include "Tenisi.h"
#include "Repo.h"
#include "Service.h"
#include "teste.h"
#include <cassert>
#include <iostream>
using namespace std;
void test_tenisi()
{
    Tenisi t1;
    t1.set_pret(100);
    t1.set_marime(35);
    t1.set_id(543);
    assert(t1.get_marime() == 35);
    assert(t1.get_pret() == 100);
    assert(t1.get_id() == 543);
}

void test_repo()
{
    Repo rep;
    rep = Repo();
    rep.add(28,60);
    rep.add(30,200);
    rep.add(42,400);
//    rep.list();cout<<endl;
    rep.delete_(28,60);
//    rep.list();cout<<endl;
    rep.update(42,400,41,700);
//    rep.list();cout<<endl;
}

void test_service() {
    Service service;

    service.add_tenisi(39, 100);
    service.add_tenisi(40, 120);
    service.add_tenisi(41, 140);

//    service.list_all_tenisi();
    service.update_tenisi(40, 120, 46, 200);
//    service.list_all_tenisi();
    service.delete_tenisi(39, 100);
//    service.list_all_tenisi();
}

void test_all()
{
    test_tenisi();
    test_repo();
    test_service();
}