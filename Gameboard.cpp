#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


struct boardset
{
    int Row = 5;
    int Col = 9;
    int Zombie = 1;
    int game = 0;
};

void showsetting(boardset data)
{
    cout << "Default Game Settings" << endl;
    cout << "-----------------------" << endl;
    cout << "Board Rows    : " << data.Row << endl;
    cout << "Board Columns : " << data.Col << endl;
    cout << "Zombie Count  : " << data.Zombie << endl;
    cout << endl;
}

char uppercase()
{
    char quest;
    cout << "Do you wish to change the setting? (Y/N): ";
    cin >> quest;
    cout << endl;
    char Q;
    Q = toupper(quest);
    return Q;
}

void chgsetting(boardset &data)
{
    cout << "Board Setting \n";
    cout << "--------------- \n";
    cout << "Enter rows => ";
    cin >> data.Row;
    cout << "Enter columns => ";
    cin >> data.Col;
    cout << endl;
    cout << "Zombie Setting\n";
    cout << "---------------\n";
    cout << "Enter number of zombie => ";
    cin >> data.Zombie;
    cout << endl;
}



void setting(boardset &data)
{
    do
    {
        showsetting(data);
        // system("cls") cant use;
        char Quest = uppercase();
        if (Quest == 'Y')
        {
            chgsetting(data);
            data.game = ++data.game;
        }
        else if (Quest == 'N')
        {
            data.game = ++data.game;
        }
        else
        {
            cout << "Sorry, We don't understand the " << Quest << endl;
            cout << "Please Try again\n" << endl;
        }
    } while(data.game == 0);
}


class gboard
{
private:
    vector<vector<char>> map_;
    boardset data;
public:
    //boardset data;
    gboard(boardset data);
    void gobj(boardset data);
    void showAlien(boardset data);
    void showzombie(boardset data);
    void displayboard(boardset data);
};


gboard::gboard(boardset data)
{
    gobj(data);
    showAlien(data);
    showzombie(data);
    //zombiesetting(zombie);
}


void gboard::gobj(boardset data)
{
    //Col = col;
    //Row = row;
    char obj[] = {' ', '^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' '};
    int numObj = 10;
    map_.resize(data.Row);
    for (int i = 0; i < data.Row; ++i)
    {
        map_[i].resize(data.Col);
    }

    for (int i = 0; i < data.Row; ++i)
    {
        for (int j = 0; j < data.Col; ++j)
        {
            int objNo = rand() % numObj;
            map_[i][j] = obj[objNo];
        }
    }
}

void gboard::showAlien(boardset data)
{
    int Alienrow = (data.Row)/2;
    int Aliencol = (data.Col)/2;
    map_[Alienrow][Aliencol] = 'A';    
}

void gboard::showzombie(boardset data)
{
    for (int i = 0; i < data.Zombie; i++) 
    {
        int x = rand() % data.Row;
        int y = rand() % data.Col;
        char numZ = 49;//according to ascii table
        map_[x][y] = numZ + i;
        if (map_[x][y] == map_[(data.Row)/2][(data.Col)/2])
        {
            --i;
        }
    }
}



void gboard::displayboard(boardset data)
{
    cout << "  ";
    string text = ".: Alien vs Zombie :.";
    const int textWidth = 21;
    int width = data.Col*2+1;
    int space = (width - textWidth)/2;
    for (int x=0; x < space; ++x)
    {
        cout << " ";
    }
    cout << text <<  endl;
    

    for (int i=0 ; i < data.Row; ++i)
    {
        cout << "  ";
        for (int j=0; j < data.Col; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (i + 1);
        for (int j=0; j < data.Col; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int j = 0; j < data.Col; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    cout << "  ";
    for (int j=0; j < data.Col; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < data.Col; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

void aliensetting()
{
    int alienHealth = 100;
    int alienatk = 0;
    cout << "Alien: Life " << alienHealth << ", Attack " << alienatk << endl;
}

void zombiesetting(boardset data)
{
    int zombieH[9] =  {100, 150, 200, 250, 300, 350, 400, 450, 500};
    int zombieatk[9] = {10, 15, 20, 25, 30, 35, 40, 45, 50};
    int zombieR[3] = {1, 2, 3};

    for (int i = 0; i < data.Zombie; i++)
    {
        int randzomH = rand() % 9;
        int randzomatk = rand() % 9;
        int randzomR = rand() % 3;
        cout << "Zombie "<< i+1 << ": ";
        cout << "Life " << zombieH[randzomH] << " ";
        cout << "Attack " << zombieatk[randzomatk] << " ";
        cout << "Range " << zombieR[randzomR] << endl;
    }
}

int main()
{
    boardset data;
    setting(data);
    srand(time(NULL));
    gboard gboard(data);
    gboard.displayboard(data);
    aliensetting();
    zombiesetting(data);
}