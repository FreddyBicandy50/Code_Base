#include <iostream>
using namespace std;
int main(){

    char type;
    cout << "A.single room for $25 per day\n"
         << "B.double room $50 per day\n"
         << "C.suite room for $150 per days\n"
         << "D.vip room for $200 per day" << endl;
    cout << "please enter room type" << endl;

    do cin >> type; while (type != 'A' && type != 'B' && type != 'C' && type != 'D');

    cout << "please enter the number of days" << endl;
    int num;
    do cin >> num; while (num <= 0);

    float price=0;
    
    if (type == 'A') price = 25 * num;
    else if (type == 'B') price = 50 * num;
    else if (type == 'C') price = 150 * num;
    else price = 200 * num;
    
    if (num > 30) price = price * (1 - 20 / 100);
    else if (num >= 15 && num <= 29) price = price * (1 - 15 / 100);
    else if (num >= 10 && num <= 14) price = price * (1 - 5 / 100);


    cout<<price*1.12<<endl;
    double g=(1+12/100);
    cout<<g;
    return 0;
}