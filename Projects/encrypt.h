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
using namespace std;
ofstream outputFile("list.txt", ios_base::app);
int encrypt(string password){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distributionInteger(1, 100); // Set the numbers for int.
    int *SLKey = (int *)malloc(sizeof(int) * password.length());
    for (int Vector_key_Pointer = 0; Vector_key_Pointer < password.length(); Vector_key_Pointer++) {
        SLKey[Vector_key_Pointer] = distributionInteger(generator);
    } 
    for (int Vector_key_Pointer = 0; Vector_key_Pointer < password.length(); Vector_key_Pointer++){
        outputFile << " " << SLKey[Vector_key_Pointer];
    } 
    fencrpt(password,SLKey);
    return Void0;
} 
#endif // !ecrypt_H