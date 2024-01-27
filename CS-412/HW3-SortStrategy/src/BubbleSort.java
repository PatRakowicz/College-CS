public class BubbleSort extends Sort {
    public BubbleSort() {
        this.name = "BubbleSort";
    }

    @Override
    public void sortData() {
        startTimer();
        boolean swapped;
        do {
            swapped = false;
            for (int i = 0; i < data.length - 1; i++) {
                if (data[i] > data[i + 1]) {
                    swap(i, i + 1);
                    swapped = true;
                }
            }
        } while (swapped);
        stopTimer();
    }
}
