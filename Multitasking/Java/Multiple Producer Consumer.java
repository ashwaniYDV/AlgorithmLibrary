import java.util.LinkedList;
import java.util.Queue;

class BlockingQueue {
    private Queue<Integer> q;
    private int capacity;

    public BlockingQueue(int capacity) {
        this.capacity = capacity;
        q = new LinkedList<>();
    }

    public boolean add(int element) {
        synchronized (q) {
            while (q.size() == capacity) {
                try {
                    q.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            q.add(element);

            // try {Thread.sleep(1000);} catch (InterruptedException e) {}

            q.notifyAll();
            return true;
        }
    }

    public int remove() {
        synchronized (q) {
            while (q.isEmpty()) {
                try {
                    q.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            int element = q.poll();

            // try {Thread.sleep(1000);} catch (InterruptedException e) {}

            q.notifyAll();
            return element;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("====Main started====");
        BlockingQueue bq = new BlockingQueue(5);

        for (int i = 1; i <= 5; i++) {
            new Thread(() -> {
                int counter = 0;
                while (++counter <= 10) {
                    Thread.currentThread().getName();
                    System.out.println(Thread.currentThread().getName() + " produced: " + bq.add(counter));
                }
            }, "producer-" + i).start();
        }

        for (int i = 1; i <= 5; i++) {
            new Thread(() -> {
                int counter = 0;
                while (++counter <= 10) {
                    System.out.println(Thread.currentThread().getName() + " consumed: " + bq.remove());
                }
            }, "consumer-" + i).start();
        }

        System.out.println("====Main ended====");
    }
}
