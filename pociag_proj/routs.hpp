#ifndef ROUTS_HPP_INCLUDED
#define ROUTS_HPP_INCLUDED
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
class routs
{
    friend class interface;
    string r_routs;
public:
    void show_routs();
};

#endif // ROUTS_HPP_INCLUDED
