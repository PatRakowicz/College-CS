public abstract class Shape3D extends Shape implements ThreeDimensional {

    public Shape3D(String type, int size) {
        super(type, size);
    }

    @Override
    public String toString() {
        return "Shape3D{type='" + type + "', size=" + size + "}";
    }
}
