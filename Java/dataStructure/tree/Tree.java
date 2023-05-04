
public class Tree {
    Node root;

public Tree(){this.root = null;}

public void insert(int number) {
    Node temp = new Node();
    temp.data = number;
    if (root == null) {
        root = temp;
    } else {
        Node current = root;
        while (true)  
            if (number > current.data)   
                if (current.right == null) {
                    current.right = temp;
                    break;
                } else current = current.right; 
            else  
                if (current.left == null) {
                    current.left = temp;
                    break;
                } else current = current.left;   
    }
    
}
  public void search(int number) {
      Node temp=new Node();
      temp=root;
      int degree=0;
      while(true){
          if (number==temp.data){
             System.out.println("FOUND!"+"\nTree:"+temp.data+"\ndegree:"+degree);
             break;
          }
          else if (number > temp.data && temp.right != null) {
            temp = temp.right;
            degree++;
          }else if (number < temp.data && temp.left != null) {
            temp = temp.left;
            degree++;
          }else {
              System.out.println("NOT FOUND!");
              break;
          } 
      }
  }
    public class Node{
        int data;
        Node left;
        Node right;
    }
  
}
