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
using namespace std;
typedef struct pointer{
    string username;
    struct pointer *next;
} node; 
node *list = NULL;
int search_unit(string username,string password);
void reverse_list();

//initiliase name in singly-linked-list
bool init_list(string Token){ 
    node *temp = (node *)malloc(sizeof(node));
    if(temp==NULL){
        cout<<"Malloc Failure!"<<endl;
        return false;
    }
    temp->username=Token;
    temp->next=list;
    while(list!=NULL){
        list=list->next;
    }
    
    list=temp;
    return true;   
}

 
//main function
int fsearch_call (string username,string password){
    //extracting list from database
    FILE *listfile=fopen(list_data,"r");
    if (listfile == NULL){
        cout << "FATAL:Error Search Stream!/>>IOFile Not Found!>>" << endl;
        cout << "Download File:https://github.com/FreddyBicandy50/MyLibrary/blob/main/Projects/list.txt" << endl;
    }
    char *Char_HOLDER = (char *)malloc(sizeof(char) * sizeofstrlen * Max_password_length);
    int flag=Void0;
    while (fscanf(listfile, "%s", Char_HOLDER) == Void1){ 
        if(isalpha(Char_HOLDER[0])){
            flag=Void0;
        }
         if(flag==0){
            if(init_list(Char_HOLDER)==false){
                cout<<"exiting...";  
                exit(-1);
            }
            flag++;
        }
    }  
    
    
    reverse_list();
    return search_unit(username, password); 
}
void reverse_list(){
    node *current = list;
    node *next = NULL;
    node *prev = NULL; 
    while (current != NULL) {
        next= current->next;
        current->next=prev;
        prev=current;
        current = next;
    }
    list = prev; 
}
//searching unit
int search_unit(string username, string password){
    int position=Void1;
    while(list!=NULL){
        if(username.compare(list->username)==Void0){
            if(checkpassword(password,position)==true) return Access_Granted;
            else  return NOT_Match;
          
        }else list=list->next;  
        position++;
    }
    return NOT_Found;
} 
#endif