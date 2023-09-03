import java.util.*;

public class ArraySet<T> implements Iterable<T>{
    private T items[];
    private int size;
    public ArraySet(){
        size = 0;
        items = (T[]) new Object[100];
    }
    public boolean contains(T x){
        for(int i = 0; i < size; i++){
            if(x.equals(items[i])){
                return true;
            }
        }
        return  false;
    }
    public void add(T x){
        if(contains(x)){
            return;
        }
        items[size] = x;
        size += 1;
    }
    public int size(){
        return size;
    }
    public Iterator<T> iterator(){
        return new ArraySetIterator();
    }
    private class ArraySetIterator implements Iterator<T>{
        private int myPos;
        ArraySetIterator(){
            myPos = 0;
        }
        public boolean hasNext(){
            return myPos < size;
        }
        public T next(){
            T x;
            x = items[myPos];
            myPos += 1;
            return x;
        }
    }
//    @Override
//    public String toString(){
//        StringBuilder returnString = new StringBuilder("{");
//        for(T my_item : this){
//            returnString.append(my_item.toString());
//            returnString.append(" , ");
//        }
//        returnString.append(" }");
//        return returnString.toString();
//    }

    @Override
    public String toString(){
        List<String> ListOfItems = new ArrayList<String>();
        for(T x : this){
            ListOfItems.add(x.toString());
        }
        return String.join(", ", ListOfItems);
    }


    @Override
    public boolean equals(Object o){
        if(this == o){
            return true;
        }
        if(o instanceof ArraySet arr){
            if (this.size != arr.size) {
                return false;
            }
            for(T x : this){
                if(!arr.contains(x)){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    public static <Glerb> ArraySet<Glerb> of(Glerb... stuff){
        ArraySet<Glerb> result = new ArraySet<Glerb>();
        for(Glerb x : stuff){
            result.add(x);
        }
        return result;
    }
    public static void main(String[] args){
        Set<String> javaSet= new HashSet<String>();
        javaSet.add("horse");
        javaSet.add("fish");
        javaSet.add("house");
        javaSet.add("horse");

        Iterator<String> itr = javaSet.iterator();
        while(itr.hasNext()){
            System.out.println(itr.next());
        }

        ArraySet<String> s = new ArraySet<String>();
        s.add("horse");
        s.add("fish");
        s.add("house");
        s.add("horse");
        System.out.println(s.contains("fish"));
        System.out.println(s.size());

        Iterator<String> itr2 = s.iterator();
        while(itr2.hasNext()) {
            System.out.println(itr2.next());
        }

        for(String i : s){
            System.out.println(i);
        }
        System.out.println(s);

        ArraySet<String> s_s = ArraySet.of("hi", "i'm", "here");
        System.out.println(s_s);
    }

}
