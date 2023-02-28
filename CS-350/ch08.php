<? php

session_set_cookie_params(60, '/);	
session_start();

if (!isset($_SESSION['x])) {
	$_SESSION['x'] = 0;
}

if (!isset($_SESSION['y])) {
        $_SESSION['y'] = 0; 
}

if (!isset($_SESSION['z])) {
        $_SESSION['z'] = 0; 
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
	if(isset($_POST[''])) {
		
	}
}

?>


<form method="POST">
	<input type="submit" name="x" val="X++">
</form>

<form method="POST">
        <input type="submit" name="y" val="Y++"> 
</form> 

<form method="POST">
        <input type="submit" name="z" val="Z++"> 
</form> 
