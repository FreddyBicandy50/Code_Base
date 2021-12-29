#include <iostream>
using namespace std;
int main(void){
    int r,counter=0;
    cout<<"enter number of rows:";
    cin>>r;
    for (int i = 1; i <= (r-1)/2; i++){
        for (int j = 1; j <= r - i; j++)
            cout<<" ";
       for (int j = 1; j <= i+counter; j++)
            cout<<"*"; 
        counter++;
        cout<<endl;
    } 
    
    for (int i = 1; i <= r; i++){
        if(i==1){
            for (int j = 1; j <=r/2; j++)
                cout << " ";
        }
        cout << "*";
    } 
    cout<<endl;

  
    for (int i =  (r-1)/2; i>=1 ; i--){
        for (int j = 1; j <= r - i; j++)
            cout<<" ";

       for (int j = i+counter-1; j>= 1; j--)
            cout<<"*"; 
        cout<<endl;
        counter--;
    } 
    return 0;
}