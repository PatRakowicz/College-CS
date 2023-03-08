<?php
function calculate($x, $y, $operations)
{
    $results = array();

    foreach ($operations as $operation) {
        switch ($operation) {
            case 'addition':
                $results[] = $x + $y;
                break;
            case 'subtraction':
                $results[] = $x - $y;
                break;
            case 'multiplication':
                $results[] = $x * $y;
                break;
            case 'division':
                if ($y == 0) {
                    $results[] = "Error: division by zero";
                } else {
                    $results[] = $x / $y;
                }
                break;
            case 'exponentiation':
                $results[] = pow($x, $y);
                break;
            case 'modulo':
                if ($y == 0) {
                    $results[] = "Error: division by zero";
                } else {
                    $results[] = $x % $y;
                }
                break;
        }
    }

    return $results;
}

function factorial($n)
{
    if ($n < 0) {
        return "Invalid input";
    } else if ($n == 0) {
        return 1;
    } else {
        $result = 1;
        for ($i = 1; $i <= $n; $i++) {
            $result *= $i;
        }
        return $result;
    }
}

function fibonacci($n)
{
    if ($n < 0) {
        return "Invalid input";
    } else if ($n == 0) {
        return 0;
    } else if ($n == 1 || $n == 2) {
        return 1;
    } else {
        $fibonacci = array(0, 1, 1);
        for ($i = 3; $i <= $n; $i++) {
            $fibonacci[$i] = $fibonacci[$i - 1] + $fibonacci[$i - 2];
        }
        return $fibonacci[$n];
    }
}

?>

<head>
    <title>Calculator</title>
</head>
<body>
<h1>Arithmetic Calculator</h1>
<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <input type="number" name="x" placeholder="Enter First Val">
    <input type="number" name="y" placeholder="Enter Second Val">
    <br>
    <input type="checkbox" name="operations[]" value="addition"> Addition
    <input type="checkbox" name="operations[]" value="subtraction"> Subtraction
    <input type="checkbox" name="operations[]" value="multiplication"> Multiplication
    <input type="checkbox" name="operations[]" value="division"> Division
    <input type="checkbox" name="operations[]" value="exponentiation"> Exponentiation
    <input type="checkbox" name="operations[]" value="modulo"> Modulo
    <br>
    <input type="submit" name="submit1" value="Calculate">
</form>

<?php
if (isset($_POST['submit1'])) {
    $x = isset($_POST['x']) ? $_POST['x'] : null;
    $y = isset($_POST['y']) ? $_POST['y'] : null;
    $operations = isset($_POST['operations']) ? $_POST['operations'] : array();
    $results = array();

    if (empty($x) || empty($y)) {
        $results[] = "Please enter two numbers";
    } else {
        $results = calculate($x, $y, $operations);
    }

    echo "<h2>Result:</h2>";
    foreach ($results as $result) {
        echo "<p>";
        if (is_numeric($result)) {
            echo "$x + $y = $result";
        } else {
            echo $result;
        }
        echo "</p>";
    }
}
?>

<h1>Factorial Calculator</h1>
<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <input type="number" name="n" placeholder="Enter a number">
    <input type="submit" name="submit2" value="Calculate">
</form>

<?php
if (isset($_POST['submit2'])) {
    $n = isset($_POST['n']) ? $_POST['n'] : null;
    $result = null;

    if (empty($n)) {
        $result = "Please enter a number";
    } else {
        $result = factorial($n);
    }

    echo "<h2>Result:</h2>";
    echo "<p>$n! = $result</p>";
}
?>

<h1>Fibonacci Calculator</h1>
<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <input type="text" name="n" placeholder="Enter a number">
    <input type="submit" name="submit3" value="Calculate">
</form>

<?php
if (isset($_POST['submit3'])) {
    $n = isset($_POST['n']) ? $_POST['n'] : null;
    $result = null;

    if (empty($n)) {
        $result = "Please enter a number";
    } else {
        $result = fibonacci($n);
    }

    echo "<h2>Result:</h2>";
    echo "<p>The $n-th Fibonacci number is $result</p>";
}
?>
</body>