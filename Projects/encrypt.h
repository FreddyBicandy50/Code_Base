#ifndef encrypt_H
#define encrypt_H
#include <iostream>
#include <chrono> //For system_clock
#include <random>
#include "Define.h"
using namespace std;
int encrypt(string password){
    int *SLKey = (int *)malloc(sizeof(int) * password.length());
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed); 
    uniform_int_distribution<int> distributionInteger(1, 100); // Set the numbers for int.
    for (int Vector_key_Pointer = Void0; Vector_key_Pointer <= password.length(); Vector_key_Pointer++){
        SLKey[Vector_key_Pointer] = distributionInteger(generator);
    }
    return Void0;
}

#endif // !ecrypt_H