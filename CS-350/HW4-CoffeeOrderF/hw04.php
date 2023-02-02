<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = isset($_POST["name"]) ? $_POST["name"] : "";
    $drink_type = isset($_POST["drink_type"]) ? $_POST["drink_type"] : "";
    $drink_size = isset($_POST["drink_size"]) ? $_POST["drink_size"] : "";
    $extras = isset($_POST["extras"]) ? $_POST["extras"] : [];
}
?>

<link rel="stylesheet" href="style.css">
<title>Drink Order Details</title>
<div class="container">
    <h1>Drink Order Details</h1>
    <h2><?php echo $name; ?>, your order is ready!</h2>
    <?php
    if (count($extras) > 0) {
        echo "You had a $drink_size {$drink_type} with " . implode(", ", $extras) . ".";
    } else {
        echo "You had a $drink_size $drink_type without any extras.";
    }
    ?>
</div>
