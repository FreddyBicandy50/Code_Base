#include <iostream>
#include "AI.h"
#include "screen.h"
#include "Define.h"
using namespace std;
 

int main(){
    Table B[Boardsize];
    board_update(true,B,0,0,false);
    B[0].Moves[0]='X';
    B[0].Moves[1]='O';
    B[0].Moves[2]='O';
    B[1].Moves[1]='O';
    B[2].Moves[0]='X';
    B[2].Moves[1]='X';
       board_update(false,B,0,0,false);
    if(check(B)==true)cout<<"winer";
    else cout<<"no";
    
    return 0;
}