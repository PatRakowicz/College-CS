<?php
require_once('header.php');
require_once('');

$model = new Model();
$user = $model->getUsers($_SESSION['user_id']);

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
