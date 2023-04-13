<?php

class Model {
    private $db;

    function __construct() {
        $dsn = 'mysql:host=localhost; dbname=cs_350';
        $username = 'student';
        $password = 'CS350';

        try {
            $this->db = new PDO($dsn, $username, $password);
        } catch (PDOException $e) {
            exit('connection Failed: ' . $e->getMessage());
        }
    }

    function createUser($username, $password) {
        $hash = password_hash($password, PASSWORD_DEFAULT);
        $stmt = $this->db->prepare("INSERT INTO users (username, password_hash) VALUES (?, ?)");
        $stmt->bindValue(1, $username);
        $stmt->bindValue(2, $hash);
        $stmt->execute();
    }

    function getUser($username) {
        $stmt = $this->db->prepare("SELECT * FROM users WHERE username = ?");
        $stmt->bindValue(1, $username);
        $stmt->execute();
        return $stmt->fetch();
    }

    function getAllUsers() {
        $stmt = $this->db->prepare("SELECT * FROM users");
        $stmt->execute();
        return $stmt->fetchAll();
    }
}