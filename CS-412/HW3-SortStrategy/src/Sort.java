public abstract class Sort {
    protected int[] data;
    protected String name;
    protected long startTime;
    protected long stopTime;

    public abstract void sortData();

    public void printData() {
        if (data != null) {
            for (int element : data) {
                System.out.println(element);
            }
        } else {
            System.out.println("Data array is null.");
        }
    }

    public boolean isSorted() {
        for (int i = 0; i < data.length - 1; i++) {
            if (data[i] > data[i + 1]) {
                return false;
            }
        }
        return true;
    }

    protected void swap(int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    public long getRuntime() {
        return stopTime - startTime;
    }

    protected void startTimer() {
        startTime = System.nanoTime();
    }

    protected void stopTimer() {
        stopTime = System.nanoTime();
    }

    public int[] getData() {
        return data;
    }

    public void setData(int[] data) {
        this.data = data;
    }

    public String getName() {
        return name;
    }
}
