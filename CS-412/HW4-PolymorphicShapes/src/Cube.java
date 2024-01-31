public class Cube extends Shape3D {

    public Cube(int size) {
        super("Cube", size);
    }

    @Override
    public double volume() {
        return Math.pow(size, 3);
    }

    @Override
    public double surfaceArea() {
        return 6 * size * size;
    }

    @Override
    public String toString() {
        return String.format("3D shape cube: size = %d, volume = %.2f, surface area = %.2f",
                size, volume(), surfaceArea());
    }
}
