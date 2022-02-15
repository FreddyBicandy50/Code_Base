//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
//public varibales
#define n 28
int winner=-1;
const char alphabet[n] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//score function
int compute_score(string str1,string str2)
{

    // TODO: Compute and return score for str1ing
    //convert upper case to lower
    for (int i = 0; i< strlen(str1); i++)
      if(str1[i]!=32)
        if (str1[i]>='A' && str1[i]<='Z')
            str1[i]=str1[i]+32;

    for (int i = 0; i <strlen(str2); i++)
      if(str2[i]!=32)
        if (str2[i]>='A' && str2[i]<='Z')
            str2[i]=str2[i]+32;

    //check str1ing 1
    int player1=0,player2=0;
    for (int i = 0; i <strlen(str1); i++){
      if(str1[i]!=32)
        for (int j = 0; j < n; j++ )
          if (str1[i]==alphabet[j])
              player1+=POINTS[j];
    }

    //check str1ing 2
    for (int i = 0; i <strlen(str2); i++){
      if(str2[i]!=32)
        for (int j = 0; j < n; j++ )
          if (str2[i]==alphabet[j])
            player2+=POINTS[j];
        }

  printf("score 1:%d\n",player1);
  printf("score 2:%d\n",player2);
  if(player1>player2){
    winner=1;}
  else if(player2>player1){
    winner=2;}
  else{
    winner=0;}
  return winner;
}

//main
int main (void){
  //prompt input to user
  string word1,word2;
  int check_string;
  do {
    check_string=0;
    word1=get_string("Player 1:");
    for (int i = 0; i <strlen(word1); i++)
      if (isalpha(word1[i]))
        check_string=0;
      else
        check_string=1;

  } while(check_string==1);


  do {
    check_string=0;
    word2=get_string("Player 2:");
    for (int i = 0; i <strlen(word2); i++)
      if (isalpha(word2[i]))
        check_string=0;
      else
        check_string=1;

  } while(check_string==1);

  //return input to function
  compute_score(word1,word2);

  //priting winner
  if (winner==1){
    printf("player 1 win\n");}
  else if(winner==2){
    printf("player 2 win\n");}
  else{
    printf("Draw\n");}
}
