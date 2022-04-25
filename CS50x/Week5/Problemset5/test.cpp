#include <cmath>
#include <iostream>
using namespace std; 
int main(void){
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    int counter=0;
    char getwords[255];
    while (fscanf(dictionary_file, "%s", &getwords) !=EOF) counter++;
     
    cout<<counter<<endl;
    return 0;
}