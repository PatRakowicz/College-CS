import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter input file path:");
        String inputFile = scanner.nextLine();
        System.out.println("Enter output file path:");
        String outputFile = scanner.nextLine();
        scanner.close();

        BracketChecker bracketChecker = new BracketChecker();
        boolean result = bracketChecker.checkBrackets(inputFile, outputFile);

        System.out.println("Bracket check completed. Result: " + (result ? "Balanced" : "Not Balanced"));
    }
}