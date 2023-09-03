public class myBST {
    private static class IntNode {
        public int item;
        public IntNode left;
        public IntNode right;

        public IntNode(int i) {
            item = i;
            right = null;
            left = null;
        }
    }
    private IntNode mySentialTree;
    public myBST(int i) {
        mySentialTree = new IntNode(i);
    }
    public void print(){
        IntNode myNode = mySentialTree;
        travels(myNode);
    }
    public void add(int i){
        IntNode myNode;
        myNode = getRightPos(mySentialTree, i);
    }
    private void travels(IntNode Node){
        if(Node == null){
            return;
        }
        travels(Node.left);
        System.out.println(Node.item);
        travels(Node.right);
    }
    private IntNode getRightPos(IntNode Node, int item){
        if(Node == null){
            Node = new IntNode(item);
            return Node;
        }
        IntNode result;
        if(item > Node.item){
            Node.right = getRightPos( Node.right, item);
        }else if(item < Node.item){
            Node.left = getRightPos( Node.left, item);
        }
        return Node;
    }
    public boolean contains(int item){
        return false;
    }
    public static void main(String[] args) {
        myBST myTree = new myBST(8);

        myTree.add(9);
        myTree.add(7);
        myTree.add(10);
        myTree.add(6);
        myTree.add(11);
        myTree.add(5);
        myTree.add(12);
        myTree.add(4);
        myTree.add(13);
        myTree.add(3);

        myTree.print();

    }
}
