#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

void arrowUp(vector<vector<char>>& map, int row, int col)
{
    if (row > 0) {
        map[row][col] = '^';
    }
}

void arrowDown(vector<vector<char>>& map, int row, int col)
{
    if (row < map.size() - 1) {
        map[row][col] = 'v';
    }
}

void arrowLeft(vector<vector<char>>& map, int row, int col)
{
    if (col > 0) {
        map[row][col] = '<';
    }
}

void arrowRight(vector<vector<char>>& map, int row, int col)
{
    if (col < map[row].size() - 1) {
        map[row][col] = '>';
    }
}

void healthpack(int &alienHealth)
{
    cout << "alien found a health pack" << endl;
    cout << "alien heath has increased\n"
         << endl;
    for (int i = 0; i < 100; ++i)
    {
        if (alienHealth == 100)
        {
            break;
        }

        ++alienHealth;

        if (i == 19)
        {
            break;
        }
    }
}

void pod(int &alienatk, int &zombieH, int row, int col)
{
    cout << "alien found a pod" << endl;
    cout << "the nearest zombie health decrease by 10" << endl;
    alienatk = alienatk + 10;
    
}

class Zombie
    {
    public:
        int health;
        Zombie() : health(100) {}

        void TakeDamage(int damage)
        {
            cout << "Zombie takes " << damage << " damage!" << endl;
            health -= damage;
        }
    };

    class Alien
    {
    public:
        int health;
        int damage;
        Alien() : health(100), damage(10) {}

        void StepOnPod(Zombie &zombie)
        {
            cout << "Alien steps on a pod and Zombie takes " << damage << " damage!" << endl;
            zombie.TakeDamage(damage);
        }
    };

void rock()
{
    cout << "alien stunned by the rock" << endl;
    cout << "alien stop" << endl;
    // need table to modify alien address
    // in table

    char object[7] = {'^', 'v', '<', '>', 'h', 'p', ' '};
    int ranobj = rand() % 7;
    cout << object[ranobj];
}

void trail(int Row, int Col)
{
    for (int i = 0; i < Row; ++i)
    {
        for (int j = 0; j < Col; ++j)
        {
            vector<vector<char>> map_;
            if (map_[i][j] == 46)
            {
                char object[10] = {'^', 'v', '<', '>', 'h', 'p', 'r', ' ', ' ', ' '};
                int ranobj = rand() % 10;
                map_[i][j] = object[ranobj];
            }
        }
    }
}

int main()
{
    int alienHealth = 100;
    int alienatk = 0;
    int zombieH = 100;
    int Row = 5;
    int Col = 9;

    alienHealth = alienHealth - 50;
    srand(time(NULL));
    healthpack(alienHealth);
    pod(alienatk, zombieH, Row, Col);
    
    Zombie zombie;
    Alien alien;
    alien.StepOnPod(zombie);
    //cout << "alien health = " << alienHealth << endl;
    //cout << "alien attack = " << alienatk << endl;
    rock();
    trail(Row, Col);
}
