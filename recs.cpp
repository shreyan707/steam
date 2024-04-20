#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void search();
void game_rec();
void after_login(); // function to run after login is succesfull, should be modified to add different functions (library, friends etc.) its a choice based program
void login();
void signin();
void forgot();
void logo(string filename)
{
    string line = "";
    ifstream steam;
    steam.open("logo.txt");
    if (steam.is_open())
    {
        while (getline(steam, line))
        {
            cout << line << endl;
        }
        steam.close();
    }
}

int main()
{
    int choise;
    cout << "\t\t\t______________________________________________________________\n\n\n";
    cout << "\t\t\t                        Welcome to Steam                      \n\n\n";
    string steamy = "logo.txt";
    logo(steamy);
    cout << "\n\n\n";
    cout << "\t\t\t_____________________        MENU       ______________________\n\n\n";
    cout << "\n\n\n";
    cout << "| Press 1 to LOGIN           |" << endl;
    cout << "| Press 2 to SIGNIN          |" << endl;
    cout << "| Press 3 to FORGOT PASSWORD |" << endl;
    cout << "| Press 4 to EXIT            |" << endl;
    cout << "\n ENTER YOUR CHOICE : ";
    cin >> choise;
    cout << endl;

    switch (choise)
    {
    case 1:
        login();
        break;

    case 2:
        signin();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\t\t\t THANK YOU! \n\n";
        break;

    default:
        system("cls");
        cout << "\t\t\t Please select from the option given above \n"
             << endl;
        main();
    }
}
void search() {
    
    string game_name;
    fstream game_finder;
    game_finder.open("games.txt", fstream::in);
    cout << "Enter the game name : ";
    cin >> game_name;
    if(game_finder.is_open()){
      string game,price,genre;
      bool found = false;
      while(!game_finder.eof()){
        game_finder >> game >> price >> genre;
        if( game == game_name){
            cout << "The game you searched for is : " << game << " Price : " << price;
            cout << " Genre : " << genre;
            found = true;
            break;
        }
      }
      if (found==false){
        cout << "Game is not in the database!";
      }
    }
    else {
        cout << "Games database is empty!";
    }
    after_login();

}
void game_rec()
{
    string genre_name;
    fstream genre_finder;
    genre_finder.open("games.txt", fstream::in);
    cout << "Enter the genre(RPG, FPS, Action, Social, Battle, Sandbox, Sports, MOBA, Fighting, Adventure, Survival, MMORPG, Strategy, Simulation, Horror) : ";
    cin >> genre_name;
    if (genre_finder.is_open())
    {
        string game, price, genre;
        bool found = false;
        cout << "These are some recommended games of the same genre : ";
        while (!genre_finder.eof())
        {
            genre_finder >> game >> price >> genre;
            while (genre_name == genre)
            {
                cout << game << "  ";
                break;
            }
        }
    }
    after_login();
}
void after_login()
{

    int choices;
    cout << "\n\n\n";
    cout << "| Press 1 to view Recommended Games           |" << endl;
    cout << "| Press 2 to view Trending Games              |" << endl; // add more features
    cout << "| Press 3 to Search Games                     |" << endl;
    cout << "\n ENTER YOUR CHOICE : ";
    cin >> choices;
    switch (choices)
    {
    case 1:
      game_rec();
      break;

    case 2 :
    case 3 :
        search();
        break;
      
   
    default:
        cout << "\n\n\n";
        cout << "\t\t\t Please select from the option given above \n"
             << endl;
        main();
    }
}
void login()
{
    int count;
    string userID, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password :" << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userID;
    cout << "\t\t\t PASSWORD ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userID && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << userID << "\n Your LOGIN is successful \n Thanks for logging in ! \n";
        after_login();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your username and password \n";
        main();
    }
}

void signin()
{
    string suserID, spassword, sid, spass;
    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> suserID;
    cout << "\t\t\t Enter the password : ";
    cin >> spassword;

    ofstream f1("records.txt", ios::app);
    f1 << suserID << ' ' << spassword << endl;
    system("cls");
    cout << "\n\t\t\t Registration successfull! \n";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t FORGOT PASSWORD \n\n ";
    cout << "Press 1 to search your id by the username " << endl;
    cout << " Press 2 to go back to the main menu\n\n"
         << endl;
    cout << "\t\t\tEnter your choice : ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string fuserID, fID, fpass;
        cout << "\n\t\t\tEnter the username you remembered: ";
        cin >> fuserID;

        ifstream f2("records.txt");
        while (f2 >> fID >> fpass)
        {
            if (fID == fuserID)
            {
                count = 1;
            }
        }
        f2.close();

        if (count == 1)
        {
            cout << "\n\n Your account is found \n ";
            cout << "\n\n Your password is :\n"
                 << fpass;
            main();
        }

        else
        {
            cout << "\n\t Sorry! your account is not found!\n";
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }

    default:
        cout << "\t\t\t Wrong choice ! Please try again " << endl;
        forgot();
    }
}
