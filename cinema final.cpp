#include <iostream>
#include <unistd.h> //sleep
#include <vector>
#include <string.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

using namespace std;
struct Hall
{
    string name;
    int profit;
    int hallPrice; // هر سالن یک قیمت صندلی مربوط به خود دارد
    string playTime[7][4];
    int totalCapacity;
};
struct Ticket
{
    string customerName;
    string movieName;
    string hallName;
    string phoneNumber;
    int totalPrice; // جمع مبلغ کل صندلی های خریداری شده در این بلیط
    int playDay;    // ایندکس تایم
    int playTime;   // ایندکس روز
    string id;
    int chairNumber[50]; // ماکسیمم تعداد صندلی که با یک بلیط میتوان خرید را ۵۰ در نظر گرفتم و در این ارایه شماره صندلی های خریداری شده است
    int chairNumberSize;
};
struct PlayMovie
{
    string movieName;
    string hallName;
    int timeIndex;
    int dayIndex;
    int hallPrice;
    int capacity;
    int totalCapacity;
    string id;
};
struct HallsChairsProfit
{
    string hallName;
    int chairsProfit;
};
struct MoviesChairsProfit
{
    string movieName;
    int chairsProfit;
};
struct TimesChairsProfit
{
    int playDay;
    int playTime;
    int chairsProfit;
};

vector<Ticket> tickets;
vector<Hall> halls;
vector<string> movieName;
vector<PlayMovie> playMovies;
bool first_time = true;
bool increaseChair = false;

const string ADMIN_USERNAME = "azaz";
const string ADMIN_PASSWORD = "777";

void customer_menu();
void show_all_movies();
void admin_menu();
void admin_login();
void show_all_movies_time(int);
void show_graphic_design_of_the_chair(PlayMovie, bool, int);
void ticket_making(PlayMovie);
string dayConvertor(int);
string timeConvertor(int);
void add_a_new_hall();
void add_a_new_movie();
void best_selling_hall();
void ticket_sales_profit_for_each_hall();
void profit_from_the_sale_of_each_film_in_the_cinema();
void profit_from_the_sale_of_each_movie_in_each_hall();
void best_selling_movie();
void the_busiest_time_of_the_day();
void show_all_movies();
void delete_a_movie();
void delete_a_hall();
void show_all_hall();
void Increased_ticket_chair();
void increase_chair(PlayMovie, int);
void delete_ticket();

