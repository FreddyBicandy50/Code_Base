#ifndef screen_H 
#define screen_H
#include <iostream>
#include <cstdlib>   
#include <cstring> 
#include <sstream>
#include "Define.h"
using namespace std;
typedef struct{
    char Moves[Boardsize];
    bool Trace[Boardsize];
} Table;
string color[Boardsize][Boardsize];

void logo(){
    printf("%s████████╗██╗ ██████╗ %s ████████╗ █████╗  ██████╗%s ████████╗ ██████╗ ███████╗ \n", RED,YELLOW,GREEN);
    printf("%s╚══██╔══╝██║██╔════╝ %s ╚══██╔══╝██╔══██╗██╔════╝%s ╚══██╔══╝██╔═══██╗██╔════╝\n", RED, YELLOW, GREEN);
    printf("%s   ██║   ██║██║      %s    ██║   ███████║██║     %s    ██║   ██║   ██║█████╗  \n", RED, YELLOW, GREEN);
    printf("%s   ██║   ██║██║      %s    ██║   ██╔══██║██║     %s    ██║   ██║   ██║██╔══╝  \n", RED, YELLOW, GREEN);
    printf("%s   ██║   ██║╚██████╗ %s    ██║   ██║  ██║╚██████╗%s    ██║   ╚██████╔╝███████╗\n", RED, YELLOW, GREEN);
    printf("%s   ╚═╝   ╚═╝ ╚═════╝ %s    ╚═╝   ╚═╝  ╚═╝ ╚═════╝%s    ╚═╝    ╚═════╝ ╚══════╝\n", RED, YELLOW, GREEN);
    reset();
}
void cls(){
    system("clear"); 
    
} 
 
void print_result(bool winner,string winnername){
    if(winner==true) printf("\n\t\t\t\t      %s%s Win       \n",WHITE,winnername.c_str());
    else printf("\n\t\t\t\t       %sTIE!        \n",WHITE);

   
}

Table *board_update(bool start,Table *Board,int player1_score,int player2_score,bool winnertracer ){
    system("clear");
    printf("\t\t\t\t      Score");
    printf("\n\t\t\t\t%s      %d | %d     \n", WHITE, player1_score, player2_score);
    printf("\n");
    if (start==true){
        int counter=1;
        for (int row=0; row<Boardsize ; row++)
            for (int column=0; column<Boardsize; column++){
                stringstream tostring;
                tostring <<counter ;
                tostring >> Board[row].Moves[column]; 
                Board[row].Trace[column] = false;
                color[row][column]=WHITE;
                counter++;
            } 
    }else {
        if(winnertracer==false){ 
            for (int row = 0; row < Boardsize; row++)
                for (int column = 0; column < Boardsize; column++) {
                    string getboard_values;
                    getboard_values.push_back(Board[row].Moves[column]);

                    if(getboard_values.compare("X")==0) color[row][column] = RED;
                    else if(getboard_values.compare("O")==0) color[row][column] = GREEN;
                } 
            
        }else{
            for (int row = 0; row < Boardsize; row++)
            for (int column = 0; column < Boardsize; column++) {
                string getboard_values;
                getboard_values.push_back(Board[row].Moves[column]);

                if(Board[row].Trace[column]==true)  
                    if(Board[row].Moves[column]=='X') {
                        color[row][column] = RED;
                        
                    }else {
                        color[row][column] = GREEN;

                    }
                else color[row][column] = WHITE;
            } 
        }
    }
    printf("\t\t\t\t%s     |     |     \n", YELLOW);
    printf("\t\t\t\t%s  %c %s |  %s%c %s |  %s%c\n", color[0][0].c_str(), Board[0].Moves[0], YELLOW, color[0][1].c_str(), Board[0].Moves[1], YELLOW, color[0][2].c_str(), Board[0].Moves[2]);
    printf("\t\t\t\t%s_____|_____|_____\n", YELLOW);
    printf("\t\t\t\t     |     |     \n", YELLOW);
    printf("\t\t\t\t%s  %c%s  |  %s%c%s  |  %s%c\n", color[1][0].c_str(), Board[1].Moves[0], YELLOW, color[1][1].c_str(), Board[1].Moves[1], YELLOW, color[1][2].c_str(), Board[1].Moves[2]);
    printf("\t\t\t\t%s_____|_____|_____\n", YELLOW);
    printf("\t\t\t\t%s     |     |     \n", YELLOW);
    printf("\t\t\t\t%s  %c %s |  %s%c  %s|  %s%c  \n", color[2][0].c_str(), Board[2].Moves[0], YELLOW, color[2][1].c_str(), Board[2].Moves[1], YELLOW, color[2][2].c_str(), Board[2].Moves[2]);
    printf("\t\t\t\t%s     |     |     \n", YELLOW);
    reset();
   
     

    return 0;
}
#endif