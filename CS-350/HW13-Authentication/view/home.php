<?php
require((realpath(dirname(__FILE__) . '/..') . '/header.php'));
require_once((realpath(dirname(__FILE__) . '/..') . '/model.php'));

$users = (new Model)->getUsers();
?>

<div class="container">
    <h2>Home</h2>
    <table class="table">
        <thead>
        <tr>
            <th>Username</th>
            <th>Password Hash</th>
        </tr>
        </thead>
        <tbody>
        <?php foreach ($users as $user): ?>
            <tr>
                <td><?php echo htmlspecialchars($user['username']); ?></td>
                <td><?php echo htmlspecialchars($user['password']); ?></td>
            </tr>
        <?php endforeach; ?>
        </tbody>
    </table>
</div>

