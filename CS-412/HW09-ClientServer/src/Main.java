import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Server.main(args);
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
        }).start();

        ClientGUI.main(args);
    }
}