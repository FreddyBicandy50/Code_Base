#ifndef screen_H 
#define screen_H
#include <iostream>
#include <cstdlib>

#include <string>
#include <cstring>
#include <string.h>
#include <sstream>
#include "Define.h"
using namespace std;
typedef struct
{
    char Moves[3];
    bool isoccupied[3];
} Table;
/*char red[10] = "\033[1;31m" ;
char green[10]= "\033[1;32m"; 
char white[10]= "\033[1;37m";  */
const char *color ;
void logo()
{
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
 

Table *board_update(bool start,Table *Board){

    system("clear");
    printf("\n\n");
    if (start==true){
        int counter=1;
        for (int row=0; row<Boardsize ; row++)
            for (int column=0; column<Boardsize; column++){
                stringstream tostring;
                tostring <<counter ;
                tostring >> Board[row].Moves[column]; 
                Board[row].isoccupied[column] = false;
                counter++;
            } 
    }else{
      
        for (int row = 0; row < Boardsize; row++)
            for (int column = 0; column < Boardsize; column++)
            {
                string getboard_values;
                getboard_values.push_back(Board[row].isoccupied[column]);

                if (getboard_values.compare("X") == 0)
                    color= RED.c_str();
                else if (getboard_values.compare("O") == 0)
                    color = GREEN.c_str();
                else
                    color = WHITE.c_str();
            }
    }
   

    printf("\t\t\t\t%s     |     |     \n", YELLOW);
    printf("\t\t\t\t%s  %c %s |  %s%c %s |  %s%c\n", color, Board[0].Moves[0], YELLOW, color, Board[0].Moves[1], YELLOW, color, Board[0].Moves[2]);
    printf("\t\t\t\t%s_____|_____|_____\n", YELLOW);
    printf("\t\t\t\t     |     |     \n", YELLOW);
    printf("\t\t\t\t%s  %c%s  |  %s%c%s  |  %s%c\n", color, Board[1].Moves[0], YELLOW, color, Board[1].Moves[1], YELLOW, color, Board[1].Moves[2]);
    printf("\t\t\t\t%s_____|_____|_____\n", YELLOW);
    printf("\t\t\t\t%s     |     |     \n", YELLOW);
    printf("\t\t\t\t%s  %c %s |  %s%c  %s|  %s%c  \n", color, Board[2].Moves[0], YELLOW, color, Board[2].Moves[1], YELLOW, color, Board[2].Moves[2]);
    printf("\t\t\t\t%s     |     |     \n", YELLOW);

    return Board;
}
#endif