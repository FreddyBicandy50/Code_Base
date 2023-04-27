public class qeue {
    int rear=-1,front=-1;
    int array[];
    public qeue(){
        this.array= new int[5];  
    }
    public void enqeue(int number) {
        if rear(+)
        if (rear == -1) {
            array[0] = number;
            rear++;
        }
        if(front == -1)front++;
        else {
            if (rear+1 <= array.length - 1) {
                array[rear + 1] = number;
                rear++;
            }else{
                rear=-1;
                enqeue(number);
            }
        }

    }
    public void print_array(){
        System.out.println("\nfront="+array[front]);
        System.out.println("rear="+array[rear]);
    }
    public void deqeue(){ 
        if(front!=-1){
            int temp=array[front];
            if(front==array.length-1) front=-1;
            else front++;
        }
    }   

}
