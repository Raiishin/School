import java.util.ArrayList;
import java.util.Scanner;

public class T01_GavinTan_A1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<TestResult> arr = new ArrayList<TestResult>();

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

            TestResult results = new TestResult(candidateId, candidateName, test1, test2);
            results.getOverallScore();
            results.getGrade();

            arr.add(results);

            System.out.println("Enter another record? (y/n)");
            String response = input.nextLine().toLowerCase();

            if (response.equals("n")) run = false;
        }

        System.out.println("1 Search test result by applicant Id");
        System.out.println("2 Search test result(s) by applicant name");
        System.out.println("3 Search test result(s) by overall score");
        System.out.println("4 Show test result(s) with highest overall score");
        System.out.println("5 Show failure list");
        System.out.println("6 Quit");
        System.out.println("Your selection?");

        String response = input.nextLine();
        boolean result = false;

        switch(response) {
            case "1":
                System.out.println("Enter applicant Id: ");
                String id = input.nextLine();

                for (int count = 0; count < arr.size(); count++) {
                    if (arr.get(count).compareId(id)) {
                        System.out.println(arr.get(count));
                        result = true;
                    }
                }

                if (result == false) System.out.println("No such Id can be found");

                break;
            case "2":
                System.out.println("Enter applicant name: ");
                String name = input.nextLine();
                
                for (int count = 0; count < arr.size(); count++) {
                    if (arr.get(count).name.equals(name)) {
                        System.out.println(arr.get(count));
                        result = true;
                    }
                }

                if (result == false) System.out.println("No such name can be found");

                break;
            case "3":
                System.out.println("Enter lower bound for overall score: ");
                int lowerBound = Integer.parseInt(input.nextLine());
                
                System.out.println("Enter upper bound for overall score: ");
                int upperBound = Integer.parseInt(input.nextLine());

                for (int count = 0; count < arr.size(); count++) {
                    if (lowerBound <= arr.get(count).overallScore && arr.get(count).overallScore <= upperBound) {
                        System.out.println(arr.get(count));
                        result = true;
                    }
                }

                if (result == false) System.out.println("No test results can be found within the specified range");

                break;
            case "4":
                int highestScore = 0;

                for (int count = 0; count < arr.size(); count++) { 
                    if (arr.get(count).overallScore > highestScore) highestScore = arr.get(count).overallScore;
                }

                for (int count = 0; count < arr.size(); count++) {
                    if (arr.get(count).overallScore == highestScore) {
                        System.out.println(arr.get(count));
                        result = true;
                    }
                }

                if (result == false) System.out.println("No test results can be found within the specified range");
                
                break;
            case "5":
                for (int count = 0; count < arr.size(); count++) { 
                    if (arr.get(count).grade.equals("Fail")) {
                        System.out.println(arr.get(count));
                        result = true;
                    }
                }

                if (result == false) System.out.println("No test results can be found within the specified range");
                
                break;
            default: // Quit
                break;
        }
    }
}

class TestResult {
    String id, name, grade;
    int score1, score2, overallScore;

    public TestResult(String candidateId, String candidateName, int test1, int test2) {
        id = candidateId;
        name = candidateName;
        score1 = test1;
        score2 = test2;
    }

    int getOverallScore () {
        overallScore = (int) ((score1 * 0.4) + (score2 * 0.6));
        return overallScore;
    }

    String getGrade () {
        if (overallScore >= 75) grade = "Good";
        else if (overallScore >= 50) grade = "Pass";
        else grade = "Fail";
        return grade;
    }

    boolean compareId (String compareId) {
        if (id.equals(compareId)) return true;
        else return false;
    }

    @Override
    public String toString () {
        return "Candidate " + id + " " + name + " scored an overall score of " + overallScore;
    }
}