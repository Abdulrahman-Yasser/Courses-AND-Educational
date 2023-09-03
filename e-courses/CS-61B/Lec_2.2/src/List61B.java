public interface List61B<Item> {
    public void addFirst(Item x);
    public void addLast(Item x);
    public Item getFirst();
    public  Item getLast();
    public Item removeLast();
    public Item get(int i);
    public void Insert(Item x, int position);
    public int size();
    default public void print(){
        for(int i = 0; i < size(); i++){
            System.out.println(get(i));
        }
    }
}
