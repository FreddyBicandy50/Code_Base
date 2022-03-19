#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct pointers{
    int data;
    struct pointers *parent[2];
}node;
node *recent,*root=(node *) malloc(sizeof(node)),*temp=root;
int depth=1,position=0;
void create_family(){
    if(temp->parent[0]==NULL && temp->parent[1]==NULL){
        temp->parent[0] = (node *)malloc(sizeof(node));
        temp->parent[1] = (node *)malloc(sizeof(node));
        return ;
    }else{
        recent=temp;
        temp=temp->parent[position];
        temp->parent[0]=temp->parent[1]=NULL;
        create_family();
        position=1;
        temp=recent;
        create_family();
        position=0;
    }
}
int main (void){
    temp->parent[0]=temp->parent[1]=NULL;
    cout<<"enter number of generations:";
    int gen;
    do{
        cin>>gen;
        if(gen<=0) cout<<"number of generations >0:";
    } while (gen<=0);
    
    while (true){
        create_family();
        depth++;
        if(depth==gen) break;
        else if(depth>gen || depth<gen) cout<<"something is wrong!"<<endl;
    }
    
    return 0;
}