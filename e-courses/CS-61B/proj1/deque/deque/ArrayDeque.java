package deque;
public class ArrayDeque<T> implements deque.Deque<T> {
    protected int first, last, size, size_memory;
    protected T[] items;
    protected void expand(){
        T[] new_items = (T[]) new Object[size_memory + 8];
        System.arraycopy(items, first, new_items, 4, last - first);
        items = new_items;
        size_memory += 8;
        last += 4;
        first = 4;
    }
    protected void shrink(){
        T[] new_items = (T[]) new Object[size_memory - 8];
        System.arraycopy(items, first, new_items, 4, last - first);
        items = new_items;
        size_memory -= 8;
        first = 4;
        last = size_memory - 4;
    }
    public ArrayDeque(){
        items = (T[]) new Object[8];
        size = 0;
        first = 3;
        last = 4;
        size_memory = 8;
    }
    public void setCapacity(int the_capacity){
        T[] new_items = (T[]) new Object[size_memory + the_capacity];
        System.arraycopy(items, 0, new_items, the_capacity/2, items.length);
        items = new_items;
        size_memory += the_capacity;
    }
    @Override
    public void addFirst(T item){
        if(first == 0){
            expand();
        }
        items[first] = item;
        first = (int) (Integer.toUnsignedLong(first - 1 ) % size_memory);
        size += 1;
    }
    @Override
    public void addLast(T item){
        if(last == size_memory){
            expand();
        }
        items[last] = item;
        last = (int) (Integer.toUnsignedLong(last + 1 ) % size_memory);
        size += 1;
    }
    @Override
    public int size(){
        return size;
    }
    @Override
    public void printDeque(){
        int h = first, s = size;
        while(s > 0){
            h = (int) (Integer.toUnsignedLong(h + 1) % size_memory);
            System.out.println(items[h] + "\n");
            s--;
        }
    }
    @Override
    public T removeFirst(){
        T x = items[first];
        if(size > 0) {
            if((size_memory - size) > 16){
                shrink();
            }
            first = (int) (Integer.toUnsignedLong(first + 1) % size_memory);
            items[first] = null;
            size-=1;
        }
        return x;
    }
    @Override
    public T removeLast(){
        T x = items[last];
        if(size > 0) {
            if((size_memory - size) > 16){
                shrink();
            }
            last = (int) (Integer.toUnsignedLong(last - 1) % size_memory);
            items[last] = null;
            size-=1;
        }
        return x;
    }
    @Override
    public T get(int index){
        int i = (int) (Integer.toUnsignedLong(first + index) % size_memory);
        System.out.println(items[i] + "\n");
        return items[i];
    }
    @Override
    public boolean equals(Object o){
        return true;
    }
}
