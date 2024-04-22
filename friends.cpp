#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class user {
    private : 
        string password;
        int wallet;
    public :
        string username;
        string friends;
        string games;
        string notis;
        user(string x, string y, int z, string a, string b, string c){
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
void remove_friends();

void friends () {
    int choices;
    cout << "\n\n\n";
    cout << "| Press 1 to view Friends           |" << endl;
    cout << "| Press 2 to Search Users           |" << endl; 
    cout << "| Press 3 to Add Friends            |" << endl;
    cout << "| Press 4 to Remove Friends         |" << endl;
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
        case 4 :
            remove_friends();
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
  int w;
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
    

}