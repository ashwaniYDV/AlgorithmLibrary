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

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
            }

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