int main()
{
    Hall hallOne = {
        "hallOne",
        0,
        100,
        {
            {"MovieTwo", "MovieOne", "MovieTwo", ""},
            {"", "", "", ""},
            {"", "", "", ""},
            {"", "", "", ""},
            {"", "", "", ""},
            {"", "", "", ""},
            {"", "", "MovieTwo", ""},
        },
        40,
    };
    Hall hallTwo = {
        "hallTwo",
        0,
        200,
        {
            {"", "", "MovieTwo", ""},
            {"", "", "", ""},
            {"", "", "", ""},
            {"", "", "", ""},
            {"", "", "", ""},
            {"", "", "", ""},
            {"", "", "", ""},
        },
        40,
    };

    halls.push_back(hallOne);
    halls.push_back(hallTwo);

    int maxProfitHall = 0;
    string maxProfitHallName;

    for (int i = 0; i < halls.size(); i++)
    {
        if (maxProfitHall < halls[i].profit)
        {
            maxProfitHall = halls[i].profit;
            maxProfitHallName = halls[i].name;
        }
    }

    movieName.push_back("MovieOne");
    movieName.push_back("MovieTwo");

    PlayMovie movieOne = {"MovieOne", "hallOne", 1, 0, 100, 38, 40, "ddddd"};
    PlayMovie movieTwo = {"MovieTwo", "hallOne", 0, 0, 100, 40, 40, "kkkkk"};
    PlayMovie movieTwo1 = {"MovieTwo", "hallOne", 2, 0, 100, 40, 40, "llll"};
    PlayMovie movieTwo2 = {"MovieTwo", "hallOne", 2, 6, 100, 40, 40, "sssss"};
    PlayMovie movieTwo3 = {"MovieTwo", "hallTwo", 02, 0, 200, 40, 40, "kkkkk"};
    playMovies.push_back(movieOne);
    playMovies.push_back(movieTwo);
    playMovies.push_back(movieTwo1);
    playMovies.push_back(movieTwo2);
    playMovies.push_back(movieTwo3);

    string movieName;
    string hallName;
    int timeIndex;
    int dayIndex;
    int hallPrice;
    int capacity;
    int totalCapacity;
    string id;

    Ticket ticketOne = {
        "dana",
        "MovieOne",
        "hallOne",
        "09123456789",
        200,
        0,
        1,
        "TEST",
        {10, 5},
        2};

    tickets.push_back(ticketOne);

    if (first_time)
    {
        cout << BOLDYELLOW << "---WELCOME---" << RESET << endl;
        first_time = false;
    }

    cout << BOLDYELLOW << "select your user type: " << endl
         << RESET;

    cout << BOLDYELLOW << "1." << RESET << CYAN << "Admin" << RESET << endl;
    cout << BOLDYELLOW << "2." << RESET << CYAN << "Customer" << RESET << endl;
    cout << BOLDYELLOW << "3." << RESET << CYAN << "Exit" << RESET << endl;
    int user_type;
    cin >> user_type;

    switch (user_type)
    {
    case 1:
        admin_login();
        break;
    case 2:
        customer_menu();
        break;
    case 3:
        cout << BOLDYELLOW << "Have a nice day" << RESET;
        exit(0);
        break;
    default:
        break;
    }
}
void admin_login()
{

    cout << BOLDYELLOW << "Enter username: " << RESET;
    string username;
    cin >> username;

    cout << BOLDYELLOW << "Enter password: " << RESET;
    string password;
    cin >> password;

    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD)
        admin_menu();
    else
    {
        cout << BOLDRED << "Error: Authentication error" << RESET << endl;
        sleep(1);
        main();
    }
}
void admin_menu()
{
    cout << BOLDYELLOW << "1." << RESET << CYAN << "Add a new hall" << RESET << endl;
    cout << BOLDYELLOW << "2." << RESET << CYAN << "Add a new movie" << RESET << endl;
    cout << BOLDYELLOW << "3." << RESET << CYAN << "Show all hall" << RESET << endl;
    cout << BOLDYELLOW << "4." << RESET << CYAN << "Show all movies" << RESET << endl;
    cout << BOLDYELLOW << "5." << RESET << CYAN << "Delete a hall" << RESET << endl;
    cout << BOLDYELLOW << "6." << RESET << CYAN << "Delete a movie" << RESET << endl;
    cout << BOLDYELLOW << "7." << RESET << CYAN << "Display ticket sales profit for each hall" << RESET << endl;
    cout << BOLDYELLOW << "8." << RESET << CYAN << "The profit from the sale of each film in the cinema" << RESET << endl;
    cout << BOLDYELLOW << "9." << RESET << CYAN << "Profit from the sale of each movie in each hall" << RESET << endl;
    cout << BOLDYELLOW << "10." << RESET << CYAN << "The best selling hall" << RESET << endl;
    cout << BOLDYELLOW << "11." << RESET << CYAN << "The best selling movie " << RESET << endl;
    cout << BOLDYELLOW << "12." << RESET << CYAN << "The busiest time of the day" << RESET << endl;
    cout << BOLDYELLOW << "0." << RESET << CYAN << "Back" << RESET << endl;

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 0:
        main();
        break;
    case 1:
        add_a_new_hall();
        sleep(1);
        break;
    case 2:
        add_a_new_movie();
        sleep(1);
        break;
    case 3:
        show_all_hall();
        int choice1;
        cin >> choice1;
        if (choice1 == 0)
        {
            admin_menu();
        }

        sleep(1);
        break;
    case 4:
        show_all_movies();
        int choice2;
        cin >> choice2;
        if (choice2 == 0)
        {
            admin_menu();
        }
        sleep(1);
        break;
    case 5:
        delete_a_hall();
        sleep(1);
        break;
    case 6:
        delete_a_movie();
        sleep(1);
        break;
    case 7:
        ticket_sales_profit_for_each_hall();
        sleep(1);
        break;
    case 8:
        profit_from_the_sale_of_each_film_in_the_cinema();
        sleep(1);
        break;
    case 9:
        profit_from_the_sale_of_each_movie_in_each_hall();
        sleep(1);
        break;
    case 10:
        best_selling_hall();
        sleep(1);
        break;
    case 11:
        best_selling_movie();
        sleep(1);
        break;
    case 12:
        the_busiest_time_of_the_day();
        sleep(1);
        break;
    default:
        cout << "Error!" << endl;
        break;
    }
    main();
}
void customer_menu()
{
    cout << BOLDYELLOW << "1." << RESET << CYAN << "Show all movies" << RESET << endl;
    cout << BOLDYELLOW << "2." << RESET << CYAN << "Increasing the number of chair in purchased tickets" << RESET << endl;
    cout << BOLDYELLOW << "3." << RESET << CYAN << "Delete ticket" << RESET << endl;
    cout << BOLDYELLOW << "0." << RESET << CYAN << "Back" << RESET << endl;
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        show_all_movies();
    }
    else if (choice == 2)
    {
        Increased_ticket_chair();
    }
    else if (choice == 3)
    {
        delete_ticket();
    }
    else if (choice == 0)
    {
        main();
    }
}
void show_all_movies()
{
    for (int i = 0; i < playMovies.size(); i++)
    {
        cout << BOLDYELLOW << i + 1 << "." << RESET << CYAN << playMovies.at(i).movieName << RESET << endl;
    }
    cout << BOLDYELLOW << "0." << RESET << CYAN << "Back" << RESET << endl;

    int choice;
    cin >> choice;
    if (choice != 0)
        show_all_movies_time(choice);
    else
        main();
}
void show_all_movies_time(int choice)
{
    string chosenMovie = playMovies.at(choice - 1).movieName;

    // پیدا کردن لوکیشن پخش فیلم مورد نظر در تمام سالن ها
    for (int i = 0; i < halls.size(); i++)
    {
        for (int j = 0; j < 7; j++)
        {
            for (int z = 0; z < 4; z++)
            {
                if (halls.at(i).playTime[j][z] == chosenMovie)
                {
                    PlayMovie PchosenMovie = {playMovies.at(choice - 1).movieName, halls.at(i).name, z, j, halls.at(i).hallPrice, halls.at(i).totalCapacity, halls.at(i).totalCapacity}; // مقدار دهی به استراکت انتخاب شده مشتری
                    playMovies.push_back(PchosenMovie);
                }
            }
        }
    }

    for (int i = 0; i < playMovies.size(); i++)
    {
        //  تبدیل ایندکس روز به اسم ان درروز های هفته
        string day = dayConvertor(playMovies[i].dayIndex);

        // تبدیل ایندکس تایم به بازه تایم
        string time = timeConvertor(playMovies[i].timeIndex);

        cout << BOLDYELLOW << (i + 1) << '.' << RESET << CYAN << playMovies.at(i).hallName << RESET << '|';
        cout << CYAN << day << RESET << '|';
        cout << CYAN << time << RESET << '|';
        cout << CYAN << "remaining capacity:" << playMovies.at(i).capacity << RESET << '|';
        cout << CYAN << playMovies.at(i).hallPrice << '$' << RESET << endl;
    }
    cout << BOLDYELLOW << "0." << RESET << CYAN << "back" << RESET << endl;
    int pChoice;

    // انتخاب یکی از پخش های فیلم مورد نظر
    cin >> pChoice;
    if (pChoice != 0)
    {
        // ایندکس بلیط
        show_graphic_design_of_the_chair(playMovies.at(pChoice - 1), increaseChair, (tickets.size() + 1));
    }
    else
    {
        main();
    }
}
void show_graphic_design_of_the_chair(PlayMovie timeAndHall, bool IncreaseChair, int indexTicket)
{
    bool reserved = false;
    int chairs[timeAndHall.totalCapacity];
    for (int i = 0; i < timeAndHall.totalCapacity; i++)
    {
        for (int j = 0; j < tickets.size(); j++)
        {
            // روی تمامی بلیط های صادر شده تا به الان و زیر شاخه تعداد صندلی های رزرو شده میگردد
            for (int z = 0; z < tickets[j].chairNumberSize; z++)
            {
                // اگر مشابه صندلی مورد نظر باشد خارج می شود
                if (i == tickets[j].chairNumber[z])
                {
                    reserved = true;
                    break;
                }
            }
            if (reserved)
            {
                break;
            }
        }

        if (reserved)
        {
            chairs[i] = 0;
            reserved = false;
        }
        else
        {
            chairs[i] = i + 1;
        }
    }
    int z = 0;
    // چاپ شماره صندلی ها به طور گرافیکی
    for (int i = 0; i < timeAndHall.totalCapacity / 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // کنار اعداد یک رقمی یک صفر بگذارد در حین چاپ
            if (chairs[z] < 10 && chairs[z] != 0)
            {
                cout << BOLDGREEN << "0" << chairs[z] << RESET << " | ";
                z++;
            }
            else if (chairs[z] >= 10 && chairs[z] != 0)
            {
                cout << BOLDGREEN << chairs[z] << RESET << " | ";
                z++;
            }
            else if (chairs[z] == 0)
            {
                cout << BOLDRED << "0" << chairs[z] << RESET << " | ";
                z++;
            }
        }
        cout << endl;
    }
    if (increaseChair)
    {
        increase_chair(timeAndHall, indexTicket);
        increaseChair = false;
    }
    else
    {
        ticket_making(timeAndHall);
    }
}
void ticket_making(PlayMovie timeAndHall)
{
    bool isOk = true;
    Ticket newTicket;
    cout << BOLDYELLOW << "enter the number of chairs you want to reserve:" << RESET;
    
    // دریافت تعداد صندلی
    int chNumner;
    cin >> chNumner;
    int ch;
    for (int i = 0; i < chNumner; i++)
    {
        // دریافت شماره صندلی ها
        cin >> ch;
        if (ch == 0)
        {
            isOk = false;
        }
        else
        {
            newTicket.chairNumber[i] = ch;
        }
    }
    if (isOk)
    {
        string customerName;
        cout << BOLDYELLOW << "Enter Your Name:" << RESET;
        cin >> customerName;

        string phoneNumber;
        cout << BOLDYELLOW << "Enter Your phoneNumber:" << RESET;
        cin >> phoneNumber;

        newTicket.customerName = customerName;
        newTicket.movieName = timeAndHall.movieName;
        newTicket.hallName = timeAndHall.hallName;
        newTicket.phoneNumber = phoneNumber;
        newTicket.totalPrice = chNumner * (timeAndHall.hallPrice);
        newTicket.playDay = timeAndHall.dayIndex;
        newTicket.playTime = timeAndHall.timeIndex;
        newTicket.chairNumberSize = chNumner;

        string id = "";
        id = id.append(phoneNumber).append(to_string(newTicket.playDay)).append(to_string(newTicket.playTime));
        newTicket.id = id;
        // بررسی تکراری نبودن شناسه
        bool invalidId = false;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (tickets[i].id == newTicket.id)
            {
                invalidId = true;
                break;
            }
        }
        if (invalidId)
        {
            cout << BOLDYELLOW << "You already booked a ticket for this time" << RESET;
            main();
        }
        else
        {
            // چاپ اطلاعات بلیط
            cout << BOLDYELLOW << "_____Your ticket information____" << RESET << endl;
            cout << YELLOW << "customer Name:" << RESET << CYAN << newTicket.customerName << RESET << endl;
            cout << YELLOW << "movie Name:" << RESET << CYAN << newTicket.movieName << RESET << endl;
            cout << YELLOW << "hall Name:" << RESET << CYAN << newTicket.hallName << RESET << endl;
            cout << YELLOW << "total Price:" << RESET << CYAN << newTicket.totalPrice << "$" << RESET << endl;
            cout << YELLOW << "time:" << RESET << CYAN << timeConvertor(newTicket.playTime) << RESET << endl;
            cout << YELLOW << "day:" << RESET << CYAN << dayConvertor(newTicket.playDay) << RESET << endl;
            cout << YELLOW << "Number of reserved chairs:" << RESET << CYAN << newTicket.chairNumberSize << RESET << endl;
            cout << YELLOW << "The number of chairs purchased:" << RESET;
            for (int i = 0; i < chNumner; i++)
            {
                cout << CYAN << newTicket.chairNumber[i] << RESET;
            }
            cout << endl;
            cout << YELLOW << "customer Id:" << RESET << CYAN << newTicket.id << RESET << endl;
            cout << BOLDYELLOW << "1." << RESET << CYAN << "accept" << RESET << endl;
            cout << BOLDYELLOW << "0." << RESET << CYAN << "back" << RESET << endl;
        }
        // دریافت دستور تایید اطلاعات و خرید بلیط
        int Achoice;
        cin >> Achoice;
        if (Achoice == 1)
        {
            tickets.push_back(newTicket);
            cout << BOLDYELLOW << "The ticket was registered" << endl
                 << RESET;
            main();
        }
        else
        {
            main();
        }
    }
    else
    {
        cout << BOLDRED << "Error: You chose wrong chair number!" << RESET << endl;
        main();
    }
}

