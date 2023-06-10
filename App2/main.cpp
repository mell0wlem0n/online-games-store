#include "../Shared/Data/clase.h"
#include "../Shared/Data/functii.h"
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

void modifica_joc(char **);
void vizualizare_catalog();
void cumparare_joc(char **);
void instalare_joc(char);
void dezinstalare_joc(char);
void vizualizare_jocuri_cumparate();
void vizualizare_jocuri_instalate();
void vizualizare_memorie_consola();

int main(int argc, char **argv)
{
    if (argc == 6)
    {
        if ((string)argv[1] == "modify_game")
        {
            modifica_joc(argv);
        }
    }
    if (argc == 2)
    {
        if ((string)argv[1] == "show_catalog")
        {
            vizualizare_catalog();
        }
    }
    if (argc == 3)
    {
        if ((string)argv[1] == "buy_game")
        {
            cumparare_joc(argv);
        }
    }

    return 0;
}

void vizualizare_catalog()
{
    vector<Game> jocuri;
    vector<Bundle> bundleuri;
    ifstream finGames("../Shared/Files/games.txt");
    ifstream finBundles("../Shared/Files/bundles.txt");
    string reader;
    set<string> categorii;
    if (finGames.is_open())
    {

        while (getline(finGames, reader))
        {

            jocuri.push_back(stringToGame(reader));
            categorii.insert(stringToGame(reader).getCategory());
        }
        finGames.close();
    }
    if (finBundles.is_open())
    {
        while (getline(finBundles, reader))
        {

            bundleuri.push_back(stringToBundle(reader));
        }
        finBundles.close();
    }
    cout << "Jocuri:" << endl
         << endl;
    for (auto i : categorii)
    {
        cout << i << ":" << endl;
        for (auto j : jocuri)
        {
            if (j.getCategory() == i)
            {
                cout << j << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "Bundleuri:" << endl
         << endl;
    for (auto i : bundleuri)
    {
        cout << i;
    }
}

void modifica_joc(char **argv)
{
    string game = findGameOrBundleInFile((string)argv[2], "games");
    if (game != "-")
    {
        Game joc = stringToGame(game);
        joc.setCategory(argv[3]);
        joc.setSize(atof(argv[4]));
        joc.setPrice(atof(argv[5]));
        ifstream fin("../Shared/Files/bundles.txt");
        vector<Bundle> bundleuri;
        if (fin.is_open())
        {
            string reader;

            while (getline(fin, reader))
            {
                bundleuri.push_back(stringToBundle(reader));
            }
            fin.close();
        }

        for (auto &i : bundleuri)
        {
            vector<Game> jocuri = i.getGames();
            for (auto &j : jocuri)
            {
                if (j.getTitle() == argv[2])
                {
                    j = joc;
                }
            }

            i.setGames(jocuri);
        }

        deleteGameOrBundleFromFile(argv[2], "games");
        writeGameToFile(joc);
        ofstream fout("../Shared/Files/bundles.txt");
        if (fout.is_open())
        {
            for (auto i : bundleuri)
            {
                fout << bundleToString(i) << endl;
            }
        }
        fout.close();
    }
}
void cumparare_joc(char **argv)
{

    string test = findGameOrBundleInFile((string)argv[2], "games");
    cout << test;
    if (test != "-")
    {

        Game joc = stringToGame(test);
        ifstream fin("../Shared/Files/consola.txt");
        if (fin.is_open())
        {
            string reader;
            getline(fin, reader);
            Console consola = stringToConsole(reader);
            vector<Game> jocuriCumparate = consola.getGames();
            jocuriCumparate.push_back(joc);
            consola.setGames(jocuriCumparate);
            consola.setStorageLeft(consola.getStorageLeft() - joc.getSize());
            fin.close();
        }
    }
}

void instalare_joc(char titlu_joc)
{
}

void dezinstalare_joc(char titlu_joc)
{
}

void vizualizare_jocuri_cumparate()
{
}

void vizualizare_jocuri_instalate()
{
}

void vizualizare_memorie_consola()
{
}

void push_data()
{
}