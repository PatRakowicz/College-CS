<?php
require_once('./model.php');
include('./views/top.php');


if (isset ($_POST['action'])) {
    if ($_POST['action'] == 'create') {
        $username = $_POST['username'];
        $password = $_POST['password'];
        createUser($username, $password);
    }
}

$users = getAllUsers();

