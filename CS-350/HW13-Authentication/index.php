<?php
// Start session
session_start();

// Load the controller
require_once('controller.php');

// Get the requested action
$action = isset($_GET['action']) ? $_GET['action'] : 'home';

// Call the controller function
controller($action);
