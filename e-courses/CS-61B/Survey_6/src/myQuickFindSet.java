import java.util.ArrayList;

public class myQuickFindSet implements DisjointInterface{
    ArrayList<Integer> myArray;
    public myQuickFindSet(int size){
        myArray = new ArrayList<Integer>(size);
        for(int q = 0; q < size; q++){
            myArray.add(-1);
        }
    }
    @Override
    public void connect(int a, int b) {
        if(myArray.get(a) == -1){
            myArray.set(b, a);
        }else{
            myArray.set(b, myArray.get(a));
        }
    }
    @Override
    public boolean isConnected(int a, int b) {
        if(myArray.get(a) == myArray.get(b)){
            return true;
        }else if(a == myArray.get(b)){
            return true;
        }else {
            return false;
        }
    }
    public void print(){
        for(int i = 0; i < myArray.size(); i++){
            if(myArray.get(i) == -1){
                System.out.println("Head of group " + i);
                continue;
            }
            System.out.println(i + "is in group " + myArray.get(i));
        }
    }
    public static void main(String[] args) {

        myQuickFindSet mySet = new myQuickFindSet(10);
        mySet.connect(4, 5);
        mySet.connect(5, 2);
        mySet.connect(2, 3);
        mySet.connect(3, 1);
        mySet.connect(0,6 );
        mySet.connect(6, 7);

        mySet.print();

        System.out.println( mySet.isConnected(5, 1) );
        System.out.println( mySet.isConnected(5, 7) );

    }
}
