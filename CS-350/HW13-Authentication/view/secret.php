<?php
require((realpath(dirname(__FILE__) . '/..') . '/header.php'));
require_once((realpath(dirname(__FILE__) . '/..') . '/model.php'));


$model = new Model();
$user = $model->getUsers();

if ($model->isLoggedIn()) {
    $secret = $model->getSecret();
    $username = $user['username'];
    $password = $user['password'];
} else {
    header('Location: login.php');
    exit();
}
?>

<div class="container">
    <h1>Secret</h1>
    <p>Hello <?php echo $username; ?>, the secret word is <?php echo $password; ?></p>
</div>
