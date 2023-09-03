public class vengefulSLList<T> extends SLList<T>{
    SLList<T> deletedItems;
    public vengefulSLList(T x){
        super(x);
        deletedItems = new SLList<T>();
    }
    public vengefulSLList(){
        super();
        deletedItems = new SLList<T>();
    }
    @Override
    public T removeLast(){
        T x =super.removeLast();
        deletedItems.addLast(x);
        return x;
    }
    public void printLostItem(){
        deletedItems.print();
    }
}
