#include <iostream>
#include <cstring>
#include <cstdlib>
#include "search.h"
using namespace std; 
typedef struct pointer{
    int data;
    struct pointer *next;
    struct pointer *prev;
}blockchain;
blockchain *MetaData = NULL;
int func;
int login(string username,string password){ 
    func=1;
    Cryptlib(func,username,password);
    return 0;
}
int main(int argc,char *argv[]){
    if(argc<3 || argc>3){
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
}