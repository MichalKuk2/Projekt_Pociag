#include "interface.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <chrono>
#include <thread>
#include <string.h>
using namespace std;
void interface::menu()
{
   routs r;
   train tr;
   ticket t;
   system("cls");
   int option;
   cout<<"\n\t\t_________TRAIN MANAGMENT SYSTEM_________";
   cout<<"\n\n 1. ADD TRAIN RECORD";
   cout<<"\n 2. VIEW TRAINS DETAIL";
   cout<<"\n 3. UPDATE TRAIN DETAIL";
   cout<<"\n 4. DELETE TRAIN DETAIL";
   cout<<"\n 5. ROUTS OF TRAINS";
   cout<<"\n 6. TRAIN SEATS DETAIL";
   cout<<"\n 7. BOOKING RECORD";
   cout<<"\n 8. SEATS RESET";
   cout<<"\n 9. SEARCH BOOKING RECORD";
   cout<<"\n 10. DELETE BOOKING RECORD";
   cout<<"\n 11. SHOW ALL BOOKING RECORD";
   cout<<"\n 12. EXIT";
   cout<<"\n\n ENTER YOUR CHOICE: ";
   cin>>option;
   switch(option)
   {
   case 1:
       tr.new_train();
       break;
   case 2:
       tr.view_train();
       break;
   case 3:
       tr.update_train();
       break;
   case 4:
       tr.del_train();
       break;
   case 5:
       r.show_routs();
       break;
   case 6:
       t.detail_train();
       break;
   case 7:
       t.booking();
       break;
   case 8:
       t.seats_reset();
       break;
   case 9:
       t.search_booking();
       break;
   case 10:
       t.delete_booking();
       break;
   case 11:
       t.view_all_booking();
       break;
   case 12:
       exit(0);
   default:
       cout<<"\n\n Invalid Choice...Please Try Again.";
   }
       getch();
       menu();
}
