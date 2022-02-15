 #include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
int size=100;

int main (void)
{
  //getting time complexity from text file
  string filename="time.txt";
  FILE *timefile=fopen(filename,"r");
    if(timefile==NULL){
        printf("can't found %s :(",filename);
        exit(-1);}
    int array_numbers[size],getnumbers,j=0;
    while(fscanf(timefile,"%d",&getnumbers)==1){
      array_numbers[j]=getnumbers;
      j++;
    }


    //determin the merge sort wich have a time complexity of both worst and best case O(nlog(n))
    size=j;
    int sum_sort1=0,sum_sort2=0,sum_sort3=0,average[size/3];
    for (int i = 0; i <=size; i++) {
        if (i<size/3) {
          sum_sort1+=array_numbers[i];
          average[0]=sum_sort1;
        }else if(i<size/3*2){
          sum_sort2+=array_numbers[i];
          average[1]=sum_sort2;
        }else{
          sum_sort3+=array_numbers[i];
          average[2]=sum_sort3;
        }
      }


    for (int i = 0; i <size/3; i++)
        average[i]=average[i]*log(average[i]);
    int merge_sort;
    for (int i = 0; i < size/3; i++)
      if (average[i]<average[i+1])
        merge_sort=average[i];


  //determin wich the average of 2 left is bubble or selection
  FILE *complexity=fopen(filename,"r");
  int bestcase1,bestcase2,k=1;
  while(fscanf(complexity,"%d",&getnumbers)==1){
    if (k==1) {
        bestcase1=getnumbers;
    }else if(k==size-2){
      bestcase2=getnumbers;
    }
    k++;
  }


  //printing result
  FILE *output=fopen("answers.txt","w");
    fprintf(output,"we tested every sorting algorithms with different file \nso we can determin wich sorting is using either:\n[Selection sort]\t[Bubble sort]\t[Merge sort]\n");
  if (bestcase1<bestcase2) {
    fprintf(output,"sort1 is Bubble sort with time complexity of best case O(n)%d\n",bestcase1);
    fprintf(output,"sort2 is Merge sort with average time complexity of O(nlog(n))%d\n",merge_sort);
    fprintf(output,"sort3 is Selection sort with average time complexity of O(n*2)%d\n",bestcase2*2);
  }else{
    fprintf(output,"sort1 is Selection sort with time complexity of best case O(n*2)%d\n",bestcase1*2);
    fprintf(output,"sort2 is Merge sort with average time complexity of O(nlog(n))%d\n",merge_sort);
    fprintf(output,"sort3 is Bubble sort with average time complexity of O(n)%d\n",bestcase2);
  }
}
