<head>
    <title>Prime Number Checker</title>
    <link rel="stylesheet" href="style.css">
</head>
<form action="" method="post">
    <label for="number">Enter a number: </label>
    <input type="number" name="number" id="number" required>
    <input type="submit" name="submit" value="Submit">
</form>

<!--<script>-->
<!--    function checkInput() {-->
<!--        let input = document.getElementById("number").value;-->
<!---->
<!--        if (input < 1) {-->
<!--            alert("Input value is negative. Enter Positive value.");-->
<!--            document.getElementById("number").value = "";-->
<!--        }-->
<!--    }-->
<!--</script>-->

<?php
if (isset($_POST['submit'])) {
    $number = $_POST['number'];
    $factors = array();

    // Check if input is a positive integer
    if (filter_var($number, FILTER_VALIDATE_INT) && $number > 0) {
        // Get all factors of the input number
        for ($i = 1; $i <= $number; $i++) {
            if ($number % $i == 0) {
                $factors[] = $i;
            }
        }

        // Check if the input number is prime
        $is_prime = (count($factors) == 2) ? true : false;
    } else {
        echo '<h2 style="color:red;">Please enter a positive integer.</h2>';
    }
    ?>

    <div class="output">
        <h2>Output:</h2>
        <p>Number: <?php echo $number; ?></p>
        <p class="factors">Factors: <?php echo implode(', ', $factors); ?></p>
        <p>Is Prime: <?php echo ($is_prime) ? 'Yes' : 'No'; ?></p>
    </div>

<?php } ?>
