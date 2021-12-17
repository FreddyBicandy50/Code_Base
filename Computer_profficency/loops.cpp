
//write a program to print the prime number from n to 10
/*#include <iostream>
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
}*/

//write a program to ask user for 10 number and display the even numbers
/*#include <iostream>
using namespace std;
int main(void){
    int number;
    for (int i = 1; i <= 10; i++){
        cout << "enter a number:";
        cin >> number;
        if (number % 2 == 0){
            cout << number << endl;
        }
    }
    return 0;
}*/

//write a program to ask user for n number and display the even numbers
#include <iostream>
using namespace std;
int main(void){

    int number;
    do{
        cout << "enter a number:";
        cin >> number;
        if (number % 2 != 0){
            cout << number << " is odd" << endl;
        }
    }while (number != -1);
    
    return 0;
}
