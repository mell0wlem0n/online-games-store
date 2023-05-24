#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <fstream>
#include <assert.h>

class Game{
    private:
        int key;
        std::string title, category;
        double size, price;
    public:
        Game(std::string t = "-", std::string c = "-", double s = 0, double p = 0);
        int getKey() { return key; }
        std::string getTitle() { return title; }
        std::string getCategory() { return category; }
        double getSize() { return size; }
        double getPrice() { return price; }
};

class Bundle{
    private:
        int key, discount;
        std::string title;
        std::vector<Game> games;
        double price;
};

class Catalog{
    private:
        std::vector<Game> games;
        std::vector<Bundle> bundles;
};

class Console{
    private:
        double storage, storageLeft;
        std::vector<Game> games, gamesInstalled;
};

Game::Game(std::string t, std::string c, double s, double p){
    std::set<int> keys;

    std::ifstream keysFileIn;
    std::ofstream keysFileOut;

    int aux;
    keysFileIn.open("../Shared/Files/keys.txt");
    assert(keysFileIn.is_open());
    while(keysFileIn >> aux)
        keys.insert(aux);
    keysFileIn.close();

    key = rand() % 1000;
    while(keys.find(key) != keys.end())
        key = rand() % 1000;

    keysFileOut.open("../Shared/Files/keys.txt", std::ios::app);
    assert(keysFileOut.is_open());
    keysFileOut << key << " ";
    keysFileOut.close();

    title = t;
    category = c;
    size = s;
    price = p;
}