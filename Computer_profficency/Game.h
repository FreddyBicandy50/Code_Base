#ifndef  Game_H
#define Game_H 
#include <iostream>
#include <cstdlib>
#include "Define.h"
#include "screen.h"
using namespace std;
Table Board[Boardsize];

void singleplayer(string playername,bool AI){
    Table *Board_address;
    Board_address = board_update(true,Board);
    
} 

void multiplayer(string player1name, string player2name){
   
}

#endif // ! Game_H
 