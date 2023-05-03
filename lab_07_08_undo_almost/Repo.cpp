#include "Repo.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <chrono>
using namespace std;
Repo::Repo()
{
    this->nr_ch = 0;
}

Repo::~Repo() {}

Repo& Repo::set_size(int new_size)
{
    this->nr_ch = new_size;
}

Repo& Repo::swap_repos(Repo repository, int new_size)
{
    Cheltuiala *repo_copy = repository.get_all();
    set_size(new_size);
    for (int i=0; i<101; i++)
    {
        cheltuieli[i].set_ziua(0);
        cheltuieli[i].set_suma(0);
        cheltuieli[i].set_type("blank");
    }

    for (int i=0; i<nr_ch; i++)
    {
        int a = repo_copy->get_ziua(),b = repo_copy->get_suma();
        char *c =  repo_copy->get_type();
        Cheltuiala ch(a,b,c);
        this->cheltuieli[i] = ch;
    }

//    for (int i = 0; i < nr_ch; i++)
//    {s
//        cheltuieli[i].set_ziua(repo_copy[i].get_ziua());
//        cheltuieli[i].set_suma(repo_copy[i].get_suma());
//        char *c = repo_copy[i].get_type();
//        cheltuieli[i].set_type(c);
//        strcpy(c, repo_copy[i].get_type());
//        cheltuieli[i].set_type(c);
//
//
//        Cheltuiala *copy = repository.get_all();
//        set_size(new_size);
//
//        for (int i = 0; i < nr_ch; i++)
//        {
//            int a = copy[i].get_ziua();
//            int b = copy[i].get_suma();
//            char c[101];
//            strcpy(c, copy[i].get_type());
//            cheltuieli[i].set_ziua(a);
//            cheltuieli[i].set_suma(b);
//            cheltuieli[i].set_type(c);
//        }
//        for (int i = nr_ch; i < 100; i++)
//        {
//            cheltuieli[i].set_ziua(0);
//            cheltuieli[i].set_suma(0);
//            cheltuieli[i].set_type(nullptr);
//        }
//    }
}


void Repo::add_cheltuieli_zi_suma_type(int zi, int suma, char *type)
{
    Cheltuiala ch;
    ch.set_ziua(zi);
    ch.set_suma(suma);
    ch.set_type(type);

    this->cheltuieli[this->nr_ch] = ch;
    this->nr_ch++;
    //    Cheltuiala ch(zi,suma,type);
//    add_cheltuieli(ch);
}

void Repo::add_cheltuieli(const Cheltuiala &c)
{
    this->cheltuieli[this->nr_ch] = c;
    this->nr_ch++;
}

void Repo::add_cheltuieli_zi_curenta(int suma, char e[])
{
    chrono::system_clock::time_point now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    tm* data = localtime(&time);
    int zi = data->tm_mday;

    Cheltuiala ch;
    ch.set_suma(suma);
    ch.set_type(e);
    ch.set_ziua(zi);

    this->cheltuieli[this->nr_ch] = ch;
    this->nr_ch++;

}

int Repo::get_size()
{
    return this->nr_ch;
}

Cheltuiala* Repo::get_all()
{
    return cheltuieli;
}

void Repo::afisare_cheltuiala(Cheltuiala c)
{
    cout<<"Ziua: "<<c.get_ziua()<<" ; "<<"Suma: "<<c.get_suma()<<" ; "<<"Tipul: "<<c.get_type()<<endl;
}

void Repo::afisare_cheltuieli()
{
    for (int i = 0; i < nr_ch; i++) {
        afisare_cheltuiala(cheltuieli[i]);
    }
}

void Repo::afisare_cheltuieli_type(char e[])
{
    for (int i = 0; i < nr_ch; i++)
        if (strcmp(cheltuieli[i].get_type(),e) == 0)
        {
            afisare_cheltuiala(cheltuieli[i]);
        }
}

