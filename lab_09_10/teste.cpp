#include "Tenisi.h"
#include "Repo.h"
#include "teste.h"
#include <cassert>
#include <iostream>
using namespace std;
void tenisi_setteri_getteri()
{
    Tenisi t1;
    t1.set_pret(100);
    t1.set_marime(35);
    assert(t1.get_marime() == 35);
    assert(t1.get_pret() == 100);
}

void repo_add_delete_update()
{
    Repo rep;
    rep = Repo();
    rep.add(28,60);
    rep.add(30,200);
    rep.add(42,400);
    rep.list();cout<<endl;
    rep.delete_(28,60);
    rep.list();cout<<endl;
    rep.update(42,400,41,700);
    rep.list();cout<<endl;

}

void test_all()
{
    tenisi_setteri_getteri();
    repo_add_delete_update();
}