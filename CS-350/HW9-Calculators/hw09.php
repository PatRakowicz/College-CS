<?php
session_start();

function arithmetic($x, $y, $operation)
{
    switch ($operation) {
        case 'addition':
            return $x + $y;
        case 'subtraction':
            return $x - $y;
        case 'multiplication':
            return $x * $y;
        case 'division':
            return $x / $y;
        case 'exponentiation':
            return pow($x, $y);
        case 'modulo':
            return $x % $y;
        default:
            return null;
    }
}

function factorial($fac)
{
    if ($fac <= 1) {
        return 1;
    } else {
        return $fac * factorial($fac - 1);
    }
}

function fibonacci($fib)
{
    if ($fib <= 0) {
        return 0;
    } else if ($fib == 1) {
        return 1;
    } else {
        return fibonacci($fib - 1) + fibonacci($fib - 2);
    }
}

// Arithmetic Post Method
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['operation']) && $_POST['operation'] == 'arithmetic') {
    $x = $_POST['x'];
    $y = $_POST['y'];
    $operation = $_POST['operation'];

    $result = arithmetic($x, $y, $operation);
    $_SESSION['arithmetic_result'] = $result;
}

// Factorial Post Method
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['operation']) && $_POST['operation'] == 'factorial') {
    $fac = $_POST['fac'];

    $result = factorial($fac);
    $_SESSION['factorial_result'] = $result;
}

// Fibonacci Post Method
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['operation']) && $_POST['operation'] == 'fibonacci') {
    $fib = $_POST['fib'];

    $result = fibonacci($fib);
    $_SESSION['fibonacci_result'] = $result;
}
?>

<head>
    <title>Calculator's</title>
</head>
<body>

<h1>Arithmetic Calculator</h1>
<form method="POST" action="">
    <input type="hidden" name="operation" value="arithmetic">
    <label for="x">Value of X:</label>
    <input type="number" step="any" name="x" required><br><br>
    <label for="y">Value of Y:</label>
    <input type="number" step="any" name="y" required><br><br>
    <label for="operation">Operation:</label>
    <select name="operation">
        <option value="addition">Addition (+)</option>
        <option value="subtraction">Subtraction (-)</option>
        <option value="multiplication">Multiplication (*)</option>
        <option value="division">Division (/)</option>
        <option value="exponentiation">Exponentiation (^)</option>
        <option value="modulo">Modulo (%)</option>
    </select><br><br>
    <input type="submit" value="Calculate">
</form>
<?php
// Arith
if (isset($_SESSION['arithmetic_result'])) {
    echo "<p>The result is: " . $_SESSION['arithmetic_result'] . "</p>";
    unset($_SESSION['arithmetic_result']);
}
?>

<h1>Factorial Calculator</h1>
<form method="POST" action="">
    <input type="hidden" name="operation" value="factorial">
    <label for="fac">Value of N:</label>
    <input type="number" name="fac" min="0" required><br><br>
    <input type="submit" value="Calculate">

</form>
<?php
// Fac
if (isset($_SESSION['factorial_result'])) {
    echo "<p>The factorial of " . $_SESSION['factorial_value'] . " is: " . $_SESSION['factorial_result'] . "</p>";
    unset($_SESSION['factorial_result']);
    unset($_SESSION['factorial_value']);
}
?>

<h1>Fibonacci Calculator</h1>
<form method="POST" action="">
    <input type="hidden" name="operation" value="fibonacci">
    <label for="fib">Value of N:</label>
    <input type="number" name="fib" min="1" required><br><br>
    <input type="submit" value="Calculate">
</form>
<?php
// Fib
if (isset($_SESSION['fibonacci_result'])) {
    echo "<p>The " . $_SESSION['fibonacci_value'] . "th Fibonacci number is: " . $_SESSION['fibonacci_result'] . "</p>";
    unset($_SESSION['fibonacci_result']);
    unset($_SESSION['fibonacci_value']);
}
?>
</body>