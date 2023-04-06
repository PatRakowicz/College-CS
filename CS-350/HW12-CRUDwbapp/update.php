<?php
// connect to the database
try {
    $db = new PDO('mysql:host=localhost;dbname=cs_350', 'student', 'CS350');
} catch (PDOException $e) {
    $_SESSION['error'] = 'Database connection failed: ' . $e->getMessage();
    header('Location: read.php');
    exit;
}



// check if ID parameter exists
if (!isset($_GET['id'])) {
    echo "ID parameter not found.";
    exit();
}

$id = $_GET['id'];

// retrieve the record from the database
$sql = "SELECT * FROM cs_350 WHERE id = ?";
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

    // update the record in the database
    $sql = "UPDATE cs_350 SET name = ?, description = ? WHERE id = ?";
    $stmt = $db->prepare($sql);
    $stmt->execute([$name, $description, $id]);

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
    <ul>
        <li><a href="read.php">Read</a></li>
        <li><a href="create.php">Create</a></li>
    </ul>
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
    <button type="submit">Update Record</button>
</form>
</body>

