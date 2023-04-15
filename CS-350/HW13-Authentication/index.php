<?php
session_start();

require_once 'model.php';
require_once 'displayController.php';

$model = new Model();
$action = $_GET['action'] ?? 'home';

switch ($action) {
    case 'home':
        $users = $model->getAllUsers();
        display_home($users);
        break;

    case 'create_user':
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $username = $_POST['username'];
            $password = $_POST['password'];

            if ($model->getUserByUsername($username)) {
                display_create_user("Username already exists.");
            } else {
                $model->createUser($username, $password);
                header("Location: index.php");
                exit;
            }
        } else {
            display_create_user();
        }
        break;

    case 'login':
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $username = $_POST['username'];
            $password = $_POST['password'];
            $user = $model->getUserByUsername($username);

            if ($user) {
                $salt = $user['salt'];
                $salted_password = $salt . $password;
                if (password_verify($salted_password, $user['password'])) {
                    $_SESSION['user_id'] = $user['id'];
                    header("Location: index.php?action=home");
                    exit;
                } else {
                    display_login("Invalid username or password.");
                }
            } else {
                display_login("Invalid username or password.");
            }
        } else {
            display_login();
        }
        break;

    case 'secret':
        if ($model->isLoggedIn()) {
            $user = $model->getUserById($_SESSION['user_id']);
            $username = $user['username'];
            display_secret($username);
        } else {
            display_login("You must log in to view the secret.");
        }
        break;

    case 'logout':
        if ($model->isLoggedIn()) {
            unset($_SESSION['user_id']);
            display_logout();
        } else {
            display_login("You must log in to log out.");
        }
        break;

    default:
        display_home($model->getAllUsers());
        break;
}
