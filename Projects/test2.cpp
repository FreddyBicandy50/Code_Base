#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream> 
#include <sstream>
#include <chrono> //For system_clock
#include <ctime> //For system_clock
#include <random>
#include <math.h>
#include "Define.h"
using namespace std::chrono;
using namespace std;

int reverse(int *dec,int *keylogger, int pLen);

int calc(int token,int position,int *key){
    if(token%2==0){
        return ((token * key[position]) / 2);
    }else{
        return ((token + pow(token,2) - key[position]);
    }
}

int main(void){
    //gen key log 
    string password="freddy@123";
    int *SLKey = (int *)malloc(sizeof(int) * password.length());
    for (int Vector_key_Pointer = 0; Vector_key_Pointer < password.length(); Vector_key_Pointer++){
        u_int16_t seed = system_clock::now().time_since_epoch().count();
        srand(seed);
        SLKey[Vector_key_Pointer] = rand() % 122;
       
    } 

    int *cipher=(int *)malloc(sizeof(int)*password.length());
    for (int position=0; position<password.length(); position++){
        int Ascci=(int)password[position];
        cipher[position] = calc(Ascci, position, SLKey);
    } 
    return 0;
} 