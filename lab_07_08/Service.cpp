#include "Service.h"
using namespace std;
Service::Service() {}

Service::~Service() {}

Repo Service::create_repo_copy()
{
    Cheltuiala* all_ch = repository.get_all();
    int size = repository.get_size();

    Cheltuiala* copied_ch = new Cheltuiala[size];

    for (int i = 0; i<size; i++)
    {
        copied_ch[i].set_ziua(all_ch[i].get_ziua());
        copied_ch[i].set_suma(all_ch[i].get_suma());
        copied_ch[i].set_type(all_ch[i].get_type());
    }

    Repo repo_copy;
    for (int i = 0; i<size;i++)
        repo_copy.add_cheltuieli(copied_ch[i]);

    return repo_copy;
}

Service& Service::swap_repo_with_copy(Repo repository)
{
    int new_size = repository.get_size();
    repository.swap_repos(repository,new_size);
}

void Service::add(int zi, int suma, char *type)
{
    repository.add_cheltuieli_zi_suma_type(zi,suma,type);
}

void Service::add_current_zi(int suma, char* type)
{
    repository.add_cheltuieli_zi_curenta(suma, type);
}

void Service::delete_all_per_zi(int zi)
{
    repository.stergere_cheltuiala_dupa_zi(zi);
}

void Service::delete_from_to_zi(int zi1, int zi2)
{
    for (zi1=zi1; zi1<=zi2; zi1++)
        repository.stergere_cheltuiala_dupa_zi(zi1);
}

void Service::delete_by_type(char *type)
{
    repository.stergere_cheltuiala_dupa_type(type);
}

void Service::list_all()
{
    repository.afisare_cheltuieli();
}

void Service::list_by_type(char *type)
{
    repository.afisare_cheltuieli_type(type);
}

void Service::list_type_more_than_sum(char *type, int suma)
{
    repository.afisare_cheltuieli_type_mmare_suma(type,suma);
}

void Service::list_type_equal_to_sum(char *type, int suma)
{
    repository.afisare_cheltuieli_type_suma(type,suma);
}

int Service::list_total_sum_from_type(char *type)
{
    return repository.suma_totala_type(type);
}

void Service::list_max_sum_from_zi()
{
    repository.ziua_suma_totala_max();
}

void Service::list_daily_sums_sorted_desc()
{
    repository.sortare_zilnic_descr();
}

void Service::list_type_daily_sums_sorted_asc(char* type)
{
    repository.sortare_zilnica_type_cresc(type);
}

void Service::filter_type(char *type)
{
    repository.filtrare_type(type);
}

void Service::filter_type_less_than_sum(char *type, int suma)
{
    repository.filtrare_type_mai_mica_suma(type, suma);
}

void Service::filter_type_equal_to_sum(char *type, int suma)
{
    repository.filtrare_type_suma_fixa(type, suma);
}


