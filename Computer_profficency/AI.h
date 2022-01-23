#ifndef AI_H
#define AI_H
#include <iostream>
#include "Game.h"
#include "Define.h"
#include "screen.h"
char win;
int minimax(Table *Board,int Depth,char p1,char p2,bool isMaximising);

bool check_winner(Table *Board){
    // function to check if we have a winner after 5 attemps
    // rows
    for (int row = 0; row < Boardsize; row++)
        if (Board[row].Moves[1] == Board[row].Moves[0] && Board[row].Moves[2] == Board[row].Moves[0]){
            win = Board[row].Moves[0];
            return true;
        }

    // columns
    for (int column = 0; column < Boardsize; column++)
        if (Board[1].Moves[column] == Board[0].Moves[column] && Board[2].Moves[column] == Board[0].Moves[column]){
            win = Board[1].Moves[column];
            return true;
        }
              
    
    // diagionles
        // left
        for (int row = 0; row < Boardsize; row++)
            for (int column = 0; column < Boardsize; column++)
                if (column == row) if (Board[row].Moves[column] == Board[row + 1].Moves[column + 1]){
                    win = Board[0].Moves[0];
                    return true;
                }
            
        

        // right diagonal
        int temp = Boardsize;
        for (int row = 0; row < Boardsize; row++) {
            temp -= 1;
            for (int column = 0; column < Boardsize; column++)
                if (column == temp) if (Board[row].Moves[column] == Board[row + 1].Moves[temp - 1]){
                    win = Board[0].Moves[2];
                    return true;
                }
        }
    return false;
}

string compMove (Table Board[Boardsize],int D,char p1,char p2){
    int bestScore=-1000,score=0;
    string temp, bestMove;
    for (int i = 0; i < Boardsize; i++)
        for (int j = 0; j < Boardsize; j++)
            if (Board[i].Moves[j] != 'X' && Board[i].Moves[j] != 'O'){
                temp = Board[i].Moves[j];
                Board[i].Moves[j] = p2;
                score = minimax(Board,D, p1, p2, false); 
                Board[i].Moves[j] = temp[0];
                if (score > bestScore){
                    bestScore = score;
                    bestMove=Board[i].Moves[j];        
                }
            }

    return bestMove;
}

int minimax(Table *Board,int Depth,char p1,char p2,bool isMaximising){

    if(check_winner(Board)==true && win==p2) return +10;
    else if(check_winner(Board)==true && win!=p2) return -10; 
    else if(Depth==9 && check_winner(Board)==false) return 0;
    

    int bestScore, score;
    string temp;
    if(isMaximising==true){
        if(p2=='X') bestScore=-1000;
        else bestScore=800;
        for (int i = 0; i < Boardsize; i++)
            for (int j = 0; j < Boardsize; j++)
                if (Board[i].Moves[j] != 'X' && Board[i].Moves[j] != 'O') {
                    temp = Board[i].Moves[j];
                    Board[i].Moves[j] = p2;
                    score = minimax(Board,Depth+1, p1, p2, false);
                    Board[i].Moves[j] = temp[0]; 
                    if (score > bestScore) bestScore = score; 
                } 

    }else{
        if(p1=='X') bestScore=-1000;
        else bestScore=800;    
            
        for (int i = 0; i < Boardsize; i++)
            for (int j = 0; j < Boardsize; j++)
                if (Board[i].Moves[j] != 'X' && Board[i].Moves[j] != 'O'){
                    temp = Board[i].Moves[j];
                    Board[i].Moves[j] = p1;
                    score = minimax(Board, Depth + 1, p1, p2, true);
                    Board[i].Moves[j] = temp[0];
                    if (score < bestScore) bestScore = score;
                }
    }
   return bestScore;
}
#endif // !minimax_H