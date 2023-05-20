#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

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
        std::vector<int> games;
        double price;
};

class Catalog{
    private:
        std::vector<int> games, bundles, top5;
};

class Console{
    private:
        double storage, storageLeft;
        std::vector<Game> games, gamesInstalled;
};

Game::Game(std::string t, std::string c, double s, double p){
    key = 10 + rand() % 89;
    title = t;
    category = c;
    size = s;
    price = p;
}