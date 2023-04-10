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

// check if ID parameter exists
if (!isset($_GET['id'])) {
    echo "ID parameter not found.";
    exit();
}

$id = $_GET['id'];

// retrieve the record from the database
$sql = "SELECT * FROM products WHERE id = ?";
$stmt = $db->prepare($sql);
$stmt->execute([$id]);
$record = $stmt->fetch(PDO::FETCH_ASSOC);

// check if record exists
if (!$record) {
    echo "Record not found.";
    exit();
}

// handle form submission
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $name = $_POST['name'];
    $description = $_POST['description'];
    $price = floatval($_POST['price']);

    // update the record in the database
    $sql = "UPDATE products SET name = ?, description = ?, price = ? WHERE id = ?";
    $stmt = $db->prepare($sql);
    $stmt->execute([$name, $description, $price, $id]);

    // redirect to the Read page
    header('Location: read.php');
    exit();
}
?>


<head>
    <title>Update Record</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<nav>
    <a href="read.php">Read</a>
    <a href="create.php">Create</a>
</nav>

<h1>Update Record</h1>
<form method="POST">
    <div>
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" value="<?php echo $record['name']; ?>" required>
    </div>
    <div>
        <label for="description">Description:</label>
        <textarea id="description" name="description" required><?php echo $record['description']; ?></textarea>
    </div>
    <div>
        <label for="price">Price:</label>
        <input type="text" id="price" name="price" value="<?php echo $record['price']; ?>" required pattern="\d+(\.\d{1,2})?">
    </div>
    <button type="submit">Update Record</button>
</form>
</body>
