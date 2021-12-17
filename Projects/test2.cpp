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
string password = "freddy@aul";
int *cipher = (int *)malloc(sizeof(int) * password.length());
int calc(int token,int position,int *key){ 
    if(key[position]%2==0){
        int encrypted=(token*key[position])/2; 
        return encrypted;
    }else {
        int encrypted=(token+key[position])-pow(token,2);
        cout<<encrypted<<endl;
        return encrypted;
    }
    return 1;
}

int main(void){
    //gen key log 
    int *SLKey = (int *)malloc(sizeof(int) * password.length());
    for (int Vector_key_Pointer = 0; Vector_key_Pointer < password.length(); Vector_key_Pointer++){
        u_int16_t seed = system_clock::now().time_since_epoch().count();
        srand(seed); // Set the numbers for int.
        SLKey[Vector_key_Pointer] = rand() % 122;
       
    } 
    
    

   
    for (int position=0; position<password.length(); position++){
        int int_Ascci=(int)password[position];
        int upload = calc(int_Ascci, position, SLKey);
        if(upload!=1){
            upload=cipher[position];
        }
        else{
            cout<<"Fatal system error\nexiting..."<<endl;
            exit(-1);
        }
    }
    return *cipher;
    

} 