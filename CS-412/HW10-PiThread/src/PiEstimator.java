// Created by Pat Rako

import java.util.concurrent.CountDownLatch;

public class PiEstimator {

    private long hits = 0;
    private final Object lock = new Object();

    public void runSimulation(int numberOfThreads, int iterations) {
        CountDownLatch latch = new CountDownLatch(numberOfThreads);

        for (int i = 0; i < numberOfThreads; i++) {
            new Thread(new MonteCarloSimulation(iterations, latch, this)).start();
        }

        try {
            latch.await();
        } catch (InterruptedException e) {
            System.err.println("Main thread interrupted.");
        }
    }

    public void addHits(long localHits) {
        synchronized (lock) {
            hits += localHits;
        }
    }

    public double getPiEstimate(int totalIterations) {
        return 4.0 * hits / totalIterations;
    }
}
