<?php
function encrypt($text, $shift)
{
    $result = "";
    $length = strlen($text);

    for ($i = 0; $i < $length; $i++) {
        $char = $text[$i];
        if (preg_match("/[a-zA-Z]/", $char)) {
            $ascii = ord($char);
            $shifted_ascii = ($ascii + $shift - ($ascii <= 90 ? 65 : 97)) % 26 + ($ascii <= 90 ? 65 : 97);
            $result .= chr($shifted_ascii);
        } else {
            $result .= $char;
        }
    }

    return $result;
}

function decrypt($text, $shift)
{
    $result = "";
    $length = strlen($text);

    for ($i = 0; $i < $length; $i++) {
        $char = $text[$i];
        if (preg_match("/[a-zA-Z]/", $char)) {
            $ascii = ord($char);
            $shifted_ascii = ($ascii - $shift - ($ascii <= 90 ? 65 : 97) + 260) % 26 + ($ascii <= 90 ? 65 : 97);
            $result .= chr($shifted_ascii);
        } else {
            $result .= $char;
        }
    }

    return $result;
}

?>

<head>
    <meta charset="UTF-8">
    <title>Shift Cipher</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<div class="container">
    <div class="form">
        <h2>Encryption</h2>
        <form method="post">
            <label for="plaintext">Plaintext:</label><br>
            <input type="text" id="plaintext" name="plaintext"><br>
            <label for="shift">Shift:</label><br>
            <input type="range" min="1" max="25" value="1" class="slider" id="shift" name="shift">
            <span id="shift-value">1</span><br>
            <label for="ciphertext">Ciphertext:</label><br>
            <input type="text" id="ciphertext" name="ciphertext" readonly><br>
            <input type="submit" name="encrypt" value="Encrypt">
        </form>
    </div>
    <div class="form">
        <h2>Decryption</h2>
        <form method="post">
            <label for="ciphertext2">Ciphertext:</label><br>
            <input type="text" id="ciphertext2" name="ciphertext2"><br>
            <label for="shift2">Shift:</label><br>
            <input type="range" min="1" max="25" value="1" class="slider" id="shift2" name="shift2">
            <span id="shift2-value">1</span><br>
            <label for="plaintext2">Plaintext:</label><br>
            <input type="text" id="plaintext2" name="plaintext2" readonly><br>
            <input type="submit" name="decrypt" value="Decrypt">
        </form>
    </div>
</div>

<?php
if (isset($_POST['encrypt'])) {
    $plaintext = $_POST['plaintext'];
    $shift = (int)$_POST['shift'];
    $ciphertext = encrypt($plaintext, $shift);
    echo '<script>document.getElementById("ciphertext").value = "' . $ciphertext . '";</script>';
} elseif (isset($_POST['decrypt'])) {
    $ciphertext = $_POST['ciphertext2'];
    $shift = (int)$_POST['shift2'];
    $plaintext = decrypt($ciphertext, $shift);
    echo '<script>document.getElementById("plaintext2").value = "' . $plaintext . '";</script>';
}
?>

<script>
    let shiftSlider = document.getElementById("shift");
    let shiftValue = document.getElementById("shift-value");
    shiftValue.innerHTML = shiftSlider.value;
    shiftSlider.oninput = function () {
        shiftValue.innerHTML = this.value;
    }
    let shift2Slider = document.getElementById("shift2");
    let shift2Value = document.getElementById("shift2-value");
    shift2Value.innerHTML = shift2Slider.value;
    shift2Slider.oninput = function () {
        shift2Value.innerHTML = this.value;
    }
</script>
</body>