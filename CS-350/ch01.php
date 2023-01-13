<?php
    $x = $_GET['x'];
    $y = $_GET['y'];
?>

<html>
    <h1> Hello!</h1>
    <?php
        $result = $x + $y;
        echo $x . " + " . $y . " = " . $result;
    ?>
</html>
