#include "../Shared/Data/clase.h"

void writeGameToFile(Game*);
void deleteGameFromFile(int);

int main(int argc, char const *argv[]){
    srand((unsigned) time(NULL));

    // writeGameToFile(new Game("GTA V", "Action", 59.99, 62.3));
    deleteGameFromFile(421);

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

    std::string key, line;
    gameFile.open("../Shared/Files/games.txt"); 
    assert(gameFile.is_open());
    temp.open("../Shared/Files/temp.txt");
    assert(temp.is_open());
    while(std::getline(gameFile, line)){
        key.clear();
        int i = 0;
        while(line.at(i) != ' '){
            key.push_back(line.at(i));
            i += 1;
        }
        if(std::stoi(key) != nr)
            temp << line << '\n';
    }
    temp.close();
    gameFile.close();
    remove("../Shared/Files/games.txt");
    rename("../Shared/Files/temp.txt", "../Shared/Files/games.txt");

    int aux;
    gameFile.open("../Shared/Files/keys.txt");
    assert(gameFile.is_open());
    temp.open("../Shared/Files/temp.txt");
    assert(temp.is_open());
    while(gameFile >> aux)
        if(aux != nr)
            temp << aux << " ";
    temp.close();
    gameFile.close();
    remove("../Shared/Files/keys.txt");
    rename("../Shared/Files/temp.txt", "../Shared/Files/keys.txt");
}
