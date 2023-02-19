#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void Zomove(boardset data)
{
    vector<vector<char>> map_;
    for (int i = 0; i < data.Row; ++i)
    {
        for (int j = 0; j < data.Col; ++j)
        {
            if (map_[i][j] > '1' && map_[i][j] < '9')
            {
                int s = 0;
                while (s = 0)
                {
                    char k = map_[i][j];
                    int m[4] = {'u', 'l', 'r', 'd'};
                    int numA = rand() % 4;
                    switch (m[numA])
                    {
                    case 'u':
                        if (i < data.Row)
                        {
                            map_[i + 1][j] = k;
                            cout << "Zombie " << k << " move up\n";
                            break;
                        }
                        continue;
                    case 'l':
                        if (j > 1)
                        {
                            map_[i][j - 1] = k;
                            cout << "Zombie " << k << " move left\n";
                            break;
                        }
                        continue;
                    case 'r':
                        if (j < data.Col)
                        {
                            map_[i][j + 1] = k;
                            cout << "Zombie " << k << " move right\n";
                            break;
                        }
                        continue;
                    case 'd':
                        if (i > 1)
                        {
                            map_[i - 1][j] = k;
                            cout << "Zombie " << k << " move down\n";
                            break;
                        }
                        continue;
                    default:
                        s = 0;
                        break;
                    }
                }
            }
        }
    }
}