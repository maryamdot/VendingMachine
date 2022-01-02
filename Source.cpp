#include <iostream> // standard library for c++
#include <ctime>    //library for time
#include <unistd.h>
#include <string> //library for string
#include <stdlib.h>
#include "Header.h"
using namespace std;


//// CreatArrayOfSeats Function
char** seats_reserving::ArrayOfSeats(int Numberofrow, int seats)
{
    /*  char **Arr_Seats;
    Arr_Seats = new char*[Numberofrow];
    for (int r=0; r<Numberofrow; r++)
    Arr_Seats[r] = new char[seats];
    return Arr_Seats;*/

    char** Arr_Seats;
    Arr_Seats = new char* [Numberofrow];
    for (int r = 0; r < Numberofrow; r++)
        Arr_Seats[r] = new char[seats];
    return Arr_Seats;
}

///// Initializing_seats Function
void seats_reserving::Initializing_seats(char** Arr_Seats, int Numberofrow, int seats)
{
    for (int i = 0; i < Numberofrow; i++)
    {
        for (int j = 0; j < seats; j++)
            Arr_Seats[i][j] = 'A' + j;
    }
}

///// DisplaySeats Function
void seats_reserving::DisplaySeats(char** Arr_Seats, int Numberofrows, int Numberofseats)
{
    for (int i = 0; i < Numberofrow; i++)
    {
        cout.width(2);
        cout << i + 1 << ' ';
        for (int j = 0; j < Numberofseats; j++)
            cout << Arr_Seats[i][j] << ' ';
        cout << endl;
    }
}

///// MemoryCleanup Function
void seats_reserving::MemoryCleanup(char** Arr_Seats, int Numberofrow, int Numberofseats)
{
    for (int i = 0; i < Numberofrow; i++)
        delete[] Arr_Seats[i];
    delete[] Arr_Seats;
}

