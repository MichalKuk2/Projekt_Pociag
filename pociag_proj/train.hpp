#ifndef TRAIN_HPP_INCLUDED
#define TRAIN_HPP_INCLUDED
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
#include "interface.hpp"
using namespace std;
class train
{
    friend class interface;
    friend class ticket;
    friend class routs;
    int t_number, t_seats;
    char t_name[32], t_route[32], t_day[11], t_time[6], t_price[16];
    int get_t_number()
    {
        return t_number;
    }
    char *get_t_name()
    {
        return t_name;
    }
    char *get_t_route()
    {
        return t_route;
    }
    char *get_t_day()
    {
        return t_day;
    }
    char *get_t_time()
    {
        return t_time;
    }
    int get_t_seats()
    {
        return t_seats;
    }
    char *get_t_price()
    {
        return t_price;
    }
    void set_t_number(int tnum)
    {
        t_number=tnum;
    }
    void set_t_name(char *tn)
    {
        strcpy(t_name, tn);
    }
    void set_t_route(char *tr)
    {
        strcpy(t_route, tr);
    }
    void set_t_day(char *td)
    {
        strcpy(t_day, td);
    }
    void set_t_time(char *tt)
    {
        strcpy(t_time, tt);
    }
    void set_t_seats(int ts)
    {
        t_seats=ts;
    }
    void set_t_price(char *tp)
    {
        strcpy(t_price, tp);
    }
    void new_train();
    void view_train();
    void single_view_train();
    void view_all_trains();
    void update_train();
    void del_train();
};


#endif // TRAIN_HPP_INCLUDED
