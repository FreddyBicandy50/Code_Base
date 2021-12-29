//calling libraries and predefines
#ifndef reverse_H
#define reverse_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "Define.h"
#include "encrypt_function.h"
using namespace std;
int *key = (int *)malloc(sizeof(int) * Max_password_length);
int *passwordkey = (int *)malloc(sizeof(int) * Max_password_length);
bool fcheck(int *address, string password);

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
    while (index != password.length())
        if (fscanf(tempfile, "%s", Char_HOLDER) == Void1){
            int to_int;
            stringstream character(Char_HOLDER);
            character >> to_int;
            key[index] = to_int;
            index++;
        }
    


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
    while (index != password.length()){
        if (fscanf(pkey, "%s", Char_HOLDER) == Void1)
            if (Char_HOLDER != " " && !isalpha(Char_HOLDER[0])){
                int to_int;
                stringstream character(Char_HOLDER);
                character >> to_int;
                passwordkey[index] = to_int;
            }
        index++;
    }

    //endof function
}

int main (){
      string password="123@aul";
      int position=1;
    init_1(position, password);
    int *address = fenc(password, key);

    if (fcheck(address, password) == true)cout<<"true";
    else cout<<"false"; 

    return false;
}

bool fcheck(int *address, string password){
    int counter, index = 0;
    while (index != password.length()){
        if (passwordkey[index] == address[index]) counter++;
        index++;
    }

    if (counter == password.length()) return true; 
    else return false; 
}
#endif // DEBUG