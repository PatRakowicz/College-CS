import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    public static void main(String[] args) {
        try {
            Socket chat = new Socket("127.0.0.1", 5001);

            System.out.print("Enter Text: ");
            InputStreamReader inputStreamReader = new InputStreamReader(System.in);
            BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

            String msg = bufferedReader.readLine();
            System.out.print("Input: " + msg);

            PrintWriter printWriter = new PrintWriter(chat.getOutputStream());
            printWriter.println(msg);
            printWriter.flush();

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
