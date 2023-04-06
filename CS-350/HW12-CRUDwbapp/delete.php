<?php
// connect to the database
try {
    $db = new PDO('mysql:host=localhost;dbname=cs_350', 'student', 'CS350');
} catch (PDOException $e) {
    $_SESSION['error'] = 'Database connection failed: ' . $e->getMessage();
    header('Location: read.php');
    exit;
}

// Prepare delete statement
$stmt = $db->prepare('DELETE FROM cs_350 WHERE id = :id');

// Bind parameters to statement
$stmt->bindParam(':id', $_GET['id']);

// Execute statement
$stmt->execute();

// Redirect to read page
header('Location: read.php');
exit;
?>
