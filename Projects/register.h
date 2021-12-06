#ifndef Register_H
#define Register_H
#include <iostream>
#include <fstream> 
#include "check.h" 
#include "ecrypt.h" 
using namespace std;
ofstream outputFile(FILENAME, ios_base::app);
int fregister(string user_regist, string password_regist){
    cout << "registering/ " ;
    for (int i = Void0; i <= sizeofstrlen; i++){
        cout << ".";
    }
    encrypt(password_regist);
    
    if(check_available(user_regist, password_regist)==Void1){
       return Void1;
    }else{
        outputFile <<"\n" << user_regist << " " << password_regist; 
        return Void0;
    }
 
}
#endif // !Register_H