#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stdlib.h>
#include <fstream>
#include <assert.h>

class Game{
    private:
        std::string title, category;
        double size, price;
    public:
        Game(std::string t = "", std::string c = "", double s = 0, double p = 0) : title{t}, category{c}, size {s}, price{p} {}

        std::string getTitle() { return title; }
        std::string getCategory() { return category; }
        double getSize() { return size; }
        double getPrice() { return price; }

        void setTitle(std::string &s) { title = s; }
        void setCategory(std::string &s) { category = s; }
        void setSize(double s) { size = s; }
        void setPrice(double s) { price = s; }
};

class Bundle{
    private:
        int discount;
        std::string title;
        std::vector<Game> games;
        double price;
    public:
        Bundle(int d = -1, std::string t = "-", std::vector<Game> g = {}, double p = -1) : discount{d}, title{t}, games{g}, price{p} {}
        
        int getDiscount() { return discount; }
        std::string getTitle() { return title; }
        std::vector<Game> getGames() { return games; }
        double getPrice() { return price; }

        void setDiscount(int s) { discount = s; }
        void setTitle(std::string &s) { title = s; }
        void setGames(std::vector<Game> &s) { games = s; }
        void setPrice(double s) { price = s; }
};

class Catalog{
    private:
        std::vector<Game> games;
        std::vector<Bundle> bundles;
    public:
        Catalog(std::vector<Game> g = {}, std::vector<Bundle> b = {}) : games{g}, bundles{b} {}

        std::vector<Game> getGames() { return games; }
        std::vector<Bundle> getBundles() { return bundles; }

        void setGames(std::vector<Game> &g) { games = g; }
        void setBundles(std::vector<Bundle> &b) { bundles = b; }
};

class Console{
    private:
        double storage, storageLeft;
        std::vector<Game> games, gamesInstalled;
    public:
        Console(double s1 = -1, double s2 = -1, std::vector<Game> g1 = {}, std::vector<Game> g2 = {}) : storage{s1}, storageLeft{s2}, games{g1}, gamesInstalled{g2} {}

        double getStorage() { return storage; }
        double getStorageLeft() { return storageLeft; }
        std::vector<Game> getGames() { return games; }
        std::vector<Game> getGamesInstalled() { return gamesInstalled; }

        void setStorage(double s) { storage = s; }
        void setStorageLeft(double s) { storageLeft = s; }
        void setGames(std::vector<Game> &s) { games = s; }
        void setGamesInstalled(std::vector<Game> &s) { gamesInstalled = s; }
};
