<head>
    <meta charset="UTF-8">
    <title>Authentication</title>
    <link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>
<nav>
    <ul>
        <li><a href="index.php">Home</a></li>
        <?php if(isset($_SESSION['username'])): ?>
            <li><a href="secret.php">Secret</a></li>
            <li><a href="logout.php">Logout</a></li>
        <?php else: ?>
            <li><a href="login.php">Login</a></li>
            <li><a href="create.php">Create User</a></li>
        <?php endif; ?>
    </ul>
</nav>
