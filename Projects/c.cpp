#include <iostream> 
#include <sstream>
using namespace std;
int main (void){
    stringstream to_int;
    int Token;
    to_int << "sara";
    to_int >> Token;
     if (Token == 0)
    {
        cout<<Token;
    }
    return 0;
}