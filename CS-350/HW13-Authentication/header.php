<?php
require_once('model.php');
$isLoggedIn = (new Model)->isLoggedIn();
?>

<head>
    <title>Authentication</title>
    <link rel="stylesheet" href="view/style.css">
</head>
<body>
<nav>
    <ul>
        <li><a href="index.php">Home</a></li>
        <?php if ($isLoggedIn) : ?>
            <li><a href="view/secret.php">Secret</a></li>
            <li><a href="view/logout.php">Logout</a></li>
        <?php else : ?>
            <li><a href="view/login.php">Login</a></li>
            <li><a href="view/create_user.php">Create User</a></li>
        <?php endif; ?>
    </ul>
</nav>
