
import java.util.Scanner;

public class AboutScanner {
    public static void main (String[] args) {
        aboutNext();
    }

    public static void aboutNext() {
        Scanner kboard = new Scanner(System.in);
        System.out.println("Name");

        String name = kboard.next();
        System.out.println(name);
    }

}
