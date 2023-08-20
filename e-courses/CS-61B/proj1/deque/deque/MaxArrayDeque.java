package deque;
import java.util.Comparator;
public class MaxArrayDeque<T> extends ArrayDeque<T> {
    Comparator<T> my_comparator;

    public MaxArrayDeque(Comparator<T> c) {
        my_comparator = c;
    }

    public T max() {
        return max(my_comparator);
    }

    public T max(Comparator<T> c) {
        int h = first, s = size;
        if(size == 0){
            return null;
        }
        T max_item = items[h];
        while (s > 0) {
            h = (int) (Integer.toUnsignedLong(h + 1) % size_memory);
            if(c.compare(items[h], max_item) > 0){
                max_item = items[h];
            }
            s--;
        }
        return max_item;
    }
}


