/*1.Write an algorithm that reads from the user an integer number x and
    determines whether x is positive, negative or null.
*/
//calling libraries and predefines
#include <iostream>
  using namespace std;

int main(){
    //start
    int x;
    cout<<"enter a value:";
    cin >> x;

    //algorithm
    if (x > 0)
        cout << "positive!";
    else
        cout << "negative!";
        cout << "hey!";

    //end
    return 0;
}

/*2.Write an algorithm that reads from the user an integer number x,
    changes the value of x into its absolute value, and displays its new value at the end.
*/
//calling libraries and predefines
#include <iostream>
    using namespace std;

int main(){
    //start
    int x;
    cout << "enter a negative value:";
    cin >> x;

    //algorithm
    if (x < 0)
        cout << "|" << x << "|=" << x * (-1);

    //end
    return 0;
}
/*3. Write an algorithm that reads from the user two real numbers a and b and
    swaps their values.
*/
//calling libraries and predefines
#include <iostream>
    using namespace std;
int main(){
    //IO
    float a,b,swap;
    cout << "enter 2 numbers:"<<endl; 
    cin >> a>>b;
    cout << "a=" << a << "\b=" << b << endl;
    cout << "swaping...\n";

    //algorithm
    swap = a;
    a = b;
    b = swap;
    cout << "a=" << a << "\nb=" << b;

    //end
    return 0;
}
/*4. Write an algorithm that reads from the user an integer number, checks and
       displays if it is even or odd
*/
//calling libraries and predefines
#include <iostream>
    using namespace std;

int main(){
    //start
    int a;
    cout << "enter a number:";
    cin >> a;

    //algorithm
    if (a%2==0)
        cout << "even";
    else
        cout << "odd";

    //end
    return 0;
}

/*5. Write an algorithm that reads two adjacent sides of a rectangle and
       calculates its area. In addition, the algorithm determines whether the
       rectangle is a square or not.
*/
//calling libraries and predefines
#include <iostream>
    using namespace std;
int main(){
    //start
    int length, width;
    cout << "enter Length:";
    cin >> length;
    cout << "enter width:";
    cin >> width;

    //algortihm
    int area = length * width;
    cout << "area a:" << area;
    if (length == width)
        cout << "square";
    else
        cout << "rectangle";

    //end
    return 0;
}

/*6. Write an algorithm that reads from the user an integer x that represents a
       numerical grade and computes its equivalent letter grade.
*/
//calling libraries and predefines
#include <iostream>
    using namespace std;
int main(){
    //start
    int grade;
    cout << "enter your grade:";
    cin >> grade;

    //algorithm
    if (grade >= 90)
        printf("A");
    else if (grade >= 80)
        printf("B");
    else if (grade >= 70)
        printf("C");
    else if (grade >= 60)
        printf("D");
    else
        printf("F");

    //end
    return 0;
}
/*7.Write an algorithm (Pseudocode and Flowchart) that reads two integers and then
    calculates and displays the following mathematical expression:
        F(x,y) = (x+2y-3xy+y')/(x+xy?)
*/
//calling libraries and predefines
#include <iostream>
    using namespace std;
int main(){
    //start
    int x, y;
    cout << "enter 2 numbers:\n";
    cin >> x >> y;

    //algorithm
    cout << "F(x,y)="<< (x+(2*y)-(3*x*y)+y)/(x+x*y);

    //end
    return 0;
}

/*8. Write an algorithm(Pseudocode and Flowchart) that reads two integers and then
    displays : a.Their sum
               b.Their difference
               c.Their product
               d.Their quotient
               e.Their remainder
*/
//calling libraries and predefines
#include <iostream>
    using namespace std;
int main(){
    //start
    int x, y;
    cout << "enter 2 numbers:\n";
    cin >> x >> y;

    //algorithm
    cout << "sum:" << x+y << endl;
    cout << "difference:" << x-y << endl;
    cout << "product:" << x*y << endl;
    cout << "quotient:" << x/y << endl;
    cout << "remainder:" << x%y << endl;

    //end
    return 0;
}
/*9. Write an algorithm(Pseudocode and Flowchart) that allows user to enter his / her
        age.If the given age is less than 18 we are going to print(You are Not Eligible to Work !)
        .If the condition fails we will check one more condition,if the age is between 18 and 60,
    print two statements(You are Eligible to Work) and (Please fill in your details and apply)
        .If the age is greater than 60,
    print(You are too old to work as per the Government rules !)
*/
//calling libraries and predefines
#include <iostream>
    using namespace std;
int main(){
    //start
    int age;
    cout << "enter your age:";
    cin >> age;
    
    //algorithm
    if (age < 18)
        printf<< "you are not elgible to work!";
    else if(age >=18 && age<=60)
        printf<< "you are elgible to work!\n please fill in your details";
    else
        cout<< "you are too old to work!";
    

    //end
    return 0;
}
/*10. Write an algorithm (Pseudocode and Flowchart) that reads a real number X and
 displays its category:
    i. Category A if (0 <= X <37)
   ii. Category B otherwise
*/
//calling libraries and predefines
#include <iostream>
    using namespace std;
int main(){
    int X;
    cout << "enter number:";
    cin >> X;

    if (X <= 37)
        printf("Category A");
    else
        printf("Category B");
      


    return 0;
}
/*11.Write an algorithm (Pseudocode and Flowchart) that converts the temperature from
 Fahrenheit to Celsius and displays the result.
               C=(5/9)(F-32)
*/

//calling libraries and predefines
#include <iostream>
    using namespace std;
int main(){
    int F;
    cout << "enter temperature in fahrenheit:";
    cin >> F;

    cout << "fahrenheit:" << F << endl;
    cout << "Celcuis:" << (4 / 3) * (F - 32);

    return 0;
}
/*12. Write an algorithm (Pseudocode and Flowchart) that prompts the user to input a
 choice to determine one of the following :
   a. The area of a circle. a = Pi*r?
   b. The surface area of a cylinder. a = 2pi*r*l
   c. The volume of a cylinder: v = pi*r*l
   d. The volume of a sphere. v = (4/3)*pi*r2
*/

//calling libraries and predefines
#include <iostream>
#include <cmath>
    using namespace std;
int main(){
    //start
    char choice;
    double pi = M_PI;
    cout << "choice to determine one of the following :";
    cout << "\na.The area of a circle\nb.The surface area of a cylinder\nc.The volume of a cylinder\nd.The volume of a sphere" << endl;
    cin >> choice;

    //algorithm
    if (choice == 'a'){
        int r;
        cout << "enter r:";
        cin >> r;
        cout << "area of a circle. a=" << pi*pow(r,2);
    }
    else if (choice == 'b'){
        int r, l;
        cout << "enter r/l:";
        cin >> r >> l;
        cout << "surface area of cylinder. a=" << 2*pi*r*l;
    }
    else if (choice == 'c'){
        int r, l;
        cout << "enter r/l:";
        cin >> r >> l;
        cout << "The volume of a cylinder. v=" << pi*r*l;
    }
    else if (choice == 'd'){
        int r;
        cout << "enter r:";
        cin >> r;
        cout << "The volume of a sphere. v=" << (4/3)*pi*pow(r,2);
    }
    else{
        cout << "Invalid!" << endl;
    }

    //end
    return 0;
}
