<?php
// Start session
session_start();

// Log out the user
unset($_SESSION['username']);

// Redirect to the home page
header('Location: index.php?action=home');
