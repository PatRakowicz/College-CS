import java.util.ArrayList;

public class StudentModel {
    private int id;
    private String name;
    private int age;

    // Constructors
    public StudentModel() {}

    public StudentModel(int id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }

    // Getters and Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    // Database Operations (Simplified)
    public static ArrayList<StudentModel> getAllStudents() {
        // This should connect to your database and return a list of all students
        // For simplification, returning an empty list
        return new ArrayList<>();
    }

    public void save() {
        // This method should insert a new student into the database or update an existing one
        // Simplified as a placeholder
    }

    public void delete() {
        // This method should delete a student from the database
        // Simplified as a placeholder
    }
}
