<?php
class View {
    function render($viewName, $data = array()) {
        extract($data);
        include('views/' . $viewName . '.php');
    }
}