string seats_reserving::mainfunction()
{
    cout << "*THIS IS PERSONALIZED SEAT RESERVING SYSTEM*" << endl
        << "ENTER THE NUMBER OF ROWS OF YOUR DESIRED: ";
    cin >> Numberofrow;
    cout << "NOW ENTER THE NUMBER OF SEATS IN EACH ROW: ";
    cin >> Numberofseats;
    string seatsArr[Numberofseats];
    Available_seats = Numberofrow * Numberofseats;

    Arr_Seats = ArrayOfSeats(Numberofrow, Numberofseats);
    Initializing_seats(Arr_Seats, Numberofrow, Numberofseats);
    DisplaySeats(Arr_Seats, Numberofrow, Numberofseats);
    string reservedSeats = " ";

    do
    {
        do
        {
            cout << " " << endl;
            cout << "THERE ARE " << Available_seats << " SEATS AVAILABLE, CHOOSE ANY ONE:(SELECT LIKE 1A)" << endl;
            cin >> arr2;
            reservedSeats = reservedSeats + " " + arr2;

            rows = arr2[0] - '1';
            if (arr2[1] >= '0' && arr2[1] <= '9') // In case there are more than 9 rows
            {
                rows += 1;
                rows *= 10;
                rows += (arr2[1] - '1');
                arr2[1] = arr2[2];
            }
            arr2[1] = toupper(arr2[1]);
            seats = arr2[1] - 'A';
            if (rows < 0 || rows > Numberofrow - 1)
                cout << "Row selections go from 1 to " << Numberofrow << ". Try a different row.." << endl;
            if (seats < 0 || seats > Numberofseats - 1)
                cout << "Seat selections go from A to " << char('A' + (Numberofseats - 1)) << ". Try a different seat.." << endl;

        } while (rows < 0 || rows > Numberofrow - 1 || seats < 0 || seats > Numberofseats - 1);
        if (rows >= 0)
        {
            if (Arr_Seats[rows][seats] == '*')
                cout << "ERROR! THIS SEAT IS ALREADY BOOKED" << endl;
            else
            {
                Arr_Seats[rows][seats] = '*';
                Available_seats--;
            }
            if (Available_seats == 0)
                cout << "NO MORE SEATS" << endl;
        }
        DisplaySeats(Arr_Seats, Numberofrow, Numberofseats);
        do
        {
            cout << endl
                << "DO YOU WANT TO RESERVE ANOTHER SEAT? (Y/N)" << endl;
            cin >> answer;
            answer = toupper(answer);
            if (answer != 'Y' && answer != 'N')
                cout << "INCORRECT INPUT TRY 'Y' OR 'N' " << endl;
        } while (answer != 'Y' && answer != 'N');
        if (answer == 'N')
            rows = -1;
    } while (Available_seats > 0 && rows >= 0);

    MemoryCleanup(Arr_Seats, Numberofrow, Numberofseats);
    char buff[100];
    cin.getline(buff, 100);

    return reservedSeats;
}




    void Ticket :: Time()
    {
        cout << "\n\n\n"
            << endl;
        //time
        cout << "\t   _____                  .__ .__           ___.    .__                 _________.__             __           " << endl;
        cout << "\t  /  _  \\  ___  _______   |__||  |  _____   \\_ |__  |  |    ____       /   _____/|  |    ____  _/  |_   ______" << endl;
        cout << "\t /  /_\\  \\ \\  \\/ /\\__  \\  |  ||  |  \\__  \\   | __ \\ |  |  _/ __ \\      \\_____  \\ |  |   /  _ \\ \\   __\\ /  ___/" << endl;
        cout << "\t/    |    \\ \\   /  / __ \\_|  ||  |__ / __ \\_ | \\_\\ \\|  |__\\  ___/      /        \\|  |__(  <_> ) |  |   \\___ \\ " << endl;
        cout << "\t\\____|__  /  \\_/  (____  /|__||____/(____  / |___  /|____/ \\___  >    /_______  /|____/ \\____/  |__|  /____  >" << endl;
        cout << "\t        \\/             \\/                \\/      \\/            \\/             \\/                           \\/" << endl;
        time_t now = time(0);
        tm* ltm = localtime(&now);

        for (int i = 0; i < 6; i++)
        {
            //generating random minutes and hours from local time
            ltm->tm_hour = i + ltm->tm_hour;
            ltm->tm_min = ltm->tm_min + 30;

            //if number of minutes is greater than 60
            if (ltm->tm_min > 60)
            {
                //subtract minutes from 60 and increment hour
                ltm->tm_min = ltm->tm_min - 60;
                ltm->tm_hour += 1;
            }
            if (ltm->tm_min == 60)
            {
                ltm->tm_min = 0;
                ltm->tm_hour += 1;
            }
            //if number of hours is greater than 60
            if (ltm->tm_hour > 24)
            {
                //subtract hours from 24
                ltm->tm_hour = ltm->tm_hour - 24;
            }
            //adding a double 0 if minutes are 0-9
            if ((ltm->tm_min >= 0 && ltm->tm_min <= 9))
            {

                showTime = to_string(ltm->tm_hour) + ":0" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
            }
            else if ((ltm->tm_sec >= 0 && ltm->tm_sec <= 9))
            {
                showTime = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":0" + to_string(ltm->tm_sec);
            }
            else if ((ltm->tm_hour >= 0 && ltm->tm_hour <= 9))
            {
                showTime = "0" + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
            }
            else
            {
                //generating time by concatinating strings of hour, minute and second
                showTime = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
                timeArr[i] = showTime;
            }
            //printing time slot
            cout << "\t\tSlot " << i + 1 << " = " << showTime << endl;
        }
    }

    void Ticket:: set_date()
    {
        cout << "\n\n\n"
            << endl;
        cout << "     _____                  .__ .__           ___.    .__               ________             __                   " << endl;
        cout << "    /  _  \\  ___  _______   |__||  |  _____   \\_ |__  |  |    ____      \\______ \\  _____   _/  |_   ____    ______" << endl;
        cout << "   /  /_\\  \\ \\  \\/ /\\__  \\  |  ||  |  \\__  \\   | __ \\ |  |  _/ __ \\      |    |  \\ \\__  \\  \\   __\\_/ __ \\  /  ___/" << endl;
        cout << "  /    |    \\ \\   /  / __ \\_|  ||  |__ / __ \\_ | \\_\\ \\|  |__\\  ___/      |    `   \\ / __ \\_ |  |  \\  ___/  \\___ \\ " << endl;
        cout << "  \\____|__  /  \\_/  (____  /|__||____/(____  / |___  /|____/ \\___  >    /_______  /(____  / |__|   \\___  >/____  >" << endl;
        cout << "          \\/             \\/                \\/      \\/            \\/             \\/      \\/             \\/      \\/" << endl;
        time_t now = time(0);
        tm* ltm = localtime(&now);

        ltm->tm_year = ltm->tm_year + 1900;
        ltm->tm_mon = ltm->tm_mon + 1;
        for (int i = 0; i < 6; i++)
        {
            //generating random days and months from local time
            ltm->tm_mday = 1 + ltm->tm_mday;

            //if number of month is greater than 12
            if (ltm->tm_mon > 12)
            {
                //subtract months from 12
                ltm->tm_mon = ltm->tm_mon - 12;
            }
            //for months having 30 days
            if ((ltm->tm_mon == 9 || ltm->tm_mon == 4 || ltm->tm_mon == 6 || ltm->tm_mon == 11) && ltm->tm_mday > 30)
            {
                ltm->tm_mday = 1;
                ltm->tm_mon += 1;
            }
            //if days are greater than 31 for other months
            else if (ltm->tm_mon != 9 && ltm->tm_mon != 4 && ltm->tm_mon != 6 && ltm->tm_mon != 11 && ltm->tm_mday > 31)
            {
                ltm->tm_mday = 1;
                ltm->tm_mon += 1;
            }
            //generating time by concatinating strings of days, month and year
            date = to_string(ltm->tm_mday) + ":" + to_string(ltm->tm_mon) + ":" + to_string(ltm->tm_year);
            dateArr[i] = date;
            //printing date slot
            cout << "\t\tDate " << i + 1 << " = " << date << endl;
        }
    }

    //function for display
    void Ticket::display()
    {

        cout << "\t\t\t                 .__                                  " << endl;
        sleep(1);
        cout << "\t\t\t__  _  __  ____  |  |    ____    ____    _____    ____" << endl;
        sleep(1);
        cout << "\t\t\t\\ \\/ \\/ /_/ __ \\ |  |  _/ ___\\  /  _ \\  /     \\ _/ __ \\ " << endl;
        sleep(1);
        cout << "\t\t\t \\     / \\  ___/ |  |__\\  \\___ (  <_> )|  Y Y  \\  ___ /" << endl;
        sleep(1);
        cout << "\t\t\t  \\/\\_/   \\___  >|____/ \\___  > \\____/ |__|_|  / \\___  >" << endl;
        sleep(1);
        cout << "\t\t\t              \\/            \\/               \\/      \\/" << endl;
        sleep(1);

        cout << "\t\t\t\t\t    __ " << endl;
        sleep(1);
        cout << "\t\t\t\t\t  _/  |_   ____" << endl;
        sleep(1);
        cout << "\t\t\t\t\t  \\   __\\ /  _ \\" << endl;
        sleep(1);
        cout << "\t\t\t\t\t   |  |  (  <_> )" << endl;
        sleep(1);
        cout << "\t\t\t\t\t   |__|   \\____/" << endl;
        sleep(1);

        cout << "\t\t\t       __   .__          __              __ " << endl;
        sleep(1);
        cout << "\t\t\t     _/  |_ |__|  ____  |  | __  ____  _/  |_" << endl;
        sleep(1);
        cout << "\t\t\t     \\   __\\|  |_/ ___\\ |  |/ /_/ __ \\ \\   __\\" << endl;
        sleep(1);
        cout << "\t\t\t      |  |  |  |\\  \\___ |    < \\  ___/  |  |  " << endl;
        sleep(1);
        cout << "\t\t\t      |__|  |__| \\___  >|__|_ \\ \\___  > |__|   " << endl;
        sleep(1);
        cout << "\t\t\t                     \\/      \\/     \\/         " << endl;
        sleep(1);

        cout << "\t\t\t                             .___.__              " << endl;
        sleep(1);
        cout << "\t\t\t  ___  __  ____    ____    __| _/|__|  ____     ____ " << endl;
        sleep(1);
        cout << "\t\t\t  \\  \\/ /_/ __ \\  /    \\  / __ | |  | /    \\   / ___\\  " << endl;
        sleep(1);
        cout << "\t\t\t   \\   / \\  ___/ |   |  \\/ /_/ | |  ||   |  \\ / /_/  > " << endl;
        sleep(1);
        cout << "\t\t\t    \\_/   \\___  >|___|  /\\____ | |__||___|  / \\___  /  " << endl;
        sleep(1);
        cout << "\t\t\t              \\/      \\/      \\/          \\/ /_____/" << endl;
        sleep(1);

        cout << "\t\t\t                         .__     .__ " << endl;
        sleep(1);
        cout << "\t\t\t  _____  _____     ____  |  |__  |__|  ____    ____  " << endl;
        sleep(1);
        cout << "\t\t\t /     \\ \\__  \\  _/ ___\\ |  |  \\ |  | /    \\ _/ __ \\ " << endl;
        sleep(1);
        cout << "\t\t\t|  Y Y  \\ / __ \\_\\  \\___ |   Y  \\|  ||   |  \\\\  ___/ " << endl;
        sleep(1);
        cout << "\t\t\t|__|_|  /(____  / \\___  >|___|  /|__||___|  / \\___  >" << endl;
        sleep(1);
        cout << "\t\t\t      \\/      \\/      \\/      \\/          \\/      \\/ " << endl;
        sleep(1);

        cout << "\n\n\n\n\n\n"
            << endl;
        cout
            << "\t\tSELECT ANY MOVIE (1-10)\n"
            "\t\t1. Spider-man: No Way Home\n"
            "\t\t2. Hera Pheri\n"
            "\t\t3. The Matrix\n"
            "\t\t4. Teefa in Trouble\n"
            "\t\t5. Frozen 2\n"
            "\t\t6. Toy story 5\n"
            "\t\t7. Maula Jutt\n"
            "\t\t8. Forrest Gump\n"
            "\t\t9. Parasyte\n"
            "\t\t10. Demon Slayer: The Mugen Train"
            << endl;
    }

    //function for selecting show
    void Ticket:: set_show()
    {
        cin >> No_of_show; //getting show from user
        //using switch case statement
        switch (No_of_show)
        {
            //when user selects a movie
        case 1:
            show = "Spider-man: No Way Home";

            cout << "\t\t\t  _________        .__     .___                   _____                   " << endl;
            cout << "\t\t\t /   _____/______  |__|  __| _/  ____  _______   /     \\  _____     ____  " << endl;
            cout << "\t\t\t \\_____  \\ \\____ \\ |  | / __ | _/ __ \\ \\_  __ \\ /  \\ /  \\ \\__  \\   /    \\ " << endl;
            cout << "\t\t\t /        \\|  |_> >|  |/ /_/ | \\  ___/  |  | \\//    Y    \\ / __ \\_|   |  \\" << endl;
            cout
                << "\t\t\t/_______  /|   __/ |__|\\____ |  \\___  > |__|   \\____|__  /(____  /|___|  /" << endl;
            cout << "\t\t\t        \\/ |__|             \\/      \\/                 \\/      \\/      \\/" << endl;

            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;
            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 800;
            break;

        case 2:
            show = "Hera Pheri";
            cout << "\t\t\t  ___ ___                              __________ .__                     .__ " << endl;
            cout << "\t\t\t /   |   \\   ____  _______ _____       \\______   \\|  |__    ____  _______ |__|" << endl;
            cout << "\t\t\t/    ~    \\_/ __ \\ \\_  __ \\\\__  \\       |     ___/|  |  \\ _/ __ \\ \\_  __ \\|  |" << endl;
            cout << "\t\t\t\\    Y    /\\  ___/  |  | \\/ / __ \\_     |    |    |   Y  \\\\  ___/  |  | \\/|  |" << endl;
            cout << "\t\t\t \\___|_  /  \\___  > |__|   (____  /     |____|    |___|  / \\___  > |__|   |__|" << endl;
            cout << "\t\t\t       \\/       \\/              \\/                     \\/      \\/             " << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;
            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 600;
            break;

        case 3:
            show = "The Matrix";
            cout << "\t\t\t___________.__                    _____             __           .__         " << endl;
            cout << "\t\t\t\\__    ___/|  |__    ____        /     \\  _____   _/  |_ _______ |__|___  ___ " << endl;
            cout << "\t\t\t  |    |   |  |  \\ _/ __ \\      /  \\ /  \\ \\__  \\  \\   __\\\\_  __ \\|  |\\  \\/  / " << endl;
            cout << "\t\t\t  |    |   |   Y  \\\\  ___/     /    Y    \\ / __ \\_ |  |   |  | \\/|  | >    <  " << endl;
            cout << "\t\t\t  |____|   |___|  / \\___  >    \\____|__  /(____  / |__|   |__|   |__|/__/\\_ \\ " << endl;
            cout << "\t\t\t                \\/      \\/             \\/      \\/                          \\/ " << endl;
            set_date(); //calling date function
            cout
                << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 700;
            break;

        case 4:
            show = "Teefa in Trouble";
            cout << "\t___________                  _____          .___          ___________                       ___.    .__           " << endl;
            cout << "\t\\__    ___/  ____    ____  _/ ____\\_____    |   |  ____   \\__    ___/_______   ____   __ __ \\_ |__  |  |    ____  " << endl;
            cout << "\t  |    |   _/ __ \\ _/ __ \\ \\   __\\ \\__  \\   |   | /    \\    |    |   \\_  __ \\ /  _ \\ |  |  \\ | __ \\ |  |  _/ __ \\ " << endl;
            cout << "\t  |    |   \\  ___/ \\  ___/  |  |    / __ \\_ |   ||   |  \\   |    |    |  | \\/(  <_> )|  |  / | \\_\\ \\|  |__\\  ___/ " << endl;
            cout << "\t  |____|    \\___  > \\___  > |__|   (____  / |___||___|  /   |____|    |__|    \\____/ |____/  |___  /|____/ \\___  >" << endl;
            cout << "\t                \\/      \\/              \\/            \\/                                         \\/            \\/" << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 800;
            break;

        case 5:
            show = "Frozen 2";
            cout << "\t\t\t___________                                             ________  " << endl;
            cout << "\t\t\t\\_   _____/_______   ____  ________  ____    ____       \\_____  \\ " << endl;
            cout << "\t\t\t |    __)  \\_  __ \\ /  _ \\ \\___   /_/ __ \\  /    \\       /  ____/ " << endl;
            cout << "\t\t\t |     \\    |  | \\/(  <_> ) /    / \\  ___/ |   |  \\     /       \\ " << endl;
            cout << "\t\t\t \\___  /    |__|    \\____/ /_____ \\ \\___  >|___|  /     \\_______ \\" << endl;
            cout << "\t\t\t     \\/                          \\/     \\/      \\/              \\/" << endl;

            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;
            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 1000;
            break;

        case 6:
            show = "Toy story 5";
            cout << "\t\t___________                      _________  __                                .________" << endl;
            cout << "\t\t\\__    ___/  ____   ___.__.     /   _____/_/  |_   ____  _______  ___.__.     |   ____/" << endl;
            cout << "\t\t  |    |    /  _ \\ <   |  |     \\_____  \\ \\   __\\ /  _ \\ \\_  __ \\<   |  |     |____  \\ " << endl;
            cout << "\t\t  |    |   (  <_> ) \\___  |     /        \\ |  |  (  <_> ) |  | \\/ \\___  |     /       \\" << endl;
            cout << "\t\t  |____|    \\____/  / ____|    /_______  / |__|   \\____/  |__|    / ____|    /______  /" << endl;
            cout << "\t\t                    \\/                 \\/                         \\/                \\/" << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 900;
            break;

        case 7:
            show = "Maula Jutt";
            cout << "\t\t\t   _____                  .__                     ____.         __     __   " << endl;
            cout << "\t\t\t  /     \\  _____    __ __ |  |  _____            |    | __ __ _/  |_ _/  |_ " << endl;
            cout << "\t\t\t /  \\ /  \\ \\__  \\  |  |  \\|  |  \\__  \\           |    ||  |  \\\\   __\\\\   __\\" << endl;
            cout << "\t\t\t/    Y    \\ / __ \\_|  |  /|  |__ / __ \\_     /\\__|    ||  |  / |  |   |  |  " << endl;
            cout << "\t\t\t\\____|__  /(____  /|____/ |____/(____  /     \\________||____/  |__|   |__|  " << endl;
            cout << "\t\t\t        \\/      \\/                   \\/                                    " << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 800;
            break;

        case 8:
            show = "Forest Gump";
            cout << "\t\t\t___________                                  __          ________                         " << endl;
            cout << "\t\t\t\\_   _____/  ____  _______   ____    _______/  |_       /  _____/  __ __   _____  ______  " << endl;
            cout << "\t\t\t |    __)   /  _ \\ \\_  __ \\_/ __ \\  /  ___/\\   __\\     /   \\  ___ |  |  \\ /     \\ \\____ \\ " << endl;
            cout << "\t\t\t |     \\   (  <_> ) |  | \\/\\  ___/  \\___ \\  |  |       \\    \\_\\  \\|  |  /|  Y Y  \\|  |_> >" << endl;
            cout << "\t\t\t \\___  /    \\____/  |__|    \\___  >/____  > |__|        \\______  /|____/ |__|_|  /|   __/ " << endl;
            cout << "\t\t\t     \\/                         \\/      \\/                     \\/              \\/ |__| " << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;
            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 800;
            break;

        case 9:
            show = "Parasyte";
            cout << "\t\t\t__________                                           __           " << endl;
            cout << "\t\t\t\\______   \\_____   _______ _____     ______ ___.__._/  |_   ____  " << endl;
            cout << "\t\t\t |     ___/\\__  \\  \\_  __ \\\\__  \\   /  ___/<   |  |\\   __\\_/ __ \\ " << endl;
            cout << "\t\t\t |    |     / __ \\_ |  | \\/ / __ \\_ \\___ \\  \\___  | |  |  \\  ___/ " << endl;
            cout << "\t\t\t |____|    (____  / |__|   (____  //____  > / ____| |__|   \\___  >" << endl;
            cout << "\t\t\t                \\/              \\/      \\/  \\/                 \\/" << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;
            price = n0_of_tickets * 900;
            break;

        case 10:
            show = "Demon Slayer: The Mugen Train";
            cout << "\t\t________                                            _________.__                                   " << endl;
            cout << "\t\t\\______ \\    ____    _____    ____    ____         /   _____/|  |  _____    ___.__.  ____  _______ " << endl;
            cout << "\t\t |    |  \\ _/ __ \\  /     \\  /  _ \\  /    \\        \\_____  \\ |  |  \\__  \\  <   |  |_/ __ \\ \\_  __ \\" << endl;
            cout << "\t\t |    `   \\\\  ___/ |  Y Y  \\(  <_> )|   |  \\       /        \\|  |__ / __ \\_ \\___  |\\  ___/  |  | \\/" << endl;
            cout << "\t\t/_______  / \\___  >|__|_|  / \\____/ |___|  /      /_______  /|____/(____  / / ____| \\___  > |__|   " << endl;
            cout << "\t\t        \\/      \\/       \\/              \\/               \\/            \\/  \\/          \\/       " << endl;
            set_date(); //calling date function
            cout << "\t\tSelect date for the show" << endl;
            cin >> dateNum;

            Time(); //calling time function
            cout << "\t\tSelect time for the show" << endl;
            cin >> timeNum;

            cout << "\t\tEnter number of tickets" << endl;
            cin >> n0_of_tickets;

            price = n0_of_tickets * 600;
            break;
        }
    }
    //function for displaying ticket of movie
    void Ticket:: display_ticket(string seats)
    {
        cout << "\t\t\t_____.___.                             ___________.__          __              __   " << endl;
        cout << "\t\t\t\\__  |   |  ____   __ __ _______       \\__    ___/|__|  ____  |  | __  ____  _/  |_" << endl;
        cout << "\t\t\t /   |   | /  _ \\ |  |  \\\\_  __ \\        |    |   |  |_/ ___\\ |  |/ /_/ __ \\ \\   __\\" << endl;
        cout
            << "\t\t\t \\____   |(  <_> )|  |  / |  | \\/        |    |   |  |\\  \\___ |    < \\  ___/  |  |  " << endl;
        cout << "\t\t\t / ______| \\____/ |____/  |__|           |____|   |__| \\___  >|__|_ \\ \\___  > |__|  " << endl;
        cout << "\t\t\t \\/                                                        \\/      \\/     \\/       " << endl;
        cout << ""
            << endl;

        cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
        cout << "\t*\t  ____    _                        \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t / ___|  | |__     ___   __      __\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t \\___ \\  | '_ \\   / _ \\  \\ \\ /\\ / / \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  ___) | | | | | | (_) |  \\ V  V /  :  " << show << "\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t |____/  |_| |_|  \\___/    \\_/\\_/ \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                 \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  ____                   _           \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t / ___|    ___    __ _  | |_ \t\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t \\___ \\   / _ \\  / _` | | __|\t\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  ___) | |  __/ | (_| | | |_ \t" << seats << "\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t |____/   \\___|  \\__,_|  \\__|\t\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                   \t\t\t\t\t\t\t\t\t*";
        cout << "\n\t*\t                                   \t\t\t\t\t\t\t\t\t*"
            << endl;
        cout << "\t*\t  ____            _               ___       _____   _                    \t\t\t\t*" << endl;
        cout << "\t*\t |  _ \\    __ _  | |_    ___     ( _ )     |_   _| (_)  _ __ ___     ___ \t\t\t\t*" << endl;
        cout << "\t*\t | | | |  / _` | | __|  / _ \\    / _ \\/\\     | |   | | | '_ ` _ \\   / _ \\ \t\t\t\t*" << endl;
        cout << "\t*\t | |_| | | (_| | | |_  |  __/   | (_>  <     | |   | | | | | | | | |  __/ :  " << dateArr[dateNum - 1] << " " << timeArr[timeNum] << "\t\t*" << endl;
        cout << "\t*\t |____/   \\__,_|  \\__|  \\___|    \\___/\\/     |_|   |_| |_| |_| |_|  \\___|\t\t\t\t*" << endl;
        cout << "\t*\t                                   \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                   \t\t\t\t\t\t\t\t\t*" << endl;

        cout << "\t*\t   ____           _               \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  |  _ \\   _ __  (_)   ___    ___ \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  | |_) | | '__| | |  / __|  / _ \\ \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  |  __/  | |    | | | (__  |  __/:\t" << price << "\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t  |_|     |_|    |_|  \\___|  \\___|\t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                 \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t*\t                                 \t\t\t\t\t\t\t\t\t*" << endl;
        cout << "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    }

//Food vending part


    RestockMode :: RestockMode()
    {
    }
    RestockMode :: RestockMode(int d, int p)
    {
        if (d > 0)
        {
            setDrinkArraySize(d);
        }
        else
            cout << "INVALID INPUT.";

        setDrinks(d);
        setDrinkPrice(d);
        setDrinkLiters(d);
        cout << "\nENTER CUPS FOR DRINK TO STORE: ";
        cin >> cups_drinks;
        system("CLS");
        if (p > 0)
        {
            setPopcornArraySize(p);
        }
        else
            cout << "INVALID INPUT.";

        setPopcorns(p);
        setPopcornPrice(p);
        setPopcornQuantity(p);
        cout << "\nENTER CUPS FOR POPCORN TO STORE: ";
        cin >> cups_popcorns;
        system("CLS");
    }

    void RestockMode:: setDrinkArraySize(int d)
    {
        drinkArraySize = d;
    }

    int RestockMode:: getDrinkArraySize()
    {
        return drinkArraySize;
    }

    void RestockMode:: setPopcornArraySize(int p)
    {
        popcornArraySize = p;
    }

    int RestockMode:: getPopcornArraySize()
    {
        return popcornArraySize;
    }

    void RestockMode:: setDrinks(int d)
    {
        for (int i = 0; i < d; i++)
        {
            cout << "ENTER NAME OF " << (i + 1) << " DRINK: ";
            cin >> drinks[i];
        }
    }

    string RestockMode:: getDrinks(int a)
    {
        return drinks[a];
    }

    void RestockMode:: setDrinkPrice(int d)
    {
        for (int i = 0; i < d; i++)
        {
            cout << "ENTER PRICE FOR " << drinks[i] << ": ";
            cin >> drinksPrice[i];
        }
    }

    int RestockMode:: getDrinkPrice(int a)
    {
        return drinksPrice[a];
    }

    void RestockMode:: setDrinkLiters(int d)
    {
        for (int i = 0; i < d; i++)
        {
            cout << "ENTER LITERS FOR " << drinks[i] << ": ";
            cin >> liters[i];
        }
    }

    int RestockMode::getDrinkLiters(int a)
    {
        return liters[a];
    }

    void RestockMode:: setPopcorns(int p)
    {
        for (int i = 0; i < p; i++)
        {
            cout << "ENTER " << (i + 1) << " POPCORN FLAVOUR: ";
            cin >> popcorns[i];
        }
    }

    string RestockMode:: getPopcorns(int a)
    {
        return popcorns[a];
    }

    void RestockMode:: setPopcornPrice(int p)
    {
        for (int i = 0; i < p; i++)
        {
            cout << "ENTER PRICE FOR " << popcorns[i] << ": ";
            cin >> popcornsPrice[i];
        }
    }

    int RestockMode:: getPopcornPrice(int a)
    {
        return popcornsPrice[a];
    }

    void RestockMode:: setPopcornQuantity(int p)
    {
        for (int i = 0; i < p; i++)
        {
            cout << "ENTER QUANTITY FOR " << popcorns[i] << ": ";
            cin >> quantity[i];
        }
    }

    int RestockMode:: getPopcornQuantity(int a)
    {
        return quantity[a];
    }

    void RestockMode:: setDrinkCups(int cup_d)
    {
        cups_drinks = cup_d;
    }

    int RestockMode:: getDrinkCups()
    {
        return cups_drinks;
    }

    void RestockMode:: setPopcornCups(int cup_p)
    {
        cups_popcorns = cup_p;
    }

    int RestockMode:: getPopcornCups()
    {
        return cups_popcorns;
    }

    void RestockMode:: decrementInDrinkCups()
    {
        cups_drinks = cups_drinks - 1;
    }

    void RestockMode:: decrementInPopcornCups()
    {
        cups_popcorns = cups_popcorns - 1;
    }

    void RestockMode:: decrementInLiters(int a)
    {
        liters[a] = liters[a] - 50;
    }

    void RestockMode:: decrementInQuantity(int a)
    {
        quantity[a] = quantity[a] - 100;
    }

    void RestockMode::display()
    {
        cout << "STORAGE: \n";
        for (int i = 0; i < drinkArraySize; i++)
        {
            cout << drinks[i] << "  " << liters[i] << " Liters" << endl;
        }
        for (int i = 0; i < popcornArraySize; i++)
        {
            cout << popcorns[i] << "  " << quantity[i] << " Quantity" << endl;
        }
        cout << "\nCUPS FOR DRINKS: " << cups_drinks;
        cout << "\nCUPS FOR POPCORNS: " << cups_popcorns << endl;
    }



    CashHandlingMode :: CashHandlingMode()
    {
    }

    CashHandlingMode:: CashHandlingMode(int th, int fh, int h, int f, int tw, int te)
    {
        setThousand(th);
        setFiveHundred(fh);
        setHundred(h);
        setFifty(f);
        setTwenty(tw);
        setTen(te);
    }

    void CashHandlingMode:: setThousand(int th)
    {
        cash_stored[0] = th;
    }

    int CashHandlingMode:: getThousands()
    {
        return cash_stored[0];
    }

    void CashHandlingMode:: setFiveHundred(int fh)
    {
        cash_stored[1] = fh;
    }

    int CashHandlingMode::getFiveHundred()
    {
        return cash_stored[1];
    }

    void CashHandlingMode::setHundred(int h)
    {
        cash_stored[2] = h;
    }

    int CashHandlingMode:: getHundred()
    {
        return cash_stored[2];
    }

    void CashHandlingMode:: setFifty(int f)
    {
        cash_stored[3] = f;
    }

    int CashHandlingMode:: getFifty()
    {
        return cash_stored[3];
    }

    void CashHandlingMode:: setTwenty(int tw)
    {
        cash_stored[4] = tw;
    }

    int CashHandlingMode:: getTwenty()
    {
        return cash_stored[4];
    }

    void CashHandlingMode:: setTen(int te)
    {
        cash_stored[5] = te;
    }

    int CashHandlingMode:: getTen()
    {
        return cash_stored[5];
    }

    void CashHandlingMode:: decrementInCash(int th, int fh, int h, int f, int tw, int te)
    {
        cash_stored[0] = cash_stored[0] - th;
        cash_stored[1] = cash_stored[1] - fh;
        cash_stored[2] = cash_stored[2] - h;
        cash_stored[3] = cash_stored[3] - f;
        cash_stored[4] = cash_stored[4] - tw;
        cash_stored[5] = cash_stored[5] - te;
    }


    void CashHandlingMode:: displayCashBox()
    {
        cout << "\n\t\tCASH LEFT\n";
        for (int i = 0; i < 6; i++)
        {
            cout << cash_type[i] << "   " << cash_stored[i];
            cout << endl;
        }
    }


    void FoodVendingMode:: displayMenu(RestockMode R)
    {
        if (choose == 1)
        {
            cout << "\n\n\t\tDRINKS \t\tPRICE\n";
            for (int i = 0; i < R.getDrinkArraySize(); i++)
            {
                cout << "\t\t" << (i + 1) << ". " << R.getDrinks(i) << "\t\t" << R.getDrinkPrice(i) << endl;
            }
        }
        else if (choose == 2)
        {
            cout << "\n\n\t\tPOPCORNS \t\tPRICE\n";
            for (int i = 0; i < R.getPopcornArraySize(); i++)
            {
                cout << "\t\t" << (i + 1) << ". " << R.getPopcorns(i) << "\t\t" << R.getPopcornPrice(i) << endl;
            }
        }
        else
        {
            invalid = true;
        }
    }

    void FoodVendingMode:: selectType(RestockMode R)
    {
        cout << "CHOOSE BETWEEN THE TWO: ";
        cout << "\n\t\t1. DRINKS\n\t\t2. POPCORNS\n\t\t";
        cin >> choose;
        displayMenu(R);
    }

    void FoodVendingMode:: selectItem(RestockMode r, CashHandlingMode c)
    {
        cout << "PLEASE ENTER THE RESPECTIVE SERIAL NUMBER FOR THE ITEM: ";
        cin >> selection;
        if (choose == 1)
        {
            if (selection > 0 && selection <= r.getDrinkArraySize())
            {
                checkItem(r, c);
            }
            else
            {
                invalid = true;
            }
        }

        if (choose == 2)
        {
            if (selection > 0 && selection <= r.getPopcornArraySize())
            {
                checkItem(r, c);
            }
            else
            {
                invalid = true;
            }
        }
    }

    void FoodVendingMode:: checkItem(RestockMode r, CashHandlingMode c)
    {
        if (choose == 1)
        {
            if (r.getDrinkLiters(selection - 1) > 0)
            {
            }
            else
            {
                cout << "ITEM IS NOT AVAILABLE";
                invalid = true;
            }
        }
        if (choose == 2)
        {
            if (r.getPopcornQuantity(selection - 1) > 0)
            {
            }
            else
            {
                cout << "ITEM IS NOT AVAILABLE";
                invalid = true;
            }
        }
    }

    void FoodVendingMode:: insertCash(RestockMode r, CashHandlingMode c)
    {
        cout << "\n\t\tPLEASE INSERT CASH\n\t\t";
        cin >> entered_cash;

        setTotalCash();
        checkCash(r, c);
    }

    void FoodVendingMode:: setTotalCash()
    {
        total_cash += entered_cash;
    }

    void FoodVendingMode:: checkCash(RestockMode r, CashHandlingMode c)
    {
        if (choose == 1)
        {
            if (r.getDrinkPrice(selection - 1) <= total_cash)
            {
                cout << "PLEASE COLLECT YOUR ITEM FROM BELOW" << endl;
                cash_return = total_cash - r.getDrinkPrice(selection - 1);
                cout << "\nHERE IS YOUR CHANGE " << cash_return << endl;
                system("pause");
                system("CLS");
                invalid = false;
            }
            else
            {
                cout << "\nNOT ENOUGH AMOUNT\n";
                invalid = true;
            }
        }

        if (choose == 2)
        {
            if (r.getPopcornPrice(selection - 1) <= total_cash)
            {
                cout << "PLEASE COLLECT YOUR ITEM FROM BELOW" << endl;
                cash_return = total_cash - r.getPopcornPrice(selection - 1);
                cout << "HERE IS YOUR CHANGE " << cash_return << endl;
                system("pause");
                system("CLS");
                invalid = false;
            }
            else
            {
                cout << "\nNOT ENOUGH AMOUNT\n";
                invalid = true;
            }
        }
    }

    int FoodVendingMode:: getCashReturn()
    {
        return cash_return;
    }

    int FoodVendingMode:: getSelection()
    {
        return selection;
    }

    int FoodVendingMode:: getChoose()
    {
        return choose;
    }

    int FoodVendingMode:: getEnteredCash()
    {
        return entered_cash;
    }
    void FoodVendingMode:: setInvalid()
    {
        invalid = false;
    }

    bool FoodVendingMode:: getInvalid()
    {
        return invalid;
    }

//------------------------------------------


    void Card_managment :: setdata()
    {
        cout << "ENTER CARD ID:";
        cin >> cardID;
        cout << "ENTER YOUR PASSWORD:";
        cin >> password;
        cout << "SUCCESFULL\n";
    }

    void Card_managment :: display()
    {
        rupees = rand() % 10000;

        cout << "TOTAL RUPEES" << rupees << endl;
    }




