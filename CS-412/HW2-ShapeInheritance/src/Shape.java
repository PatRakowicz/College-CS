public abstract class Shape {
    private String type;
    private int size;

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public abstract double area();

    public abstract double perimeter();

    public void print() {
        System.out.println(
                type + " of size "
                        + size + " has area "
                        + String.format("%.2f", area())
                        + ", perimeter "
                        + String.format("%.2f", perimeter()));
    }
}
