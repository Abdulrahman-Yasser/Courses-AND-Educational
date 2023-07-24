public class DLList<DLListType> {
    private class DLLNode<DLListType>{
        DLListType item;
        DLLNode<DLListType> next, prev;
        DLLNode(DLListType x, DLLNode p, DLLNode n){
            item = x;
            next = n;
            prev = p;
        }
    }
    DLLNode<DLListType> sentiel;
    private int size;
    public DLList(){
        sentiel = new DLLNode<DLListType>(null, null, null);
        size = 0;
    }
    public DLList(DLListType x){
        sentiel = new DLLNode<DLListType>(null, null, null);
        sentiel.next = new DLLNode<DLListType>(null, sentiel, sentiel);
        size = 1;
    }
    public void addFirst(DLListType x){
        DLLNode<DLListType> q = sentiel.next;
        sentiel.next = new DLLNode<DLListType>(x, sentiel.prev, q);
        q.prev = sentiel.next;
        size += 1;
    }
    public void addLast(DLListType x){
        DLLNode<DLListType> q =  sentiel.prev;
        sentiel.prev = new DLLNode<DLListType>(x, q, sentiel.next);
        sentiel.next.prev = sentiel.prev;
        size += 1;
    }
    public DLListType getFirst(){
        return sentiel.next.item;
    }
    public DLListType getLast(){
        return sentiel.prev.item;
    }
}
