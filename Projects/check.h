#ifndef check_h
#define check_h
#include <iostream> 
#include "Define.h"
#include "search.h"
using namespace std;
bool checkrules(string user_regist, string password_regist);

int check_available(string name,string pass){ 
    if (fsearch_call(name, pass) == Access_Granted || search_unit(name, pass) == NOT_Match){
        return Void1;
    }else if(checkrules(name, pass)!=true){
        return Void1;
    }
    
    return Void0;
}
bool checkrules(string user_regist, string password_regist){
    if(isalpha(user_regist[0])){ 
        if(user_regist.length()>35){
            cout<<"\nusername can't be longer than 35 characters!"<<endl;
            exit(-1); 
        }else if(password_regist.length()>1000){
            cout<<"\npassword is too long!"<<endl;
            exit(-1);  
        }
        return true;
    }else{
        cout<<"\nusername can't start with non alpha character!"<<endl;
        exit(-1);
    }
    return false;
}
#endif // check.h