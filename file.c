//calling libraires and predefines
#include <stdio.h>
#include <stdlib.h>
typedef struct pointer{
    int data;
    struct pointer *next;
    struct pointer *prev;
}node;
node *list=NULL;
int fprint_list();

//initialise list with next pointer
int init_next_list(int number){
    node *temp=malloc(sizeof(node));
    if(temp==NULL){
        printf("temp is null!\nsegmentaion fault");
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
int main (void){
    int size;
    printf("size of list:\n");
    do{
        scanf("%d",&number);
    }while(size<=0);
    for (int i=1; i<=size; i++){
        int number,check;
        printf("[%d]:\n",i);
        scanf("%d",&number);
        check=init_next_list(number);
        if(check==1){
            printf("exiting...");
            exit(-1);
        } 
    }
    
    //priting
    fprint_list();

    //end
    free(list);
    return 0;
}
int fprint_list(){
    while (list!=NULL){
        printf("%d\t",list->data);
        list=list->next;
    } 
    return 0;
}