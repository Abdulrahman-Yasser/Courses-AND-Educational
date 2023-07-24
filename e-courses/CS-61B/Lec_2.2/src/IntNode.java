public class IntNode<myType> {
    public myType item;
    public IntNode<myType> next;

    public IntNode(myType i, IntNode<myType> n) {
        item = i;
        next = n;
    }
}
