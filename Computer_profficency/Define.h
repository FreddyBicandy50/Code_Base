// defining File.H
#ifndef Define_H
#define Define_H
#include <iostream>
#define no_error 0                // no error indicator
#define error 1                   // error indicator
#define error_exit -1             // force exit program indactes and error
#define exit_no_error +1          // force exit program indactes and no error
#define Access_Granted 755        // return integer indicates user+pass correct
#define Access_Failed 8080        // return integer indicates password incorrect
#define Not_Matched 404           // return integer indicates user is not found in database
#define list_database ".list.txt" // creates a hidden list text file for registerd user + encrypted key
#define key_database ".key.txt"   // creates a hidden key text file to store generated key
#define starting_position 0       // for loops/array/Other indexing position
#define Max_userlength 35         // Maximum username character
#define _POSIX1_SOURCE 2          // for system based command (bash)

// bash colored output
 
 

void reset(){
    printf("\033[0m");
} 
#define RESET "\033[0m"   // Original color
#define RED "\033[31m"    // Red
#define GREEN "\033[32m"  // Green
#define YELLOW "\033[33m" // Yellow
#define BLUE "\033[34m"   // Blue
#define WHITE "\033[37m"  // White
#define CYAN "\033[36m"   // Cyan

#endif //! Define_H