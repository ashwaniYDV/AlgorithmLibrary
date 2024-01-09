// Method 1
class Stack {
    private int top;
    private int[] arr;
    Object lock;

    public Stack(int capacity) {
        top = -1;
        arr = new int[capacity];
        lock = new Object();
    }

    boolean isEmpty() {
        return (top < 0);
    }

    boolean isFull() {
        return (top >= arr.length - 1);
    }

    public boolean push (int element) {
        synchronized (lock) {
            if (isFull()) return false;
            top++;

            try {Thread.sleep(1000);} catch (InterruptedException e) {}

            arr[top] = element;
            return true;
        }
    }

    public int pop () {
        synchronized (lock) {
            if (isEmpty()) return Integer.MIN_VALUE;
            int element = arr[top];
            arr[top] = Integer.MIN_VALUE;

            try {Thread.sleep(1000);} catch (InterruptedException e) {}

            top--;
            return element;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("====Main started====");
        Stack stack = new Stack(2);

        Thread pusher = new Thread(() -> {
            int counter = 0;
            while (++counter <= 10) {
                System.out.println("Pushed: " + stack.push(counter));
            }
        }, "Pusher");


        Thread popper = new Thread(() -> {
            int counter = 0;
            while (++counter <= 10) {
                System.out.println("Popped: " + stack.pop());
            }
        }, "Popper");

        pusher.start();
        popper.start();

        System.out.println("====Main ended====");
    }
}


// Method 2 (Method 2 and 3 are same)
class Stack {
    private int top;
    private int[] arr;

    public Stack(int capacity) {
        top = -1;
        arr = new int[capacity];
    }

    boolean isEmpty() {
        return (top < 0);
    }

    boolean isFull() {
        return (top >= arr.length - 1);
    }

    public boolean push (int element) {
        synchronized (this) {
            if (isFull()) return false;
            top++;

            try {Thread.sleep(1000);} catch (InterruptedException e) {}

            arr[top] = element;
            return true;
        }
    }

    public int pop () {
        synchronized (this) {
            if (isEmpty()) return Integer.MIN_VALUE;
            int element = arr[top];
            arr[top] = Integer.MIN_VALUE;

            try {Thread.sleep(1000);} catch (InterruptedException e) {}

            top--;
            return element;
        }
    }
}

// Method 3 (Method 2 and 3 are same)
/*
For all the synchronized methods of a class, the lock is an instance of this class. 
Therefore lock is the same for all synchronized methods of this class.
Thus only one synchronized method will be able to execute by any thread.
*/
class Stack {
    private int top;
    private int[] arr;

    public Stack(int capacity) {
        top = -1;
        arr = new int[capacity];
    }

    boolean isEmpty() {
        return (top < 0);
    }

    boolean isFull() {
        return (top >= arr.length - 1);
    }

    public synchronized boolean push (int element) {
        if (isFull()) return false;
        top++;

        try {Thread.sleep(1000);} catch (InterruptedException e) {}

        arr[top] = element;
        return true;
    }

    public synchronized int pop () {
        if (isEmpty()) return Integer.MIN_VALUE;
        int element = arr[top];
        arr[top] = Integer.MIN_VALUE;

        try {Thread.sleep(1000);} catch (InterruptedException e) {}

        top--;
        return element;
    }
}
