//calling functions and defining File.H + functions
#ifndef check_h 
#define check_h

#include <cstdlib>
#include <iostream>     //basic functions
#include "Define.h"     //for predefined Variables
#include "search.h"     //to check if username is available in current database
using namespace std;
bool checkrules(string user_regist, string password_regist); //function to check username equals to rules

//main check.h function
int isvalid(string name,string pass){ 
    //search if name aleardy taken
    if (database(name, pass,true) == Access_Granted || database(name, pass,true) == Not_Matched) 
        return error;

    //check if name follows the rules
    else if(checkrules(name, pass)!=true) 
        return error;
    
    //return no error indcates username is valid
    return no_error;
}

bool checkrules(string user_regist, string password_regist){
    //check if first character always starts with alphabet
    if(isalpha(user_regist[0]))

        // check if username lenght more then Maxlength
        if(user_regist.length()>Max_userlength){

            // check if username lenght more then Maxlength
            cout<<endl;
            system("tput setaf 1 && echo username can't be longer than 35 characters!");
            exit(error_exit);

        
        return true;
    }else{ 

        //if username fisrt character is not alphabet
        cout<<endl;
        system("tput setaf 1 && echo username can't start with non alpha character!");
        exit(error_exit); 

    }

    return false;
}



#endif // check.h