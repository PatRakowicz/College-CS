import java.util.concurrent.CountDownLatch;

public class Main {
    private static long hits = 0;
    private static final Object lock = new Object();

    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Usage: java PiEstimator <number of threads> <number of iterations per thread>");
            System.exit(1);
        }

        int T = Integer.parseInt(args[0]);
        int N = Integer.parseInt(args[1]);

        if (T <= 0 || T > 1000 || N <= 0 || N > 100000) {
            System.err.println("Error: Number of threads must be between 1 and 1000 and number of iterations must be between 1 and 100000");
            System.exit(1);
        }

        CountDownLatch latch = new CountDownLatch(T);

        for (int i = 0; i < T; i++) {
            new Thread(new MonteCarloSimulation(N, latch)).start();
        }

        try {
            latch.await();
        } catch (InterruptedException e) {
            System.err.println("Main thread interrupted.");
        }

        double piEstimate = 4 * (double) hits / (T * (long) N);
        System.out.printf("Estimate of Pi: %.10f%n", piEstimate);
    }

    public static synchronized void addHits(long localHits) {
        hits += localHits;
    }
}