#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void search()
{
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
        if( game == game_name) {
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

}
int main () {
    search();
}