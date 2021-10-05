#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct pointer{
    int data;
    struct pointer *next;
    struct pointer *prev;
}node;
node *list=NULL;
const int size=5;
int fprint_list();

//next function
int init_next(int number){
    node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("temp is Null!\nsegmentation fault");
        return 1;
    }
    temp->data=number;
    temp->next=list;
    while(list!=NULL){
        list=list->next;
    }
    list=temp;
    return 0;
}

//prev function
bool prev(){
    node *recent;
    recent=list;
    list=list->next;
    list->prev=recent;
    if(list->next==NULL){
        return true;}
    return false;
}

//delete function
int del_list(){
    int number;
    printf("\ndelet number:");
    scanf("%d",&number);
    node *recent;
    node *start;
    while(list!=NULL){  
        if(list->data==number){ 
            if (list->prev==NULL){
                list=list->next;
                list->prev=NULL;
            }else if (list->next==NULL){
                list=list->prev;
                list->next=NULL;
            }
            else{
                recent=list->prev;
                list=list->next;
                recent->next=list; 
            } 
        }
        list=list->next;
    }
    return 0;
}

//main function
int main (void) {
    //init next pointer
    int check;
    for (int i = 1; i <=size; i++){ 
        check=init_next(i);
        if(check==1){
            printf("exiting...");
            exit(-1);
        }
    }
    //init prev pointer
    node *last=list;
    bool exit=false;
    while(exit!=true){
        exit=prev();
    }
    list=last;
    
    //printing
    fprint_list();
    list=last;

    //delestion
    del_list();

    //printing
    fprint_list();
   
    
    
    //end of program
    free(list);
    return 0;
}

//print function
int fprint_list(){
    while(true){
        printf("%d\t",list->data);
        if(list->next==NULL){
            break;
        }
        list=list->next;
    }
    printf("\n");
    while(list!=NULL){
        printf("%d\t",list->data); 
        list=list->prev;
    }
    return 0;
}
