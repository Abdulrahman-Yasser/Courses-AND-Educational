
public class Main {
    public static void main(String[] args) {
        SLList<Integer> L = new SLList<Integer>(10);
        L.addFirst(6);
        L.addFirst(15);
        L.addFirst(263);
        System.out.println(L.getFirst());
        System.out.println(L.getLast());
        L.addLast(20);
        System.out.println(L.getLast());
        System.out.println(L.size_recursive());
        System.out.println(L.size());


        SLList<String> y = new SLList<String>("tamam");
        y.addFirst("hoa da el kalam");
        y.addFirst("khally elly kan mesta5aby yban");
        y.addFirst("Tamam we tamam ,, ooo");
        System.out.println(y.getFirst());
        System.out.println(y.getLast());
        y.addLast("a7a ya 3am");
        System.out.println(y.getLast());
        System.out.println(y.size_recursive());
        System.out.println(y.size());

        DLList<Integer> circular = new DLList<Integer>(5);
        circular.addFirst(13);
        circular.addFirst(18);
        circular.addFirst(6);
        circular.addFirst(29);
        circular.addFirst(30);
        circular.addLast(43);
        circular.addLast(50);
        circular.addLast(95);
        System.out.println(circular.getLast());
        System.out.println(circular.getFirst());
        circular.addFirst(29); 
        System.out.println(circular.getFirst());
    }
}