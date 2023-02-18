<head>
    <title>Shift Cipher</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>

<?php
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if ($_POST['action'] === 'encrypt') {
        $plaintext = $_POST['plaintext'] ?? '';
        $shift = $_POST['shift'] ?? 0;

        $ciphertext = '';
        $len = strlen($plaintext);

        for ($i = 0; $i < $len; $i++) {
            $char = $plaintext[$i];
            if (ctype_alpha($char)) {
                $ciphertext .= chr((ord(strtoupper($char)) + $shift - 65) % 26 + 65);
            } else {
                $ciphertext .= $char;
            }
        }

        echo '<script>document.getElementById("ciphertext").value = "' . $ciphertext . '"; document.getElementById("decryptShiftValue").textContent = ' . $shift . ';</script>';
    } elseif ($_POST['action'] === 'decrypt') {
        $ciphertext = $_POST['ciphertext'] ?? '';
        $shift = $_POST['shift'] ?? 0;

        $plaintext = '';
        $len = strlen($ciphertext);

        for ($i = 0; $i < $len; $i++) {
            $char = $ciphertext[$i];
            if (ctype_alpha($char)) {
                $plaintext .= chr((ord(strtoupper($char)) - $shift - 65 + 26) % 26 + 65);
            } else {
                $plaintext .= $char;
            }
        }

        echo '<script>document.getElementById("plaintext").value = "' . $plaintext . '"; document.getElementById("encryptShiftValue").textContent = ' . $shift . ';</script>';
    }
}
?>
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

    encryptShift.oninput = function() {
        encryptShiftValue.textContent = this.value;
    }

    decryptShift.oninput = function() {
        decryptShiftValue.textContent = this.value;
    }
</script>
</body>