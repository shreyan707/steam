#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void search();
void game_rec();
void after_login(); // function to run after login is succesfull, should be modified to add different functions (library, friends etc.) its a choice based program
void login();
void signin();
void forgot();
void library(string gam,string pri);
void wallet();
void addgame(string g,string p);
void viewlib();

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
            string yesno;
            cout << "The game you searched for is : " << game << " Price : " << price;
            cout << " Genre : " << genre <<endl;;
            found = true;
            cout<<" Add Game?  (y/n)" <<endl;
            cin>>yesno;
            if(yesno=="y")
            {
                library(game,price);
            }
            else
            {
                after_login();
            }
            break;
        }
      }
      if (found==false){
        cout << "Game is not in the database!";
        after_login();
      }
    }
    else {
        cout << "Games database is empty!";
        after_login();
    }
    

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
    cout << "| press 4 to access Wallet                    |" << endl;
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
    case 4:
        wallet();
        break;
      
   
    default:
        cout << "\n\n\n";
        cout << "\t\t\t Please select from the option given above \n"
             << endl;
        main();
    }
}
string wal;
string userID, password, id, pass;
void login()
{
    int count;
    
    system("cls");
    cout << "\t\t\t Please enter the username and password :" << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userID;
    cout << "\t\t\t PASSWORD ";
    cin >> password;
    string line;
    fstream input("records.txt");

    while (getline(input,line))
    {
        istringstream iss(line);
        iss>>id>>pass>>wal;
        cout<<id<<" "<<pass<< " "<<wal<<endl;
        if (id == userID && pass == password)
        {
            count = 1;
            break;
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
string suserID, spassword, sid, spass;
void signin()
{

    system("cls");
    cout << "\t\t\t Enter the username : ";
    cin >> suserID;
    cout << "\t\t\t Enter the password : ";
    cin >> spassword;

    ofstream f1("records.txt", ios::app);
    f1 << suserID << ' ' << spassword <<' '<< "0"<< endl;
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
        while (f2 >> fID >> fpass >> wal)
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

void wallet()
{
    ofstream oss;
    oss.open("temp.txt",ofstream::out | ofstream::trunc);
    oss.close();
    cout<<"xxxxxxxxxxxxxxxx WALLET FEATURES XXXXXXXXXXXXXXXXXXXXXX "<<endl;
    cout<<" 1. View Wallet Balance"<<endl;
    cout<<" 2. Add Balance"<< endl;
    cout<<" 3. Back"<<endl;
    cout<<" Enter your choice: "<<endl;
    int ch;
    cin>> ch;
    switch(ch)
    {
        case 1:
            cout<<"Wallet Balance For: "<< userID <<endl;
            cout<<wal<<endl;
            break;
        case 2:
            int balance;
            int add;
            balance=stoi(wal);
            cout<<"Enter amount to be added: "<<endl;
            cin >> add;
            balance=balance+add;    

            string filen="records.txt";
            fstream file(filen);
            string line;
            string a,b,c;
            string input=userID;
            fstream tempfile("temp.txt");
            string a2,b2,c2;

            while(getline(file,line))
            {
                istringstream linevar(line);
                linevar >> a >> b >>c;
                if(a!=input)
                {
                    tempfile<<line<<endl;   
                }
                else
                {
                    a2=a;
                    b2=b;
                    c2=c;
                }
            }
            string c3=to_string(balance);
            tempfile<<a2<<" "<<b2<<" "<<c3<<endl;
            tempfile.close();
            file.close();
            ofstream ofs;
            ofs.open("records.txt",ofstream::out | ofstream::trunc);
            ofs.close();
            fstream file2("temp.txt");
            string line2;
            fstream file3("records.txt");
            while(getline(file2,line2))
            {
                file3<<line2<<endl;
            }
            file.close();
            file2.close();
            file3.close();

}
        }


void library(string gam,string pri)
{
    cout<<"OPTIONS: "<<endl;
    cout<<"1. VIEW LIBRARY"<<endl;
    cout<<"2. BUY GAME AND ADD TO LIBRARY"<<endl;
    cout<<"3. REMOVE GAME FROM LIBRARY"<<endl;
    cout<<"4. BACK"<<endl;
    cout<<"Enter your choice: "<<endl;
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
            viewlib();
            break;
        case 2:
            addgame(gam,pri);
            break;



    }


}

void addgame(string g, string p)
{
string filen="records.txt";
fstream file(filen);
string line;
string a,b,c,cedit;
string input=userID;
fstream tempfile("gametemp.txt");
string a2,b2,c2;

while(getline(file,line))
{
    istringstream linevar(line);
    linevar >> a >> b >>c;
    if(a!=input)
    {
        tempfile<<line<<"\n";   
    }
    else
    {
        c2=c;
        stringstream ss(line);
        stringstream updated;
        string w;
        vector <string> words;
        int num;
        num=stoi(c2);
        int price=stoi(p);
        num=num-price;
        string c3=to_string(num);       
        while (ss >> w) 
        {
            words.push_back(w);
        }
        words[2]=c3;
        for(int i=0; i<words.size();i++)
        {
            updated << words[i]<<" ";
            if (i != words.size() - 1) 
            {
                ss << " "; 
            }
        }
        string updatedsentence=updated.str();
        tempfile << updatedsentence << g <<endl;;
    }
        

    }

    tempfile.close();
    file.close();
    ofstream ofs,ofs1;
    ofs.open("records.txt",ofstream::out | ofstream::trunc);
    ofs.close();
    fstream file2("gametemp.txt");
    string line2;
    fstream file3("records.txt");
    while(getline(file2,line2))
    {
        file3<<line2<<endl;
    }
        ofs1.open("temp.txt",ofstream::out | ofstream::trunc);
        ofs1.close();
    }

void viewlib()
{
    string filen="library.txt";
    fstream file(filen);
    string line;
    string a,b,c,cedit;
    string input=userID;
    fstream tempfile("gametemp.txt");
    string a2,b2,c2;

    while(getline(file,line))
    {
        istringstream linevar(line);
        linevar >> a >> b >>c;
        if(a==input)
        {
            stringstream ss(line);
            string w;
            vector <string> words;       
            while (ss >> w) 
            {
                words.push_back(w);
            }

            cout<<" LIBRARY OF USER: "<< a <<endl;
            for(int i=3; i<words.size();i++)
            {
                cout<<words[i]<<endl;
            }
            cout<<"-----------------------";
            }
        else
        {
            c2=c;
            stringstream ss(line);
            stringstream print;
            string w;
            vector <string> words;       
            while (ss >> w) 
            {
                words.push_back(w);
            }
            for(int i=0; i<words.size();i++)
            {
                print << words[i];
                if (i != words.size() - 1) 
                {
                    print << " "; 
                }
        }
            a2=a;
            b2=b;
            /*tempfile<<line<<"hello";*/
        }
    }
}
