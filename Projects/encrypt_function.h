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
        return (token * key[position]) / 2;
        
    }
    else{
        return (token + key[position]) - pow(token, 2);
    }
    return 1;
}
 

int *fenc(string password,int KeyLogger[Max_password_length]){ 
    int *cipher = (int *)malloc(sizeof(int) * password.length());
    for (int position = 0; position < password.length(); position++) {
        int Ascci = (int)password[position];
        cipher[position] = calc(Ascci, position, KeyLogger);
    }
    return cipher;
}

#endif
