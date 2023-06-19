#ifndef PASSENGER_HPP_INCLUDED
#define PASSENGER_HPP_INCLUDED
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
using namespace std;
class passenger
{
protected:
    char name[32], surname[32];
    int id;
public:
    void input();
    void output();
    int get_id()
    {
        return id;
    }
    char *get_name()
    {
        return name;
    }
    char *get_surname()
    {
        return surname;
    }
    void set_id(int id_number)
    {
        id=id_number;
    }
    void set_name(char *n)
    {
        strcpy(name, n);
    }
    void set_surname(char *s)
    {
        strcpy(surname, s);
    }
};


#endif // PASSENGER_HPP_INCLUDED
