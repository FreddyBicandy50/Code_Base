#include <iostream>
#include <cstring>
#include <cstdlib>
#include "search.h"
#include "register.h" 
#include "Define.h" 
using namespace std; 

void login(string username,string password){
    int Access_Check = fsearch_call(username, password);

    if (Access_Check == Access_Granted)
        cout << "found" << endl;
    else if (Access_Check == NOT_Match)
        cout << "Wallet Credential not  Match!" << endl;
    else
        cout << "Credentials are not registered in chain!\nplease register" << endl;
 
}
int main(int argc,char *argv[]){

    switch (argc){
        case 1:
            cout << "Wallet missing argument: <$username$><$password$>"<<endl;
            return Void0; 
        case 2:
            if (strcmp(argv[1],"--register")==Void0) cout << "register missing argument: <$username$><$password$>"<<endl;
            else cout << "wallet missing argument: <username><$password$>"<<endl; 
            return Void1; 
        case 3:
            if (strcmp(argv[1], "--register") == Void0){
                cout << "register missing argument: <username><$password$>" << endl;
                return Void1; 
            }else login(argv[1], argv[2]); 
            break;
        case 4:
            if (strcmp(argv[1], "--register") == 0){  
                if(fregister(argv[2],argv[3])==Void1) printf("\n<$username$:%s> aleardy Available!",argv[2]);
                else printf("\ncompleted please save your wallet credentials:\n\t<usermame:%s> <password:%s>",argv[2],argv[3]);
            }else{
                cout<<"Error program varaible set parameter user may enterd sapces in either %username %password";
            }
            return Void0;
        default:
            cout<<"Error program varaible set parameter user may enterd sapces in either %username %password";
    }
  return Void0;
}