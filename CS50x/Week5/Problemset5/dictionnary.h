#ifndef dictionnary_H
#include <iostream> 
using namespace std; 
typedef struct pointer{
    string word;
    struct pointer *next;
}node;
const int LEN=26;
node *table[LEN][LEN];
int counter=0;
void store(int index1,int index2,char getword[255]){
    node *temp=(node *) malloc(sizeof(node));
    temp->word=getword;
    temp->next=table[index1][index2];
    table[index1][index2]=temp;  
    return;
}
node *load(FILE *texts_file,FILE *dictionary_file){
    
    char getwords[255];
    int hash=0;
    for (int i = 0; i < LEN; i++) for (int j = 0; j < LEN; j++) table[i][j]=NULL;

    while(fscanf(dictionary_file, "%s",&getwords)!=EOF){
        hash=getwords[0]-97;
        if(getwords[1]-97>=0) store(hash,getwords[1]-97,getwords);
        else store(hash, 0, getwords);
    } 
    while (table[25][25]!=NULL){
        cout<<table[25][25]->word<<endl;
        table[25][25]= table[25][25]->next;
    }

    return table[LEN][LEN];
}

#endif // !dictionnary_H
