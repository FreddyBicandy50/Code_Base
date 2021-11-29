//calling libraries and predefines
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#define INDEXED_Position 0
#define RUNTIME_FAILURE false
#define BUFFER_Position_Size 1
#define Position_VALUE 2
#define sizeofstrlen 9
#define UNLOCK_user 10

char FILENAME[sizeofstrlen] = "list.txt";
FILE *File_Var = fopen(FILENAME, "r");
using namespace std;

//usermame and password lists
typedef struct pointer{
    string data;
    struct pointer *next;
} node;
node *list_usernames = NULL;
node *list_passwords = NULL;
int search_unit(string username, string password);

//initiliase name in singly-linked-list
bool init_list(string VAr_HOLDER, static int keylogger){
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL){
        cout << "Error <Malloc Failure!>" << endl;
        return false;
    }
    
    if(keylogger==BUFFER_Position_Size){
        temp->data = VAr_HOLDER;
        temp->next = list_usernames;
        while (list_usernames != NULL){
            list_usernames = list_usernames->next;
        }
        list_usernames = temp;
        return true;
    }else if(keylogger==INDEXED_Position){
        temp->data = VAr_HOLDER;
        temp->next = list_passwords;
        while (list_passwords != NULL)
        {
            list_passwords = list_passwords->next;
        }
        list_passwords = temp;
        return true;
    }else{
        cout<<"Invalid KEY!"<<endl;
        return false;
    }
}

//main function
int init_SearchChain(void){
    //extracting list from database
    if (File_Var == NULL){
        cout << "FATAL:Error Search Stream!/>>IOFile Not Found!>>" << endl;
        cout << "Download File:https://github.com/FreddyBicandy50/MyLibrary/blob/main/Projects/list.txt" << endl;
    }
    char *Char_HOLDER = (char *)malloc(sizeof(char) * sizeofstrlen * 100);
    static int keyholder,PlaceHOLDER = INDEXED_Position;
    while (fscanf(File_Var, "%s", Char_HOLDER) == 1){
        if (PlaceHOLDER % Position_VALUE == INDEXED_Position){
            bool Status_Check = init_list(Char_HOLDER, BUFFER_Position_Size);
            if(Status_Check==RUNTIME_FAILURE){
                cout<<"Fatal System error:\n"<<endl;
                exit(-1);
            }
        }else{
            bool Status_Check = init_list(Char_HOLDER, INDEXED_Position);
            if(Status_Check==RUNTIME_FAILURE){
                cout<<"Fatal System error:\n"<<endl;
                exit(-1);
            }
        }
        PlaceHOLDER += BUFFER_Position_Size;
    }
 
   
    return 0;
}

int main(void){
    //1.search
    //2.Main Activity
    //3.register
    init_SearchChain();
    string name="freddy";
    string password="1120";
    search(name,password);
    return 0;
}

int search(string username, string password){
    //username
    while (list_usernames!=NULL){
        if (sctrmp(username, list_usernames->data) == 0){
            while(list_passwords!=NULL){
                if(strcmp(password,list_passwords->data)==0){
                    static int Acces_Granted;
                }
                list_passwords=list_passwords->next;
                return 0;
            }
        }
        list_usernames=list_usernames->next;
        
    }
    if(true){
        cout<<"Wallet Credential Not match any!\n";
    }
    return 0;
} 