package deque;
public class ArrayDeque<T> implements deque.Deque<T> {
    private int first, last, size, size_memory;
    private T[] items;
    private void expand(){
        T[] new_items = (T[]) new Object[size_memory + 8];
        System.arraycopy(items, 0, new_items, 4, items.length);
        items = new_items;
        size_memory += 8;
    }
    public ArrayDeque(){
        items = (T[]) new Object[8];
        size = 0;
        first = 4;
        last = 4;
        size_memory = 8;
    }
    public void addFirst(T item){
        if(first == 0){
            expand();
            first += 4;
        }
        items[first] = item;
        first = (int) (Integer.toUnsignedLong(first - 1 ) % size_memory);
        size += 1;
    }
    public void addLast(T item){
        if(last == size_memory){
            expand();
            last -= 4;
        }
        items[last] = item;
        last = (int) (Integer.toUnsignedLong(last + 1 ) % size_memory);
        size += 1;
    }
    public boolean isEmpty(){
        return (size == 0);
    }
    public int size(){
        return size;
    }
    public void printDeque(){
        int h = first, s = size;
        while(s > 0){
            h = (int) (Integer.toUnsignedLong(h + 1) % size_memory);
            System.out.println(items[h] + "\n");
            s--;
        }
    }
    public T removeFirst(){
        T x = items[first];
        items[first] = null;
        first = (int) (Integer.toUnsignedLong(first + 1) % size_memory);
        return x;
    }
    public T removeLast(){
        T x = items[last];
        items[last] = null;
        last = (int) (Integer.toUnsignedLong(last - 1) % size_memory);
        return x;
    }
    public T get(int index){
        int i = (int) (Integer.toUnsignedLong(first + index) % size_memory);
        System.out.println(items[i] + "\n");
        return items[i];
    }
    public boolean equals(Object o){
        return true;
    }
}
