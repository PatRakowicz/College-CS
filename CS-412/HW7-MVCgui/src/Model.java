import java.util.ArrayList;

class Model {
    private final ArrayList<String> data;

    public Model() {
        data = new ArrayList<>();
    }

    public void addData(String item) {
        data.add(item);
    }

    public void removeData(String item) {
        data.remove(item);
    }

    public ArrayList<String> getData() {
        return data;
    }
}