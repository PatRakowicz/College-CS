public abstract class Shape {
    protected String type;
    protected int size;

    public Shape(String type, int size) {
        this.type = type;
        this.size = size;
    }

    public abstract String toString();
}
