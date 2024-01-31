public class Circle extends Shape2D {
    public Circle(int size) {
        super("Circle", size);
    }

    @Override
    public double area() {
        return Math.PI * size * size;
    }

    @Override
    public double perimeter() {
        return 2 * Math.PI * size;
    }

    @Override
    public String toString() {
        return String.format("2D shape circle: size = %d, area = %.2f, perimeter = %.2f",
                size, area(), perimeter());
    }
}
