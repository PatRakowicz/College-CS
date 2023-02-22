<?php
// array of short words
$words = array("cat", "dog", "bat", "rat", "hat", "mat");

// select a random word from the array
$selected_word = $words[array_rand($words)];

// initialize the number of attempts to 0
$attempts = 3;

// create a string to represent the user's current guess with asterisks for missing letters
$current_guess = str_repeat("*", strlen($selected_word));

// create an array to store the letters missed so far
$missed_letters = array();

// handle form submission
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    // get user input
    $guess = $_POST['guess'];

    // validate input
    if (strlen($guess) !== 1 || !ctype_alpha($guess)) {
        echo "Invalid input. Please enter a single letter.";
        exit;
    }

    // check if the guess is in the selected word
    if (strpos($selected_word, $guess) !== false) {
        // update current guess with correct guess
        for ($i = 0; $i < strlen($selected_word); $i++) {
            if ($selected_word[$i] === $guess) {
                $current_guess[$i] = $guess;
            }
        }
    } else {
        // increment attempts and add guess to missed letters
        $attempts++;
        $missed_letters[] = $guess;
    }
}

// check if game is over
if ($attempts >= 3 || $current_guess === $selected_word) {
    // game over, display appropriate message
    if ($attempts >= 3) {
        $message = "Game over! The word was $selected_word.";
    } else {
        $message = "Congratulations! You guessed the word: $selected_word.";
    }
    // hide form
    $display_form = false;
} else {
    // game still in progress, display current guess, attempts, and missed letters
    $message = "";
    $display_form = true;
}

// HTML code for Hangman game
?>

<head>
    <title>Hangman Game</title>
</head>

<body>
<h1>Hangman Game</h1>
<?php if ($display_form) { ?>
    <p>Current guess: <?php echo $current_guess; ?></p>
    <p>Number of attempts: <?php echo $attempts; ?></p>
    <p>Letters missed so far: <?php echo implode(", ", $missed_letters); ?></p>
    <form method="POST">
        <label for="guess">Enter a letter:</label>
        <input type="text" name="guess" maxlength="1" />
        <input type="submit" value="Submit" />
    </form>
<?php } ?>
<p><?php echo $message; ?></p>
</body>