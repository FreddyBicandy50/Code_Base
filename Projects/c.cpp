#include <iostream>
using namespace std; 
int main(){ 
    int number, choice = 0;
    while (choice != -1){
        cout << "\nchoose one of the following options:\n";
        cout << "1.check if perfect number\n2.find and display factorial number\n";
        cin >> choice;
        if (choice != -1){
            cin >> number;
            switch (choice)
            {
            case 1:
                check_perfect(number);
                break;
            case 2:
                find_factorial(number);
                break;
            default:
                cout << "invalid options!";
                break;
            }
        }
    } 
    return 0;
}