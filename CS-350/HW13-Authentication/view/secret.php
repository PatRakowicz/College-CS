<?php function render_secret($username) { ?>
    <h2>Secret</h2>
    <p>This is a secret page only accessible by authenticated users.</p>
    <p>Hello <?php echo htmlspecialchars($username); ?>, the secret word is Starfish ?></p>
<?php } ?>
