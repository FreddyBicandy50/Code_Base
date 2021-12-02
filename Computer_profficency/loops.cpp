//write a program to print the prime number from n to 10
#include <iostream>
using namespace std;
int main(void){
    int number;
    bool isprime=true;
    cout<< "enter a number:";
    cin>> number;
    int counter=0;
    while(true){
        if(counter!=10){
            for (int i = 2; i <number; i++){
                if(number%i==0){
                    isprime=false;
                }
            }

            if(isprime==true){
                cout<<"prime:"<<number<<endl;
                counter++;
            }
            number++;
            isprime = true;
        }else{
            break;
        }
    }
    
    
    return 0;
}