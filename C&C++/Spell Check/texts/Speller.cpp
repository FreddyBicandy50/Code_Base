//calling library functions and predefines
#include <iostream>
#include "checking.h"
#include "dictionnary.h"
#include <sys/resource.h>
#include <sys/time.h>

#undef calculate
#undef getrusage
using namespace std;

FILE *text_file, *dictionary_file;  
double calculate(const struct rusage *b, const struct rusage *a);
double time_load = 0.0, time_check = 0.0,time_unload = 0.0;
struct rusage before, after;
void call_load();

int main(int argc, char *argv[]){ 
    argument_check(argc);
    text_file = checkfile(false, argv[1]);
    dictionary_file = checkfile(true, argv[0]);
    
    getrusage(RUSAGE_SELF, &before);
    load(text_file, dictionary_file);
    getrusage(RUSAGE_SELF, &after);
    time_load = calculate(&before, &after);

    getrusage(RUSAGE_SELF, &before);
    spell_check(text_file);
    getrusage(RUSAGE_SELF, &after);
    time_check = calculate(&before, &after);
    
     


    printf("TIME LOAD:\t%.2f\n",time_load);
    printf("TIME IN check:\t%.2f\n", time_check);
    getrusage(RUSAGE_SELF, &before);
    unload();
    getrusage(RUSAGE_SELF, &after);
    time_unload = calculate(&before, &after);
    printf("TIME IN unload:\t%.2f\n", time_unload);
    printf("TIME IN TOTAL:\t%.2f\n", time_load + time_check  + time_unload);
    fclose(text_file);
    fclose(dictionary_file);
    return 0;
}  

double calculate(const struct rusage *b, const struct rusage *a){
    if (b == NULL || a == NULL) return 0.0;
    else return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                  (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                 ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                  (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    
}
