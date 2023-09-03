public class rotateRight<T> extends SLList<T>{
    public rotateRight(T x){
        super(x);
    }
    public rotateRight(){
        super();
    }
    public void rotateRight(){
        T x = removeLast();
        addFirst(x);
    }
}
