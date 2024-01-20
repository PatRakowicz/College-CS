public class Circle extends Shape {

    @Override
    public double area() {
        return Math.PI * getSize() * getSize();
    }

    @Override
    public double perimeter() {
        return 2 * Math.PI * getSize();
    }
}
