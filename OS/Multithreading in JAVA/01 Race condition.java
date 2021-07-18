// https://www.geeksforgeeks.org/multithreading-in-java/


class Counter {
    static public int cnt = 0;
}

class MultithreadingDemo extends Thread {
    @Override
    public void run() {
        try {
            for(int i = 0; i < 10000; i++) {
                Counter.cnt++;
            }
            // Displaying the thread that is running
            System.out.println("Thread " + Thread.currentThread().getId() + " is running");
        }
        catch (Exception e) {
            // Throwing an exception
            System.out.println("Exception is caught");
        }
    }
}


public class Main {
    public static void main(String[] args) {
        int n = 2;
        for (int i = 0; i < n; i++) {
            MultithreadingDemo object = new MultithreadingDemo();
            object.start();
        }
        try {
            Thread.sleep(3000);
        } catch (Exception e) {
            System.out.println("Error!!!");
        }
        System.out.println(Counter.cnt);
    }
}





















class Counter {
    static public int cnt = 0;
}

class MultithreadingDemo implements Runnable {
    @Override
    public void run() {
        try {
            for(int i = 0; i < 10000; i++) {
                Counter.cnt++;
            }
            // Displaying the thread that is running
            System.out.println("Thread " + Thread.currentThread().getId() + " is running");
        }
        catch (Exception e) {
            // Throwing an exception
            System.out.println("Exception is caught");
        }
    }
}


public class Main {
    public static void main(String[] args) {
        int n = 2;
        for (int i = 0; i < n; i++) {
            Thread object = new Thread(new MultithreadingDemo());
            object.start();
        }
        try {
            Thread.sleep(3000);
        } catch (Exception e) {
            System.out.println("Error!!!");
        }
        System.out.println(Counter.cnt);
    }
}
