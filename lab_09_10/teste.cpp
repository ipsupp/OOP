#include "Tenisi.h"
#include "Repo.h"
#include "Service.h"
#include "teste.h"
#include <cassert>
#include <iostream>
using namespace std;
void tenisi_setteri_getteri()
{
    Tenisi t1;
    t1.set_pret(100);
    t1.set_marime(35);
    t1.set_id(11);
    assert(t1.get_marime() == 35);
    assert(t1.get_pret() == 100);
    assert(t1.get_id() == 11);
}

void repo_add_delete_update()
{
    Repo rep;
    rep = Repo();
    rep.add(28,60,11);
    rep.add(30,200,22);
    rep.add(42,400,33);
//    rep.list();cout<<endl;
    rep.delete_(28,60,11);
//    rep.list();cout<<endl;
    rep.update(22, 36, 250);
//    rep.list();cout<<endl;

}

void test_service()
{
    Service service;
    service.add_tenisi(20,100,12);
    service.add_tenisi(20,150,17);
    service.add_tenisi(20,175,18);
    service.add_tenisi(36,240,13);
    service.add_tenisi(42,300,24);
//    service.tenisi_de_marime_x(20);
}

void test_all()
{
    tenisi_setteri_getteri();
    repo_add_delete_update();
    test_service();
}