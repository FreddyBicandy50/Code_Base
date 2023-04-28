class user extends numbers{
    String name, number; 
    void user (){
        name="fredy";
        number="79131124";
    }  
    void setuser(String setname,String setnumber){
        name=setname;
        number=setnumber;
    }
    public static void main(String[] args) { 
        user objct=new user();
        objct.setuser("test","xxxxx");
        objct.print(); 
    }  
    void print(){System.out.println("name:"+name+"\nnumber:"+number);}
}