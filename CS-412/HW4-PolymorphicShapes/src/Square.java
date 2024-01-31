public class Square extends Shape2D {

    public Square(int size) {
        super("Square", size);
    }

    @Override
    public double area() {
        return size * size;
    }

    @Override
    public double perimeter() {
        return 4 * size;
    }

    @Override
    public String toString() {
        return String.format("2D shape square: size = %d, area = %.2f, perimeter = %.2f",
                size, area(), perimeter());
    }
}
