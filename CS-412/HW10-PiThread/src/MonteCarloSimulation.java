import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ThreadLocalRandom;

// Using threadlocalrandom insdead of math.random, seems to have better accuracy then math.random

public class MonteCarloSimulation implements Runnable {
    private final int iterations;
    private final CountDownLatch latch;
    private final PiEstimator piEstimator;

    public MonteCarloSimulation(int iterations, CountDownLatch latch, PiEstimator piEstimator) {
        this.iterations = iterations;
        this.latch = latch;
        this.piEstimator = piEstimator;
    }

    @Override
    public void run() {
        long localHits = 0;
        for (int i = 0; i < iterations; i++) {
            double x = ThreadLocalRandom.current().nextDouble();
            double y = ThreadLocalRandom.current().nextDouble();
            if (x * x + y * y <= 1) {
                localHits++;
            }
        }

        piEstimator.addHits(localHits);
        latch.countDown();
    }
}
