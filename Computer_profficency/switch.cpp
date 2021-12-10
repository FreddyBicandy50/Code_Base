#include <iostream>
using namespace std;
//write a program to detramain if age is legal or not using switch
int main(){ 
  int age;
  cout<<"enter age:";
  cin>>age;
  switch (age){
  case 18 ... 100:
    cout<<"legal"<<endl;
     break;
  default:
    cout<<"you either too old or not legal yet";
  }
  return 0;
}
//write a program to check grade input buy user
int main (){
  // input 
  int grade;
  cout << "enter your grade:";
  cin >> grade;

  //algorithm
  switch(grade){
    case 90 ... 100:
      cout<<"A";
      break;
    case 80 ... 89:
      cout<<"B";
      break;
    case 70 ... 79:
      cout<<"C";
      break;

    case 60 ... 69:
      cout<<"D";
      break;
    case 0 ... 50:
      cout<<"F";
    default:
      cout<<"Invalid!";
      break;
  }

  //end
  return 0;
}

//write a program to print all the month of year after the month of user input
int main(){
  //input
  int month;
  cout << "enter month number:";
  cin >> month;

  //algorithm
  switch(month){
    case 1 ... 12:
      switch (month){
      case 1:
        cout << "January" << endl;
      case 2:
        cout << "February" << endl;
      case 3:
        cout << "March" << endl;
      case 4:
        cout << "April" << endl;
      case 5:
        cout << "May" << endl;
      case 6:
        cout << "June" << endl;
      case 7:
        cout << "July" << endl;
      case 8:
        cout << "August" << endl;
      case 9:
        cout << "Septembre" << endl;
      case 10:
        cout << "Octobre" << endl;
      case 11:
        cout << "Novembre" << endl;
      case 12:
        cout << "Decembre" << endl;
    }
    break;
    default:
      cout<<"Invalid Month number!";
      break;
  }
  
  //end
  return 0;
}
