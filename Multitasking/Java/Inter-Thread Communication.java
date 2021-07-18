// https://youtu.be/A1tnVMpWHh8?si=8n5zI_s6v3PQLyXc

/*
Every object in java can be used as a lock.
*/

/*
* wait() and notify() belongs to Object class.
* sleep() belongs to Thread class.
*/

class Resource {
    int num;
    boolean valueSet;

    public Resource(boolean valueSet) {
        this.valueSet = false;
    }

    public synchronized void put(int num) {
        while (valueSet) {
            try {
                wait();
            } catch (Exception e) {
                System.out.println("Exception occurred.");
            }
        }
        this.num = num;
        System.out.println("Put : " + this.num);
        valueSet = true;
        notify();
    }

    public synchronized void get() {
        while (!valueSet) {
            try {
                wait();
            } catch (Exception e) {
                System.out.println("Exception occurred.");
            }
        }
        System.out.println("Get : " + this.num);
        valueSet = false;
        notify();
    }
}

class Producer implements Runnable {
    Resource res;

    public Producer(Resource res) {
        this.res = res;
        Thread t = new Thread(this, "Producer thread");
        t.start();
    }

    public void run() {
        int i = 0;
        while (true) {
            res.put(i++);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.println("Exception occurred.");
            }
        }
    }
}

class Consumer implements Runnable {
    Resource res;

    public Consumer(Resource res) {
        this.res = res;
        Thread t = new Thread(this, "Consumer thread");
        t.start();
    }

    public void run() {
        while (true) {
            res.get();
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                System.out.println("Exception occurred.");
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Resource res = new Resource(false);
        Runnable p = new Producer(res);
        Runnable c = new Consumer(res);
    }
}