// تبدیل ایندکس تایم به تایم
string timeConvertor(int time)
{
    string newTime;
    switch (time)
    {
    case 0:
        newTime = "9-10:30";
        break;
    case 1:
        newTime = "11-12:30";
        break;
    case 2:
        newTime = "15-16:30";
        break;
    case 3:
        newTime = "17-18:30";
        break;

    default:
        break;
    }

    return newTime;
}

// تبدیل ایندکس روز به روز
string dayConvertor(int day)
{
    string newDay;
    switch (day)
    {
    case 0:
        newDay = "Sunday";
        break;
    case 1:
        newDay = "Saturday";
        break;
    case 2:
        newDay = "Monday";
        break;
    case 3:
        newDay = "Tuesday";
        break;
    case 4:
        newDay = "Wednesday";
        break;
    case 5:
        newDay = "Thersday";
        break;
    case 6:
        newDay = "Friday";
        break;

    default:
        break;
    }
    return newDay;
}
void add_a_new_hall()
{
    Hall newHall;

    cout << BOLDYELLOW << "enter the name of new hall:  " << RESET;
    cin >> newHall.name;

    cout << BOLDYELLOW << "enter the hall Price of new hall:  " << RESET;
    cin >> newHall.hallPrice;

    cout << BOLDYELLOW << "enter the  total Capacity of new hall:  " << RESET;
    cin >> newHall.totalCapacity;

    halls.push_back(newHall);
    cout << BOLDYELLOW << "a new hall was added" << RESET << endl;
    admin_menu();
}
void add_a_new_movie()
{
    int chosenHallIndex;
    int chosenDayIndex;
    int chosenTimeIndex;
    for (int i = 0; i < halls.size(); i++)
    {
        cout << BOLDYELLOW << (i + 1) << '.' << RESET << CYAN << halls.at(i).name << RESET << endl;
    }
    cin >> chosenHallIndex;

    // چاپ جدول پخش سالن مورد نظر
    for (int i = 0; i < 7; i++)
    {
        switch (i)
        {
        case 0:
            cout << BOLDMAGENTA << "Sunday: " << RESET;
            break;
        case 1:
            cout << BOLDMAGENTA << "Saturday: " << RESET;
            break;
        case 2:
            cout << BOLDMAGENTA << "Monday: " << RESET;
            break;
        case 3:
            cout << BOLDMAGENTA << "Tuesday: " << RESET;
            break;
        case 4:
            cout << BOLDMAGENTA << "Thursday: " << RESET;
            break;
        case 5:
            cout << BOLDMAGENTA << "Wednesday: " << RESET;
            break;
        case 6:
            cout << BOLDMAGENTA << "Friday: " << RESET;
            break;

        default:
            break;
        }
        for (int j = 0; j < 4; j++)
        {
            if (halls.at(chosenHallIndex - 1).playTime[i][j] == "")
            {
                cout << GREEN << "Empty" << RESET << " , ";
            }
            else
            {
                cout << BOLDRED << halls.at(chosenHallIndex - 1).playTime[i][j] << RESET << " , ";
            }
        }
        cout << endl;
        cout << endl;
    }

    cout << endl;
    cout << BOLDYELLOW << "First enter the line and then the column of the playback time you want:" << RESET << endl;
    cin >> chosenDayIndex >> chosenTimeIndex;

    // چک کردن خالی بودن لوکیشن پخش فیلم
    if (halls.at(chosenHallIndex - 1).playTime[chosenDayIndex - 1][chosenTimeIndex - 1] == "")
    {
        // ساخت یک ساختمان برای فیلم جدید
        PlayMovie newMovie;
        string id = "";
        cout << BOLDYELLOW << "Enter the name of the new movie:  " << RESET << endl;
        cin >> newMovie.movieName;
        newMovie.id = id.append(newMovie.movieName).append(halls.at(chosenHallIndex - 1).name).append(to_string(chosenDayIndex)).append(to_string(chosenTimeIndex));
        playMovies.push_back(newMovie);
        movieName.push_back(newMovie.movieName);
    }
    // اگر لوکیشن پخش مورد نظر خالی نبود
    else
    {
        cout << BOLDRED << "Error:You chose a full time!" << RESET << endl;
        sleep(1);
    }
    admin_menu();
}
void ticket_sales_profit_for_each_hall()
{
    for (int i = 0; i < halls.size(); i++)
    {
        int profit = 0;
        for (int j = 0; j < tickets.size(); j++)
        {
            if (halls.at(i).name == tickets.at(j).hallName)
            {
                profit += tickets.at(j).totalPrice;
            }
        }
        cout << BOLDMAGENTA << halls.at(i).name << " : " << RESET << CYAN << profit << "$" << RESET << endl;
    }
    admin_menu();
}
void profit_from_the_sale_of_each_film_in_the_cinema()
{
    for (int i = 0; i < movieName.size(); i++)
    {
        int profit = 0;
        for (int j = 0; j < tickets.size(); j++)
        {
            if (movieName.at(i) == tickets.at(j).movieName)
            {
                profit += tickets.at(j).totalPrice;
            }
        }
        cout << BOLDMAGENTA << movieName.at(i) << " : " << RESET << CYAN << profit << "$" << RESET << endl;
    }
    admin_menu();
}
void profit_from_the_sale_of_each_movie_in_each_hall()
{
    for (int i = 0; i < movieName.size(); i++)
    {
        for (int j = 0; j < halls.size(); j++)
        {
            int profit = 0;
            for (int k = 0; k < tickets.size(); k++)
            {
                if (tickets.at(k).movieName == movieName.at(i) && tickets.at(k).hallName == halls.at(j).name)
                {
                    profit += tickets.at(k).totalPrice;
                }
            }
            cout << BOLDMAGENTA << "movie name :" << RESET << CYAN << movieName.at(i) << endl
                 << RESET;
            cout << BOLDMAGENTA << "hall name :" << RESET << CYAN << halls.at(j).name << endl
                 << RESET;
            cout << BOLDMAGENTA << "profit :" << CYAN << profit << endl
                 << RESET;
            cout << BOLDYELLOW << "____________________________" << endl
                 << RESET;
        }
    }
    admin_menu();
}
void best_selling_hall()
{
    vector<HallsChairsProfit> hallsChairsProfit;
    HallsChairsProfit newHallsChairsProfit;
    string maxHall;
    int maxChairsProfit = 0;

    // ساخت وکتور با ساختمان سالن و تعداد کل صندلی های فروخته شده اش در کل تایم ها
    for (int i = 0; i < halls.size(); i++)
    {
        int chairsProfit = 0;
        for (int j = 0; j < tickets.size(); j++)
        {
            if (halls.at(i).name == tickets.at(j).hallName)
            {
                chairsProfit += tickets.at(j).chairNumberSize;
            }
        }
        // پیدا کردن ماکسیمم تعداد صندلی فروخته شده در کل تایم ها
        if (chairsProfit > maxChairsProfit)
        {
            maxChairsProfit = chairsProfit;
        }

        newHallsChairsProfit.hallName = halls.at(i).name;
        newHallsChairsProfit.chairsProfit = chairsProfit;
        hallsChairsProfit.push_back(newHallsChairsProfit);
    }

    // پیدا کردن سالن هایی که ماکسیمم تعداد صندلی فروخته شده در کل تایم ها را دارند
    for (int i = 0; i < hallsChairsProfit.size(); i++)
    {
        if (hallsChairsProfit.at(i).chairsProfit == maxChairsProfit)
        {
            cout << BOLDMAGENTA << "hall name :" << RESET << CYAN << hallsChairsProfit.at(i).hallName << endl
                 << RESET;
        }
        cout << BOLDMAGENTA << "The total number of chairs sold for this hall/halls :" << RESET << CYAN << maxChairsProfit << endl
             << RESET;
    }
    admin_menu();
}
void best_selling_movie()
{
    vector<MoviesChairsProfit> moviesChairsProfit;
    MoviesChairsProfit newMoviesChairsProfit;
    string maxMovie;
    int maxChairsProfit = 0;

    // ساخت وکتور با ساختمان فیلم و تعداد کل صندلی های فروخته شده اش در کل تایم ها
    for (int i = 0; i < movieName.size(); i++)
    {
        int chairsProfit = 0;
        for (int j = 0; j < tickets.size(); j++)
        {
            if (movieName.at(i) == tickets.at(j).movieName)
            {
                chairsProfit += tickets.at(j).chairNumberSize;
            }
        }

        // پیدا کردن ماکسیمم تعداد صندلی فروخته شده در کل تایم ها
        if (chairsProfit > maxChairsProfit)
        {
            maxChairsProfit = chairsProfit;
        }

        newMoviesChairsProfit.movieName = halls.at(i).name;
        newMoviesChairsProfit.chairsProfit = chairsProfit;
        moviesChairsProfit.push_back(newMoviesChairsProfit);
    }

    // پیدا کردن فیلم هایی که ماکسیمم تعداد صندلی فروخته شده در کل تایم ها را دارند
    for (int i = 0; i < moviesChairsProfit.size(); i++)
    {
        if (moviesChairsProfit.at(i).chairsProfit == maxChairsProfit)
        {
            cout << BOLDMAGENTA << "Hall name :" << RESET << CYAN << moviesChairsProfit.at(i).movieName << endl
                 << RESET;
        }
        cout << BOLDMAGENTA << "The total number of chairs sold for this hall/halls :" << RESET << CYAN << maxChairsProfit << endl
             << RESET;
    }
    admin_menu();
}
void the_busiest_time_of_the_day()
{
    vector<TimesChairsProfit> timesChairsProfit;
    TimesChairsProfit newTimesChairsProfit;
    string maxMovie;

    // پیمایش روی ایندکس روز های پخش
    for (int i = 0; i < 7; i++)
    {
        int maxChairsProfit = 0;
        int indexMaxChairsProfit = 0;

        // پیمایش روی ایندکس تایم های پخش
        for (int j = 0; j < 4; j++)
        {
            int chairsProfit = 0;
            for (int k = 0; k < tickets.size(); k++)
            {
                if (tickets.at(k).playTime == j && tickets.at(k).playDay == i)
                {
                    chairsProfit += tickets.at(k).chairNumberSize;
                }
            }
            newTimesChairsProfit.playDay = i;
            newTimesChairsProfit.playTime = j;
            newTimesChairsProfit.chairsProfit = chairsProfit;
            timesChairsProfit.push_back(newTimesChairsProfit);

            // پیدا کردن ماکسیمم تعداد صندلی فروخته شده در هر تایم
            if (chairsProfit > maxChairsProfit)
            {
                maxChairsProfit = chairsProfit;
                indexMaxChairsProfit = j;
            }
        }
        for (int z = 0; z < timesChairsProfit.size(); z++)
        {
            if (timesChairsProfit.at(z).playDay == i && timesChairsProfit.at(z).chairsProfit == maxChairsProfit)
            {
                cout << dayConvertor(i) << " : " << endl;
                cout << BOLDMAGENTA << "Busiest time : " << RESET << CYAN << timeConvertor(timesChairsProfit.at(z).playTime) << endl
                     << RESET;
                cout << BOLDMAGENTA << "Number of chairs sold for this time : " << RESET << CYAN << maxChairsProfit << endl
                     << RESET;
                cout << BOLDYELLOW << "____________________________________________________" << endl
                     << RESET;
            }
        }
    }
    admin_menu();
}

