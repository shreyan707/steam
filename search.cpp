#include <iostream>
#include <fstream>
#include <string>
#include <cwchar>

using namespace std;

struct Game {
    wchar_t name[50];
    float price;
    wchar_t type[20];
};

void searchGame(const wchar_t *name, const Game &game) {
    if (wcscmp(name, game.name) == 0) {
        wcout << L"Name: " << game.name << endl;
        wcout << L"Type: " << game.type << endl;
        cout << "Price: $" << game.price << endl;
    } else {
        cout << "Game not found." << endl;
    }
}

int main() {
    wifstream file("C:\\Users\\BhansaLi\\Desktop\\C++ class\\ok\\games.txt");
     if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    Game games[100];
    int numGames = 0;

    while (file >> games[numGames].name >> games[numGames].price >> games[numGames].type) {
        numGames++;
    }

    file.close();

    wchar_t search_query[50];

    wcout << L"Enter the name of the game to search: ";
    wcin >> search_query;

    bool found = false;
    for (int i = 0; i < numGames; ++i) {
        if (wcscmp(search_query, games[i].name) == 0) {
            searchGame(search_query, games[i]);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Game not found." << endl;
    }

    return 0;
}
