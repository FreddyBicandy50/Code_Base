#ifndef search_H
#define search_H
#include <iostream>
#include <cstdlib>
#include <cstring>
#define FILENAME list.txt
using namespace std; 
FILE *File_Var=fopen(FILENAME,r);

bool search (string username,string password){
    if (File_Var==NULL){
        cout<<"FATAL:Error Search Stream!/>>File Not Found!>> check file attribute"<<endl;
    }
    int j=0;
    char *argv[],getdata;
    while (fscanf(timefile, "%d", &getdata) == 1){
        argv[] = getdata;
        j++;
    }
    int c=j;
    while(true){
        cout<< argv[c] << endl;
        if(c==j){
            break;
        }
    }
}       
int Cryptlib(int CallFunction,string username,string password){
    if (CallFunction==1){
        search(username,password);
    }
    return 0;
}
#endif