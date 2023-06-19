#include "passenger.hpp"
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
void passenger::input()
{
    fstream file;
    int id_d, found=0;
    char name_d[32], surname_d[32];
    system("cls");
    cout<<"\n\n\t\t\t***Your ID, Name and Surname is Required***";
    cout<<"\n\nEnter Your ID: ";
    cin>>id;
    cout<<"\n\nEnter Your Name: ";
    cin.sync();
    cin.get(name, 32);
    cout<<"\n\nEnter Your Surname: ";
    cin.sync();
    cin>>surname;
    file.open("user_info.txt", ios::in);
    if(!file)
    {
        file.open("user_info.txt", ios::app|ios::out);
        file<<id<<" "<<name<<" "<<surname<<"\n";
        file.close();
    }
    else
    {
        file>>id_d>>name_d>>surname_d;
        while(!file.eof())
        {
            if(id_d == id)
            {
                found++;
            }
            file>>id_d>>name_d>>surname_d;
        }
        file.close();
        if(found==0)
        {
            file.open("user_info.txt", ios::app|ios::out);
            file<<id<<" "<<name<<" "<<surname<<"\n";
            file.close();
        }
        else
        {
            cout<<"\n\n Duplicate Record Found...";
            getch();
            input();
        }
    }
}
void passenger::output()
{
    system("cls");
    fstream file;
    file.open("user_info.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        file>>id>>name>>surname;
        while(!file.eof())
        {
            cout<<"\n"<<id<<"\t\t"<<name<<"\t\t"<<surname;
            file>>id>>name>>surname;
        }
        file.close();
    }
    getch();
}
