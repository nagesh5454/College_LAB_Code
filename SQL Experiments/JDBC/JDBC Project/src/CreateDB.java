import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class CreateDB {

    static final String URL = "jdbc:mysql://localhost:3306/dbatu";
    static final String USER = "root";
    static final String PASS = "Nagesh@8805831382";

    public static void main(String[] args) {
        try (Connection conn = DriverManager.getConnection(URL, USER, PASS);
                Statement stmt = conn.createStatement();) {
            String sql = "Create Database dbatu";
            stmt.executeUpdate(sql);
            System.out.println("Database created Successfully...");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}