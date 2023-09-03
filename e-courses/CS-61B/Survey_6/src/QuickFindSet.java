import java.util.ArrayList;

public class QuickFindSet implements DisjointInterface{
    ArrayList<Integer> myArray;
    public QuickFindSet(int size){
        myArray = new ArrayList<Integer>(size);
        for(int q = 0; q < size; q++){
            myArray.add(-1);
        }
    }
    @Override
    public void connect(int a, int b) {
        myArray.set(b, a);
    }
    @Override
    public boolean isConnected(int a, int b) {
        return find(a) == find(b);
    }
    private int find(int a){
        int r = a;
        while(myArray.get(r) >= 0){
            r = myArray.get(r);
        }
        return r;
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

        QuickFindSet mySet = new QuickFindSet(10);
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
