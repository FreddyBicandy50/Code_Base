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
    int *cipher = (int *)malloc(sizeof(int) * password.length());
    if (key[position] % 2 == 0){
        cipher[position] = (token * key[position]) / 2;
        return 0;
    }
    else{
        cipher[position] = (token + key[position]) - pow(token, 2);
        return 0;
    }
    return 1;
}
 

int fencrpt(string password,int KeyLogger[Max_password_length]){ 
    int *cipher = (int *)malloc(sizeof(int) * password.length());
    for (int position = 0; position < password.length(); position++) {
        int Ascci = (int)password[position];
        cipher[position] = calc(Ascci, position, SLKey);
    }
    return &cipher;
}

#endif
