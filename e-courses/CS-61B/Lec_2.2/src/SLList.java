public class SLList<SLListType> implements List61B<SLListType> {
    private static int size ;

    /** Nested class, we use it when declaring something that will only be used
     * by the SLList class
     * static means: that the class can't use anything outsider of it **/
    //    private static class IntNode {
//        public int item;
//        public IntNode next;
//
//        public IntNode(int i, IntNode n) {
//            item = i;
//            next = n;
//        }
//    }
    protected IntNode<SLListType> sentinel;
    public SLList(SLListType x){
        sentinel = new IntNode<SLListType>(null, null);
        sentinel.next = new IntNode<SLListType>(x, null);
        size = 1;
    }
    public SLList(){
        sentinel = new IntNode<SLListType>(null, null);
        size = 0;
    }
    /** Adds X to front of the list **/
    public void addFirst(SLListType x){
        sentinel.next = new IntNode<SLListType>(x, sentinel.next);
        size += 1;
    }
    /** Returns the sentinel item of the list **/
    public SLListType getFirst() {
        return sentinel.next.item;
    }
    public void addLast(SLListType x)
    {
        IntNode<SLListType> q = sentinel;
        while(q.next != null){
            q = q.next;
        }
        q.next = new IntNode<SLListType>(x, null);
        size += 1;
    }
    public SLListType getLast(){
        IntNode<SLListType> q = sentinel;
        while(q.next != null){
            q = q.next;
        }
        return q.item;
    }
    private static int size(IntNode p){
        if(p.next == null){
            return 1;
        }
        return 1 + size(p.next);
    }
    public int size_recursive(){
        return size(sentinel.next);
    }
    public int size(){
        return size;
    }
    public SLListType removeLast(){
        IntNode<SLListType> q = sentinel;
        for(int i = 0; i < size; i++){
            q = q.next;
        }
        SLListType result = q.next.item;
        q.next = null;
        return result;
    }
    public SLListType get(int i){
        IntNode<SLListType> q = sentinel;
        for(int j = 0; i < i; j++){
            q = q.next;
        }
        return q.item;
    }
    public void Insert(SLListType x, int position){
        IntNode<SLListType> new_item, q = sentinel;
        for(int i = 0; i < position; i++){
            q = q.next;
        }
        new_item = new IntNode<SLListType>(x, q.next.next);
        q.next = new_item;
    }
}



