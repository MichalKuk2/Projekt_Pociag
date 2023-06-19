#include "routs.hpp"
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
void routs::show_routs()
{
    train t;
    system("cls");
    fstream file;
    file.open("train_info.txt",ios::in);
    cout<<"\n\n\t\t\tAll Routs of Trains";
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        file>>t.t_number>>t.t_name>>r_routs>>t.t_day>>t.t_time>>t.t_seats>>t.t_price;
        while(!file.eof())
        {
            cout<<"\n"<<r_routs;
            file>>t.t_number>>t.t_name>>r_routs>>t.t_day>>t.t_time>>t.t_seats>>t.t_price;
        }
        file.close();
    }
    getch();
}
