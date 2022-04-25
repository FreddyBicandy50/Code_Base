//calling library functions and predefines
#include <iostream>
#include "checking.h"
#include "dictionnary.h" 
#define N 26
using namespace std;
FILE *text_file, *dictionary_file;
node *headtable[N][N];
void call_load();

int main(int argc, char *argv[]){ 
    argument_check(argc);
    text_file = checkfile(false, argv[1]);
    dictionary_file = checkfile(true, argv[0]);
    load(text_file, dictionary_file);
                 
    
    return 0;
}  