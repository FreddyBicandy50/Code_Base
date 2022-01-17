//defining the Header File
#ifndef  Game_H
#define Game_H
#include <iostream>     //basic functions 
#include <chrono>       //for system colock function
#include <random>       //to random numbers
#include <sstream>       //to random numbers
#include "Define.h"     //for predefined const Variables
#include "screen.h"     //for init/update board,print winner... 
using namespace std;
using namespace std::chrono;
Table *Board=(Table *) malloc(sizeof(Table)*Boardsize);//array of Board size of 3 
char Winner_Announcement,p1,p2;   //to hold winner X/O, player Move=[X/O]/Computer_Move=[X/O]
int player1_score=0,player2_score=0;
void restart_game(string current_pname, bool diff);
//initialise the board with number form 1 till 9 and printing it 
void setup_game(){

    board_update(true, Board, player1_score, player2_score); // parsing the Board as a pointer so we can remodify It later on, the true parameter indicates  the game just started (function from:screen.h)

    //get a forced random number via colock value to acheive balance in game
    u_int16_t seed = system_clock::now().time_since_epoch().count();
    srand(seed); // Set the numbers for int.

    //check if random function gave me 1 p1 will play as X and p2 as O 
    if (rand() % 2 + 1 == 1) {
        p1 = 'X';
        p2 = 'O';
    }else{
        p1='O';
        p2='X';
    } 
}

//function to check if we have a winner after 5 attemps
bool check_winner(){
    
    //rows
    for (int row = 0; row < Boardsize; row++)
        if (Board[row].Moves[1]==Board[row].Moves[0] && Board[row].Moves[2] == Board[row].Moves[0]){
            Winner_Announcement = Board[row].Moves[0];
            return true;
        }
    
    
    //columns
    for (int column = 0; column < Boardsize; column++)
        if (Board[1].Moves[column] == Board[0].Moves[column] && Board[2].Moves[column] == Board[0].Moves[column]) {
            Winner_Announcement = Board[1].Moves[column];
            return true;
        }  
   

    //diagionles
        //left
        int counter=0,temp=Boardsize;
        for (int row = 0; row < Boardsize; row++){
            for (int column = 0; column < Boardsize; column++)
                if (column == row) if (Board[row].Moves[column] == Board[row + 1].Moves[column + 1]) counter++;
            if (counter==2){
                Winner_Announcement = Board[0].Moves[0];
                return true;
            }
        }

        //right diagonal
        counter=0;
        for (int row=0; row<Boardsize; row++){
            temp-=1;
            for (int column=0; column<Boardsize; column++) 
                if (column == temp) if(Board[row].Moves[column]==Board[row+1].Moves[temp-1]) counter++; 
            if(counter==2){
                Winner_Announcement = Board[0].Moves[2];
                return true;
            }
        }
    
    return false;
}

//this function will activate if the user choose to play with boot 
void singleplayer(string playername,bool AI){

    //initialise the board
    setup_game(); 

    //init a flag (playerturn) to check who's turn tor play
    bool playerturn;
    int Game_runing=0;
    if(p1=='X') playerturn=true;
    else playerturn=false; 
    while(true){
        if (Game_runing == 9 && check_winner() == false) {
            print_result(false," ");
            restart_game(playername,AI);
        }
            if (Game_runing >= 5)
                if (check_winner() == true){
                    if (Winner_Announcement == p1) {
                        print_result(true, playername);
                        player1_score++;
                    }else {
                        print_result(true, "computer");
                        player2_score++;
                    }
                    restart_game(playername, AI);
                }

        if(playerturn==true){
            string spot;
            do{ 
                cout << playername << " Turn" << YELLOW << ">" << WHITE;
                cin >> spot;
                if ((spot.length() > 1) || (spot[0] < '1' || spot[0] > '9')){
                    cout << RED << "invaild Spot!" << WHITE << endl;
                    spot = ' ';}

            }while (spot[0] < '1' || spot[0] > '9'); 
             
            for (int row=0; row<Boardsize; row++) for (int column=0; column<Boardsize; column++){
                    if (Board[row].Moves[column]==spot[0] && Board[row].isoccupied[column]==false){ 
                        Board[row].Moves[column]=p1;
                        Board[row].isoccupied[column]=true;
                        board_update(false,Board,player1_score,player2_score);
                        playerturn=false;
                        Game_runing++;
                    } 
               
            }
            if(playerturn!=false){
                cout<<RED<<"Aleardy Occupied"<<WHITE<<endl;
            } 
        }else{
           if(AI!=true){
                do{
                    u_int16_t seed = system_clock::now().time_since_epoch().count();
                    srand(seed); // Set the numbers for int.
                    stringstream tochar;
                    tochar << rand() % 9 + 1;
                    char spot;
                    tochar >> spot; 
                    
                    for (int row=0; row<Boardsize; row++)
                        for (int column=0; column<Boardsize; column++)
                            if (Board[row].Moves[column]==spot && Board[row].isoccupied[column]==false){ 
                                Board[row].Moves[column]=p2;
                                Board[row].isoccupied[column]=true;

                                board_update(false, Board, player1_score, player2_score);
                                playerturn=true;
                                Game_runing++;
                            }
               } while (playerturn!=true);
           } 
        }
        
        
    }



} 

void multiplayer(string player1name, string player2name){
    
}

void restart_game(string current_pname,bool diff){
    cout<<"restart[y/n]:";
    string restart;
    do{
        cin >> restart;
        if(restart.length()>1){
            restart='K';
        }
    } while(restart[0]!='y' && restart[0]!='n' && restart[0]!='Y' && restart[0]!='N');

    if(restart[0]=='y' || restart[0]=='Y') singleplayer(current_pname,diff);
    else exit(0);
}
#endif // ! Game_H
 