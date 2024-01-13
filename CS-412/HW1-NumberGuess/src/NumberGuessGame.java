import java.util.Random;

public class NumberGuessGame {
    private final int magicNumber;

    public NumberGuessGame() {
        Random random = new Random();
        magicNumber = random.nextInt(101); // Generates a number between 0 and 100
    }

    public String checkGuess(int userGuess) {
        if (userGuess == magicNumber) {
            return "correct";
        } else if (userGuess < magicNumber) {
            return "too low";
        } else {
            return "too high";
        }
    }
}