void Repo::afisare_cheltuieli_type_suma(char e[], int suma)
{
    for (int i = 0; i < nr_ch; i++)
        if (strcmp(cheltuieli[i].get_type(),e) == 0 and cheltuieli[i].get_suma() == suma)
        {
            afisare_cheltuiala(cheltuieli[i]);
        }
}

void Repo::afisare_cheltuieli_type_mmare_suma(char e[], int suma)
{
    for (int i = 0; i < nr_ch; i++)
        if (strcmp(cheltuieli[i].get_type(),e) == 0 and cheltuieli[i].get_suma() > suma)
        {
            afisare_cheltuiala(cheltuieli[i]);
        }
}


Repo& Repo::sortare_dupa_zi()
{
    for (int i=0; i< nr_ch; i++)
    {
        for (int j=i;j<nr_ch;j++)
            if (cheltuieli[i].get_ziua()>cheltuieli[j].get_ziua())
                swap(cheltuieli[i],cheltuieli[j]);
    }
}

Repo& Repo::stergere_cheltuiala_dupa_zi(int zi)
{
    for(int i=0;i<nr_ch;i++)
    {
        if (cheltuieli[i].get_ziua() == zi)
        {
            for(int j=i;j<nr_ch-1;j++)
            {
                swap(cheltuieli[j],cheltuieli[j+1]);
            }
            nr_ch--;
            i--;
        }
    }
}

Repo& Repo::stergere_cheltuiala_dupa_type(char *type)
{
    for(int i=0;i<nr_ch;i++)
    {
        if (strcmp(cheltuieli[i].get_type(),type) == 0)
        {
            for(int j=i;j<nr_ch-1;j++)
            {
                swap(cheltuieli[j],cheltuieli[j+1]);
            }
            nr_ch--;
            i--;
        }
    }

}

int Repo::suma_totala_type(char *e)
{
    int s = 0;
    for(int i=0;i<nr_ch;i++)
        if (strcmp(cheltuieli[i].get_type(),e) == 0)
            s = s + cheltuieli[i].get_suma();
    return s;
}

void Repo::ziua_suma_totala_max()
{
    int maxx_sum = -1,maxx_day = 0;
    Cheltuiala all_ch[100];

    for (int i = 0;i<nr_ch;i++)
        all_ch[i] = cheltuieli[i];

    for (int i=0; i< nr_ch; i++)
        for (int j=i;j<nr_ch;j++)
            if (all_ch[i].get_ziua()>all_ch[j].get_ziua())
                swap(all_ch[i],all_ch[j]);

    int sume[31] ={0};
    for (int zi = 1; zi <= 31; zi++)
    {
        for (int i = 0; i< nr_ch;i++)
            if(all_ch[i].get_ziua() == zi)
                sume[zi] = sume[zi] + all_ch[i].get_suma();
    }

    for (int i = 1; i<=31; i++)
        if (sume[i]>maxx_sum)
        {
            maxx_sum = sume[i];
            maxx_day = i;
        }
//    cout<<endl;
    cout<<maxx_day<<" este ziua cu cele mai mari cheltuieli - "<<maxx_sum<<endl;
}

void Repo::sortare_zilnic_descr()
{
    Cheltuiala all_ch[100];
    for (int i = 0;i<nr_ch;i++)
        all_ch[i] = cheltuieli[i];

    for (int i=0; i< nr_ch; i++)
        for (int j=i;j<nr_ch;j++)
            if (all_ch[i].get_ziua()>all_ch[j].get_ziua())
                swap(all_ch[i],all_ch[j]);

    int sume[33] ={0};
    for (int zi = 1; zi <= 31; zi++)
    {
        for (int i = 0; i< nr_ch;i++)
            if(all_ch[i].get_ziua() == zi)
                sume[zi] = sume[zi] + all_ch[i].get_suma();
    }
    int zi2=0;
    for (int zi = 1; zi <= 31; zi++)
    {
        if (sume[zi] != 0)
            zi2++;
    }
    while (zi2)
    {
        int maxx=-1, index = 0;
        for (int zi = 1; zi <= 31; zi++)
        {
            if (sume[zi] != 0 and sume[zi]>maxx)
            {
                maxx = sume[zi];
                index = zi;
            }
        }
        if (index!=0)
            cout<<"In ziua "<<index<<" s-au cheltuit "<<maxx<< " RON"<<endl;
        zi2--;
        sume[index] = 0;
    }
}

