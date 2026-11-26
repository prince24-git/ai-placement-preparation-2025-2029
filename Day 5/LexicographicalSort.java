import java.util.Scanner;

public class LexicographicalSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of strings: ");
        if (!scanner.hasNextInt()) {
            System.err.println("Enter a positive count.");
            return;
        }
        int n = scanner.nextInt();
        scanner.nextLine();
        if (n < 1) {
            System.err.println("Enter a positive count.");
            return;
        }

        String[] strings = new String[n];
        System.out.println("Enter each string on a new line:");
        for (int i = 0; i < n; i++) strings[i] = scanner.nextLine();

        for (int end = n - 1; end > 0; end--) {
            boolean swapped = false;
            for (int i = 0; i < end; i++) {
                if (strings[i].compareTo(strings[i + 1]) > 0) {
                    String temporary = strings[i];
                    strings[i] = strings[i + 1];
                    strings[i + 1] = temporary;
                    swapped = true;
                }
            }
            if (!swapped) break;
        }

        System.out.println("Strings in lexicographical order:");
        for (String value : strings) System.out.println(value);
        scanner.close();
    }
}
