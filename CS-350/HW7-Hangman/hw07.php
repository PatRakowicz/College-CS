<?php
session_start();

if ($_SERVER["REQUEST_METHOD"] == "GET") {
    $words = array("apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon");
    $selected_word = $words[array_rand($words)];
    $_SESSION["selected_word"] = $selected_word;
    $_SESSION["user_guess"] = str_repeat("*", strlen($selected_word));
    $_SESSION["attempts"] = 0;
    $_SESSION["missed_letters"] = "";
    print($selected_word);

} elseif ($_SERVER["REQUEST_METHOD"] == "POST") {
    $selected_word = $_SESSION["selected_word"];
    $user_guess = $_SESSION["user_guess"];
    $attempts = $_SESSION["attempts"];
    $missed_letters = $_SESSION["missed_letters"];

    $letter = strtolower($_POST["letter"]);

    if (strlen($letter) != 1) {
        echo "Please enter only one character.";
        exit();
    }

    if (strpos($selected_word, $letter) !== false) {
        for ($i = 0; $i < strlen($selected_word); $i++) {
            if ($selected_word[$i] == $letter) {
                $user_guess[$i] = $letter;
            }
        }
        $_SESSION["user_guess"] = $user_guess;
    } else {
        $attempts++;
        $missed_letters .= $letter;
        $_SESSION["attempts"] = $attempts;
        $_SESSION["missed_letters"] = $missed_letters;
    }

    if ($user_guess == $selected_word) {
        echo "<h1>HangMan Game</h1>";
        echo "Congratulations, you guessed the word!";
        exit();
    }

    if ($attempts >= 3) {
        echo "<h1>HangMan Game</h1>";
        echo "Game over. The word was " . $selected_word . ".";
        exit();
    }
}
?>


<head>
    <title>Hangman Game</title>
</head>

<body>
<h1>HangMan Game</h1>

<p>User's current guess: <?php echo $_SESSION["user_guess"]; ?></p>
<p>Number of attempts: <?php echo $_SESSION["attempts"]; ?></p>
<p>Letters missed so far: <?php echo $_SESSION["missed_letters"]; ?></p>

<?php if ($_SESSION["attempts"] < 3 && $_SESSION["user_guess"] != $_SESSION["selected_word"]) { ?>
    <form method="POST" action="">
        <label for="letter">Enter a single letter: </label>
        <input type="text" name="letter" id="letter" maxlength="1">
        <input type="submit" value="Guess">
    </form>
<?php } ?>

</body>

