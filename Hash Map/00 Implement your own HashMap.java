// https://youtu.be/sHpjxXX81Gw?si=WceyMqID1ZOt5tDx

import java.util.*;

class MapNode<K , V> {
    K key;
    V value;
    MapNode<K , V> next;

    public MapNode(K key , V value) {
        this.key = key;
        this.value = value;
    }
}

class OurMap<K , V> {
    private List<MapNode<K , V>> bucket;
    private int capacity; // length of the bucket
    private int size; // number of elements in the map
    private final int INITIAL_CAPACITY = 5; // initial length of the bucket array

    public OurMap() {
        bucket = new ArrayList<>();
        capacity = INITIAL_CAPACITY;
        for(int i = 0 ; i < capacity ; i ++) {
            bucket.add(null);
        }
    }

    private int getBucketIndex(K key) {
        int hashCode = key.hashCode();
        return hashCode % capacity;
    }

    public V get(K key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<K , V> head = bucket.get(bucketIndex);
        while(head != null) {
            if(head.key.equals(key)) {
                return head.value;
            }
            head = head.next;
        }
        return null;
    }

    public void put(K key , V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<K , V> head = bucket.get(bucketIndex);
        while(head != null) {
            if(head.key.equals(key)) {
                head.value = value;
                return;
            }
            head = head.next;
        }

        size++;
        MapNode<K, V> newEntry = new MapNode<K, V>(key, value);
        head = bucket.get(bucketIndex);
        newEntry.next = head;
        bucket.set(bucketIndex, newEntry);

        System.out.println("inserting key " + key);

        double loadFactor = (1.0 * size) / capacity;
        System.out.println("Load Factor : " + loadFactor);
        if(loadFactor > 0.7) {
            rehash();
        }
    }

    private void rehash() {
        System.out.println("Rehashing buckets");
        List<MapNode<K , V>> temp = bucket;
        bucket = new ArrayList<>();
        capacity *= 2;
        for(int i = 0 ; i < capacity ; i ++) {
            bucket.add(null);
        }
        size = 0;

        for(int i = 0 ; i < temp.size() ; i ++) {
            MapNode<K , V> head = temp.get(i);
            while(head != null) {
                put(head.key , head.value);
                head = head.next;
            }
        }
    }

    public void remove(K key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<K , V> head = bucket.get(bucketIndex);
        MapNode<K , V> prev = null;
        while(head != null) {
            if(head.key.equals(key)) {
                if(prev == null) {
                    bucket.set(bucketIndex, head.next);
                } else {
                    prev.next = head.next;
                }
                head.next = null;
                size --;
                break;
            }
            prev = head;
            head = head.next;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        OurMap<Integer, String> mp = new OurMap<>();
        mp.put(1, "one");
        mp.put(6, "six");
        mp.put(5, "five");
        mp.put(3, "three");
        mp.put(5, "fiivvee");
		mp.remove(3);

        System.out.println(mp.get(5));
        System.out.println(mp.get(1));
        System.out.println(mp.get(6));
        System.out.println(mp.get(3));
        System.out.println(mp.get(7));
    }
}
