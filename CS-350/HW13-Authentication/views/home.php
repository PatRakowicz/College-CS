<!DOCTYPE html>
<html>
<head>
    <title>Home</title>
</head>
<body>
<h1>Welcome to the Home Page</h1>

<?php if ($logged_in): ?>
    <p>You are logged in as <?php echo htmlspecialchars($_SESSION['username']); ?>.</p>
    <p><a href="index.php?action=logout">Log out</a></p>
<?php else: ?>
    <p>You are not logged in. <a href="index.php?action=login">Log in</a></p>
<?php endif; ?>

<h2>List of Users</h2>
<table>
    <thead>
    <tr>
        <th>Username</th>
    </tr>
    </thead>
    <tbody>
    <?php foreach ($users as $user): ?>
        <tr>
            <td><?php echo htmlspecialchars($user['username']); ?></td>
        </tr>
    <?php endforeach; ?>
    </tbody>
</table>

<p><a href="index.php?action=create_user">Create User</a></p>
</body>
</html>
