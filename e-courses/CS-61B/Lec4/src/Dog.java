import java.util.Comparator;

public class Dog implements OurComparable, Comparable<Dog>{
    private String name;
    private int size;
    public Dog(String i, int x){
        name = i;
        size = x;
    }
    public void bark(){
        System.out.println("my size is " + size + " barka bark bark !!!");
    }
    public int myCompareTo(Object o){
        Dog uddaDog = (Dog)o;
        return this.size - uddaDog.size;
    }
    public int compareTo(Dog uddaDog){
        return this.size - uddaDog.size;
    }

    private static class NameComparator implements Comparator<Dog>{
        public int compare(Dog a, Dog b){
            return a.name.compareTo(b.name);
        }
    }
    public static Comparator<Dog> getNameComparator(){
        return new NameComparator();
    }
}
