#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#define m 26
int c=100,n=100;
const char alphalower[m] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const char alphaupper[m] = {'T','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main (int argc,string argv[])
{
  if(argc==1){
    printf("command cannot be less then 2 arguments try /?\n");
  }else if(argc==2){
  //Validate Key
  string key=argv[1];
  int check_valid=0;
  n=strlen(key);
  string help="/?";
  if(strcmp(key,help)==0){
    printf("usage ./substituition ~key~ Example:[zxcvbnmasdfghjklqwertyuiep] \n Key Validation:\n Key=26 \t Key=ONLY letters\n");
  }else{

  //convert to upper
  for (int i = 0; i < n; i++)
    if (islower(key[i]))
      key[i]=toupper(key[i]);

  //check key length
  if (n<26){
    printf("the key must be more then %d character -->26\n",n);
  }else if(n>26){
    printf("the key must be less then %d character -->26\n",n);}
  else{


  //check key characters
  for (int i = 0; i <n; i++)
    if (check_valid!=1){
        if (isalpha(key[i])){
          for (int j = i+1; j < n; j++)
              if (key[i]==key[j] && check_valid!=1){
                check_valid=1;
                printf("the letter %c occured more then 1 time\n",key[i]);}
        }else{
        check_valid=1;
        printf("the key must only contain letters\n");}
      }
  if(check_valid!=1){
    //get plaintext
    string str=get_string("String Before:");
    c=strlen(str);

    //determine what letter it maps to
    char Encipher[c];
    for (int  i = 0; i < n; i++) {
      if (isalpha(str[i])) {
        for (int j = 0; j < m; j++) {
          if ((str[i]==alphalower[j]) || (str[i]==alphaupper[j])) {
            if (isupper(str[i])) {
              Encipher[i]=key[j];
            }else{
              Encipher[i]=key[j]+32;}
          }
        }
      }else{
          Encipher[i]=str[i];}
    }
      printf("string after:");
      puts(Encipher);
        }
      }
    }
  }else{
     printf("Segment cannot have more then 2 arguments try /?\n");
    }
}
