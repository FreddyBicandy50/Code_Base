#include <iostream>
using namespace std;
int main(void){
  int Height;
  do{
    cout<<"Height:";
    cin>>Height;
  } while (Height <= 0 || Height > 10);

  //piramide
  for (int i = 0; i < Height; i++){
    //spaces
    for (int l = Height-1-i; l>=0 ; l--)
      printf(" ");

    //blocks
    for (int j = 0; j < i; j++)
      printf("#");

    //sperate first piramid from the another
    printf("  ");

    //second piramid
    for (int k = 0; k <i; k++)
      printf("#");

    //jumping to new line
    printf("\n");
  }

}