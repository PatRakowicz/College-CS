public class ThreadArg implements Runnable {
    private final String message;

    public ThreadArg(String message) {
        this.message = message;
    }

    @Override
    public void run() {
        System.out.println(message);
    }
}
