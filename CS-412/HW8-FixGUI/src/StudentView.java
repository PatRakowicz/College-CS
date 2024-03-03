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

        jPanel.add(new JScrollPane(jList));

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

        jList.addListSelectionListener(e -> {
            if (!e.getValueIsAdjusting() && jList.getSelectedIndex() != -1) {
                String selectedValue = jList.getSelectedValue();
                String[] parts = selectedValue.trim().split("\\s+", 4);
                if (parts.length >= 3) {
                    textFieldName.setText(parts[1]);
                    textFieldAge.setText(parts[2]);
                    jButton.setEnabled(true);
                }
            }
        });

        // Action listener for the update button
        jButton.addActionListener(e -> {
            String selectedValue = jList.getSelectedValue();
            if (selectedValue != null && !selectedValue.isEmpty()) {
                String[] parts = selectedValue.trim().split("\\s+", 4);
                try {
                    int id = Integer.parseInt(parts[0]);
                    String name = textFieldName.getText();
                    int age = Integer.parseInt(textFieldAge.getText());
                    controller.updateStudent(id, name, age);
                    controller.updateStudentList();
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(jPanel, "Invalid input. Please enter a valid age.", "Error", JOptionPane.ERROR_MESSAGE);
                }
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
        jPanel.add(new JScrollPane(jList));

        JButton jButton = new JButton("DELETE");
        jButton.addActionListener(e -> {
            int i = jList.getSelectedIndex();
            if (i != -1) {
                String s = jList.getSelectedValue();
                String[] words = s.trim().split("\\s+");
                int id = Integer.parseInt(words[0]);
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
                controller.createStudent(name, age);
            } catch (NumberFormatException ex) {
                ex.printStackTrace();
            }
        });
        jPanel.add(createButton);
        return jPanel;
    }
}
