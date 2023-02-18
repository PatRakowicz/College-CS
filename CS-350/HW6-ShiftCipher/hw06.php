<?php
function shiftCipher($text, $shift) {
    $result = "";
    $text = strtolower($text);
    $shift = $shift % 26;

    for ($i = 0; $i < strlen($text); $i++) {
        if (ctype_alpha($text[$i])) {
            $ascii = ord($text[$i]);
            $ascii += $shift;

            if ($ascii > ord('z')) {
                $ascii -= 26;
            }

            $result .= chr($ascii);
        } else {
            $result .= $text[$i];
        }
    }

    return $result;
}

$plaintext = '';
$ciphertext = '';

if (isset($_POST['action']) && $_POST['action'] == 'Encrypt') {
    $plaintext = $_POST['plaintext'];
    $shift = $_POST['shift'];
    $ciphertext = shiftCipher($plaintext, $shift);

    $_POST['plaintext'] = '';
    $_POST['shift'] = 0;

    $_POST['decryptShift'] = $shift;
}

if (isset($_POST['action']) && $_POST['action'] == 'Decrypt') {
    $ciphertext = $_POST['ciphertext'];
    $shift = $_POST['shift'];
    $plaintext = shiftCipher($ciphertext, 26 - $shift);

    $_POST['ciphertext'] = '';
    $_POST['shift'] = 0;

    $_POST['plaintext'] = $plaintext;
}
?>


<head>
    <title>Shift Cipher</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<div class="container">
    <h1>Shift Cipher</h1>

    <form action="" method="post">
        <label for="plaintext">Plaintext:</label>
        <input type="text" id="plaintext" name="plaintext" value="<?php echo $plaintext; ?>">

        <label for="encryptShift">Shift:</label>
        <input type="range" min="0" max="500" value="0" class="slider" id="encryptShift" name="shift">
        <span id="encryptShiftValue">0</span>

        <input type="submit" value="Encrypt" name="action">
    </form>

    <form action="" method="post">
        <label for="ciphertext">Ciphertext:</label>
        <input type="text" id="ciphertext" name="ciphertext" value="<?php echo $ciphertext; ?>">

        <label for="decryptShift">Shift:</label>
        <input type="range" min="0" max="500" value="0" class="slider" id="decryptShift" name="shift">
        <span id="decryptShiftValue">0</span>

        <input type="submit" value="Decrypt" name="action">
    </form>
</div>

<script>
    let encryptShift = document.getElementById("encryptShift");
    let encryptShiftValue = document.getElementById("encryptShiftValue");
    let decryptShift = document.getElementById("decryptShift");
    let decryptShiftValue = document.getElementById("decryptShiftValue");

    encryptShift.oninput = function () {
        encryptShiftValue.textContent = this.value;
    }

    decryptShift.oninput = function () {
        decryptShiftValue.textContent = this.value;
    }
</script>
</body>