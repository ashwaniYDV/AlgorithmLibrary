// https://www.geeksforgeeks.org/java-and-multiple-inheritance/
// https://youtu.be/0pCyqDAGafY



// Example 1:

// Java program to demonstrate Multiple Inheritance through default methods

// Interface 1
interface PI1 {

	// Default method
	default void show() {

		// Print statement if method is called from interface 1
		System.out.println("Default PI1");
	}
}

// Interface 2
interface PI2 {

	// Default method
	default void show() {

		// Print statement if method is called from interface 2
		System.out.println("Default PI2");
	}
}

// Main class
// Implementation class code
class TestClass implements PI1, PI2 {

	// Overriding default show method
	public void show() {

		// Using super keyword to call the show method of PI1 interface
		PI1.super.show();

		// Using super keyword to call the show method of PI2 interface
		PI2.super.show();
	}

	// Mai driver method
	public static void main(String args[]) {

		// Creating object of this class in main() method
		TestClass d = new TestClass();
		d.show();
	}
}






















// Example 2

import java.io.*;
import java.util.*;

interface Lion {
    // Abstract method
    void displayLion();

    //Default method
    default void roars() {
        System.out.println("Lion Roars.");
    }
}

interface Tiger {
    // Abstract method
    void displayTiger();

    //Default method
    default void roars() {
        System.out.println("Tiger Roars.");
    }

}



class Liger implements Lion, Tiger {
    Liger() {
        System.out.println("Liger constructor.");
    }

    @Override
    public void displayLion() {
        System.out.println("Display lion");
    }

    @Override
    public void displayTiger() {
        System.out.println("Display tiger");
    }

    @Override
    public void roars() {
        Lion.super.roars();
        Tiger.super.roars();
    }
}

public class Main {
    public static void main(String[] args) {
        Liger liger = new Liger();
        liger.roars();
    }
}
