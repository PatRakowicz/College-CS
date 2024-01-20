public class Triangle extends Shape {

    @Override
    public double area() {
        return (Math.sqrt(3) / 4) * getSize() * getSize();
    }

    @Override
    public double perimeter() {
        return 3 * getSize();
    }
}
