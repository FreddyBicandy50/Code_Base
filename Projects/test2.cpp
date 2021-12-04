//calling libraries and predefines
//calling libraries and predefines
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <sstream>
#include "Define.h"  
FILE *File_Var = fopen(FILENAME, "r");
using namespace std;
#define n 10
int printing();
//usermame and password lists
typedef struct pointer{
    string data;
    struct pointer *next;
} node;
node *list_usernames = NULL;
node *list_passwords = NULL; 
node *SLKey = NULL;
//initiliase name in singly-linked-list
bool init_list(string Token,int flag){
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL){
        cout << "Error <Malloc Failure!>" << endl;
        return false;
    }
    if (flag==us_token){
        temp->data = Token;
        temp->next = list_usernames;
        while (list_usernames != NULL){
            list_usernames = list_usernames->next;
        }
        list_usernames = temp;
        return true;
    }
    return false;
}

//main function
int main (){
    //extracting list from database
    
    if (File_Var == NULL){
        cout << "FATAL:Error Search Stream!/>>IOFile Not Found!>>" << endl;
        cout << "Download File:https://github.com/FreddyBicandy50/MyLibrary/blob/main/Projects/list.txt" << endl;
    }
    
    char *Char_HOLDER = (char *)malloc(sizeof(char) * sizeofstrlen * 100);
    bool flag;
    static int keyholder, PlaceHOLDER = INDEXED_Position;
    bool flag;
    int spaces = Void0; 
    while (fscanf(File_Var, "%s", Char_HOLDER) == Void1){ 
        if(flag==true){
            stringstream to_int;
            int Token;
            to_int << Token;
            to_int >> Token;
            if(Token==0){
                spaces==0;
            }
        }
        if (spaces == Void0 || spaces == Void1 ){
            flag=false;
        }if(spaces>1){
            flag=true; 
        }
        if(flag==false){
            if(spaces==Void0){
                if (init_list(Char_HOLDER,us_token) == false){
                    cout<<"fatal system error\n";
                    exit(-1);
                    spaces++;
                }
            }else{
                if (init_list(Char_HOLDER, ps_token) == false){
                    cout << "fatal system error\n";
                    exit(-1);
                    spaces++;
                }
            }
        }else{
            if (init_list(Char_HOLDER,key_token) == false){
                cout << "fatal system error\n";
                exit(-1);
            }
        }
    }
    printing();
    return 0;
}
//printing
int printing(){
    //username
    while(SLKey!=NULL){
        cout<<SLKey->data;
        if(SLKey->next==NULL){
            break;
        }
        SLKey = SLKey->next;
    }  
    return 0;
}