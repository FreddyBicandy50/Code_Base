//calling libraries and defining fnctions

#include <iostream>     //basic functions
#include <cstdlib>      //for advanced functions
#include <cstring>      //for strcmp
#include "search.h"     //for searching function
#include "register.h"   //for registering function
#include "Define.h"     //for predefined Variables
using namespace std;    //to avoid using std with every io func
void displayhelp();     //function to display help usage


//loging in phase function
void login(string username,string password){

    //searching if username and password matches in database
    if (database(username, password, true)==Access_Granted) { 

        system("tput setaf 2 && echo Access Granted");
        cout << "\n Welcome" << username << endl;

    }else if (database(username, password,true) == Access_Failed)
        system("tput setaf 1 && echo Wallet Credential not  Match!");
    
    else
        system("tput setaf 3 && echo Username not Found");
        

}

//main function
int main(int argc,char *argv[]){

    //checking the number of inputs by parameter
    switch (argc){
        case 1:
            //the user didn't specify a user and pass
            cout<<"Wallet missing argument:"<<  "<"<< YELLOW << "$username" << RESET <<">"<<"<"<< YELLOW <<"$password"<<RESET<<">"<<endl;

            displayhelp(); //display wallet help center
            exit(exit_no_error);
        
        case 2:
            //check if user trying to login or register/delete
            if (strcmp(argv[1], "--register")==no_error || strcmp(argv[1], "--del") == no_error) {
                cout<<CYAN<<argv[1]<<RESET<<" missing argument:"<<  "<"<< YELLOW << "$username" << RESET <<">"<<"<"<< YELLOW <<"$password"<<RESET<<">"<<endl;
                exit(exit_no_error);
            }else{ 
                //if user trying to login 2 argument is incorrect
                cout<<"Wallet missing argument:"<<  "<"<< GREEN << "username" << RESET <<">"<<"<"<< YELLOW <<"$password"<<RESET<<">"<<endl;
                exit(exit_no_error);                                             // stopping the program

            }

        case 3:
            //check if user is registering and forget to specify a password 
            if (strcmp(argv[1], "--register")==no_error || strcmp(argv[1], "--del") == no_error){
                cout<<CYAN<<argv[1]<<RESET<<" missing argument:"<<  "<"<< GREEN << "username" << RESET <<">"<<"<"<< YELLOW <<"$password"<<RESET<<">"<<endl;
                exit(exit_no_error); //stoping the program

            }else 
                login(argv[1], argv[2]); //loging phase
            break;//exit the switch
    
        case 4:
            //after confirming that user is trying to register/delete  
            if (strcmp(argv[1], "--register") == no_error){  

                //check if username valid or available and regsiter it if not
                if(fregister(argv[2],argv[3])==error) {
                    cout << endl << RED << "$username:" << RESET << argv[2] << "aleardy Available!"<<endl;
                    exit(exit_no_error); 
                }
                else 
                    cout<< "\ncompleted please save your wallet credentials:\n\t<"<<GREEN <<"usermame:"<<RESET <<argv[2]<< "> "<< "< "<<RED <<"password:" <<RESET <<argv[3] <<">";

            }else if(strcmp(argv[1], "--del") == no_error){

                //
                if (database(argv[2], argv[3],true) == error){
                    printf("\n<$username$:%s> aleardy Available!", argv[2]);   
                    exit(exit_no_error);  
                }
            }else{ 
                
                //if user not registering  or deleting 
                cout << "Invalid number of parameter\n";
                displayhelp();
                exit(exit_no_error);
            }
            return no_error;

        //in case number of parameter >4 
        default:
            cout<<"Invalid number of parameter\n";
            displayhelp();
            exit(exit_no_error);
    }
  return no_error;
}

void displayhelp(){

    //displaying help
    cout<<endl;
    cout <<"Usage Option 1 [login] ./Wallet <"<< YELLOW << "$username" << RESET <<">"<<"<"<< YELLOW <<"$password"<<RESET<<">"<<endl;
    cout <<"Usage Option 2 [register] ./Wallet "<<BLUE<<"--register "<<RESET<<"<" <<YELLOW << "$username" << RESET <<">"<<"<"<< YELLOW <<"$password"<<RESET<<">"<<endl;
    cout <<"Usage Option 3 [delete account] ./Wallet "<<RED<<"--del "<<RESET<<"<" <<YELLOW << "$username" << RESET <<">"<<"<"<< YELLOW <<"$password"<<RESET<<">"<<endl;
}

//endof program