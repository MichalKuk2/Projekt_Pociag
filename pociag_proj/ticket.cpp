#include "ticket.hpp"
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
train t;
ticket tk;
interface in;
void ticket::detail_train()
{
    system("cls");
    fstream file, file1;
    int t_no, s_t_no, s_no;
    int counter=0, found=0;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    file.open("train_info.txt", ios::in);
    file1.open("seats_info.txt", ios::in);
    if(!file || !file1)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        cout<<"\n\nTrain Number: ";
        cin>>t_no;
        file1>>s_t_no>>s_no;
        while(!file1.eof())
        {
            if(t_no==s_t_no)
            {
                counter++;
            }
            file1>>s_t_no>>s_no;
        }
        file1.close();
        file>>t.t_number>>t.t_name>>t.t_route>>t.t_day>>t.t_time>>t.t_seats>>t.t_price;
        while(!file.eof())
        {
            if(t_no==t.t_number)
            {
                system("cls");
                cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
                cout<<"\n\nTotal No. of Seats: "<<t.t_seats;
                cout<<"\n\nReserved No. of Seats: "<<counter;
                cout<<"\n\nEmpty No. of Seats: "<<t.t_seats-counter;
                found++;
            }
            file>>t.t_number>>t.t_name>>t.t_route>>t.t_day>>t.t_time>>t.t_seats>>t.t_price;
        }
        file.close();
        if(found == 0)
        {
            cout<<"\n\nTrain No. is Invalid...";
        }
    }
}
void ticket::booking()
{
    vector<string>names;
    vector<string>surnames;
    system("cls");
    fstream file, pom;
    string customer_name, customer_surname, ticket_id;
    int found=0, s_n, t_no, seats, counter=0, s_s_no, s_t_no, re[100], it=0, s_amount, total_amount;
    char x;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    file.open("train_info.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        cout<<"\n\nTrain Number: ";
        cin>>t_no;
        file.close();
        file.open("seats_info.txt", ios::in);
        file>>s_t_no>>s_s_no;
        while(!file.eof())
        {
             if(t_no==s_t_no)
             {
                 counter++;
             }
             file>>s_t_no>>s_s_no;
        }
        file.close();
        file.open("train_info.txt", ios::in);
        file>>t.t_number>>t.t_name>>t.t_route>>t.t_day>>t.t_time>>t.t_seats>>t.t_price;
        while(!file.eof())
        {
            if(t_no==t.t_number)
            {
                seats=t.t_seats;
                found++;
            }
            file>>t.t_number>>t.t_name>>t.t_route>>t.t_day>>t.t_time>>t.t_seats>>t.t_price;
        }
        file.close();
        if(seats-counter==0)
        {
            cout<<"\n\nNo Free seats on the Train...";
        }
        else if(found==1)
        {
            do
            {
                cout<<"\n\nSeat No. : ";
                cin>>s_n;
                if(s_n>seats)
                {
                    cout<<"\n\nSeat No. is Invalid...Please Try Again...";
                    getch();
                    in.menu();
                }
                file.open("seats.txt, ios::in");
                if(!file)
                {
                    file.open("seats_info.txt", ios::app|ios::out);
                    file<<t_no<<" "<<s_n<<"\n";
                    file.close();
                }
                else
                {
                    file>>s_t_no>>s_s_no;
                    while(!file.eof())
                    {
                        if(t_no==s_t_no && s_n == s_s_no)
                        {
                            cout<<"\n\nThis Seat is Already Reserved...Please Try Again...";
                            file.close();
                            getch();
                            in.menu();
                        }
                        file>>s_t_no>>s_s_no;
                    }
                    file.close();
                }
                re[it]=s_n;
                it++;
                cout<<"\n\nBooking another(Y/N)?: ";
                cin>>x;
            }
            while(x=='Y' || x=='y');
            system("cls");
            pom.open("user_info.txt", ios::in);
            if(!pom)
            {
                cout<<"\n\n Error. Cannot Open Source File... ";
            }
            else
            {
                pom>>ticket_id>>name_of_passenger>>surname_of_passenger;
                names.push_back(name_of_passenger);
                surnames.push_back(surname_of_passenger);
                while(!pom.eof())
                {
                    pom>>ticket_id>>name_of_passenger>>surname_of_passenger;
                    names.push_back(name_of_passenger);
                    surnames.push_back(surname_of_passenger);
                }
                cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
                cout<<"\n\nCustomer Name: ";
                cin>>customer_name;
                cout<<"\nCustomer Surname: ";
                cin>>customer_surname;
                if(find(names.begin(), names.end(), customer_name)!=names.end() && find(surnames.begin(), surnames.end(), customer_surname)!=surnames.end() )
                {
                    ptrdiff_t posN=find(names.begin(), names.end(), customer_name) - names.begin();
                    ptrdiff_t posS=find(surnames.begin(), surnames.end(), customer_surname) - surnames.begin();
                    if(posN==posS)
                    {
                        cout<<"\nAdult/Child: ";
                        cin.sync();
                        cin.get(Type, 6);
                        cout<<"\nFrom: ";
                        cin.sync();
                        cin.get(From, 32);
                        cout<<"\nTo: ";
                        cin.sync();
                        cin.get(To, 32);
                        cout<<"\nDeparture Date: ";
                        cin.sync();
                        cin.get(day_dep, 11);
                        cout<<"\nDeparture Time: ";
                        cin.sync();
                        cin.get(valid_at, 6);
                        cout<<"\nPlatform: ";
                        cin.sync();
                        cin>>platform;
                        cout<<"\nSingle Seat Amount: ";
                        cin>>s_amount;
                        total_amount=it*s_amount;
                        cout<<"\nTotal Amount: "<<total_amount;
                        file.open("customer.txt", ios::app|ios::in);
                        file<<customer_name<<" "<<customer_surname<<" "<<t_no<<" "<<Type<<" "<<From<<" "<<To<<" "<<day_dep<<" "<<valid_at<<" "<<platform<<" "<<it<<" "<<total_amount<<"\n";
                        file.close();
                        system("cls");
                        cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
                        cout<<"\n\n\t\t***************************************";
                        cout<<"\n\n\t\t_________BOOKING INFORMATION_________";
                        cout<<"\n\n\t\t***************************************";
                        cout<<"\n\n\t\tCustomer Name: "<<customer_name;
                        cout<<"\n\n\t\tCustomer Surname: "<<customer_surname;
                        cout<<"\n\n\t\tAdult/Child: "<<Type;
                        cout<<"\n\n\t\tFrom: "<<From;
                        cout<<"\n\n\t\tTo: "<<To;
                        cout<<"\n\n\t\tDeparture Date: "<<day_dep;
                        cout<<"\n\n\t\tDeparture Time: "<<valid_at;
                        cout<<"\n\n\t\tPlatform: "<<platform;
                        cout<<"\n\n\t\tTotal Seats: "<<it;
                        cout<<"\n\n\t\tReserved Seats: ";
                        for(int u=0; u<it; u++)
                        {
                            if(u!=0)
                            {
                                cout<<", ";
                            }
                            cout<<re[u];
                        }
                        cout<<"\n\n\t\tSingle Seat Amount: "<<s_amount;
                        cout<<"\n\n\t\tTotal Amount: "<<total_amount;
                        cout<<"\n\n\t\t***************************************";
                        cout<<"\n\n\t\t_________Thank You for booking_________";
                        cout<<"\n\n\t\t***************************************";
                    }
                    else
                    {
                        cout<<"\n\nWrong Name or Surname of Customer...Please Try again...";
                        getch();
                        in.menu();
                    }
                }
                else
                {
                    cout<<"\n\nWrong Name or Surname of Customer...Please Try again...";
                    getch();
                    in.menu();
                }
            }
            pom.close();
        }
        else
        {
            cout<<"\n\nTrain No. is Invalid...";
            getch();
            booking();
        }
    }
}
void ticket::seats_reset()
{
    fstream file;
    char x;
    system("cls");
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    cout<<"\n\n\t\tDo You Want to Clear All Reservations (Y,N)?: ";
    cin>>x;
    if(x=='Y' || x=='y')
    {
        file.open("seats_info.txt", ios::out | ios::trunc);
        if(!file)
        {
            cout<<"\n\n Error. Cannot Open Source File... ";
        }
        else
        {
            cout<<"\n\n\t\tAll Seats Records Has Been Cleared...";
        }
        file.close();
    }
    else
    {
        getch();
        in.menu();
    }
}
void ticket::search_booking()
{
    vector<string>names;
    vector<string>surnames;
    system("cls");
    fstream file, pom;
    string sur, nam, c_name, c_surname, c_type, c_From, c_To, c_day_dep, c_valid_at, c_platform;
    int found=0, c_it, c_total_amount, c_n;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    file.open("customer.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        cout<<"\n\nPassenger Name: ";
        cin>>nam;
        cout<<"\n\nPassenger Surname: ";
        cin>>sur;
        pom.open("customer.txt", ios::in);
        pom>>c_name>>c_surname>>c_n>>c_type>>c_From>>c_To>>c_day_dep>>c_valid_at>>c_platform>>c_it>>c_total_amount;
        names.push_back(c_name);
        surnames.push_back(c_surname);
        while(!pom.eof())
        {
            pom>>c_name>>c_surname>>c_n>>c_type>>c_From>>c_To>>c_day_dep>>c_valid_at>>c_platform>>c_it>>c_total_amount;
            names.push_back(c_name);
            surnames.push_back(c_surname);
        }
        while(!file.eof())
        {
            if(find(names.begin(), names.end(), c_name)!=names.end() && find(surnames.begin(), surnames.end(), c_surname)!=surnames.end())
            {
                ptrdiff_t posN=find(names.begin(), names.end(), nam) - names.begin();
                ptrdiff_t posS=find(surnames.begin(), surnames.end(), sur) - surnames.begin();
                if(posN==posS)
                {
                    if(nam==c_name && sur==c_surname)
                    {
                        system("cls");
                        cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
                        cout<<"\n\nPassenger Name: "<<c_name;
                        cout<<"\n\nPassenger Surname: "<<c_surname;
                        cout<<"\n\nTrain Number: "<<c_n;
                        cout<<"\n\nAdult/Child: "<<c_type;
                        cout<<"\n\nFrom: "<<c_From;
                        cout<<"\n\nTo: "<<c_To;
                        cout<<"\n\nDeparture Date: "<<c_day_dep;
                        cout<<"\n\nDeparture Time: "<<c_valid_at;
                        cout<<"\n\nPlatform: "<<c_platform;
                        cout<<"\n\nReserved Seats: "<<c_it;
                        cout<<"\n\nTotal Amount: "<<c_total_amount;
                        found++;
                    }
                }
            }
            file>>c_name>>c_surname>>c_n>>c_type>>c_From>>c_To>>c_day_dep>>c_valid_at>>c_platform>>c_it>>c_total_amount;
        }
        pom.close();
        file.close();
        if(found == 0)
        {
            cout<<"\n\nPassenger Name or Surname is Invalid...";
        }
    }
}
void ticket::delete_booking()
{
    vector<string>names;
    vector<string>surnames;
    system("cls");
    fstream file, pom, temp;
    string sur, nam;
    int found=0, c_it, c_total_amount, c_n;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    file.open("customer.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        cout<<"\n\nEnter Name and Surname to Delete Booking Record";
        cout<<"\n\nPassenger Name: ";
        cin>>nam;
        cout<<"\n\nPassenger Surname: ";
        cin>>sur;
        pom.open("customer.txt", ios::in);
        pom>>name_of_passenger>>surname_of_passenger>>c_n>>Type>>From>>To>>day_dep>>valid_at>>platform>>c_it>>c_total_amount;
        names.push_back(name_of_passenger);
        surnames.push_back(surname_of_passenger);
        while(!pom.eof())
        {
            pom>>name_of_passenger>>surname_of_passenger>>c_n>>Type>>From>>To>>day_dep>>valid_at>>platform>>c_it>>c_total_amount;
            names.push_back(name_of_passenger);
            surnames.push_back(surname_of_passenger);
        }
        temp.open("temp_customer.txt", ios::app|ios::out);
        while(!file.eof())
        {
            if(find(names.begin(), names.end(), name_of_passenger)!=names.end() && find(surnames.begin(), surnames.end(), surname_of_passenger)!=surnames.end())
            {
                ptrdiff_t posN=find(names.begin(), names.end(), nam) - names.begin();
                ptrdiff_t posS=find(surnames.begin(), surnames.end(), sur) - surnames.begin();
                if(posN==posS)
                {
                    if(nam==name_of_passenger && sur==surname_of_passenger)
                    {
                        cout<<"\n\nRecord Deleted Successfully...";
                        found++;
                    }
                    else
                    {
                        temp<<name_of_passenger<<" "<<surname_of_passenger<<" "<<c_n<<" "<<Type<<" "<<From<<" "<<To<<" "<<day_dep<<" "<<valid_at<<" "<<platform<<" "<<c_it<<" "<<c_total_amount<<"\n";
                    }
                }
            }
            file>>name_of_passenger>>surname_of_passenger>>c_n>>Type>>From>>To>>day_dep>>valid_at>>platform>>c_it>>c_total_amount;
        }
        pom.close();
        file.close();
        temp.close();
        remove("customer.txt");
        rename("temp_customer.txt", "customer.txt");
        if(found == 0)
        {
            cout<<"\n\nPassenger Name or Surname is Invalid...";
        }
    }
}
void ticket::view_all_booking()
{
    system("cls");
    fstream file;
    string sur, nam, c_name, c_surname, c_type, c_From, c_To, c_day_dep, c_valid_at, c_platform;
    int c_it, c_total_amount, c_n;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    file.open("customer.txt", ios::in);
    if(!file)
    {
        cout<<"\n\n Error. Cannot Open Source File... ";
    }
    else
    {
        file>>c_name>>c_surname>>c_n>>c_type>>c_From>>c_To>>c_day_dep>>c_valid_at>>c_platform>>c_it>>c_total_amount;
        while(!file.eof())
        {
            cout<<"\n\nPassenger Name: "<<c_name;
            cout<<"\n\nPassenger Surname: "<<c_surname;
            cout<<"\n\nTrain Number: "<<c_n;
            cout<<"\n\nAdult/Child: "<<c_type;
            cout<<"\n\nFrom: "<<c_From;
            cout<<"\n\nTo: "<<c_To;
            cout<<"\n\nDeparture Date: "<<c_day_dep;
            cout<<"\n\nDeparture Time: "<<c_valid_at;
            cout<<"\n\nPlatform: "<<c_platform;
            cout<<"\n\nReserved Seats: "<<c_it;
            cout<<"\n\nTotal Amount: "<<c_total_amount;
            cout<<"\n\n=================================";
            file>>c_name>>c_surname>>c_n>>c_type>>c_From>>c_To>>c_day_dep>>c_valid_at>>c_platform>>c_it>>c_total_amount;
        }
        file.close();
    }
}
