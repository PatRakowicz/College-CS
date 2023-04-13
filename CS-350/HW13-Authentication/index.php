<?php
require_once ('model.php');
require_once ('view/header.php');

$action = $_GET['action'] ?? 'home';

switch ($action) {
    case 'home':
        $users = (new Model)->getAllUsers();
        require('view/home.php');
        break;

    case 'create_user':
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $username = $_POST['username'];
            $password = $_POST['password'];
            $result = (new Model)->createUser($username, $password);
            if ($result === true) {
                header('Location: index.php?action=home');
                exit;
            } else {
                $error = $result;
            }
        }
        require('view/create_user.php');
        break;

    case 'login':
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $username = $_POST['username'];
            $password = $_POST['password'];
            $result = (new Model)->loginUser($username, $password);
            if ($result === true) {
                header('Location: index.php?action=secret');
                exit;
            } else {
                $error = $result;
            }
        }
        require('view/login.php');
        break;

    case 'secret':
        if (!(new Model)->isLoggedIn()) {
            header('Location: index.php?action=login');
            exit;
        }
        require('view/secret.php');
        break;

    case 'logout':
        (new Model)->logoutUser();
        header('Location: index.php?action=home');
        exit;

    default:
        header('Location: index.php?action=home');
        exit;
}
