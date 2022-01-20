// calling libraries and defining fnctions
#include <iostream>  //basic functions
#include "Define.h"  //for predefined const Variables and colors
#include "Game.h"    //for predefined Variables
using namespace std; // to avoid using std with every io funciont

// main function
int main(void)
{

    cls();  // to clear the terminal screen from any history commands (function file:screen.h)
    logo(); // diplay the fancy TIK TAC TOE logo    (function file:screen.h)

    /*asking the user constantly for a choice to play single or multiplayer
    NOTE:ANY OTHER VALUE THE PROGRAM WON"T ACCEPT
    entering a infinite loop to take a specified choice from user*/

    string choice; // to hold user choice in a variable
    do
    {

        cout << "Multi-Player/Single Player? [m/s]:"; // toast a message
        cin >> choice;                                // read value

        // comparing if the value of choice valid one of these options
        if (choice.compare("S") != 0 && choice.compare("s") != 0 && choice.compare("m") != 0 && choice.compare("M") != 0)

            // if true a red message will be toasted
            cout << RED << "please enter one of the following options\n"
                 << WHITE;
        else
            // entering this stage means the user chooses one of our valid 2 options s or m

            // checking if the user chooses s for single player mode
            if (choice.compare("S") == 0 || choice.compare("s") == 0)
            {

                // if true 2 variable will be created and read to hold the player name and the difficulty to play with
                string difficulty, playername;
                cout << YELLOW << "player name" << WHITE << ":"; // toast message
                cin >> playername;                               // read playername

                // enterning infinite loop to ask the user for a specific choice
                do
                {

                    // toast a colored message asking for difficulty
                    cout << "Difficulty:" << GREEN << "Easy" << WHITE << "/" << RED << "Hard" << WHITE << ":";
                    cin >> difficulty; // read difficulty choice

                    // comparing if the value of choice valid one of these options
                    if (difficulty.compare("easy") != 0 && difficulty.compare("Easy") != 0 && difficulty.compare("hard") != 0 && difficulty.compare("Hard") != 0)

                        // if false a red notice will be toasted
                        cout << RED << "invalid Option!\n"
                             << WHITE;
                    else
                        // entering this stage means the user chooses one of our valid 2 options Easy or Hard

                        // after the user specifies the difficulty we need to check is easy or hard
                        if (difficulty.compare("easy") == 0 || difficulty.compare("Easy") == 0)

                            // if true the computer will play randomly against the user
                            singleplayer(playername, false); // function that send playername and false value indcates NON AI (from:Game.h file)
                        else if (difficulty.compare("hard") == 0 || difficulty.compare("Hard") == 0)

                            // if false the computer will play randomly against the user
                            singleplayer(playername, true); // function that send playername and false value indcates AI PLAY (from:Game.h file)

                } while (difficulty.compare("easy") != 0 && difficulty.compare("Easy") != 0 && difficulty.compare("hard") != 0 && difficulty.compare("Hard") != 0);
            }
            else
            {

                // entering this stage indactes the users chooses m to play multiplayer
                string player1name, player2name; // declare 2 string variable to hold the players name

                // reading player names
                cout << YELLOW << "player1 name" << WHITE << ":";
                cin >> player1name;
                cout << YELLOW << "player2 name" << WHITE << ":";
                cin >> player2name;

                multiplayer(player1name, player2name); // parsing players name to function (from:game.h)
            }
    } while (choice.compare("S") != 0 && choice.compare("s") != 0 && choice.compare("m") != 0 && choice.compare("M") != 0);

    return 0;
}

// endof program