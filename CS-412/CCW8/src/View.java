import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class View {
    public JTextField jTextField;
    private DefaultListModel<String> model;
    private JList<String> list;

    public View(ActionListener actionListener){

        JFrame jFrame = new JFrame();
        JPanel jPanel = new JPanel();
        jTextField = new JTextField(15);

        JButton jButton = new JButton("Insert");
        jButton.addActionListener(actionListener);

        model = new DefaultListModel<String>();
        list = new JList<String>(model);

        jPanel.add(jTextField);
        jPanel.add(jButton);
        jFrame.getContentPane().add(BorderLayout.NORTH, list);
        jFrame.getContentPane().add(BorderLayout.SOUTH, jPanel);
        jFrame.setSize(400,400);
        jFrame.setVisible(true);
    }

    public void displayData(ArrayList<String> data) {
        model.clear();
        for (String value : data) {
            model.addElement(value);
        }
    }
}
