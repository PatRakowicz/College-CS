<?php require('header.php'); ?>

<h2>Create User</h2>

<?php if (!empty($error)): ?>
    <p class="error"><?= $error ?></p>
<?php endif; ?>

<form method="post" action="./../index.php?action=create_user">
    <div>
        <label for="username">Username:</label>
        <input type="text" name="username" required>
    </div>
    <div>
        <label for="password">Password:</label>
        <input type="password" name="password" required>
    </div>
    <div>
        <button type="submit">Create User</button>
    </div>
</form>
