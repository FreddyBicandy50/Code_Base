#include <iostream>
using namespace std;
int main(void){
    //TODO: Prompt for start size
    int start_size,end_size;
    cout<<"start size:";
    do{
        cin>>start_size;
        cout<<"end size:";
        cin>>end_size;
        if(start_size<9) cout<< "please make sure\nstart size and end size>9:";
    }while(start_size< 9 || end_size<start_size);
    // TODO: Calculate number of years until we reach threshold
    int years=0;
    while(start_size<end_size){
        start_size=start_size+(start_size/3)-(start_size/4);
        years++;
    }
    // TODO: Print number of years
    cout<<"Years:"<<years;

}