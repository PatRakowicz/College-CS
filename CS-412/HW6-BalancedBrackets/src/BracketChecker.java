import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Stack;

public class BracketChecker {
    public boolean checkBrackets(String inputFile, String outputFile) {
        Stack<Character> stack = new Stack<>();
        boolean balanced = true;

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
             FileWriter writer = new FileWriter(outputFile)) {

            String line;
            while ((line = reader.readLine()) != null) {
                for (char ch : line.toCharArray()) {
                    if (ch == '(' || ch == '[' || ch == '{') {
                        stack.push(ch);
                    } else if (ch == ')' || ch == ']' || ch == '}') {
                        if (stack.isEmpty() || !isMatchingPair(stack.pop(), ch)) {
                            balanced = false;
                            break;
                        }
                    }
                }
                if (!balanced) break;
            }

            writer.write(balanced && stack.isEmpty() ? "Brackets are balanced" : "Brackets are not balanced");
        } catch (IOException e) {
            e.printStackTrace();
            balanced = false;
        }
        return balanced;
    }

    private boolean isMatchingPair(char opening, char closing) {
        return (opening == '(' && closing == ')') ||
                (opening == '[' && closing == ']') ||
                (opening == '{' && closing == '}');
    }
}
