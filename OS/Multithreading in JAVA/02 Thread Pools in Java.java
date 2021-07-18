// https://www.geeksforgeeks.org/thread-pools-java/
// https://www.javatpoint.com/java-thread-pool


import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

// Task class to be executed (Step 1)
class Task implements Runnable {
    private String name;

    public Task(String s) {
        this.name = s;
    }

    // Prints task name and sleeps for 1s
    // This Whole process is repeated 5 times
    public void run() {
        try {
            for (int i = 0; i <= 5; i++) {
                Date d = new Date();
                SimpleDateFormat ft = new SimpleDateFormat("hh:mm:ss");
                if (i == 0) {
                    // prints the initialization time for every task
                    System.out.println("Initialization Time for" + " task name - " + name + " = " + ft.format(d));
                } else {
                    System.out.println("Executing Time for task name - " + name + " = " + ft.format(d));
                    // prints the execution time for every task
                }
                Thread.sleep(1000);
            }
            System.out.println(name + " complete.");
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    // Maximum number of threads in thread pool
    static final int MAX_T = 3;

    public static void main(String[] args) {
        // creates five tasks
        Runnable r1 = new Task("task 1");
        Runnable r2 = new Task("task 2");
        Runnable r3 = new Task("task 3");
        Runnable r4 = new Task("task 4");
        Runnable r5 = new Task("task 5");

        // creates a thread pool with MAX_T no. of threads as the fixed pool size (Step 2)
        ExecutorService pool = Executors.newFixedThreadPool(MAX_T);

        // passes the Task objects to the pool to execute (Step 3)
        pool.execute(r1);
        pool.execute(r2);
        pool.execute(r3);
        pool.execute(r4);
        pool.execute(r5);

        // pool shutdown (Step 4)
        pool.shutdown();
    }
}
















import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Task implements Runnable {
    private String message;
    public Task(String s) {
        this.message = s;
    }
    public void run() {
        System.out.println(Thread.currentThread().getName() + " (Start) message = " + message);
        //call processmessage method that sleeps the thread for 2 seconds
        processmessage();
        //prints thread name
        System.out.println(Thread.currentThread().getName()+" (End)");
    }
    private void processmessage() {
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    // Maximum number of threads in thread pool
    static final int MAX_T = 5;

    public static void main(String[] args) {
        //creating a pool of MAX_T threads
        ExecutorService executor = Executors.newFixedThreadPool(MAX_T);
        for (int i = 0; i < 10; i++) {
            Runnable worker = new Task("task-" + i);
            executor.execute(worker);//calling execute method of ExecutorService
        }

        executor.shutdown();

        while (!executor.isTerminated()) {   }

        System.out.println("Finished all threads");
    }
}
