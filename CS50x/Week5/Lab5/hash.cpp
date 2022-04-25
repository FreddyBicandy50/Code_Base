//calling libraries and predefine functions 
#include <iostream>
#include <cctype>
#include <cstdlib>
#define Hash_Max 26 
using namespace std;
typedef struct pointer{
    string name;
    struct pointer *next;
}node;
node *hash_head[Hash_Max];
void find(string input,int distance);

//initialise names in table
void init(string name,char Ncase,int distance){
    node *temp=NULL;
    temp=(node *) malloc(sizeof(node));
    temp->name=name;
    temp->next=hash_head[distance];
    hash_head[distance]=temp;
    return;
}

//main
int main (void){
    //declaration
    char getnames[255],Ncase='A';
    int distance=0;
    
    //setup all heads pointer in array to 0x000
    for (int i = 0; i <Hash_Max; i++) hash_head[i]=NULL;
    

    //find specfic case name and init them
    for (int i = 0; i <Hash_Max; i++){
        FILE *data=fopen("name.txt", "r");
        while (fscanf(data, "%s", getnames) == 1)
            if (getnames[0] == Ncase) init(getnames, Ncase,distance);
        Ncase++;
        distance++;
    }

    //search
    string input;
    Ncase='A';
    do{
        cout<<"search:";
        cin>>input;
        if(input[0]>90){
            system("tput setaf 3;echo name first character always capital");
            system("tput setaf 7"); 
        }
    } while (input[0]>90);
    
    distance=0; 
    while(true){
        if(input[0]==Ncase) break; 
        Ncase++;
        distance++;
    }
    find(input,distance);
    return 0;
}

//searching algorithm
void find(string input,int distance){
    while (hash_head[distance]!=NULL){
        if(hash_head[distance]->name==input){ 
            cout<<input;
            system("tput setaf 2");
            cout<<" Found!"<<endl;
            exit(-1);}
        hash_head[distance]=hash_head[distance]->next;
    }
    system("tput setaf 1");
    cout<<"Not found!"<<endl;
}