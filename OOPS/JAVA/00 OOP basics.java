import java.io.*;
import java.util.*;

interface TestInterface {
    // Abstract method
    void display();
    // Abstract method
    void fun();

    // Constant variable
    String name = "no name";

    // Static method
    static void staticmethod() {
        System.out.println("static method");
    }

    //Default method
    default void defaultmethod() {
        System.out.println("default method");
    }

}

enum Gender {
    NONE,
    MALE,
    FEMALE;
}

class Car {
    private String carName;
    private String carModel;
    Car() {

    }
    Car(String carName, String carModel) {
        this.carName = carName;
        this.carModel = carModel;
    }
    String getCarModel() {
        return carModel;
    }
    String getCarName() {
        return carName;
    }
}

abstract class Person implements TestInterface {
    public static int count;
    private String name;
    private int age;
    private Gender gender;
    private Car car;

    Person() {
        count++;
        name = "noname";
        age = 0;
        gender = Gender.NONE;
        car = new Car();
        // defaultmethod();
        // TestInterface.staticmethod();
    }

    Person(String name, int age, Gender gender, Car car) {
        this();
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.car = car;
    }

    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int a) {
        this.age = a;
    }
    public void setGender(Gender gender) {
        this.gender = gender;
    }
    public void setCar(Car car) {
        this.car = car;
    }
    public void display() {
        System.out.println("Name = " + name + ". Age = " + age + ". Gender = " + gender);
        System.out.println("MyCarName = " + car.getCarName() + ". MyCarModel = " + car.getCarModel());
        System.out.println();
    }

    public void fun() {
        System.out.println("fun parent");
    }
}

class Developer extends Person {
    Developer() {
        super();
    }
    Developer(String name, int age, Gender gender, Car car) {
        super(name, age, gender, car);
    }
    public void fun() {
        System.out.println("fun child");
    }
}

public class Main {
    public static void main(String[] args) {
        Developer a = new Developer("a", 12, Gender.MALE, new Car("carname1", "carmodel1"));
        a.display();

        Developer b = new Developer("b", 12, Gender.FEMALE, new Car("carname2", "carmodel2"));
        b.display();

        Person c = new Developer("c", 12, Gender.FEMALE, new Car("carname3", "carmodel3"));
        c.display();

        a.fun();

        System.out.println(Person.count);
    }
}
