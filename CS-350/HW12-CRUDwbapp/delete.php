<?php
// connect to the database
$dsn = 'mysql:host=localhost;dbname=cs_350';
$username = 'student';
$password = 'CS350';
try {
    $db = new PDO($dsn, $username, $password);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
    header('Location: read.php');
    exit;
}

// Prepare delete statement
$stmt = $db->prepare('DELETE FROM products WHERE id = :id');

// Bind parameters to statement
$stmt->bindParam(':id', $_GET['id']);

// Execute statement
$stmt->execute();

// Redirect to read page
header('Location: read.php');
exit;
