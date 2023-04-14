<?php require((realpath(dirname(__FILE__) . '/..') . '/header.php')); ?>

<body>
<h2>Login</h2>
<?php if (isset($error)): ?>
    <p><?= $error ?></p>
<?php endif; ?>
<form method="post">
    <label for="username">Username:</label>
    <input type="text" id="username" name="username"><br><br>
    <label for="password">Password:</label>
    <input type="password" id="password" name="password"><br><br>
    <input type="submit" value="Login">
</form>
</body>
