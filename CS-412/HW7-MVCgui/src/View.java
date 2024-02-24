import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

class View {
    private final DefaultListModel<String> listModel;
    private final JList<String> list;
    private final JTextField input;
    private final JButton addButton;
    private final JButton deleteButton;

    public View() {
        JFrame frame = new JFrame("MVC Example");
        listModel = new DefaultListModel<>();
        list = new JList<>(listModel);
        input = new JTextField(20);
        addButton = new JButton("Add");
        deleteButton = new JButton("Delete");

        frame.setLayout(new FlowLayout());
        frame.add(input);
        frame.add(addButton);
        frame.add(new JScrollPane(list));
        frame.add(deleteButton);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

    public void addButtonListener(ActionListener al) {
        addButton.addActionListener(al);
    }

    public void deleteButtonListener(ActionListener al) {
        deleteButton.addActionListener(al);
    }

    public String getInputText() {
        return input.getText();
    }

    public String getSelectedValue() {
        return list.getSelectedValue();
    }

    public void addToList(String item) {
        listModel.addElement(item);
    }

    public void removeFromList(String item) {
        listModel.removeElement(item);
    }
}