void Repo::sortare_zilnica_type_cresc(char e[])
{
    char *type = e;
    Cheltuiala all_ch[100];
    int k=0;
    for (int i = 0;i<nr_ch;i++)
        if (strcmp(cheltuieli[i].get_type(),type) == 0)
        {
            all_ch[k] = cheltuieli[i];
            k++;
        }

    for (int i=0; i< nr_ch; i++)
        for (int j=i;j<nr_ch;j++)
            if (all_ch[i].get_ziua()>all_ch[j].get_ziua())
                swap(all_ch[i],all_ch[j]);

    int sume[31] ={0};
    for (int zi = 1; zi <= 31; zi++)
    {
        for (int i = 0; i< nr_ch;i++)
            if(all_ch[i].get_ziua() == zi)
                sume[zi] = sume[zi] + all_ch[i].get_suma();
    }

    int zi2=0,zi;
    for (int zi = 1; zi <= 31; zi++)
    {
        if (sume[zi] != 0)
            zi2++;
    }


    while (zi2)
    {
        int minn = 2147483647, index = 0;
        for (zi =1; zi<=31;zi++ )
        {
            if (sume[zi]!=0 and sume[zi] < minn)
            {
                minn = sume[zi];
                index = zi;
            }
        }
        if (index!=0)
            cout<<"In ziua "<<index<<" s-au cheltuit "<<minn<<" RON pe "<<type<<endl;
        zi2--;
        sume[index] = 2147483647;
    }
}


Repo& Repo::sterge_cheltuiala(int zi, int suma, char type[])
{
    for(int i=0;i<nr_ch;i++)
    {
        if (cheltuieli[i].get_ziua() == zi and cheltuieli[i].get_suma() == suma)
            if (strcmp(cheltuieli[i].get_type(), type) == 0)
            {
                for(int j=i;j<nr_ch-1;j++)
                {
                    swap(cheltuieli[j],cheltuieli[j+1]);
                }
                nr_ch--;
                i--;
            }
    }
}

Repo& Repo::undo(int zi, int suma, char type[])
{}


Repo& Repo::filtrare_type(char e[])
{
    char* type = e;
    for (int i=0; i< nr_ch; i++)
    {
        int a = cheltuieli[i].get_ziua();
        int b = cheltuieli[i].get_suma();
        char* c = cheltuieli[i].get_type();
        if (strcmp(type,c) != 0)
        {
            sterge_cheltuiala(a,b,c);
            i--;
        }
    }
}

Repo& Repo::filtrare_type_mai_mica_suma(char e[], int suma)
{
    char* type = e;
    for (int i=0; i < nr_ch; i++)
    {
        int a = cheltuieli[i].get_ziua();
        int b = cheltuieli[i].get_suma();
        char* c = cheltuieli[i].get_type();
        if (strcmp(type,c) != 0 or b >= suma)
        {
            sterge_cheltuiala(a,b,c);
            i--;
        }
    }
}

Repo& Repo::filtrare_type_suma_fixa(char e[], int suma)
{
    char* type = e;
    for (int i=0; i < nr_ch; i++)
    {
        int a = cheltuieli[i].get_ziua();
        int b = cheltuieli[i].get_suma();
        char* c = cheltuieli[i].get_type();
        if (strcmp(type,c) != 0 or b != suma)
        {
            sterge_cheltuiala(a,b,c);
            i--;
        }
    }
}