#include "Repo.h"
#include "NumarComplex.h"
#include <iostream>
#include <cmath>
using namespace std;
Repo::Repo()
{
    this->noNumbers = 0;
}

Repo::~Repo()
{}

void Repo::add_number(NumarComplex &n)
{
    this->numere[this->noNumbers++] = n;
}

void Repo::afisare_lista()
{
    for (int i=0;i<this->noNumbers;i++)
        if (numere[i].get_pc()>=0)
            cout<<numere[i].get_pr()<<"+"<<numere[i].get_pc()<<"i"<<endl;
        else
            cout<<numere[i].get_pr()<<numere[i].get_pc()<<"i"<<endl;
}

void Repo::afisare_numar(NumarComplex &n)
{
    if (n.get_pc()>=0)
        cout<<n.get_pr()<<"+"<<n.get_pc()<<"i"<<endl;
    else cout<<n.get_pr()<<n.get_pc()<<"i"<<endl;
}

bool Repo::cadran_check(NumarComplex &n)
{
    if (n.get_pr()>0 and n.get_pc() != 0 and tan(n.get_pc()/n.get_pr()) != 0)
    {
        float is, c, ang;
        ang = atan(n.get_pc() / n.get_pr());
        is = sin(ang);
        c = cos(ang);
        if (0 <= is and c >= 0)
            return true;
        return false;
    }
    return false;
}

void Repo::cadran_lista()
{
    int ok = 0,v[100],k = 0;
    for (int i = 0; i < this->noNumbers; i ++)
        if (cadran_check(this->numere[i]) == true and tan(this->numere[i].get_pc()/this->numere[i].get_pr()) !=0)
        {
            ok = 1;
            afisare_numar(this->numere[i]);
        }
    if (ok == 0)
        cout<<"Nu exista numere complexe aflate in primul cadran."<<endl;
}

int Repo::cmm_numar()
{
    NumarComplex n;
    int index =-1, mod = -1;
    for (int i=0; i<noNumbers; i++)
        if (n.modul(this->numere[i]) > mod)
        {
            mod = n.modul(numere[i]);
            index = i;
        }
    return index;
}

void Repo::afisare_cmm_numar()
{
    NumarComplex n;
    n = numere[cmm_numar()];
    afisare_numar(n);
}

bool Repo::is_equal(NumarComplex n, NumarComplex m)
{
    if (n.get_pc() == m.get_pc() and n.get_pr() == m.get_pr())
        return true;
    return false;
}

void Repo::secventa(int &i, int &j)
{

    int st = -1, dr = -1, len = -1;     //final
    int cst = -1, cdr = -1, clen = -1;  //current
    for (int i = 0; i<noNumbers;i++){
        clen=0;
        for (int j=i+1;j<noNumbers;j++){
            if (is_equal(numere[i],numere[j]) == true)
            {
                cst = i;
                cdr = j;
                if (clen < 0){
                    clen = 2;
                }
                else{
                    clen++;
                }
            }
            else{
                if (clen>len)
                {
                    st = cst;
                    dr = cdr;
                    len = clen;
                    clen = -1;
                }
                i=j;
            }
        }
        i=noNumbers;
    }
    if (clen > len)
    {
        len = clen;
        st = cst;
        dr = cdr;
    }
    i = st;
    j = dr;

//    int len = -1, lmax;
//    for (i = 0; i < this->noNumbers - 1; i++ )
//    {
//        for (j = i + 1; j < this->noNumbers -1; j++)
//        {
//            if (is_equal(numere[i], numere[j]) == false)
//            {
//                if (len < j - i)
//                {
//                    len = j - i;
//                    lmax = i;
//                }
//            }
//        }
//    }
//    i = lmax;
//    j = lmax + len;
}

void Repo::afisare_secv(int i, int j)
{
    for (; i <= j; i++)
    {
        afisare_numar(numere[i]);
    }
    cout<<endl;
}