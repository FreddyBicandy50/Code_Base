#ifndef search_H
#define search_H
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
const int R=Max_password_length; 
int IndexLoop_counter=Void0;
int printing();
//usermame and password lists
typedef struct pointer{
    string username;
    string password;
    int key[R];
    struct pointer *next;
} node; 
node *list = NULL;
int search_unit(string username,string password);

//initiliase name in singly-linked-list
//initiliase name in singly-linked-list
bool init_list(string Token,int flag){
    int key_to_int;
    if(flag==key_token){
        stringstream to_int;
        to_int << Token;
        to_int >> key_to_int;
    }
    if (flag==us_token){
        node *temp = (node *)malloc(sizeof(node));
            if (temp == NULL){
            cout << "Error <Malloc Failure!>" << endl;
            return false;
        }
        temp->username = Token;
        temp->next = list;
        while (list != NULL){
            list = list->next;
        }
        list = temp; 
        IndexLoop_counter=Void0;
        return true;
    }else if(flag==ps_token){
        list->password = Token;
        return true;
    }else{
        if(IndexLoop_counter!=list->password.length()){
            list->key[IndexLoop_counter]=key_to_int;
            IndexLoop_counter++;
        }
        return true; 
    }
    return false;
}

 
//main function
int fsearch_call (string username,string password){
    //extracting list from database
    if (File_Var == NULL){
        cout << "FATAL:Error Search Stream!/>>IOFile Not Found!>>" << endl;
        cout << "Download File:https://github.com/FreddyBicandy50/MyLibrary/blob/main/Projects/list.txt" << endl;
    }
    char *Char_HOLDER = (char *)malloc(sizeof(char) * sizeofstrlen * 100);
    bool flag;
    static int keyholder, PlaceHOLDER = INDEXED_Position; 
    int spaces = Void0; 
    while (fscanf(File_Var, "%s", Char_HOLDER) == Void1){ 
        if(flag==true){
            stringstream to_int;
            int Token;
            to_int << Char_HOLDER;
            to_int >> Token;
            if(Token==0){
                spaces=0;
            }
        }
        if(spaces == Void0 || spaces == Void1 ){ 
            flag=false;
        }if(spaces>1){
            flag=true; 
        }
       if(flag==false){
            if(spaces==Void0){
                if (init_list(Char_HOLDER,us_token) == false){
                    cout<<"fatal system error\n";
                    exit(-1);
                }
                spaces++;
            }else{ 
                if (init_list(Char_HOLDER, ps_token) == false){
                    cout << "fatal system error\n";
                    exit(-1);
                }
                spaces++;
            }
        }else{   
            if (init_list(Char_HOLDER,key_token) == false){
                cout << "fatal system error\n";
                exit(-1);
            }
        } 
    } 
    return search_unit(username, password); 
} 


//searching unit
int search_unit(string username, string password){
    while(list!=NULL){
        if(username.compare(list->username)==Void0){
            if(password.compare(list->password)==Void0){
                return Access_Granted;
            }else{
                return NOT_Match;}
        }else{
            list=list->next;
        }
    }
    return Not_Found;
} 
#endif