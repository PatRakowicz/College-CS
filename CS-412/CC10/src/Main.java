import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Thread> t =new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            Thread thread = new Thread(new Runnable() {
                @Override
                public void run() {
                    System.out.println("Howdy");
                }
            });
            t.add(thread);
            thread.start();
        }

        for (Thread th : t) {
            try {
                th.join();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
        System.out.println("Main");
    }
}