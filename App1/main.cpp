#include "../Shared/Data/clase.h"
#include <fstream>
#include <assert.h>

void writeGameToFile(Game*);
void deleteGameFromFile(int);

int main(int argc, char const *argv[]){
    srand((unsigned) time(NULL));

    Game g("GTA V", "Action", 59.99, 62.3);

    // writeGameToFile(&g);
    deleteGameFromFile(88);

    return 0;
}

void writeGameToFile(Game *g){
    std::ofstream gameFile;
    gameFile.open("../Shared/Files/games.txt", std::ios::app);
    assert(gameFile.is_open());
    gameFile << g->getKey() << " " << g->getTitle() << " ("  << g->getCategory() << ") - " << g->getPrice() << "RON (" << g->getSize() << "GB)\n";
    gameFile.close();
}

void deleteGameFromFile(int nr){
    std::ifstream gameFile;
    std::ofstream temp;
    std::string line;
    gameFile.open("../Shared/Files/games.txt");
    assert(gameFile.is_open());
    temp.open("../Shared/Files/temp.txt");
    assert(temp.is_open());
    while(getline(gameFile, line))
        if(std::stoi(line.substr(0, 2)) != nr)
            temp << line << '\n';
    temp.close();
    gameFile.close();
    remove("../Shared/Files/games.txt");
    rename("../Shared/Files/temp.txt", "../Shared/Files/games.txt");
}
