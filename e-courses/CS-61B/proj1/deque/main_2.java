import deque.*;
public class main_2 {
    public static void main(String[] args) {
//        LinkedListDequeTest myTest = new LinkedListDequeTest();
//        myTest.emptyNullReturnTest();
//        myTest.addIsEmptySizeTest();
//        myTest.addRemoveTest();
//        myTest.removeEmptyTest();
//        myTest.bigLLDequeTest();
//        myTest.multipleParamTest();

        ArrayDeque<Integer> myArray = new ArrayDeque<Integer>();
        myArray.addFirst(5);
        myArray.addFirst(6);
        myArray.addFirst(7);
        myArray.addFirst(8);
        myArray.addFirst(9);
        myArray.addFirst(10);
        myArray.addFirst(11);
        myArray.addLast(20);
        myArray.addLast(21);
        myArray.addLast(22);
        myArray.addLast(23);
        myArray.addLast(24);
        myArray.addLast(25);
        myArray.addFirst(12);
        myArray.addFirst(13);
        myArray.addLast(26);
        myArray.addLast(27);

        myArray.printDeque();

        myArray.removeLast();
        myArray.removeLast();
        myArray.removeLast();
        myArray.removeLast();
        myArray.removeLast();
        myArray.removeLast();
        myArray.removeLast();
        myArray.removeFirst();
        myArray.removeFirst();
        myArray.removeFirst();
        myArray.removeFirst();
        myArray.removeFirst();
        myArray.removeFirst();
        myArray.removeFirst();
        myArray.printDeque();
        System.out.println(myArray.size());
    }
}
