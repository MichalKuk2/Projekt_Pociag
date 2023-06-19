#ifndef TICKET_HPP_INCLUDED
#define TICKET_HPP_INCLUDED
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <string.h>
#include "train.hpp"
using namespace std;
class ticket
{
    friend class interface;
    int platform, seat;
    string name_of_passenger, surname_of_passenger;
    char Type[6], From[32], To[32], valid_at[6], day_dep[11];
public:
    char *get_Type()
    {
        return Type;
    }
    char *get_from()
    {
        return From;
    }
    char *get_to()
    {
        return To;
    }
    char *get_departure()
    {
        return day_dep;
    }
    int get_platform()
    {
        return platform;
    }
    char *get_valid_at()
    {
        return valid_at;
    }
    int get_seat()
    {
        return seat;
    }
    void set_type(char *tp)
    {
        strcpy(Type, tp);
    }
    void set_from(char *f)
    {
        strcpy(From, f);
    }
    void set_to(char *T)
    {
        strcpy(To, T);
    }
    void set_departure(char *dep)
    {
        strcpy(day_dep, dep);
    }
    void set_platform(int pl)
    {
        platform=pl;
    }
    void set_valid_at(char *v)
    {
        strcpy(valid_at, v);
    }
    void set_seat(int s)
    {
        seat=s;
    }
    void detail_train();
    void booking();
    void seats_reset();
    void search_booking();
    void delete_booking();
    void view_all_booking();
};

#endif // TICKET_HPP_INCLUDED
