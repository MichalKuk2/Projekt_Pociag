#include "train.hpp"
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
interface i;
void train::new_train()
{
    fstream file;
    int t_number_d, t_seats_d, found=0;
    char t_name_d[32], t_route_d[32], t_day_d[11], t_time_d[6], t_price_d[16];
    system("cls");
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    cout<<"\n\nTrain Number: ";
    cin.sync();
    cin>>t_number;
    cout<<"\n\nTrain Name: ";
    cin.sync();
    cin.get(t_name, 32);
    cout<<"\n\nTrain Route: ";
    cin.sync();
    cin.get(t_route, 32);
    cout<<"\n\nDate: ";
    cin.sync();
    cin.get(t_day, 11);
    cout<<"\n\nTime: ";
    cin.sync();
    cin.get(t_time, 6);
    cout<<"\n\nTotal Seats: ";
    cin.sync();
    cin>>t_seats;
    cout<<"\n\nTicket Price: ";
    cin.sync();
    cin.get(t_price, 16);
    file.open("train_info.txt", ios::in);
    if(!file)
    {
        file.open("train_info.txt", ios::app|ios::out);
        file<<t_number<<" "<<t_name<<" "<<t_route<<" "<<t_day<<" "<<t_time<<" "<<t_seats<<" "<<t_price<<"\n";
        file.close();
    }
    else
    {
        file>>t_number_d>>t_name_d>>t_route_d>>t_day_d>>t_time_d>>t_seats_d>>t_price_d;
        while(!file.eof())
        {
            if(t_number_d == t_number)
            {
                found++;
            }
            file>>t_number_d>>t_name_d>>t_route_d>>t_day_d>>t_time_d>>t_seats_d>>t_price_d;
        }
        file.close();
        if(found==0)
        {
            file.open("train_info.txt", ios::app|ios::out);
            file<<t_number<<" "<<t_name<<" "<<t_route<<" "<<t_day<<" "<<t_time<<" "<<t_seats<<" "<<t_price<<"\n";
            file.close();
        }
        else
        {
            cout<<"\n\n Duplicate Record Found...";
            getch();
            i.menu();
        }
    }
}
void train::view_train()
{
    int option;
    system("cls");
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    cout<<"\n\n 1. Single Train View";
    cout<<"\n 2. All Trains View";
    cout<<"\n 3. Go Back";
    cout<<"\n\n Enter your Choice: ";
    cin>>option;
    switch(option)
    {
    case 1:
        single_view_train();
        break;
    case 2:
        view_all_trains();
        break;
    case 3:
        i.menu();
    default:
       cout<<"\n\n Invalid Choice...Please Try Again.";
    }
    getch();
    view_train();
}
void train::single_view_train()
{
    system("cls");
    int tr_n;
    fstream file;
    int found=0;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    file.open("train_info.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        cout<<"\n\n Train No. :";
        cin>>tr_n;
        file>>t_number>>t_name>>t_route>>t_day>>t_time>>t_seats>>t_price;
        while(!file.eof())
        {
            if(tr_n==t_number)
            {
                system("cls");
                cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
                cout<<"\n\nTrain No."<<setw(32)<<"Train Name"<<setw(32)<<"Train Route"<<setw(32)<<"Day"<<setw(32)<<"Time"<<setw(32)<<"No. of Seats"<<setw(32)<<"Ticket Price";
                cout<<"\n"<<t_number<<setw(32)<<t_name<<setw(32)<<t_route<<setw(32)<<t_day<<setw(32)<<t_time<<setw(32)<<t_seats<<setw(32)<<t_price;
                found++;
            }
            file>>t_number>>t_name>>t_route>>t_day>>t_time>>t_seats>>t_price;
        }
        file.close();
        if(found ==0)
        {
            cout<<"\n\n Invalid Train No. ...";
        }
    }
}
void train::view_all_trains()
{
    system("cls");
    fstream file;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    file.open("train_info.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        cout<<"\n\nTrain No."<<setw(32)<<"Train Name"<<setw(32)<<"Train Route"<<setw(32)<<"Day"<<setw(32)<<"Time"<<setw(32)<<"No. of Seats"<<setw(32)<<"Ticket Price";
        file>>t_number>>t_name>>t_route>>t_day>>t_time>>t_seats>>t_price;
        while(!file.eof())
        {
            cout<<"\n"<<t_number<<setw(32)<<t_name<<setw(32)<<t_route<<setw(32)<<t_day<<setw(32)<<t_time<<setw(32)<<t_seats<<setw(32)<<t_price;
            file>>t_number>>t_name>>t_route>>t_day>>t_time>>t_seats>>t_price;
        }
        file.close();
    }
}
void train::update_train()
{
    system("cls");
    int t_number_d, t_seats_d, found=0;
    char t_name_d[32], t_route_d[32], t_day_d[11], t_time_d[6], t_price_d[16];
    fstream file, temp;
    int t_n;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    file.open("train_info.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        cout<<"\n\nEnter Train Number To Edit: ";
        cin>>t_n;
        file>>t_number>>t_name>>t_route>>t_day>>t_time>>t_seats>>t_price;
        temp.open("temp_train.txt", ios::app|ios::out);
        while(!file.eof())
        {
            if(t_n==t_number)
            {
                cout<<"\n\nNew Train Number: ";
                cin.sync();
                cin>>t_number_d;
                cout<<"\n\nNew Train Name: ";
                cin.sync();
                cin.get(t_name_d, 32);
                cout<<"\n\nNew Train Route: ";
                cin.sync();
                cin.get(t_route_d, 32);
                cout<<"\n\nNew Date: ";
                cin.sync();
                cin.get(t_day_d, 11);
                cout<<"\n\nNew Time: ";
                cin.sync();
                cin.get(t_time_d, 6);
                cout<<"\n\nNew Total Seats: ";
                cin.sync();
                cin>>t_seats_d;
                cout<<"\n\nNew Ticket Price: ";
                cin.sync();
                cin.get(t_price_d, 16);
                temp<<t_number_d<<" "<<t_name_d<<" "<<t_route_d<<" "<<t_day_d<<" "<<t_time_d<<" "<<t_seats_d<<" "<<t_price_d<<"\n";
                cout<<"\n\nRecord Updated Successfully...";
                found++;
            }
            else
            {
                temp<<t_number<<" "<<t_name<<" "<<t_route<<" "<<t_day<<" "<<t_time<<" "<<t_seats<<" "<<t_price<<"\n";
            }
            file>>t_number>>t_name>>t_route>>t_day>>t_time>>t_seats>>t_price;
        }
        file.close();
        temp.close();
        remove("train_info.txt");
        rename("temp_train.txt", "train_info.txt");
        if(found==0)
        {
            cout<<"\n\nTrain No. is Invalid...";
        }
    }
}
void train::del_train()
{
    system("cls");
    int t_n, found=0;
    fstream file, temp;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    file.open("train_info.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        cout<<"\n\nEnter Train Number To Delete: ";
        cin>>t_n;
        file>>t_number>>t_name>>t_route>>t_day>>t_time>>t_seats>>t_price;
        temp.open("temp_train.txt", ios::app|ios::out);
        while(!file.eof())
        {
            if(t_n==t_number)
            {
                cout<<"\n\nRecord Deleted Successfully...";
                found++;
            }
            else
            {
                temp<<t_number<<" "<<t_name<<" "<<t_route<<" "<<t_day<<" "<<t_time<<" "<<t_seats<<" "<<t_price<<"\n";
            }
            file>>t_number>>t_name>>t_route>>t_day>>t_time>>t_seats>>t_price;
        }
        file.close();
        temp.close();
        remove("train_info.txt");
        rename("temp_train.txt", "train_info.txt");
        if(found==0)
        {
            cout<<"\n\nTrain No. is Invalid...";
        }
    }
}
