public class Sphere extends Shape3D {

    public Sphere(int size) {
        super("Sphere", size);
    }

    @Override
    public double volume() {
        return (4.0 / 3) * Math.PI * Math.pow(size, 3);
    }

    @Override
    public double surfaceArea() {
        return 4 * Math.PI * size * size;
    }

    @Override
    public String toString() {
        return String.format("3D shape sphere: size = %d, volume = %.2f, surface area = %.2f",
                size, volume(), surfaceArea());
    }
}
