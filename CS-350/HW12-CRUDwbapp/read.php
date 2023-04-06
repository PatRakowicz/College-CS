<?php
// Connect to the database
$dsn = 'mysql:host=localhost;dbname=cs_350';
$username = 'student';
$password = 'CS350';
try {
    $db = new PDO($dsn, $username, $password);
} catch (PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
    exit;
}

// Retrieve all records from the table
$stmt = $db->prepare('SELECT * FROM products');
$stmt->execute();
$products = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>


<head>
    <title>Read Products</title>
    <link rel="stylesheet" href="style.css">
</head>

<body>
<h1>Products</h1>
<nav>
    <a href="read.php">Read</a>
    <a href="create.php">Create</a>
</nav>
<table>
    <thead>
    <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Description</th>
        <th>Price</th>
        <th>Actions</th>
    </tr>
    </thead>
    <tbody>
    <?php foreach ($products as $product): ?>
        <tr>
            <td><?= $product['id'] ?></td>
            <td><?= $product['name'] ?></td>
            <td><?= $product['description'] ?></td>
            <td><?= $product['price'] ?></td>
            <td>
                <a href="update.php?id=<?= $product['id'] ?>">Update</a>
                <a href="delete.php?id=<?= $product['id'] ?>">Delete</a>
            </td>
        </tr>
    <?php endforeach ?>
    </tbody>
</table>

</body>

