#include <iostream>
#include <string>
#include <vector>

class Game{
    private:
        int key;
        std::string title, category;
        double size, price;
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