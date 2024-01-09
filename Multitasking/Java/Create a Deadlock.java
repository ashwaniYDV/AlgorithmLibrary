// Creating a deadlock
/*
Deadlock can be created by making the lock-acquiring steps different for both threads.

thread1 will get lock1 and wait indefinitely for lock2
thread2 will get lock2 and wait indefinitely for lock1
*/
public class Main {
    public static void main(String[] args) {
        System.out.println("====Main started====");

        String lock1 = "lock1";
        String lock2 = "lock2";

        Thread thread1 = new Thread(() -> {
            synchronized (lock1) {
                try {Thread.sleep(100);} catch (InterruptedException e) {throw new RuntimeException(e);}
                synchronized (lock2) {
                    System.out.println("Lock acquired!");
                }
            }
        }, "thread1");

        Thread thread2 = new Thread(() -> {
            synchronized (lock2) {
                try {Thread.sleep(100);} catch (InterruptedException e) {throw new RuntimeException(e);}
                synchronized (lock1) {
                    System.out.println("Lock acquired!");
                }
            }
        }, "thread2");

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        System.out.println("====Main ended====");
    }
}



// solving the deadlock
/*
Deadlock can be avoided by making the lock-acquiring steps same for both threads.
*/
public class Main {
    public static void main(String[] args) {
        System.out.println("====Main started====");

        String lock1 = "lock1";
        String lock2 = "lock2";

        Thread thread1 = new Thread(() -> {
            synchronized (lock1) {
                try {Thread.sleep(100);} catch (InterruptedException e) {throw new RuntimeException(e);}
                synchronized (lock2) {
                    System.out.println("Lock acquired!");
                }
            }
        }, "thread1");

        Thread thread2 = new Thread(() -> {
            synchronized (lock1) {
                try {Thread.sleep(100);} catch (InterruptedException e) {throw new RuntimeException(e);}
                synchronized (lock2) {
                    System.out.println("Lock acquired!");
                }
            }
        }, "thread2");

        thread1.start();
        thread2.start();

        try {
            thread1.join();
            thread2.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        System.out.println("====Main ended====");
    }
}
