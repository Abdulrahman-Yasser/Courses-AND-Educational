public class rotateRight<T> extends SLList<T>{
    public void rotateRight(){
        T x = removeLast();
        addFirst(x);
    }
}
