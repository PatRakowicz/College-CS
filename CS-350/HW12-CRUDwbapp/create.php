<?php
// Start a session to store error messages
session_start();

// Connect to the database
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


// If the form has been submitted, insert the new record
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Validate the input data
    $name = filter_input(INPUT_POST, 'name', FILTER_SANITIZE_STRING);
    $description = filter_input(INPUT_POST, 'description', FILTER_SANITIZE_STRING);
    $price = filter_input(INPUT_POST, 'price', FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);

    if (empty($name) || empty($description) || empty($price)) {
        $_SESSION['error'] = 'Please fill in all fields.';
        header('Location: create.php');
        exit;
    }

    // Insert the new record into the database
    $stmt = $db->prepare('INSERT INTO products (name, description, price) VALUES (:name, :description, :price)');
    $stmt->bindParam(':name', $name);
    $stmt->bindParam(':description', $description);
    $stmt->bindParam(':price', $price);

    if ($stmt->execute()) {
        $_SESSION['success'] = 'Record created successfully.';
        header('Location: read.php');
        exit;
    } else {
        $_SESSION['error'] = 'Record creation failed.';
        header('Location: create.php');
        exit;
    }
}
?>


<head>
    <meta charset="UTF-8">
    <title>Create a new record</title>
    <link rel="stylesheet" href="style.css">
</head>

<body>
<nav>
    <a href="read.php">Read</a>
    <a href="create.php">Create</a>
</nav>

<h1>Create a new record</h1>
<?php if (isset($_SESSION['error'])): ?>
    <p class="error"><?= $_SESSION['error'] ?></p>
    <?php unset($_SESSION['error']) ?>
<?php endif ?>
<form method="post">
    <label for="name">Name:</label>
    <input type="text" id="name" name="name" required>
    <br>
    <label for="description">Description:</label>
    <textarea id="description" name="description" required></textarea>
    <br>
    <label for="price">Price:</label>
    <input type="number" id="price" name="price" step="0.01" required>
    <br>
    <input type="submit" value="Create">
</form>
</body>

