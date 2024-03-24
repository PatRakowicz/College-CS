// Created by Pat Rako

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of threads (1-1000):");
        int T = scanner.nextInt();
        System.out.println("Enter the number of iterations per thread (1-100000):");
        int N = scanner.nextInt();

        if (T <= 0 || T > 1000 || N <= 0 || N > 100000) {
            System.out.println("Error: Invalid input. Number of threads must be between 1 and 1000 and number of iterations must be between 1 and 100000.");
            return;
        }

        PiEstimator piEstimator = new PiEstimator();
        piEstimator.runSimulation(T, N);

        double piEstimate = piEstimator.getPiEstimate(T * N);
        System.out.printf("Estimate of Pi: %.10f%n", piEstimate);

        scanner.close();
    }
}
