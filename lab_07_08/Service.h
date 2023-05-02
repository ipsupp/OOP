#pragma once
#include "Repo.h"

#ifndef LAB_07_SERVICE_H
#define LAB_07_SERVICE_H

class Service {
private:
    Repo repository;
public:
    Service();
    ~Service();

    // adaugari - done
    void add_current_zi(int suma, char* type);
    void add(int zi, int suma, char* type);

    //modificari - done
    void delete_all_per_zi(int zi);
    void delete_from_to_zi(int zi1,int zi2);
    void delete_by_type(char* type);

    //afisari - done
    void list_all();
    void list_by_type(char* type);
    void list_type_more_than_sum(char* type, int suma);
    void list_type_equal_to_sum(char* type, int suma);

    //proprietati speciale - done
    int list_total_sum_from_type(char* type);
    void list_max_sum_from_zi();
    void list_daily_sums_sorted_desc();
    void list_type_daily_sums_sorted_asc(char* type);

    //filtrari - done
    void filter_type(char* type);
    void filter_type_less_than_sum(char* type, int suma);
    void filter_type_equal_to_sum(char* type, int suma);

    //undo - not done
    Repo create_repo_copy();
    Service& swap_repo_with_copy(Repo repository);



};


#endif //LAB_07_SERVICE_H