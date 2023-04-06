<?php
// Connect to MySQL database
try {
    $pdo = new PDO('mysql:host=localhost;dbname=cs_350', 'student', 'CS350');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    die("Error connecting to database: " . $e->getMessage());
}

// Retrieve all records from "products" table
try {
    $stmt = $pdo->query('SELECT * FROM products');
    $rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    die("Error retrieving records: " . $e->getMessage());
}

// Display records in table format
echo '<table>';
echo '<tr><th>ID</th><th>Name</th><th>Description</th><th>Price</th><th>Update</th><th>Delete</th></tr>';
foreach ($rows as $row) {
    echo '<tr>';
    echo '<td>' . $row['id'] . '</td>';
    echo '<td>' . $row['name'] . '</td>';
    echo '<td>' . $row['description'] . '</td>';
    echo '<td>' . $row['price'] . '</td>';
    echo '<td><a href="update.php?id=' . $row['id'] . '">Update</a></td>';
    echo '<td><a href="delete.php?id=' . $row['id'] . '">Delete</a></td>';
    echo '</tr>';
}
echo '</table>';
