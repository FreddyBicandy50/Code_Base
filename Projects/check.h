#ifndef check_h
#define check_h
#include <iostream>
#include "Define.h"
using namespace std;
int check_available(string name,string pass){ 
    if (fsearch_call(name, pass) == Access_Granted || search_unit(name, pass) == NOT_Match){
        return Void1;
    }
    return Void0;
}
#endif // check.h