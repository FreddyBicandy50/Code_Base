#include <stdio.h>
#include <stdlib.h>
typedef struct pointer{
    int data;
    struct pointer *next;
    struct pointer *prev;
}node;
node *list=NULL;
const int size=5;
int fprint_list();
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
int main (void) {
    int check;
    for (int i = 1; i <=size; i++){ 
        check=init_next(i);
        if(check==1){
            printf("exiting...");
            exit(-1);
        }
    }
    //printing
    fprint_list();
    free(list);
    return 0;
}
int fprint_list(){
    while(list!=NULL){
        printf("%d\t",list->data);
        list=list->next;
    }
    return 0;
}
