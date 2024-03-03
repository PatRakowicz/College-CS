import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class StudentModel {

    private Connection connect() throws SQLException {
        return DriverManager.getConnection("jdbc:sqlite:database.db");
    }

    public void createTable() {
        String cmd = "CREATE TABLE IF NOT EXISTS students (" +
                "id INTEGER PRIMARY KEY," +
                "name STRING," +
                "age INTEGER);";
        try (Connection conn = connect();
             Statement stmt = conn.createStatement()) {
            stmt.executeUpdate(cmd);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<String> getAllStudents() {
        List<String> students = new ArrayList<>();
        String cmd = "SELECT * FROM students;";
        try (Connection conn = connect();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(cmd)) {
            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                int age = rs.getInt("age");
                String student = String.format("%3d %10s %3d", id, name, age);
                students.add(student);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return students;
    }

    // CRUD Operations
    public void updateStudent(int id, String name, int age) {
        String cmd = String.format("UPDATE students SET name = '%s', age = %d WHERE id = %d;", name, age, id);
        try (Connection conn = connect();
             Statement stmt = conn.createStatement()) {
            stmt.executeUpdate(cmd);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void deleteStudent(int id) {
        String cmd = String.format("DELETE FROM students WHERE id = %d;", id);
        try (Connection conn = connect();
             Statement stmt = conn.createStatement()) {
            stmt.executeUpdate(cmd);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void createStudent(String name, int age) {
        String cmd = String.format("INSERT INTO students (name, age) VALUES ('%s', %d);", name, age);
        try (Connection conn = connect();
             Statement stmt = conn.createStatement()) {
            stmt.executeUpdate(cmd);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
