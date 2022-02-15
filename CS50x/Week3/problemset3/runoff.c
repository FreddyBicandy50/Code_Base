#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#define n 20

typedef struct {
    string name;
    int    votes;
    bool   eliminated;
}table;

table candidate[n];
int prefrences[n][n];
int Candidates_number=0;
int voters=0;
int MAX=0;
bool winner=false;

void eliminate(int position){
  candidate[position].eliminated=true;
  int t=1;
  for (int i = 0; i <voters; i++)
      if (prefrences[i][0]==position && candidate[position].eliminated==true){
        if (candidate[t].eliminated==true) {
          t++;
        }else{
          candidate[prefrences[i][t]].votes++;}
      }
}

void is_tie(){
  printf("tie\n");
  winner=true;
}
void find_min(){
  //finding the minmal candidate votes
  int position,MIN=100;
  for (int i = 0; i < Candidates_number; i++)
    if (MIN>candidate[i].votes && candidate[i].eliminated!=true){
      MIN=candidate[i].votes;
      position=i;}
  //check if min equal to max that means there is a tie

  if (MIN==MAX) {
    is_tie();
  }else{
    eliminate(position);
    winner=false;
  }

}
void check_winner() {
  ///check the max voted candidate
  int position;
  for (int i = 0; i < Candidates_number; i++)
    if (candidate[i].votes>MAX ){
      MAX=candidate[i].votes;
      position=i;}
   //check if any equals to MAX voted candidate
  bool freq=false;
  for (int i = 0; i < Candidates_number; i++)
    if (i!=position && MAX==candidate[i].votes)
      freq=true;



  //check if winner or not
 if (freq!=true) {
   if (MAX>voters/2){
     printf("\nwinner\n%s\n",candidate[position].name);
     winner=true;
   }else{
     winner=false;}
 }else{
     winner=false;}
}
void tabulate(){
  //voting for the first index of prefrences
  for (int i = 0; i < voters; i++){
    bool voted=false;
    for (int j = 0; j < Candidates_number; j++)
      if (voted!=true)
        for(int l=0; l < Candidates_number; l++)
          if ((prefrences[i][j]==l) && (candidate[j].eliminated!=true)){
            candidate[l].votes++;
            voted=true;}
  }
  //eliminate 0 voted
  for (int i = 0; i <Candidates_number; i++)
    if (candidate[i].votes<=0)
      candidate[i].eliminated=true;

}
bool vote(int voter,string get_names[]){
  //checking if the name specified found in candidate table and parse his index
  int a=0;
  for (int i = 0; i < Candidates_number; i++)
    for (int j = 0; j < Candidates_number; j++)
        if (strcmp(get_names[i],candidate[j].name)==0) {
            prefrences[voter][i]=j;
            a=1;}


  if (a==1) {
      return true;
  }else{
      return false;
  }

}

int main (int argc,string argv[]){
  //checking on arguments
  if(argc==1){
        printf("Usage ./runoff [candidate 1] [candidate 2]\n");
    }else if(argc==2){
        printf("command should have more then 1 argument \n type ~~./runoff for help\n");
    }else{
    //setting up candidates table
    Candidates_number=argc-1;
    int j=0;
    for (int i=1; i <=Candidates_number; i++) {
        candidate[j].name=argv[i];
        candidate[j].votes=0;
        candidate[j].eliminated=false;
        j++;
    }

    //voting area
    do
      voters=get_int("Number of voters:");
    while(voters<=0);

    //creating the prefrences table
    for (int i = 0; i < voters; i++)
      for (j = 0; j < Candidates_number; j++)
          prefrences[i][j]=-1;

    //voting
    string candidate_name[Candidates_number];
    //looping to each voter
    for (int i = 0; i < voters; i++) {
        //looping threw each name vote
        for (j = 0; j < Candidates_number; j++) {
          //check string if empty
          do
            candidate_name[j]=get_string("Rank %d:",j+1);
          while((strcmp(candidate_name[j],"")==0));

          int invalid;
          //check if same candidate name is parsed
          if (j>0)
            for (int k = 0; k < j; k++)
                if (strcmp(candidate_name[j],candidate_name[k])==0)
                    //check string if empty
                    do{
                      invalid=0;
                      candidate_name[j]=get_string("Rank %d:",j+1);
                      if(strcmp(candidate_name[j],candidate_name[k])==0){
                        printf("candidate name is already picked in Rank %d\n",k+1);
                        invalid=1;
                      }
                    }while((strcmp(candidate_name[j],"")==0) || (invalid==1));
        }
        printf("\n");
        vote(i,candidate_name);
      }

    //update votes of candidates
    tabulate();

    while (winner==false){
      check_winner();
      if(winner==false)
        find_min();
    }
  }

}
