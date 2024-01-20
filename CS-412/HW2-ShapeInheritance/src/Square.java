public class Square extends Shape {

    @Override
    public double area() {
        return getSize() * getSize();
    }

    @Override
    public double perimeter() {
        return 4 * getSize();
    }
}