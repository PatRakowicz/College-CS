<h1>Enter New Bike Detail</h1>
<form method="post" action="">
    Brand:<br>
    <input type="text" name="brand" required>
    <br>
    Name:<br>
    <input type="text" name="name" required>
    <br>
    Price:<br>
    <input type="number" step="0.01" min="0" name="price" required>
    <br>
    Year:<br>
    <input type="number" min="1800" name="year" required>
    <br><br>
    <input type="submit" value="Submit" name="submit">
</form>
<h2>Entered Data</h2>
<?php
$servername = "localhost";
$username = "student";
$password = "CS350";
$dbname = "cs_350";

if(isset($_POST['submit'])) {
    try {
        $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        $brand = $_POST['brand'];
        $name = $_POST['name'];
        $price = $_POST['price'];
        $year = $_POST['year'];

        $sql = "INSERT INTO bikes (brand, name, price, year) VALUES (:brand, :name, :price, :year)";
        $stmt = $conn->prepare($sql);
        $stmt->bindParam(':brand', $brand);
        $stmt->bindParam(':name', $name);
        $stmt->bindParam(':price', $price);
        $stmt->bindParam(':year', $year);
        $stmt->execute();

        echo "New record created successfully";
    } catch(PDOException $e) {
        echo "Error: " . $e->getMessage();
    }
    $conn = null;
}

try {
    $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $stmt = $conn->prepare("SELECT * FROM bikes");
    $stmt->execute();
    $result = $stmt->fetchAll();
    if(count($result) > 0) {
        echo "<table border=1><tr><th>ID</th><th>Brand</th><th>Name</th><th>Price</th><th>Year</th></tr>";
        foreach($result as $row) {
            echo "<tr><td>".$row["ID"]."</td><td>".$row["brand"]."</td><td>".$row["name"]."</td><td>$".number_format($row["price"], 2)."</td><td>".$row["year"]."</td></tr>";
        }
        echo "</table>";
    } else {
        echo "0 results";
    }
} catch(PDOException $e) {
    echo "Error: " . $e->getMessage();
}
$conn = null;
?>

