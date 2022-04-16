// Name: Gavin Tan
// File name: GavinTan_A1.java
// This is my own work and i have not passed my program to friends.
// I hereby declare that this is my own work and willing to accept whatever penalty given to me.
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Random;
import java.util.logging.Logger;

public class GavinTan_A1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean run = true;

        while (run) {
            System.out.println("Candidate Id:");
            String candidateId = input.nextLine();
            
            System.out.println("Name:");
            String candidateName = input.nextLine();
    
            System.out.println("Test 1 score:");
            int test1 = Integer.parseInt(input.nextLine());
            
            System.out.println("Test 2 score:");
            int test2 = Integer.parseInt(input.nextLine());
            
            System.out.println("Enter another record? (y/n)");
            String response = input.nextLine().toLowerCase();

            if (response.equals("n")) run = false;
        }
    }
}

class TestResult {
    
}