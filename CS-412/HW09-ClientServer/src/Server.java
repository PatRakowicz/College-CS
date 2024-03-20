import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws IOException {

        try (ServerSocket serverSocket = new ServerSocket(5000)) {
            System.out.println("Server started. Listening on port 5000.");
            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected.");

                try (BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                     PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)) {

                    String inputLine;
                    while ((inputLine = in.readLine()) != null) {
                        if ("EOF".equals(inputLine)) {
                            break;
                        }

                        try {
                            double result = processOperation(inputLine);
                            out.println(result);
                        } catch (Exception e) {
                            out.println("Error: " + e.getMessage());
                        }
                    }
                } finally {
                    clientSocket.close();
                    System.out.println("Client disconnected.");
                }
            }
        }
    }

    private static double processOperation(String input) throws Exception {
        String[] parts = input.split(" ");
        if (parts.length != 3) {
            throw new IllegalArgumentException("Invalid format");
        }

        double x = Double.parseDouble(parts[0]);
        double y = Double.parseDouble(parts[2]);
        String op = parts[1];

        return switch (op) {
            case "+" -> x + y;
            case "-" -> x - y;
            case "*" -> x * y;
            case "/" -> {
                if (y == 0) throw new IllegalArgumentException("Cannot divide by zero");
                yield x / y;
            }
            case "^" -> Math.pow(x, y);
            case "%" -> x % y;
            default -> throw new IllegalArgumentException("Invalid operator");
        };
    }
}
