#include <iostream>
#include <ctime>
using namespace std;

// function to generate and retrun random numbers.
int *fun(){
    int v=4; 
    int *r=&v; 

   return r;
} 
int main () { 
   // a pointer to an int.
   int *p; 
   p=fun(); 
   cout<<*p;

   return 0;
}