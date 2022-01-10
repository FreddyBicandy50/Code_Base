//calling functions and defining File.H
#ifndef Register_H  
#define Register_H 
#include <iostream>     //basic functions
#include <fstream>      //for ofstream functions
#include "check.h"      //to check if username valid
#include "encrypt.h"    //to encrypt password registerd
using namespace std;
ofstream putfile(list_database, ios_base::app); // opening list file to append on it

//Registering main function
int fregister(string user_regist, string password_regist){
    
    //check if username Valid and if not returning and error singal
    if (isvalid(user_regist, password_regist) == error) return error;
    
    else{
        putfile << user_regist;
        int *pass_enc = encrypt(password_regist);
        for (int position = starting_position; position < password_regist.length(); position++){
            system("echo / && sleep 1");
            putfile << " " << pass_enc[position];
            system("echo \\ && sleep 1");
            system("echo - && sleep 1");
        }
        putfile << "\n";
        return no_error;
    }
}

#endif // !Register_H