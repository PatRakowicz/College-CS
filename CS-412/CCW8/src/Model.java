import javax.swing.plaf.nimbus.State;
import javax.xml.transform.Result;
import java.sql.*;
import java.util.ArrayList;
import java.sql.SQLException;
import java.sql.Connection;

public class Model {
    Connection connect = null;

    public Model() {
        try {
            connect = DriverManager.getConnection("jdbc:sqlite:main.db");
            System.out.print("Connected");

            Statement stmt = connect.createStatement();
            String cmd = "CREATE TABLE IF NOT EXISTS cats (" +
                    "id INTEGER PRIMARY KEY," +
                    "name STRING" +
                    ");";

            stmt.execute(cmd);
            connect.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public ArrayList<String> fetchData() {
        ArrayList<String> data = new ArrayList<String>();
        try {
            String search = "SELECT name FROM cat;";
            Statement stmt = connect.createStatement();

            ResultSet resultSet = stmt.executeQuery(search);
            while (resultSet.next()) {
                String name = resultSet.getString("name");
                data.add(name);
            }
//            connect.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return data;
    }

    public void addRecord(String record) {
        String insert = "INSERT INTO cats(name) VALUES(?);";
        try {
            PreparedStatement preparedStatement = connect.prepareStatement(insert);
            preparedStatement.setString(1, record);
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
