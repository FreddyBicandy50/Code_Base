#ifndef AI_H
#define AI_H
#include "Game.h"
#include "screen.h"
char win;
// function to check if we have a winner after 5 attemps
bool check(Table Board[Boardsize]){
    // function to check if we have a winner after 5 attemps
    // rows
    for (int row = 0; row < Boardsize; row++)
        if (Board[row].Moves[1] == Board[row].Moves[0] && Board[row].Moves[2] == Board[row].Moves[0]) {
            win = Board[row].Moves[0]; 
            return true;
        }

    // columns
    for (int column = 0; column < Boardsize; column++)
        if (Board[1].Moves[column] == Board[0].Moves[column] && Board[2].Moves[column] == Board[0].Moves[column]) {
            win = Board[1].Moves[column];
            return true;
        }

    // diagionles
    // left
    if (Board[1].Moves[1] == Board[0].Moves[0] && Board[2].Moves[2] == Board[0].Moves[0]) {
        win = Board[0].Moves[2]; 
        return true;
    }

    // right diagonal
    int temp = Boardsize;
    if (Board[1].Moves[1] == Board[0].Moves[2] && Board[2].Moves[0] == Board[0].Moves[2]){
        win = Board[0].Moves[2]; 
        return true; 
    } 
    return false;
}

int minimax(Table Board[Boardsize], int Depth, char p1, char p2, bool isMaximising);
string compMove(Table Board[Boardsize], int av_spot, char p1, char p2){
    int bestScore = -10000, score = 0;
    string temp, bestMove;
    for (int row = 0; row < Boardsize; row++) for (int column=0; column<Boardsize; column++)
        if (Board[row].Moves[column]!='X' && Board[row].Moves[column]!='O') {
            temp = Board[row].Moves[column];
            Board[row].Moves[column] = p2;
            score = minimax(Board, av_spot-1, p1, p2, false);
            Board[row].Moves[column] = temp[0];
            if (score > bestScore){
                    bestScore = score;
                    bestMove = temp;
                }
        }
    
    return bestMove;
}

int minimax(Table Board[Boardsize], int Depth, char p1, char p2, bool isMaximising){
    if(check(Board)==true && win==p2) {
        cout<<"awal if";
        return 100;
        
    }else if(check(Board)==true && win!=p2){ 
        cout<<"tene if";
        return -100;
    }else if(check(Board)==false && Depth==0){
        cout<<"telit if";

        return 0;
    } 
    int bestScore = -10000, score = 0;
    string temp, bestMove;
    if(isMaximising==true){
        for (int row = 0; row < Boardsize; row++) for (int column = 0; column < Boardsize; column++)
            if (Board[row].Moves[column] != 'X' && Board[row].Moves[column] != 'O'){
                temp = Board[row].Moves[column];
                Board[row].Moves[column] = p2;
                score = minimax(Board, Depth-1, p1, p2, false);
                Board[row].Moves[column] = temp[0];
                if (score > bestScore) bestScore = score;
                     
            }
    }else{
        bestScore=800;
        for (int row = 0; row < Boardsize; row++)
            for (int column = 0; column < Boardsize; column++)
                if (Board[row].Moves[column] != 'X' && Board[row].Moves[column] != 'O'){
                    temp=Board[row].Moves[column];
                    Board[row].Moves[column]=p1;
                    score = minimax(Board, Depth - 1, p1, p2, false);
                    Board[row].Moves[column] = temp[0];
                    if (score < bestScore) bestScore = score;
                }
    }
    return bestScore;
}
#endif // !AI_H