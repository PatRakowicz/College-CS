public abstract class Shape2D extends Shape implements TwoDimensional {

    public Shape2D(String type, int size) {
        super(type, size);
    }

    @Override
    public String toString() {
        return "Shape2D{type='" + type + "', size=" + size + "}";
    }
}
