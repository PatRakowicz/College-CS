import java.util.List;

public class StudentController {
    private StudentModel model;
    private StudentView view;

    public StudentController(StudentModel model, StudentView view) {
        this.model = model;
        this.view = view;
        initView();
    }

    public void initView() {
        model.createTable();
        updateStudentList();
    }

    public void updateStudentList() {
        List<String> students = model.getAllStudents();
        view.updateStudentList(students);
    }

    //CRUD Operations
    public void updateStudent(int id, String name, int age) {
        model.updateStudent(id, name, age);
        updateStudentList();
    }

    public void deleteStudent(int id) {
        model.deleteStudent(id);
        updateStudentList();
    }

    public void createStudent(String name, int age) {
        model.createStudent(name, age);
        updateStudentList();
    }
}
