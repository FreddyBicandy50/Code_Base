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
#include "reverse.h"  
FILE *File_Var = fopen(FILENAME, "r");
FILE *File_key = fopen(keylist, "r");
using namespace std;
typedef struct pointer{
    string username;
    int password[Max_password_length];
    struct pointer *next;
    struct pointer *prev;
} node; 
node *list = NULL;
int search_unit(string username,string password);
 

//initiliase name in singly-linked-list
bool init_list(string Token,int flag,int index){ 
    if (flag==us_token){
        node *temp = (node *)malloc(sizeof(node));
        if(temp==NULL){
            cout<<"Malloc Failure!"<<endl;
            return false;
        }
        while(list!=NULL){
            list=list->next;
        }
        temp=list;
        list->username=Token; 
        return true;
    }else {
        int key_to_int;
        stringstream to_int;
        to_int << Token;
        to_int >> key_to_int; 
        list->password[index]=key_to_int;
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
    char *Char_HOLDER = (char *)malloc(sizeof(char) * sizeofstrlen * Max_password_length);
    int flag=Void0;
    while (fscanf(File_Var, "%s", Char_HOLDER) == Void1){ 
         if(flag!=1){
            init_list(Char_HOLDER,us_token,flag);
            flag++;
        }else{ 
            if(init_list(Char_HOLDER,ps_token,flag-1)==false){
                cout<<"exiting..."<<endl;
                exit(-1);
            }   
        }
        if(flag==password.length()){
            flag=Void0;
        }
    } 

    return search_unit(username, password); 
} 


//searching unit
int search_unit(string username, string password){
    while(list!=NULL){
        if(username.compare(list->username)==Void0){
            if(freverse(password,list->password)==Void0){
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