void delete_a_movie()
{
    for (int i = 0; i < movieName.size(); i++)
    {
        cout << BOLDYELLOW << i + 1 << "." << RESET << CYAN << movieName.at(i) << RESET << endl;
    }
    cout << BOLDYELLOW << "0." << RESET << CYAN << "back" << RESET << endl;

    int choice;
    cin >> choice;
    string selectedMovie;

    // یافتن اسم فیلم مورد نظر برای حذف
    for (int i = 0; i < movieName.size(); i++)
    {
        if (choice - 1 == i)
        {
            selectedMovie = movieName.at(i);
            break;
        }

        // پاک کردن فیلم مورد نظراز ارایه فیلم ها
        movieName.erase(movieName.begin() + i);
    }
    if (choice == 0)
    {
        admin_menu();
    }

    // پاک کردن تمامی بلیط هایی که برای فیلمی که حذف شده است خریداری شده بودند
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets.at(i).movieName == selectedMovie)
        {
            tickets.erase(tickets.begin() + i);
        }
    }

    // پاک کردن فیلم حذف شده از ارایه پخش فیلم
    for (int i = 0; i < playMovies.size(); i++)
    {
        if (playMovies.at(i).movieName == selectedMovie)
        {
            playMovies.erase(playMovies.begin() + i);
        }
    }

    // پاک کردن فیلم حذف شده در جدول پخش سالن ها
    for (int k = 0; k < halls.size(); k++)
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (halls.at(k).playTime[i][j] == selectedMovie)
                {
                    halls.at(k).playTime[i][j] = "";
                }
            }
        }
    }
    cout << BOLDYELLOW << "The selected movie was deleted" << endl
         << RESET;
    sleep(1);
    admin_menu();
}

