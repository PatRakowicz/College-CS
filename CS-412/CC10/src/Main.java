public class Main {
    public static void main(String[] args) {
        new Main().go();
    }

    public void go() {
        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                for(int i = 0; i< 10; i ++) {
                    System.out.println("Thread: " + i + " | Howdy");
                }
            }
        });
        thread.start();
    }
}