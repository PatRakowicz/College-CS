<?php function render_home($user = null) { ?>
	<h2>Home</h2>
	<?php if ($user) { ?>
		<p>Welcome back, <?php echo $user['username']; ?>!</p>
	<?php } else { ?>
		<p>Please Login or Create a user to start using/creating products</p>
	<?php } ?>
<?php } ?>
