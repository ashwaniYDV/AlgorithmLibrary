/*
The Producer fetches data from the API and adds it to the buffer. (you can implement the DataProvider interface for your specific API) 
The Consumer retrieves data from the buffer and writes it to the specified output file.
Both the producer and consumer run in separate threads.
The producer continuously fetches data from the API while the consumer writes data to the file as it becomes available in the buffer.
*/

import java.util.ArrayList;
import java.util.LinkedList;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Queue;
import java.util.Random;

interface DataProvider {
    String fetchData();
    void addData(String data) throws InterruptedException;
}

class MockApiDataProvider implements DataProvider {

    ArrayList<String> mockData = new ArrayList<>();

    public MockApiDataProvider() {
        mockData.add("Data 1");
        mockData.add("Data 2");
    }

    private Random random = new Random();

    @Override
    public String fetchData() {
        // Simulate fetching data from the API (replace with actual API call)
        int randomIndex = random.nextInt(mockData.size());
        return mockData.get(randomIndex);
    }

    @Override
    public void addData(String data) throws InterruptedException {
        mockData.add(data);
        Thread.sleep(1000);
    }
}


class SharedBuffer {
    private Queue<String> buffer = new LinkedList<>();
    private int capacity;

    public SharedBuffer(int capacity) {
        this.capacity = capacity;
    }

    public synchronized void produce(String data) throws InterruptedException {
        while (buffer.size() == capacity) {
            // Buffer is full, wait for consumers to make space
            wait();
        }
        buffer.add(data);
        System.out.println("Produced: " + data);
        // Notify consumers that data is available
        notify();
    }

    public synchronized String consume() throws InterruptedException {
        while (buffer.isEmpty()) {
            // Buffer is empty, wait for producers to add data
            wait();
        }
        String data = buffer.poll();
        System.out.println("Consumed: " + data);
        // Notify producers that space is available
        notify();
        return data;
    }
}

class Producer {
    private SharedBuffer buffer;
    private DataProvider apiDataProvider;

    public Producer(SharedBuffer buffer, DataProvider apiDataProvider) {
        this.buffer = buffer;
        this.apiDataProvider = apiDataProvider;
    }

    public void fetchDataAndProduce() {
        try {
            while (true) {
                String data = apiDataProvider.fetchData(); // Fetch data from API
                buffer.produce(data);
                Thread.sleep(1000); // Simulate some work or adjust as needed
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Consumer {
    private SharedBuffer buffer;
    private String outputFile;

    public Consumer(SharedBuffer buffer, String outputFile) {
        this.buffer = buffer;
        this.outputFile = outputFile;
    }

    public void writeDataToFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile, true))) {
            while (true) {
                String data = buffer.consume();
                writer.write(data);
                writer.newLine();
                writer.flush();
            }
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        SharedBuffer buffer = new SharedBuffer(3); // Set the buffer capacity
        DataProvider apiDataProvider = new MockApiDataProvider(); // Use the mock data provider
        String outputFile = "output.txt";

        Producer producer = new Producer(buffer, apiDataProvider);
        Consumer consumer = new Consumer(buffer, outputFile);

        Thread producerThread = new Thread(producer::fetchDataAndProduce);
        Thread consumerThread = new Thread(consumer::writeDataToFile);

        producerThread.start();
        consumerThread.start();

        int i = 0;
        while (true) {
            i++;
            apiDataProvider.addData(Integer.toString(i));
        }
    }
}
