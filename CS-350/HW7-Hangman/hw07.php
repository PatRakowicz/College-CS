<?php
session_start();

if (!isset($_SESSION['word'])) {
    $words = array("apple", "banana", "cherry", "date", "elderberry", "fig");
    $_SESSION['word'] = str_split(strtoupper($words[rand(0, count($words) - 1)]));
    $_SESSION['guess'] = array_fill(0, count($_SESSION['word']), "*");
    $_SESSION['attempts'] = 0;
    $_SESSION['missed'] = array();
}

if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['guess'])) {
    $guess = strtoupper($_POST['guess']);
    if (in_array($guess, $_SESSION['word'])) {
        for ($i = 0; $i < count($_SESSION['word']); $i++) {
            if ($_SESSION['word'][$i] == $guess) {
                $_SESSION['guess'][$i] = $guess;
            }
        }
        if (!in_array("*", $_SESSION['guess'])) {
            echo "Congratulations, you guessed the word: " . implode("", $_SESSION['guess']) . "!";
            session_destroy();
            exit;
        }
    } else {
        $_SESSION['attempts']++;
        $_SESSION['missed'][] = $guess;
        if ($_SESSION['attempts'] == 3) {
            echo "Game over, the word was: " . implode("", $_SESSION['word']) . ".";
            session_destroy();
            exit;
        }
    }
}

?>

<head>
    <title>Hangman</title>
</head>
<body>
<h1>Hangman</h1>
<p>Guess the word:</p>
<p><?php echo implode(" ", $_SESSION['guess']); ?></p>
<p>Attempts: <?php echo $_SESSION['attempts']; ?></p>
<p>Missed: <?php echo implode(", ", $_SESSION['missed']); ?></p>
<form method="post">
    <input type="text" name="guess" maxlength="1" autocomplete="off">
    <button type="submit">Guess</button>
<!--    <button type="button" onclick="--><?php //session_destroy(); ?><!--">Reload</button>-->
</form>
</body>
