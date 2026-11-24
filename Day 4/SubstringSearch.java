import java.util.Scanner;

public class SubstringSearch {
    private static int[] buildLps(String pattern) {
        int[] lps = new int[pattern.length()];
        int prefixLength = 0;

        for (int i = 1; i < pattern.length();) {
            if (pattern.charAt(i) == pattern.charAt(prefixLength)) {
                lps[i++] = ++prefixLength;
            } else if (prefixLength != 0) {
                prefixLength = lps[prefixLength - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }

    private static boolean containsSubstring(String text, String pattern) {
        if (pattern.isEmpty()) return true;
        if (pattern.length() > text.length()) return false;

        int[] lps = buildLps(pattern);
        int i = 0; // index in text
        int j = 0; // index in pattern

        while (i < text.length()) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
                if (j == pattern.length()) return true;
            } else if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the main string: ");
        String text = scanner.nextLine();
        System.out.print("Enter the substring to find: ");
        String pattern = scanner.nextLine();

        System.out.println(containsSubstring(text, pattern)
                ? "Substring found"
                : "Substring not found");
        scanner.close();
    }
}
