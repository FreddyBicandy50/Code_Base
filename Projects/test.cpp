#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
#define sizeofstrlen 9
char FILENAME[sizeofstrlen]="list.txt";
FILE *File_Var = fopen(FILENAME, "r");

int main(void){ 
    File_Var=NULL;
    if (File_Var == NULL){
        cout << "FATAL:Error Search Stream!/>>IOFile Not Found!>>" << endl;
        cout << "Download File:" << endl;
    }
    /*int j = 0;
    char *argv[], getdata;
    while (fscanf(File_Var, "%d", &getdata) == 1)
    {
        argv[] = getdata;
        j++;
    }
    int c = j;
    while (true)
    {
        cout << argv[c] << endl;
        if (c == j)
        {
            break;
        }
    }*/
    return 0;
} 