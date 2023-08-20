package deque;
public class LinkedListDeque<T> implements deque.Deque<T>{
    private class nodeItem<T>{
        public T item;
        public nodeItem<T> next, prev;
        public nodeItem(T x, nodeItem p, nodeItem n){
            item = x;
            next = n;
            prev = p;
        }
    }
    private nodeItem<T> Sential = new nodeItem<T>(null, null, null);;
    private int size;
    public LinkedListDeque(){
        Sential.next = Sential;
        Sential.prev = Sential;
        size = 0;
    }
    public LinkedListDeque(T item){
        Sential.next = new nodeItem<T>(item, Sential, Sential);
        Sential.prev = Sential.next;
        size = 1;
    }

    @Override
    public void addFirst(T item){
        Sential.next = new nodeItem<T>(item, Sential.prev, Sential.next);
        Sential.next.next.prev = Sential.next;
        Sential.prev.next = Sential.next;
        size += 1;
    }
    @Override
    public void addLast(T item){
        nodeItem<T> q = Sential.prev;
        Sential.prev = new nodeItem<T>(item, q, Sential.next);
        q.next = Sential.prev;
        Sential.next.prev = Sential.prev;
        size += 1;
    }
    @Override
    public int size(){
        return size;
    }
    @Override
    public void printDeque(){
        int s = size;
        nodeItem<T> q = Sential.next;
        while(s > 0) {
            System.out.println(q.item + "\n");
            q = q.next;
            s--;
        }
    }
    @Override
    public T removeFirst(){
        nodeItem<T> q = Sential.next;
        if(size > 0) {
            q.next.prev = q.prev;
            q.prev.next = q.next;
            Sential.next = q.next;
            size -= 1;
        }
        return q.item;
    }
    @Override
    public T removeLast(){
        nodeItem<T> q = Sential.prev;
        if(size > 0) {
            q.next.prev = q.prev;
            q.prev.next = q.next;
            Sential.prev = q.prev;
            size -= 1;
        }
        return q.item;
    }
    @Override
    public T get(int index){
        if(index > size){
            return null;
        }
        nodeItem<T> q = Sential.next;
        for(int i = 0; i < index; i++){
            q = q.next;
        }
        return q.item;
    }
    @Override
    public boolean equals(Object o){
        return true;
    }

}