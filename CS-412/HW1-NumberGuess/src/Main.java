import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        NumberGuessGame game = new NumberGuessGame();
        int inputLine = 0;

        while (true) {
            try {
                System.out.print("Enter your guess b/t 0 100: ");

                InputStreamReader inputStreamReader = new InputStreamReader(System.in);
                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
                inputLine = Integer.parseInt(bufferedReader.readLine());

            } catch (IOException e) {
                System.err.println(e);
            }

//            System.out.println(inputLine);
            String result = game.checkGuess(inputLine);

            if ("correct".equals(result)) {
                System.out.println("Congratulations! You guessed the number correctly!");
                break;
            } else {
                System.out.println("Your guess is " + result + ". Try again.");
            }
        }
    }
}