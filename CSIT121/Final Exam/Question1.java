
public class Question1 {
    public static void main(String[] args) {
        printNumbers(21, 29, 4);
        printNumbers(4, 12, 6);

        System.out.println(hasDuplicateChars("abcala2"));
        System.out.println(hasDuplicateChars("morning"));
        System.out.println(hasDuplicateChars("ab$wx$y"));
        System.out.println(hasDuplicateChars("35 x 12"));
        System.out.println(hasDuplicateChars("methods"));

        System.out.println(replaceWith("programming", 'r', 'R'));
        System.out.println(replaceWith("java", 'a', 'A'));
        System.out.println(replaceWith("1+2x3+4", '+', '%'));
        System.out.println(replaceWith("22 Jun 2022", ' ', '-'));

        System.out.println(countDigit(5, 0));
        System.out.println(countDigit(1, 1));
        System.out.println(countDigit(12257212, 2));
        System.out.println(countDigit(51299189, 9));
    }

    public static void printNumbers(int startNum, int endNum, int numPerLine) {
        for (int i = startNum; i <= endNum; i++) {
            System.out.print(i + " ");

            int trueCount = i - startNum + 1;

            if (trueCount != 0 && trueCount % numPerLine == 0)
                System.out.println("\n");
        }
    }

    public static boolean hasDuplicateChars(String data) {
        Boolean response = false;
        for (int i = 0; i < data.length(); i++) {
            for (int j = i + 1; j < data.length(); j++) {
                if (data.charAt(i) == data.charAt(j))
                    response = true;
            }
        }
        return response;
    }

    public static String replaceWith(String data, char ch1, char ch2) {
        if (data.length() < 1)
            return data;
        else {
            char letter = data.charAt(0);

            if (ch1 == data.charAt(0))
                letter = ch2;

            return letter + replaceWith(data.substring(1), ch1, ch2);
        }
    }

    public static int countDigit(int number, int digit) {
        if (number == 0)
            return 0;

        int nextDigit = number % 10;

        if (nextDigit == digit)
            return 1 + countDigit(number / 10, digit);

        return countDigit(number / 10, digit);
    }
}