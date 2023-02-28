<?php
session_start();
if (!isset($_SESSION['cart'])) {
    $_SESSION['cart'] = array();
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // Add selected color to cart
    $selected_color = $_POST['color'];
    if (!in_array($selected_color, $_SESSION['cart'])) {
        $_SESSION['cart'][] = $selected_color;
    }
}

// Remove selected colors from cart
if (isset($_POST['remove'])) {
    foreach ($_POST['remove'] as $color) {
        $key = array_search($color, $_SESSION['cart']);
        if ($key !== false) {
            unset($_SESSION['cart'][$key]);
        }
    }
}

// Display cart
?>

<head>
    <title>Cart</title>
</head>
<body>
<h1>Cart</h1>
<p>Selected colors:</p>
<form action="cart.php" method="POST">
    <?php
    // Display each color in the cart
    $unique_colors = array_unique($_SESSION['cart']);
    foreach ($unique_colors as $color) {
        echo "<input type='checkbox' name='remove[]' value='$color'>";
        echo "<span style='display:inline-block;width:70px;height:70px;background-color:$color;'></span>";
        echo "<br>";
    }
    ?>
    <button type="submit">Remove selected colors</button>
</form>
<a href="index.html">Add Color</a>
</body>

