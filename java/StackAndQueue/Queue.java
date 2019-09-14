public class Queue<T> {
    private static class QueueNode<T> {
        private T data;
        private QueueNode<T> next;

        public QueueNode(T data) {
            this.data = data;
        }
    }

    public QueueNode head;
    public QueueNode tail;

    public void add(T item) {
        QueueNode<T> newNode = new QueueNode<T>(item);
        if (tail != null) {
           tail.next = newNode; 
        }
        tail = newNode;
        if (first == null) {
            first = last;
        }
    }

    public T remove() {
        if (head == null) {
            throw new NoSuchElementException();
        }
        T data = head.data;
        head = head.next;
        if (head == null) {
            tail = head;
        }
        return data;
    }

    public T peek() {
        if (head == null) {
            throw new NoSuchElementException();
        }
        return head.data;
    }

    public boolean isEmpty() {
        return head == null;
    }
}