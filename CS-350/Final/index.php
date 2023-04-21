<?php
session_start();

require_once 'model.php';
require_once 'displayController.php';

$model = new Model();
$action = $_GET['action'] ?? 'home';

switch ($action) {
	case 'home':
		$users = $model->getAllUsers();
		display_home($users);
		break;

	case 'create_user':
		if ($_SERVER['REQUEST_METHOD'] === 'POST') {
			$username = $_POST['username'];
			$password = $_POST['password'];

			if ($model->getUserByUsername($username)) {
				display_create_user("Username already exists.");
			} else {
				$model->createUser($username, $password);
				header("Location: index.php");
				exit;
			}
		} else {
			display_create_user();
		}
		break;

	case 'login':
		if ($_SERVER['REQUEST_METHOD'] === 'POST') {
			$username = $_POST['username'];
			$password = $_POST['password'];
			$user = $model->getUserByUsername($username);

			if ($user) {
				$salt = $user['salt'];
				$salted_password = $salt . $password;
				if (password_verify($salted_password, $user['password'])) {
					$_SESSION['user_id'] = $user['id'];
					header("Location: index.php?action=home");
					exit;
				} else {
					display_login("Invalid username or password.");
				}
			} else {
				display_login("Invalid username or password.");
			}
		} else {
			display_login();
		}
		break;


	case 'create_prod':
		if ($model->isLoggedIn()) {
			if ($_SERVER['REQUEST_METHOD'] === 'POST') {
				$name = filter_input(INPUT_POST, 'name', FILTER_SANITIZE_STRING);
				$description = filter_input(INPUT_POST, 'description', FILTER_SANITIZE_STRING);
				$price = filter_input(INPUT_POST, 'price', FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
				$user_id = $_SESSION['user_id'];

				$model->createProduct($name, $description, $price, $user_id);

				header("Location: index.php?action=view_prod");
				exit;
			} else {
				display_create_prod();
			}
		} else {
			display_login("You must be logged in to create a product.");
		}
		break;

	case 'view_prod':
		if ($model->isLoggedIn()) {
			$products = $model->getProductsByUserId($_SESSION['user_id']);
			display_view_prod($products);
		} else {
			display_login("You must be logged in to view your products.");
		}
		break;

	case 'update_prod':
		if ($model->isLoggedIn()) {
			if ($_SERVER['REQUEST_METHOD'] === 'POST') {
				$name = filter_input(INPUT_POST, 'name', FILTER_SANITIZE_STRING);
				$description = filter_input(INPUT_POST, 'description', FILTER_SANITIZE_STRING);
				$price = filter_input(INPUT_POST, 'price', FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
				$user_id = $_SESSION['user_id'];
				$product_id = $_POST['product_id'];

				if ($model->updateProduct($name, $description, $price, $product_id)) {
					header("Location: index.php?action=view_prod");
					exit;
				} else {
					display_view_prod($model->getProductsByUserId($_SESSION['user_id']), "Failed to update product.");
				}
			} else {
				$product_id = $_GET['id'];
				display_update_prod($product_id);
			}
		} else {
			display_login("You must be logged in to update a product.");
		}
		break;

	case 'delete_prod':
		$id = $_GET['id'];
		$model->deleteProduct($id);
		header("Location: index.php?action=view_prod");
		break;

	case 'logout':
		if ($model->isLoggedIn()) {
			unset($_SESSION['user_id']);
			display_logout();
		} else {
			display_login("You must log in to log out.");
		}
		break;

	default:
		unset($_SESSION['user_id']);
		display_home($model->getAllUsers());
		break;
}
