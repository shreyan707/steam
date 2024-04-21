#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0)); 

    std::vector<std::string> gameNames = {
        "Fortnite",
        "Call of Duty: Warzone",
        "Among Us",
        "Valorant",
        "Minecraft",
        "Grand Theft Auto V",
        "Red Dead Redemption 2",
        "PlayerUnknown's Battlegrounds",
        "Rocket League",
        "Apex Legends"
    };
    
    std::cout << "Top 10 Games:\n";
    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % gameNames.size();
        std::cout << gameNames[randomIndex] << std::endl;
    }

    return 0;
}
