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
    if (flag == Void1){
        stringstream to_int;
        to_int << Token;
        int keylogger;
        to_int >> keylogger;
    } 
    if (flag==us_token){
        temp->data = Token;
        temp->next = list_usernames;
        while (list_usernames != NULL){
            list_usernames = list_usernames->next;
        }
        list_usernames = temp;
        return true;
    }else if (flag==ps_token){
        temp->data = Token;
        temp->next = SLKey;
        while (SLKey != NULL){
            SLKey = SLKey->next;
        }
        SLKey = temp;
        return true;
    }else if (Token == key_token){
        temp->data = Token;
        temp->next = list_passwords;
        while (list_passwords != NULL){
            list_passwords = list_passwords->next;
        }
        list_passwords = temp;
        return true;
    }
    return false;
}

//main function
int main (){
    //extracting list from database
    string random[n]={"freddy","1120","eliane","007","alain","788"};

    if (File_Var == NULL){
        cout << "FATAL:Error Search Stream!/>>IOFile Not Found!>>" << endl;
        cout << "Download File:https://github.com/FreddyBicandy50/MyLibrary/blob/main/Projects/list.txt" << endl;
    }
    
    char *Char_HOLDER = (char *)malloc(sizeof(char) * sizeofstrlen * 100);
    bool flag;
    static int keyholder, PlaceHOLDER = INDEXED_Position;
    
     
    while (fscanf(File_Var, "%s", Char_HOLDER) == 1){
        int space=Void0;
        if(space>=Void1){
            flag=true;
        }else if(space>=Void1+1){
            flag=false;
        }
        if(flag==true){ 
            if(space==Void0){
                bool Status_Check = init_list(Char_HOLDER,us_token);
                if (Status_Check == RUNTIME_FAILURE){
                    cout << "Fatal System error:\n" << endl;
                    exit(-1);
                    space++;
                }
            }else{
                bool Status_Check = init_list(Char_HOLDER, ps_token);
                if (Status_Check == RUNTIME_FAILURE){
                    cout << "Fatal System error:\n"<< endl;
                    exit(-1);
                    space++;
                }
            }
        }else{
            bool Status_Check = init_list(Char_HOLDER, key_token);
            if (Status_Check == RUNTIME_FAILURE){
                cout << "Fatal System error:\n" << endl;
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