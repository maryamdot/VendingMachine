#include <iostream> // standard library for c++
#include <ctime>    //library for time
#include <unistd.h>
#include <string> //library for string
#include <stdlib.h>
#include "Header.h"
using namespace std;

//main function
int main()
{
    RestockMode Rptr;
    CashHandlingMode Cptr; //needed to deal with the scope
    int startChoice = 0;
    int choice;
    int th, h, fh, f, tw, te;
    int d, p;
    string ch;
    int pass = 1234;
    bool stocked = false;
start:
    cout << "Choose an option:\n1. Ticket mode\n2. Food mode\n3. Restock mode\n";
    cin >> startChoice;

    if (startChoice == 1)
    {
        //----------------------------------------
        //Ticketing

        //creating object of ticket class
        Ticket customer1;
        cout << "NOW SELECT SEAT OF YOUR OWN CHOICE";
        seats_reserving s1;
        string seats;
        //calling functions
        customer1.display();
        customer1.set_show();
        seats = s1.mainfunction();
        customer1.display_ticket(seats);

        goto start;
        //---------------------------------------
    }
    else if (startChoice == 2)
    {
        if (stocked)
        {
            //for user to get items
            FoodVendingMode F;
        selectitem:
            F.setInvalid();
            F.selectType(Rptr);
            if (F.getInvalid())
            {
                cout << "\nINVALID ENTRY\n";
                goto selectitem;
            }

            F.selectItem(Rptr, Cptr);
            if (F.getInvalid())
            {
                goto selectitem;
            }

            //-----------------------

            int payChoice;
        selectPay:
            cout << "Payment method?\n1. Cash\n2. Credit\n";

            cin >> payChoice;

            if (payChoice == 1)
            {

                F.insertCash(Rptr, Cptr);
                if (F.getInvalid())
                {
                    goto selectitem;
                }
            }
            else if (payChoice == 2)
            {
                Card_managment c1;
                c1.setdata();
                c1.display();
            }
            else
            {
                cout << "INVALID ENTRY\n";
                goto selectPay;
            }

            int select;
            select = F.getSelection() - 1;

            //decrement in quantity and cups after user has used the vending
            if (F.getChoose() == 1)
            {
                (Rptr).decrementInLiters(select);
                (Rptr).decrementInDrinkCups();
            }
            else if (F.getChoose() == 2)
            {
                (Rptr).decrementInQuantity(select);
                (Rptr).decrementInPopcornCups();
            }
             
            cout << "\nTHANK YOU!!\n";
            system("CLS");

            //tasking cash returned to user and subtracting that cash from the one already stored
            int cash;
            th = fh = h = f = tw = te = 0;
            cash = F.getCashReturn();
            th = cash / 1000;
            cash = cash - (th * 100);

            fh = cash / 500;
            cash = cash - (fh * 500);

            h = cash / 100;
            cash = cash - (h * 100);

            f = cash / 50;
            cash = cash - (f * 50);

            tw = cash / 20;
            cash = cash - (tw * 20);

            te = cash / 10;

            (Cptr).decrementInCash(th, fh, h, f, tw, te);


            cout << "DO YOU WANT TO CHECK STORAGE? (Y/N) : ";
            cin >> ch;
            if (ch == "Y")
            {
                cout << "ENTER PASSWORD: ";
                cin >> pass;
                if (pass = 1234)
                {
                    (Rptr).display();
                    (Cptr).displayCashBox();
                }
            }
            goto start;
        }
        else
        {
            cout << "Vending is empty, please restock first\n";
            goto start;
        }
    }
    else if (startChoice == 3)
    {
        stocked = true;
        //restock
        //for storing items
        int pw;
        cout << "Enter password:";
        cin >> pw;
        if (pw == 0000)
        {
            cout << "\t\tRESTOCK MODE:\n";
            cout << "ENTER NUMBER OF DRINKS TO STORE: ";
            cin >> d;

            cout << "ENTER NUMBER OF POPCORNS TO STORE: ";
            cin >> p;
            system("CLS");

            RestockMode R(d, p);
            Rptr = R;
            //-----------------------------------------
            //for cash storing
            system("CLS");
            cout << "\nCASH HANDLING MODE\n";
            //int th, h,fh, f, tw, te;
            cout << "ENTER NUMBER OF THOUSAND RUPPES NOTE TO STORE: ";
            cin >> th;
            cout << "ENTER NUMBER OF FIVE HUNDRED RUPEES NOTE TO STORE: ";
            cin >> fh;
            cout << "ENTER NUMBER OF HUNDRED RUPPES NOTE TO STORE: ";
            cin >> h;
            cout << "ENTER NUMBER OF FIFTY RUPPES NOTE TO STORE: ";
            cin >> f;
            cout << "ENTER NUMBER OF TWENTY RUPPES NOTE TO STORE: ";
            cin >> tw;
            cout << "ENTER NUMBER OF TEN RUPPES NOTE TO STORE: ";
            cin >> te;

            CashHandlingMode C(th, fh, h, f, tw, te);
            Cptr = C;

            system("CLS");
            goto start;

            //-----------------------------------------------
        }
        else
        {
            cout << "Wrong input, try again\n";
            goto start;
        }
    }
    return 0;
}