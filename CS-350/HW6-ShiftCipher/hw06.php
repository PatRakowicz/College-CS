<?php
function shift($text, $shift, $direction) {
    $result = '';
    $shift = $shift % 26;
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_alpha($char)) {
            $case = ctype_upper($char) ? 65 : 97;
            if ($direction == 'encrypt') {
                $char = chr(($case + ord($char) + $shift - $case) % 26 + $case);
            } else {
                $char = chr(($case + ord($char) - $shift - $case + 26) % 26 + $case);
            }
        }
        $result .= $char;
    }
    return $result;
}

$plaintext = '';
$ciphertext = '';
$encrypt_shift = 0;
$decrypt_shift = 0;

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_POST['encrypt_text'])) {
        $plaintext = $_POST['encrypt_text'];
        $encrypt_shift = $_POST['encrypt_shift'];
        $ciphertext = shift($plaintext, $encrypt_shift, 'encrypt');
    } else if (isset($_POST['decrypt_text'])) {
        $ciphertext = $_POST['decrypt_text'];
        $decrypt_shift = $_POST['decrypt_shift'];
        $plaintext = shift($ciphertext, $decrypt_shift, 'decrypt');
    }
}
?>


<head>
    <title>Shift Cipher</title>
    <style>

    </style>
</head>


<body>
<h1>Shift Cipher</h1>
<form action="" method="post">
    <h2>Encrypt</h2>
    <label for="encrypt_text">Plaintext:</label>
    <input type="text" name="encrypt_text" id="encrypt_text" value="<?php echo htmlspecialchars($plaintext); ?>">
    <label for="encrypt_shift">Shift:</label>
    <input type="number" name="encrypt_shift" id="encrypt_shift" class="shift-input" value="<?php echo htmlspecialchars($encrypt_shift); ?>">
    <input type="submit" value="Encrypt">
</form>
<form action="" method="post">
    <h2>Decrypt</h2>
    <label for="decrypt_text">Ciphertext:</label>
    <input type="text" name="decrypt_text" id="decrypt_text" value="<?php echo htmlspecialchars($ciphertext); ?>">
    <label for="decrypt_shift">Shift:</label>
    <input type="number" name="decrypt_shift" id="decrypt_shift" class="shift-input" value="<?php echo htmlspecialchars($decrypt_shift); ?>">
    <input type="submit" value="Decrypt">
</form>
</body>