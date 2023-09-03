import java.util.Comparator;

public class Maximizer {
    public static OurComparable my_max(OurComparable[] items){
        int cmp, maxDex = 0;
        for(int i = 0; i < items.length; i++){
            cmp = items[i].myCompareTo(items[maxDex]);
            if(cmp > 0){
                maxDex = i;
            }
        }
        return items[maxDex];
    }
    public static Comparable max(Comparable[] items){
        int cmp, maxDex = 0;
        for(int i = 0; i < items.length; i++){
            cmp = items[i].compareTo(items[maxDex]);
            if(cmp > 0){
                maxDex = i;
            }
        }
        return items[maxDex];
    }

    public static void main(String[] args){
        Dog[] myDogs = {new Dog("DOKI", 19), new Dog("Sture", 12), new Dog("Crtemeion", 20)};
        Dog maxDog = (Dog)my_max(myDogs);
        maxDog.bark();
        maxDog = (Dog)max(myDogs);
        maxDog.bark();
        Comparator<Dog> nc = Dog.getNameComparator();
        if(nc.compare(myDogs[0], myDogs[2]) > 0){
            myDogs[0].bark();
        }else{
            myDogs[2].bark();
        }
    }
}

