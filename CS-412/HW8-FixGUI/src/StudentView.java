import javax.swing.*;
import java.awt.*;
import java.util.List;

public class StudentView {
    private JFrame jFrame;
    private JTabbedPane jTabs;
    private DefaultListModel<String> listModel;
    private StudentController controller;

    public void setController(StudentController controller) {
        this.controller = controller;
    }

    public StudentView() {
        listModel = new DefaultListModel<>();
        jFrame = new JFrame();
        jTabs = new JTabbedPane();

        jTabs.add("CREATE", makeCreateTab());
        jTabs.add("READ", makeReadTab());
        jTabs.add("UPDATE", makeUpdateTab());
        jTabs.add("DELETE", makeDeleteTab());

        jFrame.add(jTabs);
        jFrame.setSize(500, 500);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jFrame.setVisible(true);
    }

    public void updateStudentList(List<String> students) {
        listModel.clear();
        for (String student : students) {
            listModel.addElement(student);
        }
    }

    //Tabs
    private JPanel makeUpdateTab() {
        JPanel jPanel = new JPanel();
        JList<String> jList = new JList<>(listModel);
        jList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

        jPanel.add(jList);

        JPanel inner = new JPanel();
        inner.setLayout(new GridLayout(2, 2));
        JTextField textFieldName = new JTextField(10);
        JTextField textFieldAge = new JTextField(10);
        inner.add(new JLabel("NAME:"));
        inner.add(textFieldName);
        inner.add(new JLabel("AGE:"));
        inner.add(textFieldAge);

        jPanel.add(inner);

        JButton jButton = new JButton("UPDATE");
        jButton.setEnabled(false);

        jButton.addActionListener(e -> {
            String selectedValue = jList.getSelectedValue();
            if (selectedValue != null && !selectedValue.isEmpty()) {
                String[] parts = selectedValue.split("\\s+");
                try {
                    int id = Integer.parseInt(parts[0]);
                    String name = textFieldName.getText();
                    int age = Integer.parseInt(textFieldAge.getText());
                    controller.updateStudent(id, name, age);
                } catch (NumberFormatException ex) {
                    ex.printStackTrace();
                }
            }
        });

        jButton.addActionListener(e -> {
            int id = jList.getSelectedIndex();
            if (id != -1) {
                String name = textFieldName.getText();
                int age;
                try {
                    age = Integer.parseInt(textFieldAge.getText());
                } catch (NumberFormatException ex) {
                    ex.printStackTrace();
                    return; // Exit if the age is not a number
                }
                controller.updateStudent(id, name, age);
            }
        });

        jPanel.add(jButton);
        return jPanel;
    }

    public JPanel makeReadTab() {
        JPanel jPanel = new JPanel();
        JList<String> jList = new JList<>(listModel);
        jPanel.add(new JScrollPane(jList));
        return jPanel;
    }

    public JPanel makeDeleteTab() {
        JPanel jPanel = new JPanel();
        JList<String> jList = new JList<>(listModel);
        jList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        jPanel.add(new JScrollPane(jList)); // Wrap the JList in a JScrollPane for better usability

        JButton jButton = new JButton("DELETE");
        jButton.addActionListener(e -> {
            int i = jList.getSelectedIndex();
            if (i != -1) { // Make sure an item is selected
                String s = jList.getSelectedValue();
                String[] words = s.trim().split("\\s+"); // Adjusted regex to split on one or more whitespace
                int id = Integer.parseInt(words[0]);
                // Call controller to handle the deletion
                controller.deleteStudent(id);
            }
        });
        jPanel.add(jButton);
        return jPanel;
    }

    public JPanel makeCreateTab() {
        JPanel jPanel = new JPanel();
        jPanel.setLayout(new GridLayout(3, 2));
        JTextField textFieldName = new JTextField(20);
        JTextField textFieldAge = new JTextField(10);
        jPanel.add(new JLabel("NAME:"));
        jPanel.add(textFieldName);
        jPanel.add(new JLabel("AGE:"));
        jPanel.add(textFieldAge);

        JButton createButton = new JButton("CREATE");
        createButton.addActionListener(e -> {
            String name = textFieldName.getText();
            try {
                int age = Integer.parseInt(textFieldAge.getText());
                controller.createStudent(name, age); // Use the controller to create a new student
            } catch (NumberFormatException ex) {
                ex.printStackTrace(); // Handle invalid age input
            }
        });
        jPanel.add(createButton);
        return jPanel;
    }
}
