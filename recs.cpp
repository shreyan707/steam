#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void search();
void game_rec();
void after_login(); // function to run after login is succesfull, should be modified to add different functions (library, friends etc.) its a choice based program
void login();
void signin();
void forgot();
void notis();
void accept_friend();
void current_friends();
void search_users();
void add_friends();
void wallet();
void logo(string filename);
void trending();
void friends();
void add_bal();
void view_bal();

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
    cout << "| Press 4 to access Wallet                    |" << endl;
    cout << "| Press 5 to access Friend features           |" << endl;
    cout << "| Press 6 to access Notifications             |" << endl;
    cout << "\n ENTER YOUR CHOICE : ";
    cin >> choices;
    switch (choices)
    {
    case 1:
      game_rec();
      break;

    case 2 :
        trending();
        break;
    case 3 :
        search();
        break;
    case 4 :
        wallet();
        break;
    case 5 :
        friends();
        break;
    case 6 :
        notis();
        break;
   
    default:
        cout << "\n\n\n";
        cout << "\t\t\t Please select from the option given above \n"
             << endl;
        main();
    }
}
string wal,frnd,noti,gam;;
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

    ifstream input("records.txt");

    while (input >> id >> pass>>wal>>frnd>>noti>>gam)
    {
        if (id == userID && pass == password)
        {
            count = 1;
            system("cls");
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
    f1 << suserID << ' ' << spassword <<' '<< "0" << ' ' << "nil" << ' ' << "nil" << ' ' << "nil" << endl;
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
        while (f2 >> fID >> fpass>>wal>>frnd>>noti>>gam)
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

void notis() {
    fstream file("records.txt");
    string line,user;
    string a,b,c,d,e,f;
    cout << "Confirm your username : ";
    cin >> user;
    while(getline(file,line)){
      istringstream nav(line);
      nav >> a >> b >> c >> d >> e >> f;
      if(user==a){
        cout << e << endl;
        break;
      }
    }
    after_login();
}

void accept_friend() {
    string choice,user;
    cout << "Enter your choice :";
    cin >> choice;
    cout << "Enter the name of the user who wants to be friend : ";
    cin >> user;
    if(choice=="y"){
        
    }
    else{

    }

}

void friends () {
    int choices;
    cout << "\n\n\n";
    cout << "| Press 1 to view Friends           |" << endl;
    cout << "| Press 2 to view Users             |" << endl; 
    cout << "| Press 3 to Add Friends            |" << endl;
    cout << "| Press 4 to Exit                   |" << endl;
    cout << "\n ENTER YOUR CHOICE : ";
    cin >> choices; 
    switch (choices) {
        case 1 :
            current_friends();
            break;
        case 2 :
            search_users();
            break;
        case 3 :
            add_friends();
            break;
            
            
        default :
            cout << "\n\n\n";
            cout << "\t\t\t Please select from the option given above \n"
             << endl;
            after_login();
    }

}

void current_friends() {
    ifstream file;
    string frnds;
    file.open("records.txt");
    if (!file.is_open()) {
    cerr << "Error: Could not open file." << endl;
  }
  string uname;
  cout << "Confirm your username : ";
  cin >> uname;
  string u,p,f,n,g;
  string w;
  bool found = false;
  while(!file.eof()){
    file >> u >> p >> w >> f >> n >> g;
    if(uname == u){
        cout << "Your friends are : ";
        cout << f;
        found = true;
        break;
    }
  }
  if ( found == false ){
    cout << "You dont have any friends";
  }
  friends();
}

void search_users() {
    ifstream file;
    string uname;
    file.open("records.txt");
    if (!file.is_open()) {
    cerr << "Error: Could not open file." << endl;
  }
  vector<string> usernames;
  string line;
  while (getline(file, line)) {
    uname = line.substr(0,line.find(' '));
    usernames.push_back(uname);
  }
  file.close();
  cout << "List of users:" << endl;
  for (const string& user : usernames) {
    cout << user << endl;
  }
  friends();
}

void add_friends() {
   fstream file("records.txt");
   string user,frnd,line;
   cout << "Confirm your username : ";
   cin >> user;
   cout << "Enter the username you want to add as friend : ";
   cin >> frnd;
   string u,p,f,n,g,w;
   string u1,p1,f1,n1,g1,w1;
   fstream temp("temp.txt");

   while(getline(file,line)){
    istringstream line1(line);
    line1 >> u >> p >> w >> f >> n >> g >> w;
    if(u!=frnd){
      temp << line << endl;
    }
    else {
      u1 = u;
      p1 = p;
      w1 = w;
      f1 = f;
      n1 = n;
      g1 = g;
    }
   }
   string n2 = "you_have_a_friend_request_from_" + user + "_accpet?_(y/n)";
   temp << u1 << " " << p1 << " " << w1 << " " << f1 << " " << n2 << " " << g1 << endl;
   temp.close();
   ofstream o1;
   o1.open("records.txt", ofstream::out | ofstream::trunc);
   o1.close();
   fstream filea("temp.txt");
   string line2;
   fstream fileb("records.txt");
   while(getline(filea,line2)){
    fileb << line2 << endl;
   }
   friends();
  }

void wallet()
{
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
            view_bal();
            break;
        case 2:
            add_bal();
            break;
        case 3 :
            after_login();
            break;
        
        }
}

void add_bal(){

    int balance;
    int add;
    balance = stoi(wal);
    cout << "Enter amount to be added: " << endl;
    cin >> add;
    balance = balance + add;

    string filen = "records.txt";
    fstream file(filen);
    string line;
    string a, b, c, d, e, f;
    string input = userID;
    fstream tempfile("temp.txt");
    string a2, b2, c2, d2, e2, f2;

    while (getline(file, line))
    {
        istringstream linevar(line);
        linevar >> a >> b >> c >> d >> e >> f;
        if (a != input)
        {
            tempfile << line << endl;
        }
        else
        {
            a2 = a;
            b2 = b;
            c2 = c;
            d2 = d;
            e2 = e;
            f2 = f;
        }
    }
    string c3 = to_string(balance);
    tempfile << a2 << " " << b2 << " " << c3 << " " << d2 << " " << e2 << " " << f2 << endl;
    tempfile.close();
    file.close();
    ofstream ofs;
    ofs.open("records.txt", ofstream::out | ofstream::trunc);
    ofs.close();
    fstream file2("temp.txt");
    string line2;
    fstream file3("records.txt");
    while (getline(file2, line2))
    {
        file3 << line2 << endl;
    }
    wallet();
}

void view_bal()

{
    cout << "Wallet Balance For: " << userID << endl;
    cout << wal << endl;
    wallet();
}

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

void trending() {
    srand(time(0)); 
    vector<string> gameNames = {
        "Fortnite",
        "Call of Duty: Warzone",
        "Among Us",
        "Valorant",
        "Minecraft",
        "Grand Theft Auto V",
        "Red Dead Redemption 2",
        "PlayerUnknown's Battlegrounds",
        "Rocket League",
        "Apex Legends",
        "League of Legends",
        "Counter-Strike: Global Offensive",
        "Overwatch",
        "The Witcher 3: Wild Hunt",
        "Rainbow Six Siege",
        "Destiny 2",
        "Dota 2",
        "FIFA 21",
        "World of Warcraft",
        "Assassin's Creed Valhalla",
        "Cyberpunk 2077",
        "Genshin Impact",
        "Super Smash Bros. Ultimate",
        "Hades",
        "Animal Crossing: New Horizons",
        "The Last of Us Part II",
        "Final Fantasy VII Remake",
        "Ghost of Tsushima",
        "God of War",
        "The Legend of Zelda: Breath of the Wild",
        "Dark Souls III",
        "Bloodborne",
        "Sekiro: Shadows Die Twice",
        "Monster Hunter: World",
        "Persona 5",
        "NieR: Automata",
        "The Elder Scrolls V: Skyrim",
        "Fallout 4",
        "DOOM Eternal",
        "Star Wars Jedi: Fallen Order",
        "Half-Life: Alyx",
        "Resident Evil 2 Remake",
        "The Outer Worlds",
        "Control",
        "Death Stranding",
        "No Man's Sky",
        "Disco Elysium",
        "Outer Wilds",
        "Celeste",
        "Slay the Spire",
        "Into the Breach",
        "Dead Cells",
        "Cuphead",
        "Hollow Knight",
        "Stardew Valley",
        "Terraria",
        "RimWorld",
        "Factorio",
        "Cities: Skylines",
        "Age of Empires II: Definitive Edition",
        "Crusader Kings III",
        "Europa Universalis IV",
        "Civilization VI",
        "Total War: Three Kingdoms",
        "XCOM 2",
        "Stellaris",
        "Hearts of Iron IV",
        "Crash Bandicoot 4: It's About Time",
        "Tony Hawk's Pro Skater 1+2",
        "Demon's Souls",
        "Final Fantasy XIV",
        "The Sims 4",
        "Madden NFL 21",
        "NBA 2K21",
        "NHL 21",
        "MLB The Show 21",
        "WWE 2K Battlegrounds",
        "Mortal Kombat 11",
        "Street Fighter V",
        "Tekken 7",
        "Dragon Ball FighterZ",
        "Guilty Gear Strive",
        "Marvel's Spider-Man: Miles Morales",
        "Demon's Souls",
        "Persona 5 Royal",
        "Yakuza: Like a Dragon",
        "Assassin's Creed Odyssey",
        "Assassin's Creed Origins",
        "Assassin's Creed: Odyssey",
        "Watch Dogs: Legion",
        "The Division 2",
        "Tom Clancy's Rainbow Six Siege",
        "Tom Clancy's The Division 2",
        "Far Cry 5",
        "Far Cry: New Dawn",
        "For Honor",
        "Tom Clancy's Ghost Recon Breakpoint"
};

    cout << "Top 10 Games:\n";
    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % gameNames.size();
        cout << gameNames[randomIndex] << endl;
        gameNames.erase(gameNames.begin() + randomIndex);
    }
after_login()
;
}
