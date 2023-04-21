<?php function render_create_user($error) { ?>
	<h2>Create User</h2>
	<?php if ($error): ?>
		<p class="error"><?= $error ?></p>
	<?php endif; ?>
	<form action="./index.php?action=create_user" method="post">
		<label for="username">Username:</label>
		<input type="text" name="username" id="username" required>
		<label for="password">Password:</label>
		<input type="password" name="password" id="password" required>
		<button type="submit">Create User</button>
	</form>
<?php } ?>
