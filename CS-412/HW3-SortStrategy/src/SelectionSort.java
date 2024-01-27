public class SelectionSort extends Sort {
    public SelectionSort() {
        this.name = "SelectionSort";
    }

    @Override
    public void sortData() {
        startTimer();
        int n = data.length;

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                swap(i, minIndex);
            }
        }
        stopTimer();
    }
}
