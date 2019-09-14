public class MinStack<T> implements Comparable {
    private static class StackNode<T> {
        private T data;
        private StackNode<T> next;
        private StackNode<T> localMin;

        public StackNode(T data) {
            this.data = data;
        }
    }

    private StackNode<T> top;

    public T pop() {
        if (top == null) {
            throw new StackEmptyException();
        }

        T item = top.data;
        top = top.next;
        return item;
    }

    public void push (T item) {
        StackNode<T> t = new StackNode<T>(item);
        if (head == null) {
            min = head;
            head.localMin = head;
            head = t;
        }
        if (t.data < head.localMin.data) {
            t.localMin = t;
        } else {
            t.localMin = head.localMin;
        }
        t.next = top;
        top = t;
    }

    public T peek() {
        if (top == null) {
            throw new StackEmptyException();
        }
        return top.data;
    }

    public StackNode<T> min() {
        if (top == null) {
            throw new StackEmptyException();
        }
        return head.localMin;
    }

    public boolean isEmpty() {
        return top == null;
    }
}