  int[] array = {5, 3, 1, 4, 8, 6}; 
        for (int i=0; i<array.length; i++){
            for(int j=0; j<array.length-i; j++){
                if(array[j]>array[j+1]){
                    int temp=array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }
        }
        for(int i=0; i<array.length; i++) System.out.println(array[i]);
         