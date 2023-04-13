<?php
// Start session
session_start();

// Load the model and view
require_once('model.php');
require_once('view.php');

// Define the controller function
function controller($action) {
    // Check if the user is logged in
    $logged_in = isset($_SESSION['username']);

    switch($action) {
        // Display home page
        case 'home':
            // Get all users
            $users = get_users();
            // Render the view
            render('home', array('users' => $users, 'logged_in' => $logged_in));
            break;

        // Display create user page
        case 'create_user':
            // Render the view
            render('create_user', array('logged_in' => $logged_in));
            break;

        // Process create user form submission
        case 'create_user_submit':
            // Get the submitted username and password
            $username = $_POST['username'];
            $password = $_POST['password'];

            // Check if the username is already taken
            $user = get_user_by_username($username);
            if ($user !== false) {
                // Render the view with an error message
                render('create_user', array('error' => 'Username is already taken.', 'logged_in' => $logged_in));
                return;
            }

            // Hash the password
            $password_hash = password_hash($password, PASSWORD_DEFAULT);

            // Create the user
            create_user($username, $password_hash);

            // Redirect to the home page
            header('Location: index.php?action=home');
            break;

        // Display login page
        case 'login':
            // Render the view
            render('login', array('logged_in' => $logged_in));
            break;

        // Process login form submission
        case 'login_submit':
            // Get the submitted username and password
            $username = $_POST['username'];
            $password = $_POST['password'];

            // Get the user by username
            $user = get_user_by_username($username);

            // Check if the user exists and the password is correct
            if ($user !== false && password_verify($password, $user['password_hash'])) {
                // Log in the user
                $_SESSION['username'] = $username;

                // Redirect to the secret page
                header('Location: index.php?action=secret');
            } else {
                // Render the view with an error message
                render('login', array('error' => 'Invalid username or password.', 'logged_in' => $logged_in));
            }
            break;

        // Display secret page
        case 'secret':
            // Check if the user is logged in
            if (!$logged_in) {
                // Redirect to the login page
                header('Location: index.php?action=login');
                return;
            }

            // Render the view
            render('secret', array('logged_in' => $logged_in));
            break;

        // Process logout
        case 'logout':
            // Check if the user is logged in
            if (!$logged_in) {
                // Redirect to the home page
                header('Location: index.php?action=home');
                return;
            }

            // Log out the user
            unset($_SESSION['username']);

            // Redirect to the home page
            header('Location: index.php?action=home');
            break;

        // Display error page for unknown action
        default:
            render('error', array('error' => 'Unknown action.', 'logged_in' => $logged_in));
            break;
    }
}
