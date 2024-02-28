import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class Controller implements ActionListener {
    View view;
    Model model;

    public Controller(){
        view = new View(this);
        model = new Model();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String record = view.jTextField.getText();
        model.addRecord(record);
        view.displayData(model.fetchData());
    }

}
