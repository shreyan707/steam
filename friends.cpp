#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class user {
    private : 
        string password;
        string wallet;
    public :
        string username;
        string friends;
        string games;
        string notis;
        user(string x, string y, string z, string a, string b, string c){
          this->username=x;
          this->password=y;
          this->wallet=z;
          this->friends=a;
          this->notis=b;
          this->games=c;
          

        }

};

void current_friends();
void search_users();
void add_friends();



void friends () {
    int choices;
    cout << "\n\n\n";
    cout << "| Press 1 to view Friends           |" << endl;
    cout << "| Press 2 to view Users           |" << endl; 
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
            friends();
    }

}

void current_friends() {
    ifstream file;
    string frnds;
    file.open("test.txt");
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
    file.open("test.txt");
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
   fstream file("test.txt");
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
   o1.open("test.txt", ofstream::out | ofstream::trunc);
   o1.close();
   fstream filea("temp.txt");
   string line2;
   fstream fileb("test.txt");
   while(getline(filea,line2)){
    fileb << line2 << endl;
   }
  }




    

