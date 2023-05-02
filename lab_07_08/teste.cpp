#include <iostream>
#include <cassert>
#include <cstring>

#include "Cheltuiala.h"
#include "Repo.h"
#include "Service.h"
#include "UI.h"

using namespace std;

// test Cheltuiala
void test_setteri_getteri() {
    Cheltuiala ch;
    ch.set_ziua(10);
    ch.set_suma(900);
    ch.set_type("mancare");

    char *p = ch.get_type();

    assert(ch.get_ziua() == 10);
    assert(ch.get_suma() == 900);
    assert(strcmp(p, "mancare") == 0);
    Cheltuiala ch1(21,150,"internet");
    char* c = ch1.get_type();

    ch.set_type(c);
    assert(strcmp(ch.get_type(),c)== 0 );
//    for (int i=0; i<strlen(ch1.get_type());i++)
//    {
//        c[i] =
//    }

//    ch.set_type(ch1.get_type());
//    assert (strcmp(ch.get_type(),"internet") ==0);
}
// test Repo

void test_add_all_size()
{
    Repo rep;
    rep = Repo();
    Cheltuiala c1(2,10,"mancare"), c2(3,1000,"chirie");
    rep.add_cheltuieli(c1);
    rep.add_cheltuieli(c2);

    Cheltuiala ch;
    rep.add_cheltuieli_zi_curenta(60,"internet");
//    rep.afisare_cheltuieli();

    assert(rep.get_size() == 3);
    Cheltuiala* all_ch = rep.get_all();

    char* p1 = all_ch[0].get_type();
    char* p2 = all_ch[1].get_type();

    assert(all_ch[0].get_ziua() == 2);
    assert(all_ch[1].get_ziua() == 3);
    assert(all_ch[0].get_suma() == 10);
    assert(all_ch[1].get_suma() == 1000);
    assert(strcmp(p1,"mancare") == 0);
    assert(strcmp(p2,"chirie") == 0);
    c1 = c2;
    //c2(3,1000,"out","chirie")
    assert(c1.get_ziua() == 3);
    assert(c1.get_suma() == 1000);
    char* p = c1.get_type();
    assert(strcmp(p,"chirie") == 0);
}

void test_sort_delete()
{
    Cheltuiala c1(28,1000,"chirie"),c2(15,30,"mancare"),c3(15,105,"menaj");
    Cheltuiala c4(28, 5,"mancare"),c5(10,100,"menaj");
    Repo rep;
    rep = Repo();
    rep.add_cheltuieli(c1);
    rep.add_cheltuieli(c2);
    rep.add_cheltuieli(c3);
    rep.add_cheltuieli(c4);
    rep.add_cheltuieli(c5);

//    rep.afisare_cheltuieli();
//    cout<<endl;

//    rep.afisare_cheltuieli();

//    rep.filtrare_type_suma_fixa("mancare",5);
//    rep.filtrare_type_mai_mica_suma("menaj",105);
//    rep.filtrare_type("mancare");

//    rep.sterge_cheltuiala(28,1000,"chirie");
//    rep.sterge_cheltuiala(15,100,"menaj");
//    rep.sterge_cheltuiala(28,5,"mancare");

//    rep.sortare_dupa_zi();
//    rep.stergere_cheltuiala_dupa_zi(15);
//    char *e="menaj";
//    rep.stergere_cheltuiala_dupa_type(e);
//    rep.afisare_cheltuieli();
//    functioneaza, nu afisez ca sa nu complic treaba.
}



void test_proprietati()
{
    Cheltuiala c1(28,1000,"chirie"),c2(15,30,"mancare"),c3(15,100,"menaj");
    Cheltuiala c4(28, 5,"mancare"),c5(10,100,"menaj");
    Repo rep;
    rep = Repo();
    rep.add_cheltuieli(c1);
    rep.add_cheltuieli(c2);
    rep.add_cheltuieli(c3);
    rep.add_cheltuieli(c4);
    rep.add_cheltuieli(c5);

    assert(rep.suma_totala_type("mancare") == 35);
//    rep.ziua_suma_totala_max();
//    rep.sortare_zilnic_descr();
//    char e[10] ="mancare";
//    rep.sortare_zilnica_type_cresc(e);

}
//test Service

void test_service()
{
    Service serv;
    serv = Service();
    serv.add(15,200,"mancare");
    serv.add(31,1200,"chirie");
    serv.add(1,60,"menaj");
    serv.add(31,66,"internet");
    serv.add(2,300,"mancare");

//    serv.list_all();
//    cout<<endl;
// filtrari
//    serv.filter_type("mancare");
//    serv.filter_type_less_than_sum("mancare", 250);
//    serv.list_type_equal_to_sum("internet", 66);

//    serv.list_all();


// afisari
//
//    cout<<endl;
//    serv.list_by_type("mancare");
//    cout<<endl;
//    serv.list_type_more_than_sum("mancare", 250);
//    cout<<endl;
//    serv.list_type_equal_to_sum("mancare", 200);
//    cout<<endl;
//    functioneaza;

//proprietati speciale
//    cout<<serv.list_total_sum_from_type("mancare")<<endl;
//    serv.list_max_sum_from_zi();
//    cout<<endl;
//    serv.list_daily_sums_sorted_desc();
//    cout<<endl;
//    serv.list_type_daily_sums_sorted_asc("mancare");

// stergeri
    serv.delete_all_per_zi(31);
    serv.delete_by_type("internet");
    serv.delete_from_to_zi(1,5);

//    serv.list_all();
}

void test_swap_repos()
{
    Cheltuiala c1(28,1000,"chirie"),c2(15,30,"mancare"),c3(15,100,"menaj");
    Cheltuiala c4(28, 5,"mancare"),c5(10,100,"menaj");
    Repo rep;
    Repo repcopy;
    rep = Repo();
    repcopy = Repo();
    rep.add_cheltuieli(c1);
    rep.add_cheltuieli(c2);
    rep.add_cheltuieli(c3);
    rep.add_cheltuieli(c4);
    rep.add_cheltuieli(c5);
    repcopy.add_cheltuieli(c1);
    repcopy.add_cheltuieli(c3);
    repcopy.add_cheltuieli(c4);
    cout<<"R1"<<endl;
    rep.afisare_cheltuieli();
    cout<<endl;
    cout<<"R2"<<endl;
    repcopy.afisare_cheltuieli();
    cout<<endl<<endl;
    rep.swap_repos(repcopy,3);
    rep.afisare_cheltuieli();

}

void test_undo()
{
    Service serv;
    serv = Service();
    serv.add(15,200,"mancare");
    serv.add(31,1200,"chirie");
    serv.add(1,60,"menaj");
    serv.add(31,66,"internet");
    serv.add(2,300,"mancare");
    serv.add(21,150,"sala");
    serv.add(7,10,"mancare");
    serv.add(15,60,"menaj");
    serv.add(25,120,"mancare");
    serv.add(12,150,"sala");

    serv.list_all();
    cout<<endl;

    Repo crepo;
    crepo = serv.create_repo_copy();

    serv.filter_type("mancare");
    serv.list_all();
    cout<<endl;

    serv.swap_repo_with_copy(crepo);
    serv.list_all();
    cout<<endl;

}

//test UI
void test_ui()
{
    UI ui;

}


void test_all()
{
    test_setteri_getteri();
    test_add_all_size();
    test_sort_delete();
    test_proprietati();
    test_service();
    //test_undo();
    test_swap_repos();
    test_ui();

    cout<<"Testare completa!"<<endl;

}