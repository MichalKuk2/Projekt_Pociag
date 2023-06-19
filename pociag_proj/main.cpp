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
#include "passenger.hpp"
#include "train.hpp"
#include "interface.hpp"
#include "routs.hpp"
#include "ticket.hpp"
using namespace std;
int main()
{
    p:
    int choice, n;
    passenger arr[100];
    passenger p;
    interface i;
    cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
    cout<<"\n\n1. ADD PASSENGER";
    cout<<"\n2. SHOW ALL PASSENGERS";
    cout<<"\n3. SKIP";
    cout<<"\n\nENTER YOUR CHOICE: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Enter n to process: ";
        cin>>n;
        for(int a=0; a<n; a++)
        {
            arr[a].input();
        }
        break;
    case 2:
        p.output();
        break;
    case 3:
        break;
    default:
        cout<<"\n\n Invalid Choice...Please Try Again.";
        getch();
        goto p;
    }
    cout<<"\n\n\n\t\t\tLoading";
    for(int i=1;i<=5;i++)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<".";
    }
    i.menu();
    return 0;
}
