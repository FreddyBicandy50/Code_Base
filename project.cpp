// calling libraries and predefines
#include <iostream>
#define n_size 6
typedef struct pointer{
    int data;
    struct pointer *next;
    struct pointer *prev;
} node;
node *list = NULL;
//list function
int init_list(int input)
{
    node *temp =(node*)malloc(sizeof(node));
    if (temp == NULL){
        cout<<"malloc failure\n";
        return 1;
    }
    temp->data = input;
    temp->next = list;
    while (list != NULL){
        list = list->next;
    }
    list = temp;
    while (true){
        if (list->next != NULL){
            list = list->next;
            list->prev = temp;
            list = list->prev;
        }
        break;
    }
    return 0;
}
//delete function
int delete_list(int input){
    node *list_head = list;
    while (true){
        if (list->data == input){
            if (list->prev == NULL) {
                list = list->next;
                list->prev = NULL;
                return 0;
            }
            else if (list->next == NULL){
                list = list->prev;
                list->next = NULL;
                list = list_head;
                return 0;
            }
            else{
                list = list->prev;
                list->next = list->next->next;
                list = list->next;
                list->prev = list->prev->prev;
                list = list_head;
                return 0;
            }
        }
        else{
            if (list == NULL){
                return 1;
            }
            list = list->next;
        }
    }
    return 0;
}
//sort function
int sort(){
    for (node *i = list; i != NULL; i = i->next){
        for (node *j = i->next; j != NULL; j = j->next){
            if (i->data < j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return 0;
}
//main function
int main(void){
    //initialise the list
    int size;
    printf("Size of list:");
    do{
        scanf("%d", &size);
        if (size <= 0){
            printf("size of list should be >0:");
        }
    } while (size <= 0);
    for (int i = 1; i <= size; i++){
        int number, malloc_check;
        printf("number [%d]:", i);
        scanf("%d", &number);
        malloc_check = init_list(number);
        if (malloc_check == 1)
        {
            printf("exiting...");
            exit(-1);
        }
    }

    //sort printing
    sort();
    fprint_list();

    //delete/insert
    printf("\n");
    while (true)
    {
        char s;
        printf("delete/insert:");
        do{
            scanf("%s", &argv);
            if (strcmp(argv, "delete") != 0 && strcmp(argv, "insert") != 0)
            {
                printf("delete/insert:");
            }
        } while (strcmp(argv, "delete") != 0 && strcmp(argv, "insert") != 0);
        if (strcmp(argv, "delete") == 0)
        {
            int delete, search;
            printf("delete number:");
            scanf("%d", &delete);
            search = delete_list(delete);
            if (search != 0)
            {
                printf("\nNot found\n");
            }
        }
        else
        {
            int insert, malloc_check;
            printf("insert number:");
            scanf("%d", &insert);
            malloc_check = init_list(insert);
            if (malloc_check == 1)
            {
                printf("exiting...");
                exit(-1);
            }
        }
        char user[n_size];
        printf("exit [yes/no]:");
        do
        {
            scanf("%s", &user);
            if (strcmp(user, "yes") != 0 && strcmp(user, "no") != 0)
            {
                printf("yes/no:");
            }
        } while (strcmp(user, "yes") != 0 && strcmp(user, "no") != 0);
        if (strcmp(user, "yes") == 0)
        {
            break;
        }
    }

    //sort printing
    sort();
    fprint_list();

    //end of program
    free(list);
    return 0;
}

//print functions
int fprint_list()
{
    while (list != NULL)
    {
        if (list->next == NULL)
        {
            break;
        }
        list = list->next;
    }
    while (list != NULL)
    {
        printf("%d\t", list->data);
        if (list->prev == NULL){
            break;
        }
        list = list->prev;
    }
    return 0;
}
