import java.util.concurrent.CountDownLatch;

public class MonteCarloSimulation implements Runnable {
    private final int iterations;
    private final CountDownLatch latch;

    public MonteCarloSimulation(int iterations, CountDownLatch latch) {
        this.iterations = iterations;
        this.latch = latch;
    }

    @Override
    public void run() {
        long localHits = 0;
        for (int i = 0; i < iterations; i++) {
            double x = Math.random();
            double y = Math.random();
            if (x * x + y * y <= 1) {
                localHits++;
            }
        }

        Main.addHits(localHits);
        latch.countDown();
    }
}

