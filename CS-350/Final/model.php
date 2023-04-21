<?php

class Model {
	private $db;

	public function __construct() {
		$this->db = new PDO('mysql:host=localhost;dbname=cs_350;charset=utf8', 'student', 'CS350');
		$this->db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	}

	public function isLoggedIn() {
		return isset($_SESSION['user_id']);
	}

	public function getAllUsers() {
		$stmt = $this->db->query('SELECT * FROM users');
		return $stmt->fetchAll(PDO::FETCH_ASSOC);
	}

	public function getUserByUsername($username) {
		$stmt = $this->db->prepare('SELECT * FROM users WHERE username = :username');
		$stmt->bindParam(':username', $username);
		$stmt->execute();
		return $stmt->fetch(PDO::FETCH_ASSOC);
	}

	public function getUserById($id) {
		$stmt = $this->db->prepare('SELECT * FROM users WHERE id = :id');
		$stmt->bindParam(':id', $id);
		$stmt->execute();
		return $stmt->fetch(PDO::FETCH_ASSOC);
	}

	public function createUser($username, $password) {
		$salt = bin2hex(random_bytes(32));
		$salted_password = $salt . $password;
		$hashed_password = password_hash($salted_password, PASSWORD_DEFAULT);
		$stmt = $this->db->prepare('INSERT INTO users (username, password, salt) VALUES (?, ?, ?)');
		return $stmt->execute([$username, $hashed_password, $salt]);
	}

	public function createProduct($name, $description, $price, $user_id) {
		$stmt = $this->db->prepare('INSERT INTO products (name, description, price, user_id) VALUES (:name, :description, :price, :user_id)');
		$stmt->bindParam(':name', $name);
		$stmt->bindParam(':description', $description);
		$stmt->bindParam(':price', $price);
		$stmt->bindParam(':user_id', $user_id);
		return $stmt->execute();
	}

	public function getProductsByUserId($user_id) {
		$stmt = $this->db->prepare('SELECT * FROM products WHERE user_id = :user_id');
		$stmt->bindParam(':user_id', $user_id);
		$stmt->execute();
		return $stmt->fetchAll(PDO::FETCH_ASSOC) ?? [];
	}

	public function updateProduct($name, $description, $price, $id) {
		$stmt = $this->db->prepare('UPDATE products SET name = :name, description = :description, price = :price WHERE id = :id');
		$stmt->bindParam(':name', $name);
		$stmt->bindParam(':description', $description);
		$stmt->bindParam(':price', $price);
		$stmt->bindParam(':id', $id);
		return $stmt->execute();
	}

	public function getProductById($id) {
		$stmt = $this->db->prepare('SELECT * FROM products WHERE id = :id');
		$stmt->bindParam(':id', $id);
		$stmt->execute();
		return $stmt->fetch(PDO::FETCH_ASSOC);
	}

	public function deleteProduct($id) {
		$stmt = $this->db->prepare('DELETE FROM products WHERE id = ?');
		$stmt->execute([$id]);
	}

	public function getProducts($user_id) {
		$stmt = $this->db->prepare('SELECT * FROM products WHERE user_id = :user_id');
		$stmt->bindParam(':user_id', $user_id);
		$stmt->execute();
		return $stmt->fetchAll(PDO::FETCH_ASSOC);
	}
}
