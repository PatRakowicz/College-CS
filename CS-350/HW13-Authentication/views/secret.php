<?php
// Ensure the user is logged in
if (!$logged_in) {
    // Redirect to the login page
    header('Location: index.php?action=login');
    exit();
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Secret Page</title>
</head>
<body>
<h1>Secret Page</h1>
<p>Congratulations, you have successfully logged in and reached the secret page!</p>
<form action="index.php?action=logout" method="POST">
    <input type="submit" value="Log Out">
</form>
</body>
</html>
