#ifndef search_H
#define search_H
//calling libraries and predefines
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#define INDEXED_Position 0
#define BUFFER_Position_Size 1
#define Position_VALUE 2
#define sizeofstrlen 9
char FILENAME[sizeofstrlen] = "list.txt";
FILE *File_Var = fopen(FILENAME, "r");
using namespace std;

//usermame and password lists
typedef struct pointer
{
    string data;
    struct pointer *next;
} node;
node *list_usernames = NULL;
node *list_passwords = NULL;
int search_unit(string username,string password);


//initiliase name in singly-linked-list
bool init_name_list(string Name_HOLDER)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        cout << "Malloc Failure" << endl;
    }
    temp->data = Name_HOLDER;
    temp->next = list_usernames;
    while (list_usernames != NULL)
    {
        list_usernames = list_usernames->next;
    }
    list_usernames = temp;
    return true;
}

//initiliase passwords in singly-linked-list
bool init_password_list(string Password_HOLDER){
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        cout << "Error <Malloc Failure!>" << endl;
    }
    temp->data = Password_HOLDER;
    temp->next = list_passwords;
    while (list_passwords != NULL)
    {
        list_passwords = list_passwords->next;
    }
    list_passwords = temp;
    return true;
}

//main function
int init_SearchChain(void){
    //extracting list from database
    if (File_Var == NULL)
    {
        cout << "FATAL:Error Search Stream!/>>IOFile Not Found!>>" << endl;
        cout << "Download File:https://github.com/FreddyBicandy50/MyLibrary/blob/main/Projects/list.txt" << endl;
    }
    char *Char_HOLDER = (char *)malloc(sizeof(char) * sizeofstrlen * 100);
    static int PlaceHOLDER = INDEXED_Position;
    while (fscanf(File_Var, "%s", Char_HOLDER) == 1){
        if (PlaceHOLDER % Position_VALUE == INDEXED_Position){
            init_name_list(Char_HOLDER);
        }
        else{
            init_password_list(Char_HOLDER);
        }
        PlaceHOLDER += BUFFER_Position_Size;
    }

    //1.search
    //2.Main Activity
    //3.register
    return 0;
}

int Cryptlib(int CallFunction,string username,string password){
    if (CallFunction==1){
        init_SearchChain();
        search(username, password);
    }
    return 0;
}

int search(string username,string password){
    //username
    while (list_usernames!=NULL){
        if(sctrmp(username,list_usernames->data)==0){
            
        }
    }
        return 0;
}
#endif