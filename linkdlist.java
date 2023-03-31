
public class linkedlist{
    
   public static void main(String[]args){
        class Node {
           int data;
           Node next;   
       }
       Node head =null;
        
       Node temp1 = new Node();
       temp1.data = 1;
       temp1.next=head;
       head=temp1;
       Node temp2=new Node();
       temp2.data=2;
       head.next=temp2;
       
        while(true){
            if(head.next!=null){
               System.out.println(head.data);
            }else break;
            head=head.next;
        } 
}
}