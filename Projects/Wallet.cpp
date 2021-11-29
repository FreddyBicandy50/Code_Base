#include <iostream>
#include <cstring>
#include <cstdlib>
#include "search.h"
#define CallFunction 1
#define Void_NULL 0
using namespace std; 
typedef struct chain{
    int data;
    struct chain *next;
    struct chain *prev;
}blockchain;
blockchain *MetaData = NULL;
static int func=Void_NULL;
int login(string username,string password){ 
    func=CallFunction;
    if(Cryptlib(func,username,password)==0){
        cout<<"found"<<endl;
    }
    else if (Cryptlib(func, username, password) == 1){
        cout<<"wrong password"<<endl;
    }else{
        cout<<"NOT Match!"<<endl;
    }
    return 0;
}
int main(int argc,char *argv[]){
    if(argc<2 || argc>3){
        cout<<"Wallet Has no arguments!\n\t\t~run Wallet --help"<<endl;
        return 0;
    }else {
        if(strcmp(argv[1],"--help")==0){
            cout << "./Wallet username/password";
            return 0;
        }else{ 
           string username=argv[1],password=argv[2];
           login(username,password); 
        }
    }
    return 0;
}