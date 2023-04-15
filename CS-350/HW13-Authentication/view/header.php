<?php
require_once 'model.php';
$model = new Model();
?>

<head>
    <title>Authentication</title>
    <link rel="stylesheet" href="./view/style.css">
</head>
<body>
<nav>
    <ul>
        <li><a href="./index.php">Home</a></li>
        <?php if ($model->isLoggedIn()) : ?>
            <li><a href="./index.php?action=secret">Secret</a></li>
            <li><a href="./index.php?action=logout">Logout</a></li>
        <?php else : ?>
            <li><a href="./index.php?action=login">Login</a></li>
            <li><a href="./index.php?action=create_user">Create User</a></li>
        <?php endif; ?>
    </ul>
</nav>
