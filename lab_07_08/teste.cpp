#include <assert.h>
#include <cstring>
#include "Cheltuiala.h"
#include "Repo.h"
#include <string.h>
#include <iostream>
using namespace std;

// test Cheltuiala
void test_setteri_getteri()
{
    Cheltuiala ch;
    ch.set_ziua(10);
    ch.set_suma(900);
    ch.set_type("chirie");

    //    char *e ="chirie";
//    assert(ch.get_ziua() == 10);
//    assert(ch.get_suma() == 900);
//    assert(strcmp(ch.get_type(), e) == 0);
//    failed test (but whyy)

    char type[100];
    strcpy(type,ch.get_type());

    assert(ch.get_ziua() == 10);
    assert(ch.get_suma() == 900);
    assert(strcmp(type,"chirie")== 0);


//    Cheltuiala c1, c2;
//    c1.set_ziua(10);
//    c1.set_suma(250);
//    c1.set_type("mancare");
//    c2.set_ziua(20);
//    c2.set_suma(1000);
//    c2.set_type("menaj");
//
//
//    assert(c1.get_ziua() == 10);
//    assert(c1.get_suma() == 250);
//    assert(c1.get_type() == "mancare");
//
//    assert(c2.get_ziua() == 20);
//    assert(c2.get_suma() == 1000);
//    assert(c2.get_type() == "menaj");
}

// test Repo

void test_add_all_size()
{
    Repo rep;
    rep = Repo();
    Cheltuiala c1(2,10,"mancare"), c2(3,1000,"chirie");
    rep.add_cheltuieli(c1);
    rep.add_cheltuieli(c2);

    assert(rep.get_size() == 2);
    Cheltuiala* all_ch = rep.get_all();

    char type0[101], type1[101];
    strcpy(type0,all_ch[0].get_type());
    strcpy(type1, all_ch[1].get_type());

    assert(all_ch[0].get_ziua() == 2);
    assert(all_ch[1].get_ziua() == 3);
    assert(all_ch[0].get_suma() == 10);
    assert(all_ch[1].get_suma() == 1000);
    assert(strcmp(type0,"mancare") == 0);
    assert(strcmp(type1,"chirie") == 0);


}

void test_all()
{
    test_setteri_getteri();
    test_add_all_size();

}