#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure for game items
struct Game {
    string title;
    string genre;
    float price;
};

// Class for the wishlist
class Wishlist {
private:
    vector<Game> games;
public:
    // Add a game to the wishlist
    void addGame(const Game& newGame) {
        games.push_back(newGame);
    }

    // Display all games in the wishlist
    void displayGames() const {
        if (games.empty()) {
            cout << "Wishlist is empty." << endl;
        } 
        else {
            cout << "Wishlist Games:" << endl;
            for (const auto& game : games) {
                cout << "Title: " << game.title << ", Genre: " << game.genre << ", Price: ₹" << game.price << endl;
            }
        }
    }

    // Clear the wishlist
    void clear() {
        games.clear();
    }
};

// Class for the Steam-like gaming website
class U {
private:
    vector<string> bannedUsers;
public:
    // Ban a user from the website
    void banUser(const string& username) {
        bannedUsers.push_back(username);
        cout << "User " << username << " has been banned from the website." << endl;
    }

    // Check if a user is banned
    bool isUserBanned(const string& username) const {
        for (const auto& bannedUser : bannedUsers) {
            if (bannedUser == username) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Wishlist myWishlist;
    string title1,discription1,title2,genre1,genre2;
    float p1,p2;
    cin>>title1;
    cin>>title2;
    cin>>genre1;
    cin>>genre2;
    
    myWishlist.addGame(game1);
    myWishlist.addGame(game2);

    myWishlist.displayGames();

    Steam steamPlatform;
    steamPlatform.banUser("user123");

    cout << "Is user123 banned? " << (steamPlatform.isUserBanned("user123") ? "Yes" : "No") << endl;
    cout << "Is user456 banned? " << (steamPlatform.isUserBanned("user456") ? "Yes" : "No") << endl;

    return 0;
}