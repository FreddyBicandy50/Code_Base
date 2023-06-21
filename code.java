public class QueueExample {
    private Object[] queue;
    private int front; // Index of the front element
    private int rear; // Index of the rear element
    private int size; // Current size of the queue
    private int capacity; // Maximum capacity of the queue

    public QueueExample(int capacity) {
        this.capacity = capacity;
        queue = new Object[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }

    public int size() {
        return size;
    }

    public void enqueue(Object item) {
        if (isFull()) {
            throw new IllegalStateException("Queue is full");
        }
        rear = (rear + 1) % capacity;
        queue[rear] = item;
        size++;
    }

    public Object dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        Object dequeuedItem = queue[front];
        front = (front + 1) % capacity;
        size--;
        return dequeuedItem;
    }

    public Object peek() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty");
        }
        return queue[front];
    }

    public static void main(String[] args) {
        QueueExample queue = new QueueExample(5);

        queue.enqueue("Apple");
        queue.enqueue("Banana");
        queue.enqueue("Cherry");

        System.out.println("Size of the queue: " + queue.size());
        System.out.println("First item in the queue: " + queue.peek());
         
        while (!queue.isEmpty()) {
            System.out.println("Dequeued item: " + queue.dequeue());
        }
    }
}
