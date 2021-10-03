//calling libraries and predefines
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct pointer{
    int data;
    struct pointer *next;
    struct pointer *prev;
    struct pointer *rr;
    struct pointer *e;
}node;
node *list=NULL;
const int size=5;
int fprint_list();
int init_next(int number){
    printf("d");
    node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("temp is NULL!\nsegmentation fault");
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
bool init_prev(){
    node *recent=list;
    list=list->next;
    if(list==NULL){
        return true;
    }
    list->prev=recent;
    return false;
}
int main (void){
    //initalise list next
    int check;
    for (int i = 1; i <=size; i++){ 
        check=init_next(i);
        if(check==1){
            printf("\nexiting...");
            exit(-1);
        } 
    }
    bool exit=false;
    node *last=list;
    while (exit!=true){
        exit=init_prev();
    }
    list=last;
    fprint_list();
    free(list);
    return 0;
}
int fprint_list(){
    while(list!=NULL){
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
