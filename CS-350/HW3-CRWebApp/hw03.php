<?php
$dsn = "mysql:host=localhost;dbname=cs_350";
$username = "student";
$password = "CS350";

try {
    $conn = new PDO($dsn, $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $brand = $_POST['brand'];
    $name = $_POST['name'];
    $price = $_POST['price'];
    $stmt = $conn->prepare("INSERT INTO products (brand, name, price) VALUES (:brand, :name, :price)");
    $stmt->bindParam(':brand', $brand);
    $stmt->bindParam(':name', $name);
    $stmt->bindParam(':price', $price);
    $stmt->execute();
    echo "Product added successfully";
} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
}
$conn = null;
?>