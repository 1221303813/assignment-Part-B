#include <iostream>
#include <string>
#include <vector>
#include <ctime>   //time() in srand( time(NULL) )
#include <cstdlib> //system purpose
#include <iomanip> // setw()
#include <map>
using namespace std;

void GameBoard(vector<vector<char>> map, int row, int col)
{
    int Alife = 100;
    int Aattack= 0;
    int Zlife = 100 + (rand()% 201);
    int Zattack= 1+ (rand()% 15);
    int range= 1+ rand() %3;
   

    cout << "-> Alien :  Life"<< Alife ;
    cout <<"," <<"Attack" << Aattack<< endl ;
    cout << "Zombie 1 :  Life"<< Zlife ;
    cout << "," <<"Attack" << Zattack<< ',';
    cout << "Range  "<< range<<endl;
    cout << "Zombie 2 :  Life"<< Zlife ;
    cout << "," <<"Attack" << Zattack<< ',';
    cout << "Range  "<< range<< endl ;
    cout << "command =" ;
}

class Alien {

private:
  int arrowCount;
  int attack;
  int border;
  int game;

public:
  Alien() {
    //Alien attack increase 20 when it received one arrow while moving
    arrowCount = 0;
    attack = 0;
    border = 0;
    game = 0;
    
  }

  void moveUp(vector<vector<char>> map, int row, int col)
  {
    if (row > 0 ) {
    
    map[row][col] = 'A';
    cout << "Alien Moved Up" << endl;
    displayStatus(map,row,col);
    }
  
    //Alien will stop when it touched the boarder
    if (row < border) {
      
      cout << "Alien touched the gameboard border." << endl;} 
    
    else if(row > border){
      game =++game;}

    //Alien attack increase when it got one arrow
    if(arrowCount++ >0)
    {
      attack += 20;
    }
    else
    {game = ++game;}
    
  }
  

  void moveDown(vector<vector<char>> map, int row, int col) {
    if (row < map.size() - 1) {
   
    map[row][col] = 'A';
    cout << "Alien Moved Down" << endl;
   
     Display(map, col, row);}

        //Alien will stop when it touched the boarder
    if (row < border) {
      
      cout << "Alien touched the gameboard border." << endl;} 
    
    else if(row > border){
      game =++game;}

    //Alien attack increase when it got one arrow
    if(arrowCount++ >0)
    {
      attack += 20;
    }
    else
    {game = ++game;}
  }
  

  void moveLeft(vector<vector<char>> map, int row, int col) {
    if (col > 0) {
   
    map[row][col] = 'A';
    cout << "Alien Moved Left" << endl;
     Display(map, col, row);}

        //Alien will stop when it touched the boarder
    if (row < border) {
      
      cout << "Alien touched the gameboard border." << endl;} 
    
    else if(row > border){
      game =++game;}

    //Alien attack increase when it got one arrow
    if(arrowCount++ >0)
    {
      attack += 20;
    }
    else
    {game = ++game;}
  }
  

  void moveRight(vector<vector<char>> map, int row, int col) {
    if (col < map[0].size() - 1) {
   
    map[row][col] = 'A';
    cout << "Alien Moved Right" << endl;
    Display (map, col, row);}
    
        //Alien will stop when it touched the boarder
    if (row < border) {
      
      cout << "Alien touched the gameboard border." << endl;} 
    
    else if(row > border){
      game =++game;}

    //Alien attack increase when it got one arrow
    if(arrowCount++ >0)
    {
      attack += 20;
    }
    else
    {game = ++game;}
  }
  
void displayStatus(vector<vector<char>> map, int row, int col) {
    cout << "Attack: " << attack << endl;
  }
};

void Object(vector<vector<char>>& map, int col, int row)
{ 
    char objects[] = {' ','h',' ','v','^','r','p','<','>','2','1'};
    int noOfObjects = 10; // no. of objects

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int objNo = rand() % noOfObjects;
            if (i == row / 2 && j == col / 2) {
                map[i][j] = 'A';
                continue;
            }
            map[i][j] = objects[objNo];
        }
    }
}



int main() {
  Alien a;
  string command;
  int row = 5;
  int col = 9;
  
  vector<vector<char>> map(row, vector<char>( col));

  Object(map, col, row);
  cout << "Alien move :  ";


  while (true) {
    cin >> command;
    if (command == "Up") {
      a.moveUp(map ,row,col);
    } else if (command == "Down") {
      a.moveDown(map ,row,col);
    } else if (command == "Left") {
      a.moveLeft(map ,row,col);
    } else if (command == "Right") {
      a.moveRight(map ,row,col);
    } else if (command == "Quit") {
      break;
    } else {
      cout << "Invalid command. Try again." << endl;
    }
  }
  map[row][col] = 'A';
  
}