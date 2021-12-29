//calling libraries and predefines
#ifndef reverse_H
#define reverse_H
#include <iostream>
#include <fstream>
#include <sstream> 
#include <vector>
#include "Define.h"
#include "encrypt_function.h"
using namespace std;
int *key = (int *)malloc(sizeof(int) * Max_password_length);
typedef struct ptr{
    int data;
    struct ptr *next;
}linked_list;
linked_list *password_key=NULL;
bool fcheck(int *address, string password);
void reverse_password_list();

//initialise essatials key Logger/ encrypted password
void init_1(int position, string password){
    //extract key from position
    ifstream keyline(keylist);
    string line;
    int index = 0;
    while (index != (position + 2)){
        getline(keyline, line);
        index++;
    }
    keyline.close(); 
    
    //throw key in tempfile
    ofstream outputkeytemp(keytemp, ios_base::app);
    outputkeytemp << line;
    outputkeytemp.close(); 

    //import key to array
    FILE *tempfile = fopen(keytemp, read_only);
    char *Char_HOLDER = (char *)malloc(sizeof(char) * Max_password_length);
    index = 0;
    while (fscanf(tempfile, "%s", Char_HOLDER) == Void1){
        int to_int;
        stringstream character(Char_HOLDER);
        character >> to_int;
        key[index] = to_int;  
        index++;
    }
    
    cout<<endl;

    //encrypted password from user position
    ifstream pwdline(list_data);
    index = 0;
    while (index != (position + Void1)){
        getline(pwdline, line);
        index++;
    }
    pwdline.close();

    // throw key in tempfile
    ofstream outputlisttemp(pwdtemp, ios_base::app);
    outputlisttemp << line;
    outputlisttemp.close(); 

    // import key to array
    FILE *pkey = fopen(pwdtemp, read_only);
    int flag;
    index = -1;
    while (fscanf(pkey, "%s", Char_HOLDER) == Void1){
            if (!isalpha(Char_HOLDER[0])){
                int to_int;
                stringstream character(Char_HOLDER);
                character >> to_int;

                linked_list *temp = (linked_list *)malloc(sizeof(linked_list));
                if (temp == NULL) {
                    cout << "Malloc Failure!" << endl;
                    exit(-1);
                }

                temp->data = to_int;
                temp->next = password_key;
                while (password_key != NULL) password_key = password_key->next;

                password_key = temp;
            }
        index++;
    }

    //endof function
}

bool checkpassword(string password, int position){ 

    init_1(position, password);
    reverse_password_list();
    
    int *enc_address = fenc(password, key);
    int index=0;
   
    if(fcheck(enc_address, password)==true) return true;
    else return false; 
}

void reverse_password_list (){
    linked_list *current = password_key;
    linked_list *next = NULL;
    linked_list *prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    password_key = prev;
}

bool fcheck(int *address, string password){
    linked_list *temp=(linked_list *) malloc(sizeof(linked_list));
    int index = 0;
    while(password_key!=NULL){
        password_key=password_key->next;
        index++;
    }  

    if(index!=password.length()) return false;
    
    while(password_key!=NULL){
        if (address[index] != password_key->data) {
            return false;
        }
        password_key=password_key->next;
        index++;
    }   
    
     
    return true;
}  
#endif // DEBUG