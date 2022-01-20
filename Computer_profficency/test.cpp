#include <iostream>
using namespace std;
  
int main (){    
   int n;
    cout<<"enter number of length (odd):"; 
    do cin >> n; while (n%2==0) ;
    
    int s=2;
    for (int lines = 1; lines <=n/2; lines++) {
        for (int spaces = 0; spaces <s ; spaces++)
            cout<<" ";
        
        for (int stars =1;  stars<=(lines*2)-1 ; stars++)
            cout<<"*"; 
            
        cout<<endl;
        s--;
    }

    for (int k = 0; k <1 ; k++) cout<<" "; 
    for (int i = 0; i < n; i++)   cout<<"*"; 

    cout<<endl;
    
    for (int lines = n/2; lines >=1; lines--) {
        for (int spaces = s; spaces >=0 ; spaces--)
            cout<<" ";
        
        for (int stars =(lines*2)-1;  stars>=1 ; stars--)
            cout<<"*"; 
            
        cout<<endl;
        s++;
    }
    return 0;
}