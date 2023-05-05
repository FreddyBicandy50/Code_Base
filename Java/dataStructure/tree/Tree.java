
public class Tree {
    Node root;

public Tree(){this.root = null;}

public void insert(int number) {
    //make a temp variable and assign the number to it 
    Node temp = new Node();
    temp.data = number;
    //check the head if empty add the new number 
    if (root == null) root = temp;
    else {
        //make another pointer to the tree head
        Node current = root;
        while (true) 
            //check if the number greater or less than the number inside the tree 
            if (number > current.data)  
                //check if the right pointer null 
                if (current.right == null) {
                    //if yes assign the temp node to the right branch and break the loop
                    current.right = temp;
                    break;
                }
                //if the right node contains number go sit on it
                else current = current.right; 
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
