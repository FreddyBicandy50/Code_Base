//calling libraries and defining fnctions

#include <iostream>     //basic functions
#include <cstdlib>      //for advanced functions
#include <cstring>      //for strcmp
#include "Define.h"     //for predefined Variables
#include "logo.h"     //for Tic Tac Toe logo

using namespace std;    //to avoid using std with every io func
void displayhelp();     //function to display help usage
 
//main function
int main(int argc,char *argv[]){
    Logo();  
    // checking the number of inputs by parameter
    switch (argc){
        case 1:
            //the user didn't specify a user and pass
            printf("Tic-tac-toe missing argument:");
            cout<<"Tic-tac-toe missing argument:"<<CYAN<<"--MOD"<<RESET <<" <"<< YELLOW<< "Player-name"<<RESET <<">"<<" <"<< RED <<"Player2-name"<<RESET <<"/"<<GREEN <<"Difficulty" <<RESET<<">"<<endl;
            displayhelp(); //display wallet help center
            exit(exit_no_error);

        case 2:
            //check if user trying to login or register/delete
            if (strcmp(argv[1], "--S")==no_error){
                cout<<CYAN <<argv[1] <<RESET <<"missing argument:"<<  "<"<<YELLOW <<"Player-name" <<RESET <<"> <"<< YELLOW <<"Difficulty"<<RESET<<">"<<endl;
                exit(exit_no_error);
            }else if(strcmp(argv[1], "--2P")==no_error){
                cout<<CYAN<<argv[1]<<RESET<<" missing argument:"<<  "<"<< YELLOW << "Player-name" << RESET <<">"<<"<"<< YELLOW <<"Player2-name"<<RESET<<">"<<endl;
                exit(exit_no_error);
            }
    }
        */
    return no_error;
}

void displayhelp(){

    //displaying help
    cout<< endl;
    cout<<"Usage Option 1 [single] ./tic-tac-toe " <<CYAN <<"--S " <<RESET  <<"<"<<YELLOW<<"Player-name" << RESET <<">"<< "<Difficulty:"<< GREEN <<"Easy"<< RESET <<"/" <<RED<<"Hard"<<RESET <<">" <<endl;
    cout<<"Usage Option 2 [2 Player] ./tic-tac-toe "<<CYAN <<"--2P "<<RESET <<"<" <<YELLOW << "Player1-name"<< RESET <<">" <<"<" <<YELLOW <<"Player2-name" <<RESET <<">" <<endl;
}

//endof program