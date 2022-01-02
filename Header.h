#ifndef HEADER_H
#define HEADER_H

#include <iostream> // standard library for c++
#include <ctime>    //library for time
#include <unistd.h>
#include <string> //library for string
#include <stdlib.h>
using namespace std;

class seats_reserving
{
    char** Arr_Seats;
    char arr2[3];
    char answer;
    int Numberofrow;
    int Numberofseats;
    int Available_seats;
    int rows;
    int seats;
    friend class Ticket;

public:
    char** ArrayOfSeats(int Numberofrow, int seats);
    void Initializing_seats(char** Arr_Seats, int Numberofrow, int seats);
    void DisplaySeats(char** Arr_Seats, int Numberofrow, int Numberofseats);
    void MemoryCleanup(char** Arr_Seats, int Numberofrow, int Numberofseats);
    string mainfunction();
};

class Ticket
{
private:
    //data members
    int price;
    int No_of_show;
    string show;
    int dateNum;
    int timeNum;
    string date;
    string showTime;
    string dateArr[6];
    string timeArr[6];

    int n0_of_tickets;

public:
    //member functions
    void Time();
    void set_date();
    void display();
    void set_show();
    void display_ticket(string seats);
};

class RestockMode
{
public:
    int drinkArraySize;
    int popcornArraySize;
    string drinks[50];
    string popcorns[50];
    int drinksPrice[50];
    int popcornsPrice[50];
    int liters[50];
    int quantity[50];
    int cups_popcorns;
    int cups_drinks;

public:
    RestockMode();
    RestockMode(int d, int p);
    void setDrinkArraySize(int d);
    int getDrinkArraySize();
    void setPopcornArraySize(int p);
    int getPopcornArraySize();
    void setDrinks(int d);
    string getDrinks(int a);
    void setDrinkPrice(int d);
    int getDrinkPrice(int a);
    void setDrinkLiters(int d);
    int getDrinkLiters(int a);
    void setPopcorns(int p);
    string getPopcorns(int a);
    void setPopcornPrice(int p);
    int getPopcornPrice(int a);
    void setPopcornQuantity(int p);
    int getPopcornQuantity(int a);
    void setDrinkCups(int cup_d);
    int getDrinkCups();
    void setPopcornCups(int cup_p);
    int getPopcornCups();
    void decrementInDrinkCups();
    void decrementInPopcornCups();
    void decrementInLiters(int a);
    void decrementInQuantity(int a);
    void display();
    
};

class CashHandlingMode
{
protected:
    string cash_type[6] = { "THOUSAND", "FIVE HUNDRED", "HUNDRED", "FIFTY", "TWENTY", "TEN" };
    int cash_stored[6];

public:
    CashHandlingMode();
    CashHandlingMode(int th, int fh, int h, int f, int tw, int te);
    void setThousand(int th);
    int getThousands();
    void setFiveHundred(int fh);
    int getFiveHundred();
    void setHundred(int h);
    int getHundred();
    void setFifty(int f);
    int getFifty();
    void setTwenty(int tw);
    int getTwenty();
    void setTen(int te);
    int getTen();
    void decrementInCash(int th, int fh, int h, int f, int tw, int te);
    void displayCashBox();
};

class FoodVendingMode : public RestockMode, CashHandlingMode
{
protected:
    int choose;
    int choose2;
    int selection;
    int entered_cash;
    bool invalid = false;
    int total_cash = 0;
    int thousand;
    int fivehundred;
    int hundred;
    int fifty;
    int twenty;
    int ten;
    int cash_return;

public:
    void displayMenu(RestockMode R);
    void selectType(RestockMode R);
    void selectItem(RestockMode r, CashHandlingMode c);
    void checkItem(RestockMode r, CashHandlingMode c);
    void insertCash(RestockMode r, CashHandlingMode c);
    void setTotalCash();
    void checkCash(RestockMode r, CashHandlingMode c);
    int getCashReturn();
    int getSelection();
    int getChoose();
    int getEnteredCash();
    void setInvalid();
    bool getInvalid();
};

class Card_managment
{
    int rupees;
    int cardID;
    int password;

public:
    void setdata();
    void display();
};

#endif
