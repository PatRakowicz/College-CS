<?php
require_once('model.php');
$isLoggedIn = (new Model)->isLoggedIn();
?>


<head>
    <title>Authentication</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<nav>
    <ul>
        <li><a href="./../index.php">Home</a></li>
        <?php if ($isLoggedIn) : ?>
            <li><a href="secret.php">Secret</a></li>
            <li><a href="logout.php">Logout</a></li>
        <?php else : ?>
            <li><a href="login.php">Login</a></li>
            <li><a href="create_user.php">Create User</a></li>
        <?php endif; ?>
    </ul>
</nav>
