import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class Controller {
    private final View view;
    private final Model model;

    public Controller() {
        view = new View();
        model = new Model();

        view.addButtonListener(new AddButtonActionListener());
        view.deleteButtonListener(new DeleteButtonActionListener());
    }

    private class AddButtonActionListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String item = view.getInputText();
            if (!item.isEmpty()) {
                model.addData(item);
                view.addToList(item);
            }
        }
    }

    private class DeleteButtonActionListener implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            String selectedItem = view.getSelectedValue();
            if (selectedItem != null) {
                model.removeData(selectedItem);
                view.removeFromList(selectedItem);
            }
        }
    }
}
