#include "NumarComplex.h"
#include <iostream>
#include <cmath>
int NumarComplex::get_pr()
{
    return this->parte_reala;
}

void NumarComplex::set_pr(float x)
{
    this->parte_reala = x;
}

int NumarComplex::get_pc()
{
    return this->parte_complexa;
}

void NumarComplex::set_pc(float x)
{
    this->parte_complexa= x;
}

NumarComplex::NumarComplex()
{
    this->parte_reala = 0;
    this->parte_complexa = 0;
}

NumarComplex::NumarComplex(float x, float y)
{
    this->parte_reala = x;
    this->parte_complexa = y;
}

NumarComplex::NumarComplex(const NumarComplex &m)
{
    this->parte_reala = m.parte_reala;
    this->parte_complexa = m.parte_complexa;
}

//deconstructor vvv
NumarComplex::~NumarComplex()
{
    this->parte_reala = 0;
    this->parte_complexa = 0;
}

void NumarComplex::adunare(const NumarComplex n, const NumarComplex m)
{
    float a,b;
    a = n.parte_reala + m.parte_reala;
    b = n.parte_complexa + m.parte_complexa;
    if (b>0)
        std:: cout<<a<<"+"<<b<<"i"<<std::endl;
    else std:: cout<<a<<b<<"i"<<std::endl;
}

void NumarComplex::scadere(const NumarComplex n, const NumarComplex m)
{
    float a,b;
    a = n.parte_reala - m.parte_reala;
    b = n.parte_complexa - m.parte_complexa;
    if (b>0)
        std:: cout<<a<<"+"<<b<<"i"<<std::endl;
    else std:: cout<<a<<b<<"i"<<std::endl;
}

void NumarComplex::inmultire(const NumarComplex n, const NumarComplex m)
{
    float a,b,c,d;
    a = n.parte_reala * m.parte_reala;
    b = n.parte_complexa * m.parte_complexa;
    c = n.parte_reala * m.parte_complexa;
    d = n.parte_complexa * m.parte_reala;
    if (c+d>0)
        std:: cout<<a-b<<"+"<<c+d<<"i"<<std::endl;
    else std:: cout<<a-b<<c+d<<"i"<<std::endl;
}

int NumarComplex::modul(const NumarComplex n)
{
    float a;
    a = n.parte_reala * n.parte_reala + n.parte_complexa * n.parte_complexa;
    return sqrt(a);
}