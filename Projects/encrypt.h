#ifndef encrypt_H
#define encrypt_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>  
#include <chrono> //For system_clock
#include <random>
#include "Define.h"
#include "encrypt_function.h"
using namespace std::chrono;
using namespace std;
ofstream outputFile(FILENAME, ios_base::app);
int *encrypt(string password){
    int *SLKey = (int *)malloc(sizeof(int) * password.length());
    for (int Vector_key_Pointer = 0; Vector_key_Pointer < password.length(); Vector_key_Pointer++){
        u_int16_t seed = system_clock::now().time_since_epoch().count();
        srand(seed); // Set the numbers for int. 
        SLKey[Vector_key_Pointer] = rand() %255;
    } 
    int *encrypted_pass=fenc(password,SLKey);
    return encrypted_pass;
} 
#endif // !ecrypt_H