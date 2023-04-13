<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Create User</title>
</head>
<body>
<h1>Create User</h1>

<?php if (isset($error)): ?>
    <p style="color:red;"><?php echo $error; ?></p>
<?php endif; ?>

<form method="post" action="index.php?action=create_user_submit">
    <p>
        <label for="username">Username:</label>
        <input type="text" id="username" name="username">
    </p>
    <p>
        <label for="password">Password:</label>
        <input type="password" id="password" name="password">
    </p>
    <p>
        <input type="submit" value="Create">
    </p>
</form>

<p><a href="index.php?action=home">Home</a></p>
</body>
</html>
