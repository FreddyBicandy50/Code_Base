#include <iostream>
#include <cstring>
#include <cstdlib>
#include "search.h"
#include "register.h" 
#include "Define.h" 
using namespace std; 
typedef struct chain{
    int data;
    struct chain *next;
    struct chain *prev;
}blockchain;
blockchain *MetaData = NULL;
int login(string username,string password){
    if (fsearch_call(username, password) == Access_Granted){
        //main menu
        cout<<"found"<<endl;
    }
    else if (fsearch_call(username, password) == NOT_Match) {
        cout<<"Wallet Credential not Match!"<<endl;
    }
    else{
        cout<<"Credentials are not registered in chain!\n please run ./Wallet --register"<<endl;
    }
    return Void0;
}
int main(int argc,char *argv[]){
    switch (argc){
        case 1:
            cout << "Wallet missing argument: <$username$><$password$>"<<endl;
            return Void0; 
        case 2:
            if (strcmp(argv[1],"--register")==0){
                cout << "register missing argument: <$username$><$password$>"<<endl;
            }else{
                cout << "wallet missing argument: <username><$password$>"<<endl; 
            }
            return Void0; 
        case 3:
            if (strcmp(argv[1], "--register") == 0){
                cout << "register missing argument: <username><$password$>" << endl;
                return Void0; 
            }else{
                login(argv[1], argv[2]);
                return Void0; 
            }
        case 4:
            if (strcmp(argv[1], "--register") == 0){ 
                if(fregister(argv[2],argv[3])==Void1){
                    printf("\n<$username$:%s> aleardy Available",argv[2]);
                }else{
                    printf("\ncompleted please save your wallet credentials:\n\t<usermame:%s> <password:%s>",argv[2],argv[3]);
                }
                return Void0; 
            }
    }
   
}