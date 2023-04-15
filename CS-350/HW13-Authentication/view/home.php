<?php function render_home($users) { ?>
    <h2>Home</h2>
    <table>
        <thead>
        <tr>
            <th>Username</th>
            <th>Password Hash</th>
        </tr>
        </thead>
        <tbody>
        <?php foreach ($users as $user): ?>
            <tr>
                <td><?= htmlspecialchars($user['username']) ?></td>
                <td><?= htmlspecialchars($user['password']) ?></td>
            </tr>
        <?php endforeach; ?>
        </tbody>
    </table>
<?php } ?>
