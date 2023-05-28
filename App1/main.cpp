#include "../Shared/Data/clase.h"

Game stringToGame(std::string);
std::string gameToString(Game);
Bundle stringToBundle(std::string);
std::string bundleToString(Bundle);

void writeGameToFile(Game);
void deleteGameFromFile(std::string);

std::vector<Game> createGameVector(std::vector<std::string>);


int main(int argc, char const *argv[]){
    std::string s = "Jocurile fericite;82.99;50;2;GTA V;Action;60;59.99;Minecraft;Sandbox;20;23;";
    std::cout << stringToBundle(s);
    std::cout << '\n' << bundleToString(stringToBundle(s));

    return 0;
}

Game stringToGame(std::string s){
    std::string title, category, size, price;

    std::size_t pos = s.find(';');
    title = s.substr(0, pos);

    pos = s.find(';', pos + 1);
    category = std::string(&s[title.length() + 1], &s[pos]);

    pos = s.find(";", pos + 1);
    size = std::string(&s[title.length() + category.length() + 2], &s[pos]);

    pos = s.find(";", pos + 1);
    price = std::string(&s[title.length() + category.length() + size.length() + 3], &s[pos]);

    return Game(title, category, std::stod(size), std::stod(price));
}

std::string gameToString(Game g){
    std::string game, aux;
    char cifra;

    game = g.getTitle() + ";";
    game += g.getCategory() + ";";
    aux = std::to_string(g.getSize()).erase(std::to_string(g.getSize()).length() - 4);
    while(*(aux.end() - 1) == '0' || *(aux.end() - 1) == '.'){
        if(*(aux.end() - 1) == '.'){
            aux.pop_back();
            break;
        }
        aux.pop_back();
    }
    game += aux + ";";
    aux = std::to_string(g.getPrice()).erase(std::to_string(g.getPrice()).length() - 4);
    while(*(aux.end() - 1) == '0' || *(aux.end() - 1) == '.'){
        if(*(aux.end() - 1) == '.'){
            aux.pop_back();
            break;
        }
        aux.pop_back();
    }
    game += aux + ";";

    return game;
}

Bundle stringToBundle(std::string s){
    int numberOfGames, lengthToJump = 0;
    std::string discount, title, price;

    std::size_t pos = s.find(';');
    title = std::string(&s[lengthToJump], &s[pos]);
    lengthToJump += title.length() + 1;

    pos = s.find(';', pos + 1);
    price = std::string(&s[lengthToJump], &s[pos]);
    lengthToJump += price.length() + 1;

    pos = s.find(";", pos + 1);
    discount = std::string(&s[lengthToJump], &s[pos]);
    lengthToJump += discount.length() + 1;

    pos = s.find(";", pos + 1);
    numberOfGames = std::stoi(std::string(&s[lengthToJump], &s[pos]));
    lengthToJump += std::string(&s[lengthToJump], &s[pos]).length() + 1;

    std::vector<Game> games;
    for(int i = 0; i < numberOfGames; i++){
        for(int j = 0; j < 4; j++)
            pos = s.find(";", pos + 1);
        std::string game = std::string(&s[lengthToJump], &s[pos + 1]);
        games.push_back(stringToGame(game));
        lengthToJump += std::string(&s[lengthToJump], &s[pos]).length() + 1;
    }

    return Bundle(std::stod(discount), title, games, std::stod(price));
}

std::string bundleToString(Bundle b){
    std::vector<Game> games = b.getGames();
    std::string bundle;

    bundle = b.getTitle() + ";";
    bundle += std::to_string(b.getPrice()).erase(std::to_string(b.getPrice()).length() - 4) + ";";
    bundle += std::to_string(b.getDiscount()) + ";";
    bundle += std::to_string(games.size()) + ";";

    for(auto i : games)
        bundle += gameToString(i);

    return bundle;
}

void writeGameToFile(Game g){
    bool ok = true;
    std::ifstream gamesFileIn;
    gamesFileIn.open("../Shared/Files/games.txt");
    if(gamesFileIn.is_open()){
        std::string line;
        while(std::getline(gamesFileIn, line)){
            auto pos = line.find(";");
            if(line.substr(0, pos) == g.getTitle()){
                ok = false;
                break;
            }
        }
        gamesFileIn.close();
    }

    if(ok){
        std::ofstream gamesFileOut;
        gamesFileOut.open("../Shared/Files/games.txt", std::ios::app);
        if(gamesFileOut.is_open()){
            gamesFileOut << gameToString(g) << '\n';
            gamesFileOut.close();
        }
    }
}

void deleteGameFromFile(std::string g){
    std::list<std::string> jocuri;
    int contorJocuri;

    std::ifstream gamesFileIn;
    gamesFileIn.open("../Shared/Files/games.txt");
    if(gamesFileIn.is_open()){
        std::string line;
        while(std::getline(gamesFileIn, line)){
            contorJocuri += 1;
            auto pos = line.find(";");
            if(line.substr(0, pos) != g)
                jocuri.push_back(line);
        }
        gamesFileIn.close();
    }

    if(contorJocuri != jocuri.size()){
        std::ofstream gamesFileOut;
        gamesFileOut.open("../Shared/Files/games.txt");
        if(gamesFileOut.is_open()){
            for(auto i : jocuri)
                gamesFileOut << i << '\n';
            gamesFileOut.close();
        }
    }
}

std::vector<Game> createGameVector(std::vector<std::string> games){
    std::vector<Game> out;

    for(auto i : games){
        std::ifstream gamesFileIn;
        gamesFileIn.open("../Shared/Files/games.txt");
        if(gamesFileIn.is_open()){
            std::string line;
            while(std::getline(gamesFileIn, line)){
                auto pos = line.find(";");
                if(line.substr(0, pos) == i){
                    out.push_back(stringToGame(line));
                }
            }
            gamesFileIn.close();
        }
    }
    return out;
}
