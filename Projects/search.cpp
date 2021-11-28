 #include <iostream>
  using namespace std;

int main(void){
    int x;
    cout<<"enter a value:";
    cin >> x;

    if (x > 0)
        cout << "positive!";
    else
        cout << "negative!";

    return 0;
}