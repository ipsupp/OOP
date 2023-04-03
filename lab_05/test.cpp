#include "Repo.h"
#include "NumarComplex.h"
#include "test.h"
#include <iostream>
#include <assert.h>
using namespace std;

void test_cadran()
{
    Repo rep;
    rep = Repo();
    NumarComplex n1(2,3), n2(3,5), n3(2,5);
    assert(rep.cadran_check(n1) == true);
    assert(rep.cadran_check(n2) == true);
    assert(rep.cadran_check(n3) == true);

    NumarComplex n4(0,0), n5(0,2), n6(2,0);
    assert(rep.cadran_check(n4) == false);
    assert(rep.cadran_check(n5) == false);
    assert(rep.cadran_check(n6) == false);
}

void test_cmm_numar()
{
    Repo rep;
    rep = Repo();
    NumarComplex n1(2,3), n2(3,4), n3(0,1);
    rep.add_number(n1);
    rep.add_number(n2);
    rep.add_number(n3);
    assert(rep.cmm_numar() == 1);

}

void test_secventa()
{
    Repo rep;
    rep = Repo();

    NumarComplex n,n1(2,3), n2(2,4), n3(2,4), n4(2,4), n5(2,4), n6(2,5);
    int i = 0, j = 0;
    rep.add_number(n1);
    rep.add_number(n2);
    rep.add_number(n3);
    rep.add_number(n4);
    rep.add_number(n5);
    rep.add_number(n6);
    rep.secventa(i,j);
    assert(i == 1 and j == 4);
}

void test_all()
{
    cout<<"Testarea incepe..."<<endl;
    test_cadran();
    test_cmm_numar();
    test_secventa();
    cout<<"Testare completa!"<<endl;
}