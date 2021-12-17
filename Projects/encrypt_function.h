#ifndef encrypt_function_H
#define encrypt_function_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono> //For system_clock
#include <ctime>  //For system_clock
#include <random>
#include <math.h>
#include "Define.h"
using namespace std::chrono;
using namespace std;

int calc(int token, int position, int *key){
    if (key[position] % 2 == 0){
        int encrypted = (token * key[position]) / 2;
        return encrypted;
    }
    else{
        int encrypted = (token + key[position]) - pow(token, 2);
        cout << encrypted << endl;
        return encrypted;
    }
    return 1;
}
 

int fencrpt(string pass,int KeyLogger[Max_password_length]){
int *cipher = (int *)malloc(sizeof(int) * pass.length());
    for (int position = 0; position < pass.length(); position++){
        int int_Ascci = (int)password[position];
        int upload = calc(int_Ascci, position, KeyLogger);
        if (upload != 1){
            upload = cipher[position];
        }
        else{
            cout << "Fatal system error\nexiting..." << endl;
            exit(-1);
        }
    } 
    return &cipher;
   
     
}
#endif
