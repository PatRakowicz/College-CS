<head>
    <link rel="stylesheet" href="style.css">
</head>

<body>
<nav>
    <ul>
        <li><a href="index.php">Home</a></li>
        <?php if(isset($_SESSION['username'])) { ?>
            <li><a href="secret.php">Secret</a></li>
            <li><a href="logout.php">Logout</a></li>
        <?php } else { ?>
            <li><a href="login.php">Login</a></li>
            <li><a href="create_user.php">Create User</a></li>
        <?php } ?>
    </ul>
</nav>
<main>
    <h1>My Web App</h1>
    <?php if(isset($_SESSION['message'])) { ?>
        <p class="message"><?= $_SESSION['message'] ?></p>
        <?php unset($_SESSION['message']); ?>
    <?php } ?>
    <table>
        <tr>
            <th>Username</th>
            <th>Password Hash</th>
        </tr>
        <?php foreach($users as $user) { ?>
            <tr>
                <td><?= $user['username'] ?></td>
                <td><?= $user['password'] ?></td>
            </tr>
        <?php } ?>
    </table>
    <?php if(isset($_SESSION['username'])) { ?>
        <p>Welcome, <?= $_SESSION['username'] ?>!</p>
    <?php } ?>
    <?php if(!isset($_SESSION['username'])) { ?>
        <h2>Create User</h2>
        <form action="index.php" method="post">
            <input type="hidden" name="action" value="create">
            <label for="username">Username:</label>
            <input type="text" name="username" required>
            <label for="password">Password:</label>
            <input type="password" name="password" required>
            <button type="submit">Create User</button>
        </form>
        <h2>Login</h2>
        <form action="login.php" method="post">
            <label for="username">Username:</label>
            <input type="text" name="username" required>
            <label for="password">Password:</label>
            <input type="password" name="password" required>
            <button type="submit">Login</button>
        </form>
    <?php } ?>
</main>
</body>
