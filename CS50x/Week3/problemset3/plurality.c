#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#define n 20
int MAX=0;

typedef struct {
    string name;
    int votes;
}table;
table candidate[n];

int printing_winner(){
  int biggest_votes=0,position;
  for (int i = 0; i< MAX; i++)
    if (biggest_votes < candidate[i].votes) {
      biggest_votes=candidate[i].votes;
      position=i;
    }


  printf("%s\n",candidate[position].name);
  //finding if there is any equals
  for (int i = 0; i <MAX; i++){
    if ((biggest_votes==candidate[i].votes) && (i!=position))
        printf("%s\n",candidate[i].name);
  }

  return 0;
}


bool vote(string name){
  int a=0;
  for (int i = 0; i <MAX; i++)
      if (strcmp(name,candidate[i].name)==0) {
        candidate[i].votes++;
        a=1;
      }

  if(a==1){
    return true;
  }else{
    return false;
  }

}


int main (int argc,string argv[]){
  //checking on arguments
  if(argc==1){
        printf("Usage ./plurality [candidate 1] [candidate 2]\n");
    }else if(argc==2){
        printf("command should have more then 1 argument \n type ~~./plurality for help\n");
    }else{

    //parsing name to the table
    MAX=argc-1;
    int j=0;
    for (int i=1; i <=MAX; i++) {
        candidate[j].name=argv[i];
        candidate[j].votes=0;
      j++;}


    //voting area
    int voters=get_int("Number of voters:");
    string candidate_name;
    for (int i = 0; i <voters; i++) {
        candidate_name=get_string("Vote:");
        vote(candidate_name);}

    //printing the winner
    printing_winner();
  }

}