// چاپ اسامی سالن ها
void show_all_hall()
{
    for (int i = 0; i < halls.size(); i++)
    {
        cout << BOLDYELLOW << i + 1 << "." << RESET << CYAN << halls.at(i).name << RESET << endl;
    }
    cout << BOLDYELLOW << "0." << RESET << CYAN << "back" << RESET << endl;
}
void delete_a_hall()
{
    show_all_hall();
    int choice;
    cin >> choice;
    string selectedHall;

    // یافتن اسم سالن مورد نظر برای حذف
    for (int i = 0; i < halls.size(); i++)
    {
        if (choice - 1 == i)
        {
            selectedHall = halls.at(i).name;
            break;
        }

        // پاک کردن سالن مورد نظراز ارایه سالن ها
        halls.erase(halls.begin() + i);
    }
    if (choice == 0)
    {
        admin_menu();
    }

    // پاک کردن تمامی بلیط هایی که برای سالنی که حذف شده است خریداری شده بودند
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets.at(i).hallName == selectedHall)
        {
            tickets.erase(tickets.begin() + i);
        }
    }
    cout << BOLDYELLOW << "The selected hall was removed" << endl
         << RESET;
    admin_menu();
}
void Increased_ticket_chair()
{
    string phoneNumber;
    cin >> phoneNumber;
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets.at(i).phoneNumber == phoneNumber)
        {

            //  تبدیل ایندکس روز به اسم ان درروز های هفته
            string day = dayConvertor(tickets.at(i).playDay);

            // تبدیل ایندکس تایم به بازه تایم
            string time = timeConvertor(tickets.at(i).playTime);

            // چاپ اطلاعات بلیط های خریداری شده کاربر
            cout << BOLDYELLOW << (i + 1) << '.' << RESET << CYAN << tickets.at(i).movieName << RESET << '|';
            cout << CYAN << tickets.at(i).hallName << RESET << '|';
            cout << CYAN << day << RESET << '|';
            cout << CYAN << time << RESET << '|';
            cout << BOLDYELLOW << "Number of chair:" << RESET << CYAN << tickets.at(i).chairNumberSize << RESET << '|';
        }
        cout << endl;
    }
    cout << BOLDYELLOW << "Choose the ticket you want:" << RESET;
    int choice;
    cin >> choice;
    PlayMovie timeAndHall;
    for (int i = 0; i < playMovies.size(); i++)
    {
        // پیدا کردن پخشی که بلیط برای ان صادر شده
        if (playMovies.at(i).movieName == tickets.at(choice - 1).movieName && playMovies.at(i).hallName == tickets.at(choice - 1).hallName && playMovies.at(i).timeIndex == tickets.at(choice - 1).playTime && playMovies.at(i).dayIndex == tickets.at(choice - 1).playDay)
        {
            timeAndHall = playMovies.at(i);
            break;
        }
    }

    increaseChair = true;

    show_graphic_design_of_the_chair(timeAndHall, increaseChair, (choice - 1));
}
void increase_chair(PlayMovie timeAndHall, int indexTicket)
{
    bool isOk = true;
    Ticket newTicket;
    cout << BOLDYELLOW << "enter the number of chairs you want to reserve:" << RESET;

    // دریافت تعداد صندلی
    int chNumner;
    cin >> chNumner;
    int chairsNum[chNumner];

    // قیمت هر صندلی در ای سالن برابر است با تقسیم قیمت کل بلیط بر تعداد کل صندلی هایش
    int hallPrice = tickets.at(indexTicket).totalPrice / tickets.at(indexTicket).chairNumberSize;

    int ch;
    for (int i = 0; i < chNumner; i++)
    {
        // دریافت شماره صندلی ها
        cin >> ch;
        if (ch == 0)
        {
            isOk = false;
        }
        else
        {
            chairsNum[i] = ch;
        }
    }
    if (isOk)
    {
        for (int i = 0; i < chNumner; i++)
        {

            newTicket.chairNumber[tickets.at(indexTicket).chairNumberSize + i] = chairsNum[i];
        }
        tickets.at(indexTicket).chairNumberSize += chNumner;

        // تعداد صندلی های کل ضربدر قیمت صندلی در سالن میشود قیمت کل
        tickets.at(indexTicket).totalPrice = tickets.at(indexTicket).chairNumberSize * hallPrice;

        // چاپ اطلاعات بلیط
        cout << BOLDYELLOW << "_____Your ticket information____" << RESET << endl;
        cout << YELLOW << "customer Name:" << RESET << CYAN << newTicket.customerName << RESET << endl;
        cout << YELLOW << "movie Name:" << RESET << CYAN << newTicket.movieName << RESET << endl;
        cout << YELLOW << "hall Name:" << RESET << CYAN << newTicket.hallName << RESET << endl;
        cout << YELLOW << "total Price:" << RESET << CYAN << newTicket.totalPrice << "$" << RESET << endl;
        cout << YELLOW << "time:" << RESET << CYAN << timeConvertor(newTicket.playTime) << RESET << endl;
        cout << YELLOW << "day:" << RESET << CYAN << dayConvertor(newTicket.playDay) << RESET << endl;
        cout << YELLOW << "Number of reserved chairs:" << RESET << CYAN << newTicket.chairNumberSize << RESET << endl;
        cout << YELLOW << "The number of chairs purchased:" << RESET;
        for (int i = 0; i < chNumner; i++)
        {
            cout << CYAN << newTicket.chairNumber[i] << RESET;
        }
        cout << endl;
        cout << YELLOW << "customer Id:" << RESET << CYAN << newTicket.id << RESET << endl;
        sleep(1);
        main();
    }
    else
    {
        cout << BOLDRED << "Error: You chose wrong chair number!" << RESET << endl;
        sleep(1);
        main();
    }
}
void delete_ticket()
{
    string id;
    cout << BOLDYELLOW << "Enter the ID of the ticket you want to delete :" << endl
         << RESET;
    cin >> id;

    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets.at(i).id == id)
        {
            // پیدا کردن تایمز پخش فیلم مربوط به بلیط مربوط به ایدی و برگرداندن ظرفیت
            for (int j = 0; j < playMovies.size(); j++)
            {
                if (playMovies.at(j).movieName == tickets.at(i).movieName && playMovies.at(j).hallName == tickets.at(i).hallName && playMovies.at(j).timeIndex == tickets.at(i).playTime && playMovies.at(j).dayIndex == tickets.at(i).playDay)
                {
                    playMovies.at(j).capacity -= tickets.at(i).chairNumberSize;
                }
            }

            // حذف بلیط از وکتور بلیط ها
            tickets.erase(tickets.begin() + i);
        }
    }
}