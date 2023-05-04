
public class Tree {
    Node root;

public Tree(){this.root = null;}

public void insert(int number) {
      Node temp=new Node();
       if(root==null){
          temp.data=number;
          root=temp;
       }else{
         temp=root;
         while(temp!=null){
           if(number>temp.data) {
             temp.right=new Node();
             temp=temp.right;
            }else{
              temp.left = new Node();
              temp=temp.left;
            }
            
          }
       } 

    }
  public void print() {
    Node temp=root;
    while(temp!=null){ 
        System.out.println(temp.data);
        temp=temp.left;
      }
    }

    public class Node{
        int data;
        Node left;
        Node right;
    }
  
}
